#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>   //用于计时器
#include <QMovie>   //用于动图
#include <QKeyEvent>   //用于按键

#define A 2 //按键-显示 增益
#define FILENAME "D:\\FTP\\Program\\Qt\\tmp.bmp"    //用于加解密的文件位置
#define MOVIETIME 10000 //影片时长

using namespace std;
using namespace Qt;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_destroy_clicked();  //按钮_点击
    void time_trigger();    //定时_触发变色
    void showstop();    //定时_影片结束播放

private:
    Ui::MainWindow *ui;
    QTimer* timer = new QTimer(this);   //定时
    QTimer* showtime = new QTimer(this);    //播放计时
    QMovie* gif = new QMovie("D:/FTP/Program/Qt/test.gif"); //动图
    int cnt_Return = 0;
    void keyPressEvent(QKeyEvent* event);  //窗口_按键响应
};

#endif // MAINWINDOW_H
