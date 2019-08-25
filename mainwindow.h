#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class TranslatorController;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setController(TranslatorController* con);
    void loadText(const QString text);
    void loadMors(const QString text);

signals:
    void NotifySaveText(const QString,const QString);
    void NotifyMorsToText(const QString);
    void NotifyTextToMars(const QString);

private slots:
    void on_actionSave_Text_triggered();
    void on_actionSave_Mors_triggered();

    void on_pbToMors_clicked();

    void on_pbToText_clicked();

private:
    void init();

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
