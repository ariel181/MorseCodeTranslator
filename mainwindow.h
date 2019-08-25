#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class TranslatorController;

/**
 * @brief The main window of MorsCodeTranslator.
 *
 * The main window will show up after the application started.
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
     * @brief The method spins assigned signals with a view.
     *
     * @param con
     */
    void setController(TranslatorController* con);
    /**
     * @brief The method transfers the text from the file or after translation into text.
     *
     * @param text
     */
    void loadText(const QString text);
    /**
     * @brief The method transfers the text from the file or after translation into mors.
     *
     * @param text
     */
    void loadMors(const QString text);

signals:
    /**
     * @brief Emitted when the user wants to save the text. The method is called when saving text and mors.
     *
     * @param QString Text to write.
     * @param QString Title window name.
     */
    void NotifySaveText(const QString,const QString);
    /**
     * @brief Emitted when there is a need to convert to Text
     *
     * @param QString
     */
    void NotifyMorsToText(const QString);
    /**
     * @brief Emitted when there is a need to convert to Mors
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
