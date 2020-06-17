#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(add()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(add()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(add()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(add()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add()
{
    QPushButton *button = (QPushButton *)sender();
    if((ui->progressBar->value() + button->text().toInt()) > 100){
        ui->progressBar->setValue(100);
    }else{
        ui->progressBar->setValue(ui->progressBar->value() + button->text().toInt());
    }
}

