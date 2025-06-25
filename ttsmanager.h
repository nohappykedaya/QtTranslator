#ifndef TTSMANAGER_H
#define TTSMANAGER_H

#include <QObject>
#include <QTextToSpeech>

class ttsmanager : public QObject
{
    Q_OBJECT
public:
    explicit ttsmanager(QObject *parent = nullptr);
    void speak(const QString &text);
private:
    QTextToSpeech *tts;
};

#endif // TTSMANAGER_H
