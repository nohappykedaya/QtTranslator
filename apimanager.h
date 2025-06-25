#ifndef APIMANAGER_H
#define APIMANAGER_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>




class apimanager : public QObject
{
    Q_OBJECT
public:
    explicit apimanager(QObject *parent = nullptr);
    void queryOnline(const QString &word);
signals:
    void resultReady(const QString &result);
private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager manager;
    QString appKey;
    QString appSecret;
};

#endif // APIMANAGER_H
