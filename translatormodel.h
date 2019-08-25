#ifndef TRANSLATORMODEL_H
#define TRANSLATORMODEL_H

#include <QObject>
#include <QMap>

/**
 * \brief Class responsible for translating the Mors alphabet into text and reverse.
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
     * @brief The method translates to Mors.
     * The method divides the string into lines and then into words. Transmits to coding Mors.
     * @sa  encode()
     * @param text
     * @return QString
     */
    QString convertToMors(const QString text);
    /**
     * @brief The method translates to Text.
     * The method divides the string into lines and then into words. Transmits to coding words.
     *
     * @param text
     * @return QString
     */
    QString convertToText(const QString text);

signals:

public slots:

private:
    /**
     * @brief The method loads character tables.
     *
     */
    void init();
    /**
     * @brief The method adds a character to dictionaries.
     *
     * Splits a word into characters and search for a match in the dictionary.
     *
     * @param ch
     * @param mors
     */
    void addCoder(const QString ch, const QString mors);
    /**
     * @brief The method encode the words.
     *
     * Splits a word into characters and search for a match in the dictionary.
     *
     * @param word
     * @return QString
     */
    QString encode(const QString word);
    /**
     * @brief The method decode the words.
     *
     * @param word
     * @return QString
     */
    QString decode(const QString word);

    QMap<QString,QString> _codeMors; /**< Mors code dictionary. */
    QMap<QString,QString> _codeChar; /**< Char character dictionary. */
};

#endif // TRANSLATORMODEL_H
