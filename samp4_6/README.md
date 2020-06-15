# QComboBox和QPlainTextEdit

## 1.QComboBox

QComboBox是下拉列表框组件类，提供一个下拉列表供用户选择，也可以直接当作一个QLineEdit用作输入。除了显示可见的下拉列表外，每个项(item,或称列表项)还可以关联一个Qvariant类型的变量，用于存储一些不可见的数据。  

- 1.addItem()和addItems()用代码添加简单项
    ```
    void Widget::on_btnIniItems_clicked()
    {
        //初始化列表按钮
        QIcon icon;
        icon.addFile(":/img/new.svg");
        ui->comboBox->clear();
        for(int i=0; i<9; ++i)
    //        ui->comboBox->addItem(icon, QString::asprintf("Item %d", i));//带图标
            ui->comboBox->addItem(QString::asprintf("Item %d", i));//不带图标
    }

    void Widget::on_btnIni2_clicked()
    {
        QStringList strList;
        strList<<"北京"<<"上海"<<"重庆"<<"天津";
        ui->comboBox_2->clear();
        ui->comboBox_2->addItems(strList);
    }
    ```
    addItem()用于添加单一列表项，原型为：
    ```
    void QComboBox::addItem(const QString &text, const QVariant &userData = QVariant())
    
    void QComboBox::addItem(const QIcon &icon, const QString &text, const QVariant &userData = QVariant())
    ```
    既可以添加带图标的列表项，也可以添加不带图标的列表项。addItems()用于一次添加多个列表项，参数为QStringList类型。
- 2.添加具有用户数据的项  
    观察addItem()的原型可知，后面都有一个可选的QVariant类型的参数userData，可以利用这个变量存储用户定义数据。
    ```
    //初始化具有自定义数据的ComboBox
    QMap<QString, int> City_Zone;
    City_Zone.insert("北京", 10);
    City_Zone.insert("上海", 21);
    City_Zone.insert("重庆", 22);
    City_Zone.insert("天津", 5);
    ui->comboBox_2->clear();
    foreach(const QString &str, City_Zone.keys())
        ui->comboBox_2->addItem(str, City_Zone.value(str));
    ```
    City_Zone是一个关联容器类，用于存储<城市，区号>映射表。城市名称作为项显示的字符串，电话区号作为项关联的用户数据，但是在列表框里只能看到城市名称。City_Zone的内容添加到列表框中后，显示顺序与程序中设置的不一致，因为QMap<Key, T>容器类会自动按照Key排序。
- 3.QComboBox列表项的访问  
    虽然QComboBox存储的是一个列表，但是QComboBox不提供整个列表用于访问，可以通过索引访问某个项。访问项的一些函数主要有以下几种：
    - int currentIndex(),返回当前项的序号，首项序号为0.
    - QString currentText()，返回当前项的文字。
    - QVariant currentData(int role = Qt::UserRole),返回当前项的关联数据，数据的缺省角色为role = Qt::UserRole。
    - QString itemText(int index),返回指定索引号的项的文字。
    - QVariant itemData(int index, int role = Qt::UserRole),返回指定索引号的项的关联数据。
    - int count(),返回项的个数

    **在一个QComboBox组件上选择项发生变化时，会发射如下两个信号，这两个信号只是传递的参数不同**：
    ```
    void currentIndexChanged(int index);
    void currentIndexChanged(const QString &text);
    ```
    只需要为一个信号编写槽函数即可。

## 2.QPlainTextEdit的使用

QPlainTextEdit是多行文本编辑器，可以编辑普通文本。另外还有一个**QTextEdit组件，是一个所见即所得的可以编辑带格式文本的组件，以HTML格式标记符定义文本格式**。  
QPlainTextEdit提供cut()、copy()、paste()、undo()、clear()、selectAll()等标准编辑功能的槽函数，**QPlainTextEdit还提供一个标准的右键快捷菜单**。

- 1.读取QPlainTextEdit的所有内容：`QString QPlainTextEdit::toPlainText() const`,可以将QPlainTextEdit的所有内容输出为一个字符串。
- 2.逐行读取QPlainTextEdit的内容
    ```
    void Widget::on_btnToComboBox_clicked()
    {        
        QTextDocument * doc = ui->plainTextEdit->document();//文本对象
        int cnt = doc->blockCount();//回车符是一个block
        QIcon icon(":/img/new.svg");
        ui->comboBox->clear();
        for(int i=0; i<cnt; ++i){
            QTextBlock textLine = doc->findBlockByNumber(i);
            QString str = textLine.text();
            ui->comboBox->addItem(icon, str);
        }
    }
    ```
    QPlainTextEdit的文字内容以QTextDocument类型存储，函数document()返回这个文档对象的指针。QTextDocument是内存中的文本对象，以文本块的方式存储，一个文本块就是一个段落，每个段落以回车符结束。
    - int blockCount()，获得文本块个数
    - QtextBlock findBlockByNumber(int blockNumber)，读取某一个文本块，从0开始。

    一个document有多个TextBlock,从document中取出的一个文本块类型为QTextBlock,QTextBlock::text()可以获取其纯文本文字。

