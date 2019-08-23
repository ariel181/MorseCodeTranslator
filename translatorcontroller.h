#ifndef TRANSLATORCONTROLLER_H
#define TRANSLATORCONTROLLER_H

#include <QObject>
#include "mainwindow.h"

class TranslatorController : public QObject
{
    Q_OBJECT
public:
    explicit TranslatorController(QObject *parent = 0);

signals:

public slots:
    void openText();
    void openMors();

private:
    QString openFile();
    bool isMors(QString);

    MainWindow* _ui;
};

#endif // TRANSLATORCONTROLLER_H
