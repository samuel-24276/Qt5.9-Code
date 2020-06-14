# QString

## 1.字符串转整数

- 1.int toInt(bool * ok = Q_NULLPTR, int base=10) const
- 2.long toLong(bool * ok = Q_NULLPTR, int base=10) const
- 3.short toShort(bool * ok = Q_NULLPTR, int base=10) const
- 4.uint toUInt(bool * ok = Q_NULLPTR, int base=10) const
- 5.ulong toULong(bool * ok = Q_NULLPTR, int base=10) const

这些函数如果不设参数，缺省表示从十进制表示的字符串转换为整数；若指定整数基数参数，还**可以将二进制、十六进制字符串转换为整数**。
```
QString str = ui->editBin->text();
bool ok;
int val = str.toInt(&ok, 2);
//    str = QString::number(val, 16);
str = str.setNum(val, 16);
str = str.toUpper();
ui->editHex->setText(str);
```

## 2.字符串转浮点数

- 1.double toDouble(bool * ok = Q_NULLPTR) const
- 2.float toFloat(bool * ok = Q_NULLPTR) const
```
QString str = ui->editNum->text();//读取数量
int num = str.toInt();
str = ui->editPrice->text();//读取单价
float price = str.toFloat();
float total = num * price;
```
得到计算结果total后，希望将其显示在编辑框editTotal中，且只显示两位小数，以下4行语句都可以实现这个功能：
```
str = QString::number(total, 'f', 2);
str = QString::asprintf("%.2f", total);
str = str.setNum(total, 'f', 2);
str = str.sprintf("%.2f", total);
```

>question:为什么没有使用connect()函数就实现了点击按钮就能激活函数on_btnDec_clicked()进行处理的功能？

