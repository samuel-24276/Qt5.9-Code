# QTreeWidget和QDockWidget

## 1.QDockWidget停靠区域组件

QDockWidget组件是一个可拖动的区域，可以将QTreeWidget拖动到QDockWidget上面，做一个可拖动的文件目录显示。主要属性如下：
- 1.allowedAreas，设置允许的停靠区域   
由函数`setAllowedAreas(Qt::DockWidgetAreas areas)`设置允许停靠区，参数areas是枚举类型`Qt::DockWidgetAreas`的值得组合，可设置在窗口的左右上下停靠，或所有区域都可停靠，或不允许停靠。
    - 1.`Qt::LeftDockWidgetArea` 左侧允许停靠
    - 2.`Qt::RightDockWidgetArea` 右侧允许停靠
    - 3.`Qt::TopDockWidgetArea` 顶部允许停靠
    - 4.`Qt::BottomDockWidgetArea` 底部允许停靠
    - 5.`Qt::AllDockWidgetAreas` 所有区域允许停靠
    - 6.`Qt::NoDockWidgetArea` 禁止停靠

- 2.features属性，设置停靠区组件得特性  
由函数`setFeatures(QDockWidget::DockWidgetFeatures features)`设置停靠区组件的特性，参数features是枚举类型`QDockWidget::DockWidgetFeatures`的值的组合，枚举值如下。
    - 1.`QDockWidget::DockWidgetClosable` 停靠区可关闭
    - 2.`QDockWidget::DockWidgetMovable` 停靠区可移动
    - 3.`QDockWidget::DockWidgetFloatable` 停靠区可浮动
    - 4.`QDockWidget::DockWidgetVerticalTitleBar` 在停靠区左侧显示垂直标题栏
    - 5.`QDockWidget::AllDockWidgetFeatures` 使用以上所有特征
    - 6.`QDockWidget::NoDockWidgetFeatures` 不能停靠、移动、关闭

QDockWidget停靠区组件还能改变自己的可见性和浮动性，单击组件的关闭按钮时，会隐藏停靠区并发射信号`visibilityChanged(bool)`；当拖动DockWidget组件，使其浮动或停靠时，会发射信号`topLevelChanged(bool)`。为这两个信号编写槽函数，可更新两个Actions的状态。
```
void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    //停靠区可见性变化
    ui->actDockVisible->setChecked(visible);
    qDebug()<<"可见性"<<visible;
}

void MainWindow::on_dockWidget_topLevelChanged(bool topLevel)
{
    //停靠区浮动性变化
    ui->actDockFloat->setChecked(topLevel);

    qDebug()<<"浮动性"<<topLevel;
}
```
为工具栏上两个按钮“窗体浮动”和“窗口可见”编写代码如下：
```
void MainWindow::on_actDockVisible_triggered(bool arg1)
{
    //停靠区的可见性
    ui->dockWidget->setVisible(arg1);
}

void MainWindow::on_actDockFloat_triggered(bool checked)
{
    //停靠区浮动性
    ui->dockWidget->setFloating(checked);
}
```
这两个按钮实现让浮动窗体固定和让窗口隐藏的功能。

## 2.QTreeWidget目录树控件

在UI设计器里双击QTreeWidget组件，可以看到两个属性，Columns用于设计目录树的列，Items用于设计目录树的节点，下方按钮可以给节点增加子节点，两个属性右下角Properties可以设置列和节点的具体属性。   
每个树节点都是一个QTreeWidgetItem对象，为了标识树结点是顶层节点、组节点、图片节点，我们需要定义枚举类型` enum treeItemType{itTopItem=1001, itGroupItem, itImageItem};`，自定义节点的类型必须大于1000，在构造QTreeWidgetItem对象时要用到该枚举类型初始化`QTreeWidgetItem * item = new QTreeWidgetItem(MainWindow::itTopItem);`。除此之外，一个树结点可以有多个属性，即多个列，为了标识列数，我们定义枚举类型`enum treeColNum{colItem=0, colItemType=1};`。树结点还有许多函数：
- 1.`setIcon()`: 设置节点图标，第一参数为枚举类型treeColNum，标识设置图标的列数，第二参数为QIcon对象
- 2.`setText()`: 设置节点显示文字，第一参数为枚举类型treeColNum，标识设置文字的列数，第二参数为QString对象
- 3.`setFlags()`: 设置节点的可选、可复选、使能、半选属性，参数是四者的组合
- 4.`setCheckState()`: 设置节点的选中状态，第一参数为枚举类型treeColNum，标识设置选中状态的列数；第二参数是`Qt::Checked`或`Qt::Unchecked`。
- 5.`setData()`:第一参数为枚举类型treeColNum，标识设置数据的列数，第二参数为`Qt::UserRole`，第三参数是QVariant(存储信息)对象
- 6.`parent()`: 获取父节点
- 7.`child(i)`: 获取第i个子节点


目录树本身也有许多函数，如下：
- 1.`currentItem()`: 获取目录树的当前节点
- 2.`addTopLevelItem(顶层节点)`: 给目录树添加顶层节点
- 3.`addChild(子节点)`: 在父节点下添加子节点
- 4.`removeChild(子节点)`: 删除父结点下的子节点
- 5.`topLevelItem(i)`: 获取序号为i的顶层节点
- 6.`topLevelItemCount()`: 返回顶层节点个数


>**状态栏和菜单栏无法直接添加控件，要通过代码实现：**
- 1.状态栏添加控件：`addWidget(被添加组件)`
- 2.菜单栏添加按钮事件：可以在UI设计器里将设计好的Action拖拽至菜单栏上，或者调用函数`addAction(被添加的按钮动作)`
- 3.除了connect()函数外，实现按下按钮执行响应事件还可以调用按钮的`setDefaultAction(被执行的动作)`，将按钮和动作关联起来
- 4.给Action设置图标，双击Action Editor下的动作，在icon一栏中选择资源文件即可。


