# SpinBox的使用

QSpinBox用于整数的显示和输入，一般显示10进制数，也可以显示2，16进制数，而且可以在显示框中增加前缀或后缀。 

QDoubleSpinBox用于浮点数的显示和输入，可以设置显示小数位数，也可以设置显示的前缀和后缀。 

samp4_3与samp4_1类似，只是Line Edit换成了SpinBox和DoubleSpinBox，二者都是QAbstractSpinBox的子类，具有大多数相同的属性，只是参数类型不同。SpinBox和DoubleSpinBox读取和设置数值时，无需做字符串与数值之间的转换，对输入输出十分方便。

- 1.设置前缀setPrefix(str)  
    `ui->spinHex->setPrefix("Hex ");`

- 2.设置后缀setSuffix(str)  
    `ui->spinNum->setSuffix("kg");`

- 3.设置显示n进制数setDisplayIntegerBase(n)  
    ```
    ui->spinBin->setDisplayIntegerBase(2);
    ui->spinDec->setDisplayIntegerBase(10);
    ui->spinHex->setDisplayIntegerBase(16);
    ```

- 4.设置显示的小数位数setDecimals(n)  
    `ui->spinTotal->setDecimals(1);`

- 5.设置单步数量setSingleStep(n)  
    `ui->spinNum->setSingleStep(10);`


