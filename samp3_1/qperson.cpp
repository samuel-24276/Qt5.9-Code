#include "qperson.h"

QPerson::QPerson(QString fName, QObject *parent) : QObject(parent)
{
    m_name = fName;
};

int QPerson::age()
{
    return m_age;
}

void QPerson::setAge(int val)
{
    m_age = val;
    emit ageChanged(m_age); //发射信号
}

void QPerson::incAge()
{
    m_age++;
    emit ageChanged(m_age); //发射信号
}

