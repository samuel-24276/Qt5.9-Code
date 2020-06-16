# QListWidget和QToolButton🔥

Qt中用于**项(item)处理**的组件有两类，一类是Item Views,包括QListView、QTreeView、QTableView、QColumnView等；另一类是Item Widgets，包括QListWidget、QTreeWidget和QTableWidget。  
Item Views基于模型/视图(Model/View)结构，视图(View)与模型数据(Model Data)关联实现数据的显示和编辑，模型/视图结构的使用在地5章详细介绍。  
Item Widgets是直接将数据存储在每一个项里，一个项里存储了文字、文字格式、自定义数据等。例如QListWidget的每一行是一个项，QTreeWidget的每个节点是一个项，QTableWidget的每个单元格是一个项。

## 1.QToolBox多分组窗口
在QToolBox组件上右键快捷菜单，可以使用"Insert Page""Delete Page"等菜单项实现分组的添加或删除，内部可以放置任何界面组件，主要属性设置如下:
- currentIndex， 当前分组编号，改变这个值可以选择不同的分组页面
- currentItemText， 当前分组标题
- currentItemName， 当前分组的对象名称
- currentItemIcon， 为当前分组设置一个图标，显示在文字标题的左侧

## 2.QTabWidget多页面窗口

在QTabWidget组件上右键快捷菜单，可以使用"Insert Page""Delete Page"等菜单项实现页面的添加或删除，主要属性如下：
- tabPosition， 页标签的位置，东西南北四方位中选择一个
- currentIndex， 当前页的编号
- currentTabText， 当前页的标题
- currentTabName， 当前页的对象名称
- currentTabIcon， 为当前页设置一个图标，显示在文字标题的左侧

## 3.QListWidget列表项窗口

双击QListWidget组件，可以打开列表项编辑器，对属性进行设置，重要属性是flags，用于设置项的一些标记，这些标记是Qt::ItemFlag的具体值，包括以下几种：
- Selectable: 项是否可被选择，对应枚举值Qt::ItemIsSelectable
- Editable: 项是否可被编辑，对应枚举值Qt::ItemIsEditable
- DragEnable: 项是否可被拖动，对应枚举值Qt::ItemIsDragEnable
- DropEnable: 项是否可以接收拖放的项，对应枚举值Qt::ItemIsDropEnable
- UserCheckable: 像是否可以被复选，若为true，前面会出现一个CheckBox，对应枚举值Qt::ItemIsUserCheckable
- Enabled: 项是否被使能，对应枚举值Qt::ItemIsEnabled
- Tristate: 是否允许Check的第三种状态，若为false，则只有checked和unChecked两种状态，对应枚举值Qt::ItemIsAutoTristate

例如：`aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);`,列表项可被选择，可被复选，使能  
除flags属性外，QListWidget其他属性如下：
- count(): 获取列表项的数量
- currentRow(): 获取当前列表项的行数
- item(): 获取当前列表项，参数为列表项的下标
- setCheckState(): 设置列表项的状态，Qt::Checked是选中，Qt::Unchecked是未选中。

QListWidget在当前项切换时会发射两个信号，只是传递的参数不同。
- currentRowChanged(int currentRow): 传递当前项的行号作为参数。
- currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous): 传递两个QListWidgetItem对象作为参数，current表示当前项，previous是前一项。

当前项的内容发生变化时发射信号currentTextChanged(const QString &currentText)，为其编写的槽函数如下：
```
void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous)
{
    ui->editCutItemText->clear();
    QString str;
    if(current != NULL)
    {
        if(previous == NULL)
            str = "当前项："+current->text();
        else
            str = "前一项："+previous->text()+"；当前项："+current->text();
        ui->editCutItemText->setText(str);
    }
}
```

## 4.QToolButton

### 4.1.QAction创建

QAction可在Ui界面下方的Action Editor里创建，而QToolBar虽然不支持直接将控件拖放到上面，但可以将QAction拖放到上面，再为QAction编写槽函数即可实现其功能。

### 4.2.QToolButton关联Action

当QToolButton按钮的功能已经有Action实现后，可将二者关联起来。**QToolButton有一个槽函数setDefaultAction()**,原型如下：`void QToolButton::setDefaultAction(QAction *action)`,QToolButton关联Action后，将自动获取Action的文字、图标、ToolTip等设置为按钮的相应属性。可将所有关联的代码放到一个窗体的私有函数setActionsForButton()中，并在主窗口的构造函数里完成调用，即可成功关联。

### 4.3.为QToolButton按钮设计下拉菜单

在主窗口类里定义一个私有函数createSelectionPopMenu()，并在窗口的构造函数里调用，代码如下：
```
void MainWindow::createSelectionPopMenu()
{
    //创建下拉菜单
    QMenu * menuSelection = new QMenu(this);//创建弹出式菜单
    menuSelection->addAction(ui->actSelALL);
    menuSelection->addAction(ui->actSelNone);
    menuSelection->addAction(ui->actSelInvs);

    //ListWidget上方的tBtnSelectItem按钮
    ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);
    ui->tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tBtnSelectItem->setDefaultAction(ui->actSelPopMenu);//关联Action
    ui->tBtnSelectItem->setMenu(menuSelection);//设置下拉菜单

    //工具栏上的 下拉式菜单按钮
    QToolButton * aBtn = new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup);
    aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//按钮样式
    aBtn->setDefaultAction(ui->actSelPopMenu);
    aBtn->setMenu(menuSelection);//设置下拉菜单
    ui->mainToolBar->addWidget(aBtn);//工具栏添加按钮

    //工具栏添加分割条，和退出按钮
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actQuit);
}
```
观察代码可知为QToolButton按钮设计下拉菜单首先要创建QMenu对象，menuSelection,将三个用于选择列表项的Action添加作为菜单项，tBtnSelectItem是QToolButton按钮的名称，需要调用四个函数对下拉菜单进行设置：
- setPopupMode(QToolButton::MenuButtonPopup)，设置其弹出菜单的模式，**QToolButton::MenuButtonPopup是枚举常量，这种模式下，按钮右侧会有一个向下的小箭头，必须单击这个小按钮才会弹出下拉菜单，直接单击按钮会执行按钮关联的Action,而不会弹出下拉菜单**。
- setToolButtonStyle(Qt::ToolButtonTextBesideIcon)，设置按钮样式，按钮标题文字在图标右侧显示。
- setDefaultAction(ui->actSelPopMenu)，设置按钮关联的Action，actSelPopMenu与actSelInvs有信号与槽的关联，所以单击按钮会执行反选的功能。
- setMenu(menuSelection)，为按钮设置下拉菜单对象。

工具栏上具有下拉菜单的按钮需要动态创建。先创建QToolButton对象aBtn,再用上面四个函数进行设置，但设置参数略有不同，特别是设置菜单弹出模式为:  
`aBtn->setPopupMode(QToolButton::InstantPopup);`  
这种模式下，工具按钮的右下角显示一个小的箭头，单击按钮直接弹出下拉菜单，即使为这个按钮设置了别的关联的Action，也不会执行Action的功能。

## 5.创建右键快捷菜单

每个从QWidget继承的类都有信号customConTextMenuRequested()，这个信号在鼠标右击时发射，为此信号编写槽函数，可以创建和运行右键快捷菜单。
```
void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug()<<"快捷键";
    Q_UNUSED(pos);
    QMenu * menuList = new QMenu(this);//创建菜单
    //添加Actions创建菜单项
    menuList->addAction(ui->actListIni);
    menuList->addAction(ui->actListClear);
    menuList->addAction(ui->actListInsert);
    menuList->addAction(ui->actListAppend);
    menuList->addAction(ui->actListDelete);
    menuList->addSeparator();
    menuList->addAction(ui->actSelALL);
    menuList->addAction(ui->actSelNone);
    menuList->addAction(ui->actSelInvs);
    menuList->exec(QCursor::pos());//在鼠标光标位置显示右键快捷菜单
    delete menuList;
}
```
但运行后却发现鼠标右击后无反应，没有弹出快捷菜单，因为我们还没有添加右键菜单策略，listWidget组件无法知道我们是否点击了它。所以我们应该在构造函数里添加代码：`ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);`





