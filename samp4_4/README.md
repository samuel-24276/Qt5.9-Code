# 各组件的主要功能和属性

## 1.QSlider

QSlider、QScrollBar和QDial三个组件都从**QAbstractSlider**继承而来，有一些共有的属性。QSlider是滑动的标尺型组件，滑动标尺上的一个滑块可以改变值。  
基类QAbstractSlider的主要属性包括以下几种：
- minimum、maximum：设置输入范围的最小值和最大值，例如用红绿蓝配色时，美忠吉色的大小范围是0~255，所以minimum=0，maximum=255.
- singleStep:单步长，拖动标尺上的滑块，或按下左右光标时的最小变化数值。
- pageStep:在Slider上输入焦点，按PgUp或PgDn键时变化的数值。
- value:组件的当前值，拖动滑块时自动改变此值，并限定在minimum和maximum定义的范围之内。
- sliderPosition:滑块的位置，若tracking属性设置为true，sliderPosition=value。
- tracking:sliderPosition是否等同于value，如果tracking=true,改变value时也同时改变sliderPosition。
- orientation:Slider的方向，方向参数是Qt的枚举类型enum Qt::Orientation,取值有两种：  
    Qt::Horizontal 水平方向  
    Qt::Vertical 垂直方向
- invertedAppearance:显示方向是否反向，=false时，水平方向从左到右数值增大。
- invertedControls:反向按键控制，若=true,则按下PgUp或PgDn键时，调整数值的方向相反。

属于QSlider的专有属性有两个，如下。
- trackPosition:标尺刻度的显示位置，使用枚举类型QSlider::TrackPosition,取值包括以下6种。
    - QSlider::NoTracks 不显示刻度
    - QSlider::TicksBothSides 标尺两侧都显示刻度
    - QSlider::TicksAbove 标尺上方显示刻度
    - QSlider::TicksBelow 标尺下方显示刻度
    - QSlider::TicksLeft 标尺左侧显示刻度
    - QSlider::TicksRight 标尺右侧显示刻度
- tickInterval:标尺刻度的间隔值，若设置为0，会在singleStep和pageStep之间自动选择。

## 2.QScrollBar

具有QAbstractSlider的所有属性，没有专有属性。

## 3.QDial

QDial是仪表盘式组件，特有属性有两种：
- notchesVisible:表盘的小刻度是否可见。
- notchesTarget:表盘刻度间的间隔像素值。

## 4.QProcessBar

父类是QWidget,常用属性如下：
- minimum、maximum：最小值和最大值
- value:当前值，可以设定或读取当前值。
- textVisible:是否显示文字，文字一般是百分比表示的进度。
- orientation:可以设置为水平或垂直方向
- format:显示文字的格式，"%p%"显示百分比，"%v"显示当前值，"%m"显示总步数，"%p%"为缺省值

## 5.QLCDNumber

QLCDNumber是模拟LCD显示数字的组件，可以显示整数或小数，还可以选择不同进制来显示。
- digitCount:显示的数的位数，如果是小数，小数点也算一个数位。
- smallDecimalPoint:是否有小数点，如果有小数点，就可以显示小数。
- mode:数的显示进制，通过调用函数setDecMode()、setBinMode()、setOctMode()、setHexMode()可以设置为常用的十进制。二进制、八进制、十六进制格式。
- value:显示返回值，浮点数。若设置为显示整数，会四舍五入得到整数，设置为intValue的值
- intValue:返回显示的整数值。

>解决了samp4_1的question:为什么没有使用connect()函数就实现了点击按钮就能激活函数on_btnDec_clicked()进行处理的功能？

>解答：应该是默认调用了connect()函数，SIGNAL为点击按钮的信号。使用connect()函数可以用不同的信号激发同一个槽函数on_SliderRed_valueChanged()。

>**更改初始窗口大小：`this->resize( QSize( 800, 600 ))`**