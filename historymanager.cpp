#include "historymanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>


historymanager::historymanager(QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase("QSQLITE", "history");
    db.setDatabaseName("database.db");
    if (!db.open()) {
        qDebug() << "数据库打开失败:" << db.lastError().text();
    }
    initDB();

}
void historymanager::initDB() {
    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS history (word TEXT PRIMARY KEY, result TEXT)");
}

void historymanager::addHistory(const QString &word, const QString &result) {
    QSqlQuery query(db);
    query.prepare("REPLACE INTO history (word, result) VALUES (?, ?)");
    query.addBindValue(word);
    query.addBindValue(result);
    query.exec();
}

QString historymanager::getResult(const QString &word) const {
    QSqlQuery query(db);
    query.prepare("SELECT result FROM history WHERE word = ?");
    query.addBindValue(word);
    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    return "";
}

QStringList historymanager::getAllWords() const {
    QStringList list;
    QSqlQuery query(db);
    query.exec("SELECT word FROM history ORDER BY rowid DESC");
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}
