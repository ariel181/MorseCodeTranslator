#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "translatorcontroller.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setController(TranslatorController *con)
{
   connect(ui->actionLoad_Text,&QAction::triggered,con,&TranslatorController::openText);
   connect(ui->actionLoad_Mors,&QAction::triggered,con,&TranslatorController::openMors);

}

void MainWindow::loadText(const QString text)
{
    ui->pTText->setPlainText(text);
}

void MainWindow::loadMors(const QString text)
{
    ui->pTMors->setPlainText(text);
}
