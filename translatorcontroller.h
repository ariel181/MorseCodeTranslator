#ifndef TRANSLATORCONTROLLER_H
#define TRANSLATORCONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "translatormodel.h"

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
    void saveFile(const QString content, const QString title);
    void transMorsToText(const QString content);
    void transTextToMors(const QString content);

private:
    QString openFile();
    bool isMors(QString);

    MainWindow* _ui;
    TranslatorModel* _model;
};

#endif // TRANSLATORCONTROLLER_H
