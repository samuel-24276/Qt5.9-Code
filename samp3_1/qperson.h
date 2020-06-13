#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author", "wang")
    Q_CLASSINFO("company", "UPC")
    Q_CLASSINFO("version", "1.0.0")
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    //MEMBER指定一个成员变量与属性关联，成为可读可写的属性
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)
public:    
    explicit QPerson(QString fName, QObject *parent = nullptr);
    int age();
    void setAge(int val);
    void incAge();
private:
    int m_age = 10;
    QString m_name;
    int m_score;

signals:
    void ageChanged(int val);

public slots:
};

#endif // QPERSON_H
