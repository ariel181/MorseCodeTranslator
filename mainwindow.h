#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class TranslatorController;

/**
 * @brief
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~MainWindow();
    /**
     * @brief
     *
     * @param con
     */
    void setController(TranslatorController* con);
    /**
     * @brief
     *
     * @param text
     */
    void loadText(const QString text);
    /**
     * @brief
     *
     * @param text
     */
    void loadMors(const QString text);

signals:
    /**
     * @brief
     *
     * @param QString
     * @param QString
     */
    void NotifySaveText(const QString,const QString);
    /**
     * @brief
     *
     * @param QString
     */
    void NotifyMorsToText(const QString);
    /**
     * @brief
     *
     * @param QString
     */
    void NotifyTextToMars(const QString);

private slots:
    /**
     * @brief
     *
     */
    void on_actionSave_Text_triggered();
    /**
     * @brief
     *
     */
    void on_actionSave_Mors_triggered();

    /**
     * @brief
     *
     */
    void on_pbToMors_clicked();

    /**
     * @brief
     *
     */
    void on_pbToText_clicked();

    /**
     * @brief
     *
     */
    void on_actionExit_triggered();

private:

    Ui::MainWindow *ui; /**< TODO: describe */

};

#endif // MAINWINDOW_H
