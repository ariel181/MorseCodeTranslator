#ifndef TRANSLATORMODEL_H
#define TRANSLATORMODEL_H

#include <QObject>
#include <QMap>

class TranslatorModel : public QObject
{
    Q_OBJECT
public:
    explicit TranslatorModel(QObject *parent = 0);
    QString convertToMors(const QString text);
    QString convertToText(const QString text);

signals:

public slots:

private:
    void init();
    void addCoder(const QString ch, const QString mors);
    QString encode(const QString word);
    QString decode(const QString word);
    QMap<QString,QString> _codeMors;
    QMap<QString,QString> _codeChar;
};

#endif // TRANSLATORMODEL_H
