# 自定义对话框及其调用

该程序有一个主窗口MainWindow和三个弹出窗口：

## 1.QWDialogSize

设置主窗口的TableView的行列数，通过动态创建的模态（modal）对话框，**每次打开时创建，关闭时销毁**。所谓模态，就是指创建子窗口后，必须先关闭该子窗口才能对父窗口进行操作；如果能同时对父窗口和子窗口进行操作（如notepad++的文字查找和替换），则为非模态。

## 2.QWDialogHeaders

设置主窗口TableView的表头标题，**创建一次，多次调用，关闭后只是隐藏，并不删除**。

```c++
if (dlgSetHeaders == NULL)
{
    dlgSetHeaders = new QWDialogHeaders(this);
}
```

QWDialogHeaders包含了一个ListView，其数据模型为QStringListModel，可以通过QStringListModel的`setStringList()`方法和ListView的`setModel()`方法更新表头标题。添加，插入，删除表头标题可以借助QStringListModel的`stringList()`方法实现，该方法返回的只是一个副本，因此还需要执行一次`setStringList()`方法。

## 3.QWDialogLocate

定位单元格，可以在该对话框设置某个位置的单元格文字，也可以在主窗口点击单元格，位置同步更新到该对话框，因此是**交互式的，非模态的**。

两个窗口的数据传递通过信号和槽进行，该对话框有两个信号：

```c++
signals:
    void changeCellText(int row, int col, QString &text);
    void changeActEnable(bool);
```

两个槽函数：

```c++
public slots:
    void setSpinValue(int rowNo, int colNo);
private slots:
    void on_BtnSetText_clicked();// 发射信号changeCellText(int row, int col, QString &text)
```

两个事件：

```c++
private:
    void closeEvent(QCloseEvent *event);// 发射信号changeActEnable(true)
    void showEvent(QShowEvent *event);// 发射信号changeActEnable(false)
```

主窗口MainWIndow对应有一个信号：

```c++
signals:
    void cellIndexChanged(int rowNo, int colNo);
```

三个槽函数：

```c++
private slots:
    void on_tableView_clicked(const QModelIndex &index);// 发射cellIndexChanged(int rowNo, int colNo)信号
    void setACellText(int row, int col, QString &text);// 定位到单元格，并设置字符串
    void setActLocateEnabled(bool flag);// 响应QWDialogLocate对话框发射的changeActEnable(bool)信号
```

## 4.其他要点

> 模态的关键是QDialog::exec()函数，该函数返回值为int型，若为`QDialog::Accepted`或者`QDialog::Rejected`即可结束模态，即关闭窗口

> 普通对话框的关闭比一定非要编写对应按钮槽函数，以下形式更为简单：
>
> ```c++
> connect(ui->BtnOk, SIGNAL(clicked()), this, SLOT(accept()));
> connect(ui->BtnCancel, SIGNAL(clicked()), this, SLOT(reject()));
> ```

> 主窗口的关闭提示：
>
> ```c++
> void MainWindow::closeEvent(QCloseEvent *event)
> {
>     QMessageBox::StandardButton ret = QMessageBox::question(this, "Question", "Dou you want to quit?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
>     if (ret == QMessageBox::Yes)
>     {
>         event->accept();
>     }
>     else
>     {
>         event->ignore();
>     }
> }
> ```

