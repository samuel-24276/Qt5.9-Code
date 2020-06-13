#include "qmywidget.h"
#include "ui_qmywidget.h"
#include<QTextEdit>
#include<QMetaProperty>

QmyWidget::QmyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QmyWidget)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(600, 400));
    boy = new QPerson("王小明");
    boy->setProperty("score", 95);
    boy->setProperty("age", 10);
    boy->setProperty("sex", "Boy");//动态属性
    connect(boy, &QPerson::ageChanged, this, &QmyWidget::on_ageChanged);

    girl = new QPerson("张晓丽");
    girl->setProperty("score", 81);
    girl->setProperty("age", 20);
    girl->setProperty("sex", "Girl");//动态属性
    connect(girl, &QPerson::ageChanged, this, &QmyWidget::on_ageChanged);

    ui->spinBoy->setProperty("isBoy", true);//动态属性
    ui->spinGirl->setProperty("isBoy", false);

    connect(ui->spinBoy, SIGNAL(valueChanged(int)), this, SLOT(on_spin_valChanged(int)));
    connect(ui->spinGirl, SIGNAL(valueChanged(int)), this, SLOT(on_spin_valChanged(int)));
    connect(ui->btnBoyInc, SIGNAL(clicked), this, SLOT(on_btnBoyInc_clicked()));
    connect(ui->btnGirlInc, SIGNAL(clicked), this, SLOT(on_btnGirlInc_clicked()));

}

void QmyWidget::on_ageChanged(int val)
{
    //响应QPerson的ageChanged信号
    Q_UNUSED(val)
    QPerson * aPerson = qobject_cast<QPerson *>(sender());//类型投射
    QString hisName = aPerson->property("name").toString();//姓名
    QString hisSex = aPerson->property("sex").toString();//性别
    int hisAge = aPerson->age();//通过接口函数获取年龄
    //int hisAge = aPerson->property("age").toInt;//通过属性获得年龄
    ui->textEdit->append(hisName+","+hisSex+QString::asprintf(",年龄=%d",hisAge));
}

void QmyWidget::on_spin_valChanged(int arg1)
{
    //响应界面上的spinBox的valueChanged(int)信号
    Q_UNUSED(arg1)
    QSpinBox * spinBox = qobject_cast<QSpinBox *>(sender());
    if(spinBox->property("isBoy").toBool())
        boy->setAge(spinBox->value());
    else
        girl->setAge(spinBox->value());
}

void QmyWidget::on_btnClear_clicked()
{
    ui->textEdit->clear();
}

void QmyWidget::on_btnBoyInc_clicked()
{
    boy->incAge();
    //ui->textEdit->append(QString("男孩年龄为 %1 岁").arg(boy->age()));
}

void QmyWidget::on_btnGirlInc_clicked()
{
    girl->incAge();
    //ui->textEdit->append(QString("女孩年龄为 %1 岁").arg(girl->age()));
}

void QmyWidget::on_btnClassInfo_clicked()
{
    //类的元对象信息按钮
    const QMetaObject * meta = boy->metaObject();
    ui->textEdit->clear();
    ui->textEdit->append("==元对象信息==\n");
    ui->textEdit->append(QString("类名称：%1\n").arg(meta->className()));
    ui->textEdit->append("property");
    for(int i=meta->propertyOffset(); i<meta->propertyCount(); ++i)
    {
        QMetaProperty prop = meta->property(i);
        const char * propName = prop.name();
        QString propVal = boy->property(propName).toString();
        ui->textEdit->append(QString("属性名称=%1, 属性值=%2").arg(propName).arg(propVal));

    }
    ui->textEdit->append("");
    ui->textEdit->append("classInfo");
    for(int i=meta->propertyOffset(); i<meta->propertyCount(); ++i)
    {
        QMetaClassInfo classInfo = meta->classInfo(i-1);
        ui->textEdit->append(QString("Name=%1, Val=%2").arg(classInfo.name()).arg(classInfo.value()));
    }
    //类的元对象信息按钮
    ui->textEdit->append("========================================");
    const QMetaObject * meta2 = girl->metaObject();
    ui->textEdit->append(QString("类名称：%1\n").arg(meta2->className()));
    ui->textEdit->append("property");
    for(int i=meta2->propertyOffset(); i<meta2->propertyCount(); ++i)
    {
        QMetaProperty prop = meta2->property(i);
        const char * propName = prop.name();
        QString propVal = girl->property(propName).toString();
        ui->textEdit->append(QString("属性名称=%1, 属性值=%2").arg(propName).arg(propVal));

    }
    ui->textEdit->append("");
    ui->textEdit->append("classInfo");
    for(int i=meta2->propertyOffset(); i<meta2->propertyCount(); ++i)
    {
        QMetaClassInfo classInfo = meta2->classInfo(i-1);
        ui->textEdit->append(QString("Name=%1, Val=%2").arg(classInfo.name()).arg(classInfo.value()));
    }
}

QmyWidget::~QmyWidget()
{
    delete ui;
}
