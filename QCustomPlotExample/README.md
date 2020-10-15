# QCustomPlot绘图和数据可视化库

> Qt C++绘图和数据可视化的 Qt 小部件 ，官网： https://www.qcustomplot.com/index.php/introduction 

您可以通过在绘图中创建新图形，然后为图形分配一些数据点，例如，以 x 和 y 的 2 个形式（键和值）。QCustomPlot 之所以使用术语键和值而不是*x*和y，是为了让分配哪个轴具有什么角色时具有更大的灵活性。因此，如果将左轴定义为"**键轴**"，将底部定义为"**值轴**"，可以绘制垂直于绘图左侧的图形。默认情况下，QCustomPlot 小部件有四个轴，对应于下轴、左轴、上轴和右轴。它们的范围定义绘图的哪个部分当前可见 。 

## 1.graph图表

The look of the graph is characterized by many factors, all of which can be modified. Here are the most important ones:

 图形的外观由许多因素所影响，所有这些都可以修改。以下是最重要的 ：

- **Line style**: Call `graph->setLineStyle(..)`. For all possible line styles, see the [QCPGraph](https://www.qcustomplot.com/doc.php/QCPGraph)[::LineStyle](https://www.qcustomplot.com/doc.php/QCPGraph/LineStyle) documentation or the line style demo screenshot on the introduction page.

   **行样式**：调用`graph->setLineStyle(..)`设置有关所有可能的线条样式，请参阅[介绍页面上的 QCPGraph](https://www.qcustomplot.com/doc.php/QCPGraph)[：：LineStyle](https://www.qcustomplot.com/doc.php/QCPGraph/LineStyle)文档或线条样式演示屏幕截图 。

- **Line pen**: All pens the QPainter-framework provides are available, e.g. solid, dashed, dotted, different widths, colors, transparency, etc. Set the configured pen via `graph->setPen(..)`.

  **画笔**：QPainter-框架提供的所有笔都可用，例如实心笔、虚线笔、虚线笔、不同宽度笔、颜色笔、透明度笔等。通过`graph->setPen(..)`设置配置的笔。

- **Scatter symbol**: Call  `graph->setScatterStyle(..)` to change the look of the scatter point symbols. For all possible scatter styles, see the [QCPScatterStyle](https://www.qcustomplot.com/doc.php/QCPScatterStyle) documentation or the scatter style demo screenshot shown on the introduction page. If you don't want any scatter symbols to show at the data points, set the graph's scatter style to `QCPScatterStyle::ssNone`.

   **散点**符号：调用 `graph->setScatterStyle(..)`以更改散点点符号的外观。有关所有可能的散点样式，[请参阅 QCPScatterStyle](https://www.qcustomplot.com/doc.php/QCPScatterStyle)文档或介绍页面上显示的散点样式演示屏幕截图。 如果不希望在数据点显示任何散点符号，请将图形的散点样式设置为`QCPScatterStyle::ssNone` 。 

- **Fills under graph or between two graphs**: All brushes the QPainter-framework provides can be used in graph fills: solid, various patterns, textures, gradients, colors, transparency, etc. Set the configured brush via .`graph->setBrush(..)`

   **图形下或两个图形之间的**填充：QPainter 框架提供的所有画笔都可用于图形填充：实体、各种图案、纹理、渐变、颜色、透明度等。通过 设置配置的画笔。 

## 2.axis坐标轴

## 3.grid lines网格线

The grid is modified by accessing the respective [QCPGrid](https://www.qcustomplot.com/doc.php/QCPGrid) instance of an axis. For example, changing the look of the horizontal grid lines, which are tied to the left axis, is done by accessing `customPlot->yAxis->grid()` . The look of the grid lines is basically the pen they are drawn with, which can be set via `yAxis->grid()->setPen()`. The grid line at tick 0 can be drawn with a different pen, it can be configured with `setZeroLinePen`. If you do not wish to draw the zero line with a special pen, just set it to `Qt::NoPen`, and the grid line at tick 0 will be drawn with the normal grid pen.
Sub-grid lines are set to be invisible by default. They can be activated with .

通过访问轴的各[QCPGrid 实例](https://www.qcustomplot.com/doc.php/QCPGrid)来修改网格。例如，通过访问 `customPlot->yAxis->grid()`来更改与左轴相连的水平网格线的外观。网格线的外观基本上是他们绘制的笔，可以通过`yAxis->grid()->setPen()`进行设置。刻度 0 的网格线可以使用不同的笔绘制，也可以使用 `setZeroLinePen`进行配置。如果不希望使用特殊笔绘制零线，只需将零线设置为`Qt::NoPen` ，则刻度 0 的网格线将用普通网格笔绘制。
默认情况下，子网格线设置为不可见。它们可以使用 `grid()->setSubGridVisible(true)`激活。 

## 4.其他

图表是这样一个占主导地位的用例，因此QCustomPlot 为他们提供了一个专门的接口，我们一直在使用它，例如，`QCustomPlot::addGraph`， `QCustomPlot::graph` 等。 **QCustomPlot** 具有更通用的接口，*用于在绘图内绘制数据的类，*称为“ *Plottables* ”。  此接口是围绕抽象基类*[QCPAbstractPlottables](https://www.qcustomplot.com/doc.php/QCPAbstractPlottable)*构建的。所有可绘制的可派生项都来自此类， 也是熟悉的[QCPGraph 类](https://www.qcustomplot.com/doc.php/QCPGraph)。 QCustomPlot 提供了许多其他可绘图类：

- **[QCPGraph](https://www.qcustomplot.com/doc.php/QCPGraph)**: That's the plottable class we've been using. Displays a series of data points as a graph with different line styles, filling and scatters.

  我们一直在使用的可绘制类。将一系列数据点显示为具有不同线样式、填充和散射的图形。 

- **[QCPCurve](https://www.qcustomplot.com/doc.php/QCPCurve)**: Similar to [QCPGraph](https://www.qcustomplot.com/doc.php/QCPGraph) with the difference that it's made for displaying parametric curves. Unlike function graphs, they may have *loops*.

   类似于[QCPGraph](https://www.qcustomplot.com/doc.php/QCPGraph)，它用于显示参数曲线。与函数图不同，它们可能有*循环*。 

- **[QCPBars](https://www.qcustomplot.com/doc.php/QCPBars)**: A Bar Chart. Takes a series of data points and represents them with bars. If there are multiple [QCPBars](https://www.qcustomplot.com/doc.php/QCPBars) plottables in the plot, they can be stacked on top of each other, as shown in the screenshot on the introduction page.

  条形图。以一系列数据点表示它们用条形图。如果绘图中有多个[QCPBar](https://www.qcustomplot.com/doc.php/QCPBars)可绘制，它们可以堆叠在一起，如介绍页面上的屏幕截图所示。 

- **[QCPStatisticalBox](https://www.qcustomplot.com/doc.php/QCPStatisticalBox)**: A Statistical Box Plot. Takes a five-number-summary (minimum, lower quartile, median, upper quartile, maximum) and represents it as a statistical box. Outliers can also be displayed.

  统计框图。采取五个数字汇总（最小、下四分位数、中位数、上四分位数、最大值），并表示它作为统计框。还可以显示异常值。 

- **[QCPColorMap](https://www.qcustomplot.com/doc.php/QCPColorMap)**: A 2D map which visualizes a third data dimension by using a color gradient. The class [QCPColorScale](https://www.qcustomplot.com/doc.php/QCPColorScale) accompanies this plottable to visualize the data scale in the plot.

  *使用颜色渐变***可视化第三个数据维度**的 2D 地图。类[QCPColorScale](https://www.qcustomplot.com/doc.php/QCPColorScale)附带此可绘制的图形，以可视化绘图中的数据比例。 

- **[QCPFinancial](https://www.qcustomplot.com/doc.php/QCPFinancial)**: A plottable which can be used to visualize for example stock price open, high, low, close information by either using Candlesticks or OHLC bars.

   一个可用于可视化的*plottable*，无论是使用烛台或OHLC柱，例如股票价格开盘，高，低，接近信息。 

- **[QCPErrorBars](https://www.qcustomplot.com/doc.php/QCPErrorBars)**: This is a special plottable in that it attaches to a second plottable, to allow displaying error bars on the data points of the other plottables.

   这是一个特殊的*plottable*，因为它附加到第二个可绘制的，允许在其他可绘图的数据点上显示误差条。 

Unlike graphs, other plottables need to be created with `new` outside of QCustomPlot. This means that there is no *addCurve* or *addBars* function in the way there is an *[addGraph](https://www.qcustomplot.com/doc.php/addGraph)* function.  The QCustomPlot instance which the plottable shall belong to is inferred from the passed axes in the plottable's constructor. QCustomPlot then takes ownership of the plottable. Existing plottables can be accessed with `QCustomPlot::plottable(int index)` and the total number of plottables in the plot (including graphs) can be retrieved with `QCustomPlot::plottableCount`.

与图形不同，其他可绘制对象需要使用`new`从 QCustomPlot 外部创建。这意味着没有添加*曲线或*添加*栏函数*的方式有一个[addGraph函数](https://www.qcustomplot.com/doc.php/addGraph)*。plottable* 所属的 QCustomPlot 实例从可绘制的构造函数中传递的轴推断。QCustomPlot 然后接管*plottable* 的所有权。可以使用`QCustomPlot::plottable(int index)`访问现有的可绘制对象，也可以使用`QCustomPlot::plottableCount`访问绘图（包括图形）中的*plottable* 总数。