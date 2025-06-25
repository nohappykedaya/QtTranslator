#ifndef DICTMANAGER_H
#define DICTMANAGER_H

#include <QString>
#include <QMap>


class dictmanager
{
public:
    dictmanager();
    QString query(const QString &word);
private:
    QMap<QString, QString> dict;
    void loadDict();
};

#endif // DICTMANAGER_H
