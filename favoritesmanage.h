#ifndef FAVORITESMANAGE_H
#define FAVORITESMANAGE_H

#include <QObject>
#include <QSqlDatabase>
#include <QStringList>



class favoritesmanage : public QObject
{
    Q_OBJECT
public:
    explicit favoritesmanage(QObject *parent = nullptr);
    void addFavorite(const QString &word, const QString &result);
    QString getResult(const QString &word) const;
    QStringList getAllWords() const;

private:
    QSqlDatabase db;
    void initDB();
};

#endif // FAVORITESMANAGE_H
