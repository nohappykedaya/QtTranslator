#include "apimanager.h"
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QCryptographicHash>

apimanager::apimanager(QObject *parent)
    : QObject{parent}
{
    connect(&manager, &QNetworkAccessManager::finished, this, &apimanager::onReplyFinished);
    appKey = "4a465ba2a5f131ee";
    appSecret = "xcxjVow5VgEGQLS5PqTNB9y60Yne01Jd";
}
void apimanager::queryOnline(const QString &word) {
    QString salt = QString::number(QDateTime::currentMSecsSinceEpoch());
    QString signStr = appKey + word + salt + appSecret;
    QString sign = QCryptographicHash::hash(signStr.toUtf8(), QCryptographicHash::Md5).toHex();

    QUrl url("https://openapi.youdao.com/api");
    QUrlQuery query;
    query.addQueryItem("q", word);
    query.addQueryItem("from", "auto");
    query.addQueryItem("to", "zh-CHS");
    query.addQueryItem("appKey", appKey);
    query.addQueryItem("salt", salt);
    query.addQueryItem("sign", sign);
    url.setQuery(query);

    QNetworkRequest request(url);
    manager.get(request);
}

void apimanager::onReplyFinished(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        emit resultReady("在线翻译失败");
        reply->deleteLater();
        return;
    }
    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QString result;
    if (doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("translation")) {
            QJsonArray arr = obj["translation"].toArray();
            if (!arr.isEmpty())
                result = arr[0].toString();
        }
    }
    if (result.isEmpty()) result = "未查到翻译";
    emit resultReady(result);
    reply->deleteLater();
}
