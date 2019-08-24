#ifndef TRANSLATORCONTROLLER_H
#define TRANSLATORCONTROLLER_H

#include <QObject>
#include "mainwindow.h"

class TranslatorController : public QObject
{
    Q_OBJECT
public:
    explicit TranslatorController(QObject *parent = 0);
    void show();

signals:

public slots:
    void openText();
    void openMors();
    void closeApp();

private:
    QString openFile();
    bool isMors(QString);

    MainWindow* _ui;
};

#endif // TRANSLATORCONTROLLER_H
