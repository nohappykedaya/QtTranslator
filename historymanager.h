#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QStringList>

class historymanager : public QObject
{
    Q_OBJECT
public:
    explicit historymanager(QObject *parent = nullptr);
    void addHistory(const QString &word, const QString &result);
    QString getResult(const QString &word) const;
    QStringList getAllWords() const;

private:
    QSqlDatabase db;
    void initDB();
};

#endif // HISTORYMANAGER_H
