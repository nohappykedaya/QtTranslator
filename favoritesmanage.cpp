#include "favoritesmanage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

favoritesmanage::favoritesmanage(QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase("QSQLITE", "favorites");
    db.setDatabaseName("database.db");
    if (!db.open()) {
        qDebug() << "数据库打开失败:" << db.lastError().text();
    }
    initDB();
}
void favoritesmanage::initDB() {
    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS favorites (word TEXT PRIMARY KEY, result TEXT)");
}

void favoritesmanage::addFavorite(const QString &word, const QString &result) {
    QSqlQuery query(db);
    query.prepare("REPLACE INTO favorites (word, result) VALUES (?, ?)");
    query.addBindValue(word);
    query.addBindValue(result);
    query.exec();
}

QString favoritesmanage::getResult(const QString &word) const {
    QSqlQuery query(db);
    query.prepare("SELECT result FROM favorites WHERE word = ?");
    query.addBindValue(word);
    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    return "";
}

QStringList favoritesmanage::getAllWords() const {
    QStringList list;
    QSqlQuery query(db);
    query.exec("SELECT word FROM favorites ORDER BY rowid DESC");
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}
