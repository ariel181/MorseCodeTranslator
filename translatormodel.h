#ifndef TRANSLATORMODEL_H
#define TRANSLATORMODEL_H

#include <QObject>
#include <QMap>

/**
 * @brief
 *
 */
class TranslatorModel : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit TranslatorModel(QObject *parent = 0);
    /**
     * @brief
     *
     * @param text
     * @return QString
     */
    QString convertToMors(const QString text);
    /**
     * @brief
     *
     * @param text
     * @return QString
     */
    QString convertToText(const QString text);

signals:

public slots:

private:
    /**
     * @brief
     *
     */
    void init();
    /**
     * @brief
     *
     * @param ch
     * @param mors
     */
    void addCoder(const QString ch, const QString mors);
    /**
     * @brief
     *
     * @param word
     * @return QString
     */
    QString encode(const QString word);
    /**
     * @brief
     *
     * @param word
     * @return QString
     */
    QString decode(const QString word);
    QMap<QString,QString> _codeMors; /**< TODO: describe */
    QMap<QString,QString> _codeChar; /**< TODO: describe */
};

#endif // TRANSLATORMODEL_H
