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


## 2.QTreeWidget目录树控件

在UI设计器里双击QTreeWidget组件，可以看到两个属性，Columns用于设计目录树的列，Items用于设计目录树的节点，下方按钮可以给节点增加子节点，两个属性右下角Properties可以设置列和节点的具体属性。


