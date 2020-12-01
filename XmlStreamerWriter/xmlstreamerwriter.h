#ifndef XMLSTREAMERWRITER_H
#define XMLSTREAMERWRITER_H

#include <QDebug>
#include <QFile>
#include <QXmlStreamWriter>

class XmlStreamerWriter
{
public:
    XmlStreamerWriter(QString fName);

    bool Write();

private:
    QString filePath;

    QXmlStreamWriter writer;
};

#endif // XMLSTREAMERWRITER_H
