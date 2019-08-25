#include "translatormodel.h"
#include <QDebug>

TranslatorModel::TranslatorModel(QObject *parent) : QObject(parent)
{

    init();
}

QString TranslatorModel::convertToMors(const QString text)
{
    QString pom;

    QStringList list = text.split('\n');

    for(const QString ip : list){
        QStringList words = ip.split(" ");

        for(const QString iw: words) {
            pom += encode(iw);
        }
        pom += "\n";
    }
    return pom;
}

QString TranslatorModel::convertToText(const QString text)
{
    QString pom;

    QStringList list = text.split('\n');

    for (const QString ip : list) {

        QStringList words = ip.split("  ");

        for(const QString iw: words) {
            pom += decode(iw);
        }

        pom += "\n";
    }

    return pom;
}

void TranslatorModel::init()
{

    addCoder("A","•—");
    addCoder("B","—•••");
    addCoder("C","—•—•");
    addCoder("D","—••");
    addCoder("E","•");
    addCoder("F","••—•");
    addCoder("G","——•");
    addCoder("H","••••");
    addCoder("I","••");
    addCoder("J","•———");
    addCoder("K","—•—");
    addCoder("L","•—••");
    addCoder("M","——");
    addCoder("N","—•");
    addCoder("O","———");
    addCoder("P","•——•");
    addCoder("Q","——•—");
    addCoder("R","•—•");
    addCoder("S","•••");
    addCoder("T","—");
    addCoder("U","••—");
    addCoder("V","•••—");
    addCoder("W","•——");
    addCoder("X","—••—");
    addCoder("Y","—•——");
    addCoder("Z","——••");

    addCoder("0","—————");
    addCoder("1","•————");
    addCoder("2","••———");
    addCoder("3","•••——");
    addCoder("4","••••—");
    addCoder("5","•••••");
    addCoder("6","—••••");
    addCoder("7","——•••");
    addCoder("8","———••");
    addCoder("9","————•");

    addCoder(".","•—•—•—");
    addCoder(",","——••——");
    addCoder("'","•————•");
    addCoder("\"","•—••—•");
    addCoder("_","••——•—");
    addCoder(":","———•••");
    addCoder(";","—•—•—•");
    addCoder("?","••——••");
    addCoder("!","—•—•——");
    addCoder("–","—••••—");
    addCoder("+","•—•—•");
    addCoder("/","—••—•");
    addCoder("(","—•——•");
    addCoder(")","—•——•—");
    addCoder("=","—•••—");
    addCoder("@","•——•—•");

}

void TranslatorModel::addCoder(const QString ch, const QString mors)
{
    _codeMors.insert(mors, ch.toLower());
    _codeChar.insert(ch.toLower(), mors);

}

QString TranslatorModel::encode(const QString word)
{

    QString pom;

    for(int i = 0; i<word.length();i++) {

        QString ch = word[i].toLower();
        QMap<QString,QString>::iterator ip = _codeChar.find(ch);

        if(ip!=_codeChar.end()) {
            pom += ip.value();
            pom += " ";
        }

    }

    if(!pom.isEmpty()) pom += " ";

    return pom;
}

QString TranslatorModel::decode(const QString word)
{
    QString pom;
    QStringList chList = word.split(" ");

    for(const QString ch: chList)
    {
        QMap<QString,QString>::iterator ip = _codeMors.find(ch);

        if(ip!=_codeMors.end()) {
            pom += ip.value();
        }

    }

    if(!pom.isEmpty()) pom += " ";

    return pom;

}
