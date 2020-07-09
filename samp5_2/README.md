# QFileSystemModel

**QFileSystemModel**和视图组件**QTreeView**结合使用，可以用目录树的形式显示本机上的文件系统，如同Windows的资源管理器一样。使用QFileSystemModel提供的接口函数，可以创建目录、删除目录、重命名目录，可以获得文件名称、目录名称、文件大小等参数，还可以获得文件的详细信息。

要通过QFileSystemModel获得本机的文件系统，需要用setRootPath()函数为QFileSystemModel设置一个根目录，例如：

```c++
QFileSystemModel *model = new QFileSystemModel;
model->setRootPath(QDir::currentPath());
```

静态函数QDir::currentPath()获取应用程序的当前路径。

因为TreeView的clicked(QModelIndex)信号会传递一个QModelIndex变量，是当前节点的**模型索引**，将此模型索引传递给listView和tableView的槽函数setRootIndex(QModelIndex)，listView和tableView就会显示此节点下的目录和文件。

QFileSystemModel有以下几种函数：

- 1.bool isDir(QModelIndex &index)：判断节点是不是一个目录
- 2.QString filePath(QModelIndex &index)：返回节点的目录名或带路径的文件名
- 3.QString fileName(QModelIndex &index)：返回去除路径的文件夹名称或文件名
- 4.QString type(QModelIndex &index)：返回描述节点类型的文字
- 5.qint64 size(QModelIndex &index)：如果节点是文件，返回文件大小的字节数；如果节点是文件夹，返回0

# QStringListModel

**QStringListModel**用于处理字符串列表的数据模型，它可以作为**QListView**的数据模型，在界面上显示和编辑字符串列表。常用函数有如下几种：

- 1.setStringList(const [QStringList](qstringlist.html) &*strings*)：初始化数据模型的字符串列表的内容
- 2.stringList()：返回数据模型的字符串列表
- 3.insertRow(int *row*, const [QModelIndex](qmodelindex.html) &*parent* = QModelIndex())：向数据模型内插入一个空行，第二参数可省略
- 4.setData(const [QModelIndex](qmodelindex.html) &*index*, const [QVariant](qvariant.html) &*value*, int *role* = Qt::EditRole)：给index所在行填充数据，并指明角色
- 5.insertRows(int *row*, int *count*, const [QModelIndex](qmodelindex.html) &*parent* = QModelIndex())：向数据模型内插入多个空行
- 6.removeRows(int *row*, int *count*, const [QModelIndex](qmodelindex.html) &*parent* = QModelIndex())：移除数据模型内的多行数据
- 7.removeRow(int *row*, const [QModelIndex](qmodelindex.html) &*parent* = QModelIndex())：移除数据模型内的第row行数据
- 8.clear()：清空数据模型内的数据

