#include "translatorcontroller.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

TranslatorController::TranslatorController(QObject *parent) : QObject(parent)
  ,_ui(new MainWindow())
  ,_model(new TranslatorModel(this))
{
    qDebug()<<"Start aplication";

    _ui->setController(this);
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

void TranslatorController::saveFile(const QString content,const QString title)
{
    QString fileName = QFileDialog::getSaveFileName(_ui,
                                                    title, "",
                                                    tr("*.txt"));

    if (fileName.isEmpty())   return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(_ui, tr("Unable to open file"),
                                 file.errorString());
        return;
    }

    QTextStream out(&file);
    out << content;

    file.close();
}

void TranslatorController::transMorsToText(const QString content)
{
    const QString text =  _model->convertToText(content);
}

void TranslatorController::transTextToMors(const QString content)
{
    const QString text =  _model->convertToMors(content);
}

QString TranslatorController::openFile()
{

    QString fileName = QFileDialog::getOpenFileName(_ui,
                                                    tr("Open File"),QString(""),tr(" *.txt (*.txt)"));

    QString pom("");
    if(fileName.isEmpty()) return pom;

    qDebug()<<"File name:"<<fileName;

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::information(_ui, tr("Unable to open file"),
                                 file.errorString());
        return pom;
    }

    QTextStream strem(&file);
    pom = strem.readAll();
    file.close();

    return pom;
}
