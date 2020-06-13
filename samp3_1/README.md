# 元对象特性测试用例

## 1.元对象系统
元对象系统由以下三个基础构成：
- QObject类是所有使用元对象系统的类的基类。
- 在类里声明Q_OBJECT宏，使得类可以使用元对象的特性，如动态属性、信号与槽
- MOC（元对象编译器）为每个QObject的子类提供必要代码来实现元对象系统的特性

对于QObject及其子类，可以使用qobject_cast()函数进行**动态投射(dynamic cast)**。例如qmywidget.cpp的on_ageChanged()函数里的`QPerson * aPerson = qobject_cast<QPerson *>(sender());`,而且qobject_cast()并不区分Qt内建类型和用户自定义类型。**使用动态投射，使得程序可以在运行时对不同的对象做不同的处理。**

## 2.属性系统

Qt提供一个Q_PROPERTY()宏可以定义属性，也是基于元对象系统实现的。
```
Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
Q_PROPERTY(QString name MEMBER m_name)
Q_PROPERTY(int score MEMBER m_score)
```
- READ指定一个读取属性的函数，没有MEMBER关键字时必须设置READ
- WRITE指定一个设定属性值的函数，只读属性没有WRITE设置
- MEMBER指定一个成员变量与属性关联，成为可读可写的属性，无需再设置READ和WRITE
- NOTIFY是可选的，用于设置一个信号，当属性值变化时发射此信号。
- FINAL表示所定义的属性不能被子类重载

我们能够通过QObject::property()读取属性值，通过QObject::setProperty()设置属性值，且QObject::setProperty()可在运行时为类定义一个新的属性，称之为**动态属性**。
```
boy = new QPerson("王小明");
boy->setProperty("score", 95);
boy->setProperty("age", 10);
boy->setProperty("sex", "Boy");//动态属性
QPerson * aPerson = qobject_cast<QPerson *>(sender());//类型投射
QString hisName = aPerson->property("name").toString();//姓名
QString hisSex = aPerson->property("sex").toString();//性别
```

## 3.信号与槽

QObject::connect()函数有多种重载方式，常用的有两种：
```
connect(boy, &QPerson::ageChanged, this, &QmyWidget::on_ageChanged);

connect(ui->spinBoy, SIGNAL(valueChanged(int)), this, SLOT(on_spin_valChanged(int)));
```
第一种方式采用函数指针的方式进行信号与槽的关联（适用于有默认参数的信号与槽），在信号的参数较多时简便一些。但如果一个同名信号有不同参数，那只能采用第二种方式，使用宏SIGNAL()和SLOT()指定信号和槽函数。  
`QSpinBox * spinBox = qobject_cast<QSpinBox *>(sender());`,**在槽函数里，使用QObject::sender()可以获取信号发射者的指针**。如果知道信号发射者的类型，可以将指针投射为确定的类型，然后使用这个确定类的接口函数。  
**信号**就是类定义里生命的一个函数，但无需实现，只需发射(emit)。信号函数必须是无返回值的函数(void)，但是可以有输入参数。
