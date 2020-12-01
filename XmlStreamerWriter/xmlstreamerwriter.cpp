#include "xmlstreamerwriter.h"
#include <QTextCodec>

XmlStreamerWriter::XmlStreamerWriter(QString fName):
    filePath(fName)
{

}

bool XmlStreamerWriter::Write()
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << filePath << file.errorString();
        return false;
    }
    writer.setDevice(&file);
    writer.setAutoFormatting(true);
    // 中文有问题，编码好像没起作用
    //    QTextCodec *codeC = QTextCodec::codecForName("utf-8");
    //    writer.setCodec(codeC);
    writer.writeStartDocument();
    writer.writeStartElement("PersonalInfo");
    writer.writeStartElement("Name");
    writer.writeAttribute("FirstName", "Marcus");
    writer.writeAttribute("FamilyName", "Smart");
    writer.writeCharacters("Marcus Smart");
    writer.writeEndElement();
    writer.writeTextElement("Sex", "男");
    writer.writeStartElement("Age");
    writer.writeCharacters("18");
    writer.writeEndElement();
    writer.writeEndElement();
    writer.writeEndDocument();
    file.close();
    return true;
}
