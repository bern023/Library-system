#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "classes.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
//Braedan M
//switches pages
void MainWindow::on_pushButton_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_bckhome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

bool MainWindow::bLogin(const QString email, const QString password){

    QFile file(":/Library-data/Users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(' ');
            if (parts.size() == 2 && parts[0] == email && parts[1] == password) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;

}
void MainWindow::on_pushButton_login_clicked()
{
    QString email = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(bLogin(email, password)) {
        QMessageBox::information(this, "Login Successful", "Logged in Successfully");
        ui->stackedWidget->setCurrentIndex(1);

    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid email or password");
    }

}


void MainWindow::on_pushButton_bckadmin_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}



