#include "xmlstreamerreader.h"

XmlStreamerReader::XmlStreamerReader(QString fName) :
    fileName(fName)
{

}

bool XmlStreamerReader::ReadFile()
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << fileName << file.errorString();
        return false;
    }
    reader.setDevice(&file);
    reader.readNext();              // 不是读一行，而是读一个标记

    while (!reader.atEnd())
    {
        if (reader.isStartElement())
        {
            if (reader.name() == "bookindex")
            {
                ReadBookIndexElement();
            }
            else
            {
                reader.raiseError(QObject::tr("Not a bookindex file"));
            }
        }
        else
        {
            reader.readNext();
        }
    }
    file.close();
    if (reader.hasError())
    {
        qDebug() << reader.errorString();
        return false;
    }
    else if (file.error() != QFile::NoError)
    {
        qDebug() << file.errorString();
        return false;
    }
    return true;
}

void XmlStreamerReader::ReadAllChildElement()
{
    if (reader.isStartElement())
    {
        qDebug() << reader.readElementText(QXmlStreamReader::IncludeChildElements);
    }
}

void XmlStreamerReader::ReadBookIndexElement()
{
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }
        if (reader.isStartElement())
        {
            if (reader.name() == "entry")
            {
                qDebug() << "   " << reader.attributes().value("term").toString();
                ReadEntryElement();
            }
            else
            {
                SkipUnknownElement();
            }
        }
        else
        {
            reader.readNext();
        }
    }
}

void XmlStreamerReader::ReadEntryElement()
{
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }
        if (reader.isStartElement())
        {
            if (reader.name() == "entry")
            {
                ReadEntryElement();
            }
            else if (reader.name() == "page")
            {
                ReadPageElement();
            }
            else
            {
                SkipUnknownElement();
            }
        }
        else
        {
            reader.readNext();
        }
    }
}

void XmlStreamerReader::ReadPageElement()
{
    qDebug() << "       " << reader.readElementText();
    if (reader.isEndElement())
    {
        reader.readNext();
    }

}

void XmlStreamerReader::SkipUnknownElement()
{
    qDebug() << "SKIP";
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }
        if (reader.isStartElement())
        {
            SkipUnknownElement();
        }
        else
        {
            reader.readNext();
        }
    }
}
