#include "translatorcontroller.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>

TranslatorController::TranslatorController(QObject *parent) : QObject(parent)
  ,_ui(new MainWindow())
{
    qDebug()<<"Start aplication";

    _ui->setController(this);

    openFile();
}

void TranslatorController::show()
{
    _ui->show();
}

void TranslatorController::openText()
{

    const QString text = openFile();

    _ui->loadText(text);

}

void TranslatorController::openMors()
{
    const QString text = openFile();

    _ui->loadMors(text);

}

void TranslatorController::closeApp()
{

}

QString TranslatorController::openFile()
{

    QString fileName = QFileDialog::getOpenFileName(_ui,
           tr("Open File"),QString(""),tr(" *.txt (*.txt)"));

//    QString fileName = "./text.txt";

    qDebug()<<"File name:"<<fileName;
    QString pom("");

    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);

    if(file.isOpen()) {
        QTextStream strem(&file);
        pom = strem.readAll();
    }

    qDebug()<<"file text:"<<pom;

    return pom;
}
