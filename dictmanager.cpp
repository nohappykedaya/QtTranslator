#include "dictmanager.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QCoreApplication>

dictmanager::dictmanager()
{
    loadDict();
}

void dictmanager::loadDict() {
    QString path = QCoreApplication::applicationDirPath() + "/resources/dict.csv";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() >= 2)
            dict[parts[0].trimmed()] = parts[1].trimmed();
    }
}

QString dictmanager::query(const QString &word) {
    return dict.value(word, "");
}
