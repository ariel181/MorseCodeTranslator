#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "translatorcontroller.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   connect(ui->actionClear_Mors,&QAction::triggered,ui->pTMors,&QPlainTextEdit::clear);
   connect(ui->actionClear_Text,&QAction::triggered,ui->pTText,&QPlainTextEdit::clear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setController(TranslatorController *con)
{
   connect(ui->actionLoad_Text,&QAction::triggered,con,&TranslatorController::openText);
   connect(ui->actionLoad_Mors,&QAction::triggered,con,&TranslatorController::openMors);

   connect(this,&MainWindow::NotifySaveText,
           con,&TranslatorController::saveFile);

}

void MainWindow::loadText(const QString text)
{
    ui->pTText->setPlainText(text);
}

void MainWindow::loadMors(const QString text)
{
    ui->pTMors->setPlainText(text);
}

void MainWindow::on_actionSave_Text_triggered()
{
    const QString text = ui->pTText->toPlainText();

    if(text.isEmpty()) return;

    emit NotifySaveText(text,tr("Save Text"));

}

void MainWindow::on_actionSave_Mors_triggered()
{
    const QString text = ui->pTMors->toPlainText();

    if(text.isEmpty()) return;

    emit NotifySaveText(text,tr("Save Mors"));

}

void MainWindow::on_pbToMors_clicked()
{

    const QString text = ui->pTText->toPlainText();
    if(text.isEmpty()) return;
    emit NotifyTransMors(text);

}

void MainWindow::on_pbToText_clicked()
{

    const QString text = ui->pTMors->toPlainText();
    if(text.isEmpty()) return;
    emit NotifyTransText(text);

}
