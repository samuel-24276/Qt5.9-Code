# QStandardItemModel

存在问题：

- 在打开文件时，会产生多余的一行表格内容，而表格的最后一项是逻辑型数据，不是默认产生的数据，所以此时产生的表格行数据的最后一项是错误的。
- 加粗函数没有起到应有作用，字体没有变换，checked一直为false。

QTableView设置水平标题时不能像QTableWidget那样直接设置，而是通过QStandardItemModel设置相关属性（如水平标题）后，再将其设置为QTableView关联的Model即可。

表格视图除了设置数据模型`QStandardItemModel`外，还要设置选择模型`QItemSelectionModel`，而且选择模型要与数据模型关联起来，这一点是通过构造选择模型时将数据模型作为参数传递进去实现的。设置完两个模型后还要设置选择的策略`setSelectionBehavior()`。

表格里的每个数据都是一个QStandardItem项，通过该项可以设置单元格内显示的内容（如单选框，图片，文字等）。

单元格内文字的排列方式（居左，居中，居右）也是通过该项的 `setTextAlignment()`方法实现，单元格内的文字字体（加粗、斜体、正常）可以通过该项的`setFont(Font font)`方法实现。

每次添加append之后都要清除之前的选择，即调用选择模型的`clearSelection()`方法，还要调整当前选中的位置为新添加的一行的第一个数据，通过选择模型的`setCurrentIndex(QModelIndex index, QItemSelectionModel::选择策略)`方法实现。删除delete与之类似，也要调用`setCurrentIndex(选择模型->currentIndex(), QItemSelectionModel::选择策略)`方法。