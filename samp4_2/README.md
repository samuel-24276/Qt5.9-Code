# QString常用功能

- 1.append()和prepend()  
    在字符串前面/后面添加字符串，参数是被添加的内容
    
- 2.toUpper()和toLower()  
    将字符串内的字母全部转换为大写/小写形式，无参数

- 3.count()、size()和length()  
    这三个函数是相同的，都返回字符串的字符个数。QString存储字符采用的是Unicode码，每一个字符是16位的QChar,所以一个汉字是一个字符。无参数

- 4.trimmed()和simplified()  
    trimmed()去掉字符串首尾的空格，simplified()不仅去掉首尾的空格，中间连续的空格也用一个空格替换。无参数

- 5.indexOf()和lastIndexOf()  
    indexOf()原型为`int indexOf(const QString &str, int from = 0, Qt::CaseSensitivity cs = Qt::CaseSensitive) const`，功能是在自身字符串内查找参数字符串str出现的位置，参数from是开始查找的位置，cs参数指定是否区分大小写

- 6.isNull()和isEmpty()  
    判断字符串是否为空，但对于空字符串"\0",isNull()返回false,而isEmpty()返回true。只有未赋值的字符串isNUll()才返回true，判断字符串内容是否为空，常用isEmpty()。无参数

- 7.constains()  
    判断字符串内是否包含某个字符串，可指定是否区分大小写。第一参数为被包含的字符串，第二参数指定是否区分大小写,Qt::CaseSensitive大小写敏感,Qt::CaseInsensitive大小写不敏感

- 8.endsWith()和startsWith()  
    判断是否以某个字符串开头/结尾，第一参数是某个字符串，第二参数指定是否区分大小写

- 9.left()和right()  
    表示从字符串中取左边/右边多少个字符，参数n是取字符的个数

- 10.section()  
    原型为`QString::section(QChar sep, int start, int end = ..., QString::SectionFlags flags = SectionDefault) const`,功能是从字符串中提取以sep作为分隔符，从start端到end端的字符串。