# QXmlStreamWriter

## 1.Properties

- autoFormatting : bool

  流编写器的自动格式化标志

  此属性控制流编写器是否自动格式化生成的XML数据。 如果启用，编写器会自动将换行符和缩进添加到元素之间的空白部分（可忽略的空白）。 自动格式化的主要目的是将数据分成几行，并提高人类读者的可读性。 可以通过autoFormattingIndent属性控制缩进深度。

  默认情况下，禁用自动格式化。

- autoFormattingIndent : int

  启用自动格式设置后，此属性保存用于缩进的空格或制表符的数量。 正数表示空格，负数选项卡。

  默认缩进为4。

## 2.Public Functions

- `bool	hasError () const`

  如果流无法写入基础设备，则返回true；否则返回false。

  错误状态永远不会重置。 即使清除了错误条件，也会忽略发生错误后发生的写操作。

  此功能在Qt 4.8中引入。

- `void	setAutoFormatting ( bool enable )`

- `void	setAutoFormattingIndent ( int spacesOrTabs )`

- `void	setCodec ( QTextCodec * codec )`

  将此流的编解码器设置为编解码器。 编解码器用于对任何写入的数据进行编码。 默认情况下，QXmlStreamWriter使用UTF-8。

  编码信息存储在初始xml标记中，该标记在您调用writeStartDocument（）时写入。 在调用writeStartDocument（）之前，请先调用此函数。

- `void	setCodec ( const char * codecName )`

  将此流的编解码器设置为 QTextCodec，以使用codecName指定的编码。 codecName的常用值包括“ ISO 8859-1”，“ UTF-8”和“ UTF-16”。 **如果无法识别编码，则不会发生任何事情**。

- `void	setDevice ( QIODevice * device )`

  将当前设备设置为device 。 如果希望流写入QByteArray，则可以创建QBuffer设备。

- `void	writeDefaultNamespace ( const QString & namespaceUri )`

  为namespaceUri写入默认的名称空间声明。

  如果调用了writeStartElement（）或writeEmptyElement（），则声明适用于当前元素； 否则，它将应用于下一个子元素。

  请注意，按照定义，命名空间http://www.w3.org/XML/1998/namespace（绑定到xmlns）和http://www.w3.org/2000/xmlns/（绑定到xml）不能声明为 默认。

- `void	writeEmptyElement ( const QString & namespaceUri, const QString & name )`

  写一个空元素，其名称以指定的namespaceUri为前缀。 如果尚未声明名称空间，则QXmlStreamWriter将为其生成名称空间声明。 随后对writeAttribute（）的调用将向该元素添加属性。

- `void	writeEmptyElement ( const QString & qualifiedName )`

- `void	writeEndDocument ()`

  关闭所有剩余的打开开始元素并编写换行符。

- `void	writeEndElement ()`

  关闭上一个开始元素。

- `void	writeStartDocument ( const QString & version )`

  写入以XML版本号version开头的文档。

- `void	writeStartDocument ( const QString & version, bool standalone )`

  编写以XML版本号version和独立属性standalone开头的文档。

- **`void	writeStartDocument ()`**

  **写入以XML版本号“ 1.0”开头的文档。 这也将写入编码信息**。

- `void	writeStartElement ( const QString & namespaceUri, const QString & name )`

  写一个name为开头的start元素，该元素以指定的namespaceUri为前缀。 如果尚未声明名称空间，则QXmlStreamWriter将为其生成名称空间声明。 随后对writeAttribute（）的调用将向该元素添加属性。

- **`void	writeStartElement ( const QString & qualifiedName )`**

  用qualifiedName写一个开始元素。 随后对writeAttribute（）的调用将向该元素添加属性。

- **`void	writeTextElement ( const QString & namespaceUri, const QString & name, const QString & text )`**

  写入一个文本元素，其名称为指定的namespaceUri的前缀，并带有文本。 如果尚未声明名称空间，则QXmlStreamWriter将为其生成名称空间声明。

  这是一个便捷功能，等效于：

  ```c++
  writeStartElement(namespaceUri, name);
  writeCharacters(text);
  writeEndElement();
  ```

- `void	writeTextElement ( const QString & qualifiedName, const QString & text )`

  用qualifiedName和text编写一个文本元素。

  这是一个便捷功能，等效于：

  ```c++
  writeStartElement(qualifiedName);
  writeCharacters(text);
  writeEndElement();
  ```

- `void	writeNamespace ( const QString & namespaceUri, const QString & prefix = QString() )`

  为带前缀的namespaceUri写一个名称空间声明。 如果前缀为空，则QXmlStreamWriter分配一个唯一的前缀，该前缀由字母“ n”和数字组成。

  如果调用了writeStartElement（）或writeEmptyElement（），则声明适用于当前元素； 否则，它将应用于下一个子元素。

  请注意，前缀xml是预定义的，并且是为http://www.w3.org/XML/1998/namespace保留的，因此不能将其绑定到任何其他前缀。 前缀xmlns及其URI http://www.w3.org/2000/xmlns/用于名称空间机制本身，因此在声明中完全禁止使用。

- `void	writeProcessingInstruction ( const QString & target, const QString & data = QString() )`

  用target和data 编写XML处理指令，其中数据不得包含序列“？>”。

- `void	writeAttribute ( const QString & namespaceUri, const QString & name, const QString & value )`

  写入具有名称和值的属性，该属性以指定的namespaceUri为前缀。 如果尚未声明名称空间，则QXmlStreamWriter将为其生成名称空间声明。

  **该函数只能在writeStartElement（）之后，任何内容写入之前或writeEmptyElement（）之后调用**。

- `void	writeAttribute ( const QString & qualifiedName, const QString & value )`

  写入具有名称和值的属性。

  该函数只能在writeStartElement（）之后，任何内容写入之前或writeEmptyElement（）之后调用。

- **`void	writeCharacters ( const QString & text )`**

  写文本。字符"<"、"&"和"""被转义为实体引用"\&It;"、"\&amp;"和"\&quot;"。为了避免被禁序列"]]>"，">"也被转义为"\&gt;"。

- `void	writeAttribute ( const QXmlStreamAttribute & attribute )`

- `void	writeAttributes ( const QXmlStreamAttributes & attributes )`

  写入属性向量attributes。 如果尚未声明属性中引用的名称空间，则QXmlStreamWriter将为其生成名称空间声明。

  该函数只能在writeStartElement（）之后，任何内容写入之前或writeEmptyElement（）之后调用。

- `void	writeDTD ( const QString & dtd )`

  写入DTD部分。 dtd表示XML 1.0规范中的整个doctypedecl产品，即文档类型定义。

  ```xml
  <!DOCTYPE xbel>
  <xbel version="1.0">
  	···
  </xbel>
  ```

- `void	writeCDATA ( const QString & text )`

- `void	writeComment ( const QString & text )`

- `void	writeCurrentToken ( const QXmlStreamReader & reader )`

- `void	writeEntityReference ( const QString & name )`

- `QXmlStreamWriter ()`

- `QXmlStreamWriter ( QIODevice * device )`

- `QXmlStreamWriter ( QByteArray * array )`

- `QXmlStreamWriter ( QString * string )`

- `~QXmlStreamWriter ()`

- `bool	autoFormatting () const`

- `int	autoFormattingIndent () const`

- `QTextCodec *	codec () const`

- `QIODevice *	device () const`

## 3.Detailed Description

QXmlStreamWriter类为XML编写器提供了一个简单的流API。

QXmlStreamWriter是用于编写XML的QXmlStreamReader的副本。与其相关类一样，它在通过setDevice（）指定的QIODevice上运行。该API简单明了：对于您要编写的每个XML令牌或事件，编写器都提供了专用功能。

您可以使用writeStartDocument（）开始文档，并使用writeEndDocument（）结尾。这将隐式关闭所有剩余的打开标签。

元素标签的打开方式是writeStartElement（），然后是writeAttribute（）或writeAttributes（），元素内容，然后是writeEndElement（）。可以**使用较短的形式writeEmptyElement（）来写空元素**，然后是writeAttributes（）。

**元素内容由字符，实体引用或嵌套元素组成**。它是使用writeCharacters（）编写的，该代码还负责转义所有禁止的字符和字符序列，writeEntityReference（）或后续对writeStartElement（）的调用。方便的方法writeTextElement（）可用于编写仅包含文本的终端元素。

以下简短代码片段显示了该类使用缩进格式的XML的基本用法：

```c++
     QXmlStreamWriter stream(&output);
     stream.setAutoFormatting(true);
     stream.writeStartDocument();
     ...
     stream.writeStartElement("bookmark");
     stream.writeAttribute("href", "http://qt.nokia.com/");
     stream.writeTextElement("title", "Qt Home");
     stream.writeEndElement(); // bookmark
     ...
     stream.writeEndDocument();
```

QXmlStreamWriter负责为名称空间添加前缀，您要做的就是在编写元素或属性时指定namespaceUri。如果必须遵循某些前缀，则可以通过使用writeNamespace（）或writeDefaultNamespace（）手动声明名称空间来强制作者使用它们。另外，您可以绕过流编写器对名称空间的支持，而改用采用限定名称的重载方法。名称空间http://www.w3.org/XML/1998/namespace是隐式的，并映射到前缀xml。

通过在元素之间的空白部分添加换行符和缩进，流编写器可以自动格式化生成的XML数据，从而使XML数据对人类更具可读性，并且对于大多数源代码管理系统而言更易于使用。可以使用autoFormatting属性打开该功能，并使用autoFormattingIndent属性进行自定义。

其他函数是writeCDATA（），writeComment（），writeProcessingInstruction（）和writeDTD（）。 writeCurrentToken（）支持XML流的链接。

默认情况下，QXmlStreamWriter以UTF-8编码XML。可以使用setCodec（）实施不同的编码。

如果在写入基础设备时发生错误，则hasError（）开始返回true，随后的写入将被忽略。

“ QXmlStream书签”示例说明了如何使用流编写器来编写XML书签文件（XBEL），该文件先前由QXmlStreamReader读取。