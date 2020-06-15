# 时间日期与定时器

## 1.日期时间数据

QTimeEdit、QDateEdit都从QDateTimeEdit继承而来,实现针对日期或事件的特定显示功能：
```
QDateTime curDateTime = QDateTime::currentDateTime();
ui->timeEdit->setTime(curDateTime.time());
ui->editTime->setText(curDateTime.toString("hh:mm:ss"));
ui->dateEdit->setDate(curDateTime.date());
ui->editDate->setText(curDateTime.toString("yyyy-MM-dd"));
ui->dateTimeEdit->setDateTime(curDateTime);
ui->editDateTime->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));
```
QDateTimeEdit的主要属性如下：
- date: 日期，设置datetime时会自动改变date,同样设置date时也会自动改变datetime里的日期。
- time: 时间，设置datetime时会自动改变time,同样设置time时也会自动改变datetime里的时间。
- currentSection: 当前输入光标所在的时间日期数据段（年月日时分秒），是枚举类型QDateTimeEdit::Section。
- calendarPopup: 是否允许弹出一个日历选择框。=true时，右侧的输入按钮变成与QComboBox类似的下拉按钮，单击按钮时出现一个日历选择框，用于在日历上选择日期。
- displayFormat: 显示格式，单字母表示不补零，双字母补零（年除外，年双字母不补零，四字母补零）。在设置日期时间显示格式时，还可以使用填字符，甚至使用汉字，如：`curDateTime.toString("yyyy年MM月dd日 hh时mm分ss秒")`。

>时间日期转换成字符串：调用toString()函数，参数是displayFormat.
>字符串转换成时间日期：调用fromString()函数，原型为`QDateTime QDateTime::fromString(const QString &string, Qt::DateFormat format = Qt::TextDate)`,第一参数是要转换的字符串，第二参数是转换成的格式,示例代码如下。
```
void Dialog::on_btnSetDateTime_clicked()
{
    //字符串转换为QDateTime
    QString str = ui->editDateTime->text();
    str = str.trimmed();
    if(!str.isEmpty()){
        QDateTime dateTime = QDateTime::fromString(str,"yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(dateTime);
    }
}
```

## 2.QCalendarWidget日历组件

QCalendarWidget日历有一个信号selectionChanged()，在日历上选择的日期变化后会发射此信号，为此信号创建槽函数，代码如下：
```
void Dialog::on_calendarWidget_selectionChanged()
{
    QDate dt = ui->calendarWidget->selectedDate();
    QString str = dt.toString("yyyy年MM月dd日");
    ui->editCalendar->setText(str);
}
```

## 3.定时器的使用

QTimer主要属性是interval,是定时中断的周期；主要信号是timeout()，在定时中断时发射此信号：`connect(fTimer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));`,**要想在定时中断里做出响应，需要编写timeout()的槽函数on_timer_timeout()**。
- start()： 启动定时器
- stop()： 停止定时器
- setInterval(n)： 设置定时中断的周期，n的单位是毫秒
