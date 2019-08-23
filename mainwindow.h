#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void NotifySaveText(const QString);
    void NotifySaveMors(const QString);
    void NotifyTransText(const QString);
    void NotifyTransMors(const QString);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
