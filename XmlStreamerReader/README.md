# XmlStreamerReader

读取自定义结构的xml文件book.xml的内容，有以下几个关键函数：

- `void ReadAllChildElement();`

  读取所有类型的xml结构数据。

- `void ReadBookIndexElement();`

  读取bookindex标签下的结构数据

- `void ReadEntryElement();`

  读取entry标签下的结构数据

- `void ReadPageElement();`

  读取page标签下的结构数据

- **`void SkipUnknownElement();`**

  跳过xml文件里在该程序里未定义的结构数据，对程序健壮性十分重要。

此外该项目还涉及了以下几个方法的使用：

- 文件对话框打开函数`QFileDialog::getOpenFileName()`（文件对话框保存函数`QFileDialog::getSaveFileName()`用法和其相同）
- 颜色选择对话框`QColorDialog::getColor()`
- 字体选择对话框`QFontDialog::getFont()`
- 输入对话框 的文字输入函数`QInputDialog::getText()`、整数输入函数`QInputDialog::getInt()`、浮点数输入函数`QInputDialog::getDouble()`、下拉列表的选择函数`QInputDialog::getItem()`
- Question对话框`QMessageBox::question()`

# QXmlStreamReader

> 初始化后的TokenType是NoToken，第一次readNext()获取到StartDocument，再次readNext()即获取到StartElement。
>
> 创建一个QXmlStreamReader的类对象
> 通过setDevice()设置好要处理的XML文件
> 通过readNext()挨个读入节点，
> 通过isStartElement()和isEndElement()判断是节点的开始和结束.
>
> 通过name()得到当前节点名字
> 通过readElementText()访问当前节点的内容
>
> 通过attributes()获取含有属性的节点的属性

Qt 4具有三个不同的XML解析器：

- QDomDocument——DOM解析器,QtXML的一部分
- QXmlSimpleReader——推送(事件)解析器,是QtXML的一部分
- **QXmlStreamReader**——**Pull解析器**,是QtCore的一部分,**现在是推荐的解析器**

## 1.Public Types

- Error { NoError, CustomError, NotWellFormedError, PrematureEndOfDocumentError, UnexpectedElementError }

  | Constant                                      | Value | Description                                                  |
  | --------------------------------------------- | ----- | ------------------------------------------------------------ |
  | QXmlStreamReader::NoError                     | 0     | No error has occurred.                                       |
  | QXmlStreamReader::CustomError                 | 2     | 使用raiseError（）引发了自定义错误                           |
  | **QXmlStreamReader::NotWellFormedError**      | 3     | 由于读取的XML格式不正确，解析器在内部引发错误。              |
  | QXmlStreamReader::PrematureEndOfDocumentError | 4     | 输入流在解析格式正确的XML文档之前结束。 如果有更多XML到达流中，则可以通过调用addData（）或等待它到达device（）来从此错误中恢复。 |
  | **QXmlStreamReader::UnexpectedElementError**  | 1     | 解析器遇到的元素与预期的元素不同。                           |

  

- enum	ReadElementTextBehaviour { ErrorOnUnexpectedElement, IncludeChildElements, SkipChildElements }

  该枚举指定readElementText（）的不同行为。

  | Constant                                   | Value | Description                                                  |
  | ------------------------------------------ | ----- | ------------------------------------------------------------ |
  | QXmlStreamReader::ErrorOnUnexpectedElement | 0     | 引发UnexpectedElementError并返回到目前为止遇到子元素时已读取的内容。 |
  | QXmlStreamReader::IncludeChildElements     | 1     | 递归包括子元素中的文本。                                     |
  | QXmlStreamReader::SkipChildElements        | 2     | 跳过子元素                                                   |

  

- enum	TokenType { NoToken, Invalid, StartDocument, EndDocument, ..., ProcessingInstruction }

  | Constant                                | Value | Description                                                  |
  | --------------------------------------- | ----- | ------------------------------------------------------------ |
  | QXmlStreamReader::NoToken               | 0     | 读者尚未阅读任何内容。                                       |
  | QXmlStreamReader::Invalid               | 1     | 发生错误，报告为error（）和errorString（）。                 |
  | QXmlStreamReader::StartDocument         | 2     | 读者在documentVersion（）中报告XML版本号，并在documentEncoding（）中报告XML文档中指定的编码。 如果文档被声明为独立文档，则isStandaloneDocument（）返回true； 否则返回false。 |
  | QXmlStreamReader::EndDocument           | 3     | 读者报告文档的结尾。                                         |
  | QXmlStreamReader::StartElement          | 4     | 读者可以使用namespaceUri（）和name（）报告元素的开始。 空元素也报告为StartElement，然后直接报告为EndElement。 可以调用便捷功能readElementText（）来连接所有内容，直到对应的EndElement。 属性在attribute（）中报告，在namespaceDeclarations（）中报告名称空间。 |
  | QXmlStreamReader::EndElement            | 5     | 读者使用namespaceName Uri（）和name（）报告元素的结尾。      |
  | QXmlStreamReader::Characters            | 6     | 读者报告text（）中的字符。 如果字符都是空白，则isWhitespace（）返回true。 如果字符来自CDATA节，则isCDATA（）返回true。 |
  | QXmlStreamReader::Comment               | 7     | 读者在text（）中报告comment。                                |
  | QXmlStreamReader::DTD                   | 8     | 读者在text（）中报告DTD，在notationDeclarations（）中报告符号声明，并在EntityDeclarations（）中报告实体声明。 DTD声明的详细信息在dtdName（），dtdPublicId（）和dtdSystemId（）中报告。 |
  | QXmlStreamReader::EntityReference       | 9     | 读者报告无法解析的实体引用。 引用的名称在name（）中报告，替换文本在text（）中报告。 |
  | QXmlStreamReader::ProcessingInstruction | 10    | 读取器在processingInstructionTarget（）和processingInstructionData（）中报告一条处理指令。 |

  

## 2.Properties

- namespaceProcessing : bool

  流读取器的名称空间处理标志

  此属性控制流读取器是否处理名称空间。 如果启用，则读取器处理名称空间，否则不处理。

  默认情况下，启用名称空间处理。

## 3.Public Functions

- **`void	setDevice ( QIODevice * device )`**

  将当前设备设置为device 。 设置设备会将流重置为其初始状态。

- TokenType	readNext ()

  **读取下一个标记并返回其类型**。

  除了一个例外，一旦readNext（）报告了error（），就不可能进一步读取XML流。 然后atEnd（）返回true，hasError（）返回true，此函数返回QXmlStreamReader :: Invalid。

  例外是error（）返回PrematureEndOfDocumentError时。 当到达其他格式良好的XML块的末尾时报告此错误，但是该块不代表完整的XML文档。 在这种情况下，可以通过从QByteArray读取流时调用addData（）以添加下一个XML块来恢复解析，或者在从device（）读取流时等待更多数据到达来恢复解析。 

- **`void	addData ( const QByteArray & data )`**

  添加更多数据供读者阅读。 如果阅读器具有device（），则此函数不执行任何操作。

- void	addData ( const QString & data )

- void	addData ( const char * data )

- **QString	readElementText ( ReadElementTextBehaviour behaviour )**

  在读取StartElement时调用的便捷功能。 **读取直到相应的EndElement并返回中间的所有文本**。 如果没有错误，则调用此函数后的当前标记（请参见tokenType（））为EndElement。

  该函数在读取Characters或EntityReference标记时会串联text（），但会跳过ProcessingInstruction和Comment。 如果当前令牌不是StartElement，则返回一个空字符串。

  该行为定义了在到达EndElement之前读取了其他任何内容的情况。 **该函数可以包含子元素中的文本**（例如，对于HTML有用），忽略子元素或引发UnexpectedElementError并返回到目前为止已读取的内容。

- QString	readElementText ()

  调用此函数等效于调用readElementText（ErrorOnUnexpectedElement）。

- **bool	readNextStartElement ()**

  **读取直到当前元素中的下一个开始元素**。 到达开始元素时返回true。 当到达end元素或发生错误时，将返回false。

  当前元素是与最近解析的开始元素匹配的元素，而该元素尚未达到匹配的结束元素。 当解析器到达end元素时，当前元素成为父元素。

  您可以通过重复调用此函数来遍历文档，同时确保流阅读器不在文档末尾

- **void	skipCurrentElement ()**

  **读取直到当前元素的末尾，跳过所有子节点**。 此功能对于跳过未知元素很有用。

  当前元素是与最近解析的开始元素匹配的元素，而该元素尚未达到匹配的结束元素。 当解析器到达end元素时，当前元素成为父元素。

- QStringRef	processingInstructionData () const

  返回处理指令的数据。

- QStringRef	processingInstructionTarget () const

  返回ProcessingInstruction的目标。

- QStringRef	name () const

  返回StartElement，EndElement或EntityReference的本地名称。

- **bool	atEnd () const**

  如果阅读器已阅读到XML文档的末尾，或者发生了error（）且阅读已中止，则返回true。 否则，它返回false。

  **当atEnd（）和hasError（）返回true并且error（）返回PrematureEndOfDocumentError时，这表示XML到目前为止格式正确，但是尚未解析完整的XML文档**。 如果正在从QByteArray读取XML，则可以使用addData（）添加下一个XML块，或者如果正在从QIODevice读取XML，则可以等待更多数据到达。 无论哪种方式，一旦有更多数据可用，atEnd（）都将返回false。

- QXmlStreamAttributes	attributes () const

  返回StartElement的属性。搭配value("属性名").toString()函数可以查询某个具体属性的值。

- Error	error () const

  返回当前错误的类型，如果没有发生错误，则返回NoError。

- **QString	errorString () const**

  返回使用raiseError（）设置的错误消息。

- bool	hasError () const

  如果发生错误，则返回true，否则返回false。

- **QString	tokenString () const**

  以字符串形式返回阅读器的当前令牌。

- QXmlStreamNamespaceDeclarations	namespaceDeclarations () const

  如果state（）是StartElement，则此函数返回元素的命名空间声明。 否则，将返回一个空向量。

  QXmlStreamNamespaceDeclaration类定义为QXmlStreamNamespaceDeclaration的QVector。

- bool	namespaceProcessing () const

- QStringRef	namespaceUri () const

  返回StartElement或EndElement的namespaceUri。

- QStringRef	prefix () const

  返回StartElement或EndElement的前缀。

- **void	raiseError ( const QString & message = QString() )**

  使用可选错误消息引发自定义错误。

- QXmlStreamReader ()

- QXmlStreamReader ( QIODevice * device )

- QXmlStreamReader ( const QByteArray & data )

- QXmlStreamReader ( const QString & data )

- QXmlStreamReader ( const char * data )

- ~QXmlStreamReader ()

- void	addExtraNamespaceDeclaration ( const QXmlStreamNamespaceDeclaration & extraNamespaceDeclaration )

- void	addExtraNamespaceDeclarations ( const QXmlStreamNamespaceDeclarations & extraNamespaceDeclarations )

- qint64	characterOffset () const

- void	clear ()

- qint64	columnNumber () const

- QIODevice *	device () const

- QStringRef	documentEncoding () const

- QStringRef	documentVersion () const

- QStringRef	dtdName () const

- QStringRef	dtdPublicId () const

- QStringRef	dtdSystemId () const

- QXmlStreamEntityDeclarations	entityDeclarations () const

- QXmlStreamEntityResolver *	entityResolver () const

- bool	isCDATA () const

- bool	isCharacters () const

- bool	isComment () const

- bool	isDTD () const

- bool	isEndDocument () const

- bool	isEndElement () const

- bool	isEntityReference () const

- bool	isProcessingInstruction () const

- bool	isStandaloneDocument () const

- bool	isStartDocument () const

- bool	isStartElement () const

  如果tokenType（）等于StartElement，则返回true；否则返回false。

- bool	isWhitespace () const

- qint64	lineNumber () const

- QXmlStreamNotationDeclarations	notationDeclarations () const

- QStringRef	qualifiedName () const

- void	setEntityResolver ( QXmlStreamEntityResolver * resolver )

- void	setNamespaceProcessing ( bool )

- QStringRef	text () const

- TokenType	tokenType () const

## 4.Detailed Description

QXmlStreamReader类提供了一个快速解析器，用于通过简单的流API读取格式正确的XML。

QXmlStreamReader是Qt自己的SAX解析器的一种更快，更方便的替代方法（请参阅QXmlSimpleReader）。在某些情况下，对于在其他情况下将使用DOM树的应用程序中使用，它可能是一种更快，更方便的替代方法（请参阅QDomDocument）。 QXmlStreamReader从QIODevice（请参阅setDevice（））或从原始QByteArray（请参阅addData（））读取数据。

Qt提供QXmlStreamWriter来编写XML。

流读取器的基本概念是将XML文档作为令牌流报告，类似于SAX。 QXmlStreamReader和SAX之间的主要区别在于如何报告这些XML令牌。使用SAX，应用程序必须提供处理程序（回调函数），以便在解析器方便时从解析器接收所谓的XML事件。使用QXmlStreamReader，应用程序代码本身可以驱动循环并根据需要从读取器中逐个提取令牌。这是通过调用readNext（）来完成的，在该方法中，读取器从输入流中读取内容，直到完成下一个标记为止，此时，它返回tokenType（）。然后可以使用一组方便的函数，包括isStartElement（）和text（）来检查令牌，以获得有关已读取内容的信息。这种拉取方法的最大优点是可以使用它构建递归下降解析器，这意味着您可以轻松地将XML解析代码拆分为不同的方法或类。这使得在解析XML时轻松跟踪应用程序自身的状态。

**QXmlStreamReader的典型循环如下所示**：

```c++
  QXmlStreamReader xml;
   ...
   while (!xml.atEnd()) {
         xml.readNext();
         ... // do processing
   }
   if (xml.hasError()) {
         ... // do error handling
   }
```

QXmlStreamReader是格式良好的XML 1.0解析器，不包含外部解析的实体。只要没有错误发生，就可以确保应用程序代码确保流读取器提供的数据满足W3C的格式正确的XML标准。例如，可以确定所有标签确实都正确嵌套和关闭，对内部实体的引用已被正确的替换文本替换，并且属性已根据DTD的内部子集进行了规范化或添加。

如果解析时发生错误，则atEnd（）和hasError（）返回true，而error（）返回发生的错误。函数errorString（），lineNumber（），columnNumber（）和characterOffset（）用于构造适当的错误或警告消息。为了简化应用程序代码，QXmlStreamReader包含一个raiseError（）机制，使您可以引发触发描述的相同错误处理的自定义错误。

QXmlStream书签示例说明了如何使用递归下降技术通过流阅读器读取XML书签文件（XBEL）。

### Namespaces

QXmlStream理解并解析XML名称空间。例如。如果是StartElement，则namespaceUri（）返回元素所在的名称空间，而name（）返回元素的本地名称。 namespaceUri和name的组合唯一标识一个元素。如果阅读器解析的XML实体中未声明名称空间前缀，则namespaceUri为空。

如果您解析的XML数据没有根据XML规范使用命名空间，或者根本不使用命名空间，则可以改用元素的qualifiedName（）。限定名称是元素的prefix（），后跟冒号，然后是元素的本地name（），就像元素出现在原始XML数据中一样。由于将namespaceUri映射到前缀既不是唯一的也不是通用的，因此应避免使用符合名称空间的XML数据qualifiedName（）。

为了解析使用未声明的名称空间前缀的独立文档，可以使用namespaceProcessing属性完全关闭名称空间处理。

### Incremental parsing

QXmlStreamReader是一个**增量解析器**。它**可以处理无法一次全部解析文档的情况**，因为文档是成块到达的（例如，来自多个文件或通过网络连接）。当读者在分析完整个文档之前用完数据时，将报告PrematureEndOfDocumentError。*当由于调用addData（）或由于可以通过网络device（）获得更多数据而到达更多数据时，读取器将从PrematureEndOfDocumentError错误中恢复，并继续使用下一次对readNext（）的调用来解析新数据*。

例如，如果您的应用程序使用网络访问管理器从网络读取数据，则您将向网络管理器发出网络请求并收到网络回复。由于QNetworkReply是QIODevice，因此您可以将其readyRead（）信号连接到自定义插槽，例如有关QNetworkAccessManager的讨论中显示的代码段中的slotReadyRead（）。在此插槽中，您可以使用readAll（）读取所有可用数据，然后使用addData（）将其传递给XML流读取器。然后，调用自定义解析函数，该函数从阅读器读取XML事件。

### Performance and memory consumption

QXmlStreamReader在设计上是节省内存的，因为它不会将整个XML文档树存储在内存中，而是在报告时仅存储当前令牌。 此外，QXmlStreamReader避免了通常将XML文档映射到方便的Qt-ish API所需的许多小字符串分配。 它通过将所有字符串数据报告为QStringRef而不是实际的QString对象来做到这一点。 **QStringRef是QString子字符串的精简包装**，它提供了QString API的子集，而没有内存分配和引用计数开销。 在任何这些对象上调用toString（）会返回等效的实际QString对象。