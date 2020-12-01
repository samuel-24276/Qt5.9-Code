#ifndef XMLSTREAMERREADER_H
#define XMLSTREAMERREADER_H

#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>

class XmlStreamerReader: public QObject
{
public:
    XmlStreamerReader(QString fileName);

    bool ReadFile();

private:
    void ReadAllChildElement();

    void ReadBookIndexElement();

    void ReadEntryElement();

    void ReadPageElement();

    void SkipUnknownElement();

    QString fileName;

    QXmlStreamReader reader;
};

#endif // XMLSTREAMERREADER_H
