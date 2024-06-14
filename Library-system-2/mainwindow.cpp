#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>//for file handling
#include <QMessageBox>//message windows
#include <QFile>//for file handling
#include <QVector>//so vectors can be used
#include <QString>//for user typed input
#include <QDebug>//check if things work
//created by Braedan M and Bernadette W
//preset system stuff
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
bool Login::bLogin(const QString username, const QString password){

    QFile file("users.txt");//opens the file
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
    if(login.bLogin(username, password)) {//if true display message and change page
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
bool Login::aLogin(const QString username, const QString password, const QString code){
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
    if(login.aLogin(username, password, code)) {
        QMessageBox::information(this, "Login Successful", "Logged in Successfully");
        ui->stackedWidget->setCurrentIndex(2);

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

void MainWindow::on_pushButton_bckaddmodB_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}



//Braedan M
//takes user input and adds a new book object in vector.
void MainWindow::on_pushButton_addBook_clicked()
{
    QString bookName = ui->lineEdit_bookTitle->text();
    QString bookAuthor = ui->lineEdit_bookAuthor->text();
    library.books.push_back(Book(bookName, bookAuthor));
    QMessageBox::information(this, "Book Added", "Book Added Successfully");
    qDebug() << "Button clicked!";
    qDebug() << "Book Name:" << bookName;
    qDebug() << "Book Author:" << bookAuthor;
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

void MainWindow::on_pushButton_bckaddmodbook_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushbutton_admin_a_book_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
//Braedan M
void MainWindow::on_pushbutton_admin_m_book_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
//outputs the contents of the vector
    QString str;
    for (const Book& book : library.books) {
        str += book.getTitle() + ", " + book.getAuthor() + "\n";
    }
//replaces the blank text edit with the output
    ui->plainTextEdit_bookVector->setPlainText(str);

    qDebug() << "Button clicked!";

}

//Braedan M
//this function makes it so when the text edit is edited it updates the vector in real time
void MainWindow::on_plainTextEdit_bookVector_textChanged()
{
    QString modifiedText = ui->plainTextEdit_bookVector->toPlainText();

    QStringList lines = modifiedText.split('\n');
    QVector<Book> updatedBooks;
    for (const QString& line : lines) {
//it will only save if it is typed as title, author
//these are recognised as 2 parts split by a comma and space
        QStringList parts = line.split(", ");
        if (parts.size() == 2) {
            QString title = parts[0];
            QString author = parts[1];
            updatedBooks.append(Book(title, author));
        }
    }
//updates the vector
    library.books = updatedBooks;
}


void MainWindow::on_pushButton_bookmod_clicked()
{
  QMessageBox::information(this, "Books Modifed", "Books Modifed Successfully!");
}




//Bernadette

void MainWindow::on_pushButton_feat_book_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButton_odr_book_clicked()
{
}


//Braedan M
void MainWindow::on_pushButton_addnewUser_clicked()
{
//converts user input to qstring
    QString username = ui->lineEdit_newUser->text();
    QString password = ui->lineEdit_newPass->text();
//opens (or creates if never run) the users.txt
    QFile file("users.txt");
    //if the file opens it will write to the file
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        qDebug() << "File opened successfully!";
        QTextStream out(&file);
        out << "\n" << username << " " << password;//writes to the file separated by a space and goes down a line
        file.close();//closes the file when it has finished
        QMessageBox::information(this, "User Added", "User Added Successfully");
    } else { //if it fails an error will appear
        qDebug() << "Error opening the file!";
        QMessageBox::critical(this, "Error", "Unable to open file for writing.");
    }
}

//Braedan M
void MainWindow::on_pushButton_modify_user_clicked()
{
    //this is similar to the book vector output but is for text
    ui->stackedWidget->setCurrentIndex(16);
    QFile file("users.txt");//opens the file
    if(file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "File opened successfully!";
    QString fileContents = file.readAll();//reads the text out
    ui->plainTextEdit_userList->setPlainText(fileContents);//chnages the plain text with the output
    } else {//if openining the file fails
        qDebug() << "Error opening the file!";
        QMessageBox::critical(this, "Error", "Unable to open file.");
    }
}


void MainWindow::on_pushButton_bckaddmodUser_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_plainTextEdit_userList_textChanged()
{
    //simiiar to the vector being changed from user input this is with text
    QString modifiedText = ui->plainTextEdit_userList->toPlainText();//takes the changes as a string
    QFile file("users.txt");//file is opened
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << modifiedText;//writes to the text file
        file.close();
    }  else {//error if it can't be opened
        qDebug() << "Error opening the file!";
        QMessageBox::critical(this, "Error", "Unable to open file.");
    }
}


void MainWindow::on_pushButton_userMod_clicked()
{
    QMessageBox::information(this, "Users Modifed", "Users Modifed Successfully!");
}

