#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "classes.h"
#include <QTextStream>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QVector>
#include <QString>


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
    //switches the active widget page in the index
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_bckhome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//Braedan M login file check
bool MainWindow::bLogin(const QString username, const QString password){

    QFile file(":/Library-data/Users.txt");//opens the file
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);//reads in the file
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(' ');//knows each text is seprated by a space
            if (parts.size() == 2 && parts[0] == username && parts[1] == password) {
                //declares how many "parts" on a line to check for and what each is
                file.close();//closes file on completion
                return true;
            }
        }
        file.close();
    }
    return false;

}
//Braedan M
//Convert user input to be checked and accept or deny
void MainWindow::on_pushButton_login_clicked()
{//converts user input to readble text in the system
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(bLogin(username, password)) {//if true display message and change page
        QMessageBox::information(this, "Login Successful", "Logged in Successfully");
        ui->stackedWidget->setCurrentIndex(7);

    } else {//if false display warning message
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
    }

}


void MainWindow::on_pushButton_bckadmin_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

//Braedan M admin login
bool MainWindow::aLogin(const QString username, const QString password, const QString code){
//same as basic log in but with an added code
    QFile file(":/Library-data/admin.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(' ');
            if (parts.size() == 3 && parts[0] == username && parts[1] == password && parts[2] == code) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;

}
//Braedan M
void MainWindow::on_pushButton_adminlogin_clicked()
{//same as basic but with added code
    QString username = ui->lineEdit_username_2->text();
    QString password = ui->lineEdit_password_2->text();
    QString code = ui->lineEdit_admincode->text();
    if(aLogin(username, password, code)) {
        QMessageBox::information(this, "Login Successful", "Logged in Successfully");
        ui->stackedWidget->setCurrentIndex(3);

    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username, password or code");
    }

}

//Braedan M
void MainWindow::on_pushButton_addmodBook_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

//Braedan M
void MainWindow::on_pushButton_bckadminMan_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_bckadminMan_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_new_user_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_pushButton_addmodUser_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_bckaddmodU_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_bckaddmodU_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

/*void Library::addBook(QString title, QString author, int amount){
    books.push_back(Book(title, author, amount));
}
*/

void MainWindow::on_pushButton_addBook_clicked()
{

    QString bookName = ui->lineEdit_bookTitle->text();
    QString bookAuthor = ui->lineEdit_bookAuthor->text();
    QString bookAmount = ui->lineEdit_bookAmount->text();
    library.books.push_back(Book(bookName, bookAuthor, bookAmount));

}

void MainWindow::on_pushButton_bckmenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_pushButton_account_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}



