#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define FILENAME "D:\\FTP\\Program\\Qt\\tmp.bmp"

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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
