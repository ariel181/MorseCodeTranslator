#include "mainwindow.h"
#include <QApplication>
#include "translatorcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TranslatorController trans;
    trans.show();

    return a.exec();
}
