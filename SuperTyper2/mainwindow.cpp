#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "decoder.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(time_trigger()));  //定时_链接响应
    connect(showtime, SIGNAL(timeout()), this, SLOT(showstop()));

    QPalette codetext_palette;  //画刷_备用
    codetext_palette.setColor(QPalette::Base, green);

    ui->codetext->setTextColor(green); //代码_设置颜色
    ui->label_gif->hide();  //动图_初始隐藏
    ui->label_gif->raise(); //让动图在顶层
    ui->destroy->hide();  //按钮_初始隐藏
    ui->destroy->raise();   //按钮_在顶层
    timer->start(500);  //定时_设置周期
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_destroy_clicked()   //按钮_点击
{
}

void MainWindow::time_trigger() //定时_触发变色
{
    static int cnt;
    cnt++;
    ui->destroy->setStyleSheet(cnt&1 ? "background-color: rgb(255, 0, 0)" : "background-color: rgb(255, 255, 255)");
}

void MainWindow::showstop() //定时_影片结束播放
{
    ui->label_gif->hide();
    showtime->stop();
    cnt_Return = 0;
}

void MainWindow::keyPressEvent(QKeyEvent* event)    //窗口_按键响应
{
    static int cnt_Letter;
    static Decoder decoder;
    switch(event->key())
    {
    case Key_Escape:
        exit(0);
    case Key_Return:
        if(cnt_Return)
        {
            ui->label_gif->show();
            ui->label_gif->setMovie(gif);
            gif->start();
            showtime->start(13000);
            ui->destroy->hide();
        }
        else
            ui->destroy->show();
        cnt_Return++;
        break;
    default:
        if(cnt_Letter)
        {
            char* tmp = new char[cnt_Letter + 1];
            strncpy(tmp, decoder.get_text(), cnt_Letter);
            tmp[cnt_Letter] = 0;
            ui->codetext->setText(tmp + decoder.adjust(cnt_Letter));
            delete [] tmp;
        }
        else
        {
            decoder.load(FILENAME);
        }
        cnt_Letter += A;
        break;
    }
}
