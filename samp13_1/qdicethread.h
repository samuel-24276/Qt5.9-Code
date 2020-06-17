#ifndef QDICETHREAD_H
#define QDICETHREAD_H

#include <QThread>

class QDiceThread : public QThread
{
    Q_OBJECT
public:    
    QDiceThread();
    void diceBegin();//掷一次筛子
    void dicePause();//暂停
    void stopThread();//结束线程
private:
    int m_seq = 0;//掷筛子次数序号
    int m_diceValue;//筛子点数
    bool m_Paused = true;//暂停
    bool m_stop = false;//停止
protected:
    void run() Q_DECL_OVERRIDE;

signals:
    void newValue(int seq, int diceValue);//产生新点数的信号
public slots:
};

#endif // QDICETHREAD_H
