#ifndef TRANSLATORCONTROLLER_H
#define TRANSLATORCONTROLLER_H

#include <QObject>

class TranslatorController : public QObject
{
    Q_OBJECT
public:
    explicit TranslatorController(QObject *parent = 0);

signals:

public slots:
};

#endif // TRANSLATORCONTROLLER_H