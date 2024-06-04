#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_admin, SIGNAL(clicked()), this,SLOT(page1Widget()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//switches pages
void MainWindow::on_pushButton_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_bckhome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

