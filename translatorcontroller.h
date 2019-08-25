#ifndef TRANSLATORCONTROLLER_H
#define TRANSLATORCONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "translatormodel.h"

/**
 * @brief
 *
 */
class TranslatorController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit TranslatorController(QObject *parent = 0);
    /**
     * @brief
     *
     */
    void show();

signals:

public slots:
    /**
     * @brief
     *
     */
    void openText();
    /**
     * @brief
     *
     */
    void openMors();
    /**
     * @brief
     *
     * @param content
     * @param title
     */
    void saveFile(const QString content, const QString title);
    /**
     * @brief
     *
     * @param content
     */
    void transMorsToText(const QString content);
    /**
     * @brief
     *
     * @param content
     */
    void transTextToMors(const QString content);

private:
    /**
     * @brief
     *
     * @return QString
     */
    QString openFile();
    /**
     * @brief
     *
     * @param QString
     * @return bool
     */
    bool isMors(QString);

    MainWindow* _ui; /**< TODO: describe */
    TranslatorModel* _model; /**< TODO: describe */
};

#endif // TRANSLATORCONTROLLER_H
