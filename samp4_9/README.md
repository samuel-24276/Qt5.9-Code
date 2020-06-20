# QTableWidget表格控件的使用

在QTableWidget表格中，每一个单元格是一个QTableWidgetItem对象，可以设置文字内容、字体、前景色、背景色、图标，也可以设置编辑和显示标记。**每个单元格还可以存储一个QVariant数据，用于设置用户自定义数据。**和QTreeWidget类似，创建每一列的QTableWidgetItem对象时，需要有枚举变量作为标识，即
```
//自定义单元格Type的类型，在创建单元格的item时使用
enum CellType{ctName=1000, ctSex, ctBirth, ctNation,ctPartyM, ctScore};
//各字段在表格中的序号
enum FieldColNum{colName=0, colSex, colBirth, colNation, colScore, colPartyM};
```
QTableWidget的主要属性和函数如下：
- 1.`columnCount()`:  获取表格的列数
- 2.`setColumnCount()`: 设置表格的列数
- 3.`RowCount()`: 获取表格的行数
- 4.`setRowCount()`: 设置表格的行数
- 5.`currentRow()`: 返回当前的行数
- 6.`removeCurrentRow()`: 删除当前行的数据
- 7.`currentColumn()`: 返回当前的列数
- 8.`removeCurrentColumn()`: 删除当前列的数据
- 9.`setAlternatingRowColors(bool)`: 设置间隔行底色，默认为灰色
- 10.`setEditTriggers()`: 设置编辑模式，参数有三种，可以自由组合：
    - 1.`QAbstractItemView::NoEditTriggers`: 禁止编辑
    - 2.`QAbstractItemView::DoubleClicked`: 双击编辑
    - 3.`QAbstractItemView::SelectedClicked`: 获取焦点后单击编辑
- 11.`setSelectionBehavior()`: 表格的选择模式，参数有两种：
    - 1.`QAbstractItemView::SelectRows`： 行选择
    - 2.`QAbstractItemView::SelectItems`: 单元格选择
- 12.`item()`: 第一参数是行，第二参数是列，返回值是QTableWidget *对象。
- 13.`resizeRowsToContents()`: 自动调节所有的行高以适应其内容，当加入参数时，只调整参数行的高度
- 14.`resizeColumnsToContents()`: 自动调节所有的列宽以适应其内容，当加入参数时，只调整参数列的宽度
- 15.`insertRow(行数)`:  插入一个空白行，行的内容需要自己创建
- 16.`insertColumn(列数)`: 插入一个空白列，列的内容需要自己创建
- 17.`clearContents()`: 只清除工作区，不清除表头
- 18.`clear()`: 清除表格所有内容
- 19.`setItem()`: 第一参数为行号，第二参数为MainWindow::列的枚举类型，第三参数为被设置的item，功能是将设置好的item加入单元格

QTableWidgetItem的主要属性和函数如下：
- 1.`font()`: 获取当前字体
- 2.`setFont(字体对象)`: 设置字体
- 3.`setForeground(Qt::red)`: 设置前景色，即字体颜色
- 4.`setBackground(Qt::red)`： 设置背景色
- 5.`data(Qt::UserRole)`: 获取用户自定义数据类型，后面可以再跟toString()或toInt()函数
- 6.`text()`: 返回QTableWidgetItem对象的内容
- 7.`setTextAlignment()`: Qt::AlignHCenter 设置文字水平居中， Qt::AlignVCenter设置文字垂直居中
- 8.`setIcon()`: 单元格内容设置为图标，参数是QIcon对象
- 9.`QTableWidgetItem(item内容, MainWindow::单元格枚举类型)`: 通过构造函数设置item内容
- 10.`type()`: 获取单元格类型
- 11.`setCheckState()`: 设置单元格勾选状态，单元格里会出现一个QCheckBox组件，参数是Qt::Checked或者Qt::Unchecked

当前单元格发生切换时，会发射currentCellChanged()信号和currentItemChanged()信号，我们可以利用这两个信号中的一个编写槽函数，实现一些功能。



