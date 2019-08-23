#ifndef TRANSLATORMODEL_H
#define TRANSLATORMODEL_H

#include <QObject>

class TranslatorModel : public QObject
{
    Q_OBJECT
public:
    explicit TranslatorModel(QObject *parent = 0);

signals:

public slots:
};

#endif // TRANSLATORMODEL_H