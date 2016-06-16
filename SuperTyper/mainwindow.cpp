#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coder.h"

#include "decoder.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Coder coder;
    ui->textBrowser->setText(coder.load(FILENAME, ui->textEdit->toPlainText().toStdString()));
    Decoder decoder;
    decoder.load(FILENAME);
    ui->textEdit->setText(decoder.get_text());
}
