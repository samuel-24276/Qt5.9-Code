# QThread创建多线程程序

QThread是线程类，是实现多线程操作的核心类，一般从QThread继承定义自己的线程类。Qt还有Qt Concurrent模块，提供一些高级的API实现多线程编程而无需使用QMutex、QwaitCondition和QSemaphore等基础操作。

## 1.QThread类功能简介

QThread类提供不依赖于平台的管理线程的方法。**一个QThread类的对象管理一个线程，一般从QThread继承一个自定义类，并重定义虚函数run()，在run()函数里实现线程需要完成的任务。**    
QThread自身定义了start()和finished()两个信号，started()信号在线程开始执行之前发射，也就是在run()函数被调用之前，finished()信号在线程就要结束时发射。同时还定义了三个槽函数：
```
void quit()
void start(QThread::Priority priority = InheritPriority)
void terminate()
```
将应用程序的线程称为**主线程**，额外创建的线程称为**工作线程**。一般在主线程里创建工作线程，并调用start()开始执行工作线程的任务。start()会在内部调用run()函数，进入工作线程的事件循环，并在run()函数里调用exit()或quit()可以结束线程的事件循环，或者在主线程里调用terminate()强制结束线程。  
掷色子时将run()重写为：
```
void QDiceThread::run()
{
    //线程任务
    m_stop = false;
    m_seq = 0;
    qsrand(QTime::currentTime().msec());//随机数初始化，qsrand是线程安全的
    while(!m_stop)//循环主体
    {
        if(!m_Paused)
        {
            m_diceValue = qrand();//获取随机数
            m_diceValue = (m_diceValue % 6)+1;
            m_seq++;
            emit newValue(m_seq, m_diceValue);//发射信号
        }
        msleep(500);//线程休眠500ms
    }
    quit();//相当于exit(0),退出线程的事件循环
}
```
当然为了在窗口关闭时也能停止线程，我们需要重载closeEvent()事件，代码如下：
```
void Dialog::closeEvent(QCloseEvent * event)
{
    if(threadA.isRunning())
    {
        threadA.stopThread();
        threadA.wait();
    }
    event->accept();
}
```
QThread常用函数如下：
- isRunning(): 判断线程是否在运行，若是则返回true
- isFinished(): 判断线程是否已经停止，若是则返回true
- wait(unsigned long time = ULONG_MAX): 阻塞的是这个对象所在的线程（通常是主线程），参数可省略
- setPriority(QThread::Priority priority): 给线程设置优先级，共有7种优先级，如下表

|   Constant    |   Value    |  Description    |  
|   ---    |   :---:    |   ---    |
|QThread::IdlePriority|0|scheduled only when no other threads are running.|
|QThread::LowestPriority|1|scheduled less often than LowPriority.|
|QThread::LowPriority|2|scheduled less often than NormalPriority.|
|QThread::NormalPriority|3|the default priority of the operating system.|
|QThread::HighPriority|4|scheduled more often than NormalPriority.|
|QThread::HighestPriority|5|scheduled more often than HighPriority.|
|QThread::TimeCriticalPriority|6|scheduled as often as possible.|
|QThread::InheritPriority|7|use the same priority as the creating thread. This is the default.|

## 2.QThread的使用方法

- 1.不使用事件循环。这是官方的 Manual 、example 以及相关书籍中都介绍的一种的方法。
    - a.子类化 QThread
    - b.重载 run 函数，run函数内有一个 while 或 for 的死循环
    - c.设置一个标记为来控制死循环的退出。

- 2.使用事件循环。
    - a. 子类化 QThread，
    - b. 重载 run()函数，使其调用 `QThread::exec() `
    - c. 为该类定义信号和槽，槽函数并不会在新开的 thread 运行，很多人为了解决这个问题在构造函数中调用 moveToThread(this); 


