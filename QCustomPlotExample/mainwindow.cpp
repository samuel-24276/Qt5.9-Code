#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCustomPlot* customPlot = ui->widget;
//EXP1. X Square X的平方函数图
    /*
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }

    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
    //要在屏幕上显示对绘图的任何更改，需调用replot()方法。请注意，当调整窗口小部件的大小并触发内置用户交互时，将自动发生重新绘制。 这样的用户交互例子是用鼠标拖动轴范围并用鼠标滚轮缩放
    customPlot->replot();
    */

//EXP2. Simple plot of two graphs 两图叠加显示
    /*
    // add two new graphs and set their look:
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    //QColor构造函数的第四参数是透明度，0~255，0为透明，255为不透明
    customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 0))); // first graph will be filled with translucent blue第一幅图将用半透明的蓝色填充
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine指数衰减余弦
      y1[i] = qExp(-i/150.0);              // exponential envelope指数余弦
    }
    // configure right and top axis to show ticks but no labels:配置右轴和上轴显示间隔但不显示数字
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:使左轴和下轴始终将其范围转移到右轴和上轴：
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
//    customPlot->graph(0)->setData(x, y0);
//    customPlot->graph(1)->setData(x, y1);
    customPlot->graph(0)->setData(x, y0);
    customPlot->graph(1)->setData(x, y1);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:让范围自行缩放，使图0完全适合可见区域
    customPlot->graph(0)->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):与图1相同，但仅扩大范围（如果图1小于图0）
    customPlot->graph(1)->rescaleAxes(true);
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:允许用户使用鼠标拖动轴范围，使用鼠标滚轮缩放以及通过单击以下内容选择图形：
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    */

//EXP3. Plotting with multiple axes and more advanced styling 多轴和多图同时显示
    /*
    //右下角图例
    customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    customPlot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    customPlot->legend->setFont(legendFont);
    customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    //默认情况下，图例位于主轴rect的插入布局中（默认位置右上方）。 因此，这是我们用来更改图例位置的方式：
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);

    // setup for graph 0: key axis left, value axis bottom图0的键轴为左轴，值轴为下轴
    // will contain left maxwell-like function
    //左侧点线图
    customPlot->addGraph(customPlot->yAxis, customPlot->xAxis);//第一参数为键轴，第二参数为值轴
    customPlot->graph(0)->setPen(QPen(QColor(255, 100, 0)));
    customPlot->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    customPlot->graph(0)->setName("Left maxwell function");

    // setup for graph 1: key axis bottom, value axis left (those are the default axes)
    // will contain bottom maxwell-like function with error bars
    //下方阶梯图
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(1)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // same fill as we used for graph 0
    customPlot->graph(1)->setLineStyle(QCPGraph::lsStepCenter);
    customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    customPlot->graph(1)->setName("Bottom maxwell function");
    //跟随阶梯图的黑色竖线
    QCPErrorBars *errorBars = new QCPErrorBars(customPlot->xAxis, customPlot->yAxis);
    errorBars->removeFromLegend();
    errorBars->setDataPlottable(customPlot->graph(1));

    // setup for graph 2: key axis top, value axis right
    // will contain high frequency sine with low frequency beating:
    //上方蓝色曲线图sin*cos
    customPlot->addGraph(customPlot->xAxis2, customPlot->yAxis2);
    customPlot->graph(2)->setPen(QPen(Qt::blue));
    customPlot->graph(2)->setName("High frequency sine");

    // setup for graph 3: same axes as graph 2
    // will contain low frequency beating envelope of graph 2
    //虚线图cos
    customPlot->addGraph(customPlot->xAxis2, customPlot->yAxis2);
    QPen blueDotPen;
    blueDotPen.setColor(QColor(30, 40, 255, 150));
    blueDotPen.setStyle(Qt::DotLine);
    blueDotPen.setWidthF(4);
    customPlot->graph(3)->setPen(blueDotPen);
    customPlot->graph(3)->setName("Sine envelope");

    // setup for graph 4: key axis right, value axis top
    // will contain parabolically distributed data points with some random perturbance
    //随机点图
    customPlot->addGraph(customPlot->yAxis2, customPlot->xAxis2);
    customPlot->graph(4)->setPen(QColor(50, 50, 50, 255));
    customPlot->graph(4)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    customPlot->graph(4)->setName("Some random data around\na quadratic function");

    // generate data, just playing with numbers, not much to learn here:
    QVector<double> x0(25), y0(25);
    QVector<double> x1(15), y1(15), y1err(15);
    QVector<double> x2(250), y2(250);
    QVector<double> x3(250), y3(250);
    QVector<double> x4(250), y4(250);
    for (int i=0; i<25; ++i) // data for graph 0
    {
      x0[i] = 3*i/25.0;
      y0[i] = qExp(-x0[i]*x0[i]*0.8)*(x0[i]*x0[i]+x0[i]);
    }
    for (int i=0; i<15; ++i) // data for graph 1
    {
      x1[i] = 3*i/15.0;;
      y1[i] = qExp(-x1[i]*x1[i])*(x1[i]*x1[i])*2.6;
      y1err[i] = y1[i]*0.25;
    }
    for (int i=0; i<250; ++i) // data for graphs 2, 3 and 4
    {
      x2[i] = i/250.0*3*M_PI;
      x3[i] = x2[i];
      x4[i] = i/250.0*100-50;
      y2[i] = qSin(x2[i]*12)*qCos(x2[i])*10;
      y3[i] = qCos(x3[i])*10;
      y4[i] = 0.01*x4[i]*x4[i] + 1.5*(rand()/(double)RAND_MAX-0.5) + 1.5*M_PI;
    }

    // pass data points to graphs:
    customPlot->graph(0)->setData(x0, y0);
    customPlot->graph(1)->setData(x1, y1);
    errorBars->setData(y1err);
    customPlot->graph(2)->setData(x2, y2);
    customPlot->graph(3)->setData(x3, y3);
    customPlot->graph(4)->setData(x4, y4);
    // activate top and right axes, which are invisible by default:
    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    // set ranges appropriate to show data:
    customPlot->xAxis->setRange(0, 2.7);
    customPlot->yAxis->setRange(0, 2.6);
    customPlot->xAxis2->setRange(0, 3.0*M_PI);
    customPlot->yAxis2->setRange(-70, 35);
    // set pi ticks on top axis:
    customPlot->xAxis2->setTicker(QSharedPointer<QCPAxisTickerPi>(new QCPAxisTickerPi));
    // add title layout element:
    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(customPlot, "Way too many graphs in one plot", QFont("sans", 12, QFont::Bold)));
    // set labels:
    customPlot->xAxis->setLabel("Bottom axis with outward ticks");
    customPlot->yAxis->setLabel("Left axis label");
    customPlot->xAxis2->setLabel("Top axis label");
    customPlot->yAxis2->setLabel("Right axis label");
    // make ticks on bottom axis go outward:
    customPlot->xAxis->setTickLength(0, 5);
    customPlot->xAxis->setSubTickLength(0, 3);
    // make ticks on right axis go inward and outward:
    customPlot->yAxis2->setTickLength(3, 3);
    customPlot->yAxis2->setSubTickLength(1, 1);
    */

//EXP4. Plotting date and time data 绘制日期时间
    /*
    // set locale to english, so we get english month names:
    customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    // seconds of current time, we'll use it as starting point in time for data:
    double now = QDateTime::currentDateTime().toTime_t();
    srand(8); // set the random seed, so we always get the same random data
    // create multiple graphs:
    for (int gi=0; gi<5; ++gi)
    {
      customPlot->addGraph();
      QColor color(20+200/4.0*gi,70*(1.6-gi/4.0), 150, 150);
      customPlot->graph()->setLineStyle(QCPGraph::lsLine);
      customPlot->graph()->setPen(QPen(color.lighter(200)));
      customPlot->graph()->setBrush(QBrush(color));
      // generate random walk data:
      QVector<QCPGraphData> timeData(250);
      for (int i=0; i<250; ++i)
      {
        timeData[i].key = now + 24*3600*i;
        if (i == 0)
          timeData[i].value = (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
        else
          timeData[i].value = qFabs(timeData[i-1].value)*(1+0.02/4.0*(4-gi)) + (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
      }
      customPlot->graph()->data()->set(timeData);
    }
    // configure bottom axis to show date instead of number:
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    customPlot->xAxis->setTicker(dateTicker);
    // configure left axis text labels:
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTick(10, "a bit\nlow");
    textTicker->addTick(50, "quite\nhigh");
    customPlot->yAxis->setTicker(textTicker);
    // set a more compact font size for bottom and left axis tick labels:
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
    // set axis labels:
    customPlot->xAxis->setLabel("Date");
    customPlot->yAxis->setLabel("Random wobbly lines value");
    // make top and right axes visible but without ticks and labels:
    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);
    // set axis ranges to show all data:
    customPlot->xAxis->setRange(now, now+24*3600*249);
    customPlot->yAxis->setRange(0, 60);
    // show legend with slightly transparent background brush:
    customPlot->legend->setVisible(true);
    customPlot->legend->setBrush(QColor(255, 255, 255, 150));
    */

//EXP5. a bar chart with three bars:带三个条形的条形图
    QCPBars *myBars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    // now we can modify properties of myBars:
    myBars->setName("Bars Series 1");
    QVector<double> keyData;
    QVector<double> valueData;
    keyData << 1 << 2 << 3;
    valueData << 2 << 4 << 8;
    myBars->setData(keyData, valueData);
    customPlot->rescaleAxes();
    customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

