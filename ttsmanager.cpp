#include "ttsmanager.h"

ttsmanager::ttsmanager(QObject *parent)
    : QObject{parent}
{
    tts = new QTextToSpeech(this);
}
void ttsmanager::speak(const QString &text) {
    tts->say(text);
}
