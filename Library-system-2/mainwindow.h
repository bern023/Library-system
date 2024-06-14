#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>//for stacked widgets/pages
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
//Braedan M
class Book{//the book class is so the book objects can be created
private://the variables are in the private access and can be accessed through the public functions
    QString title, author, amount;

public://public access that includes the constructor for the book object
    Book( const QString Title, const QString Author) : title(Title), author(Author){}
    //functions to access the book obkect private variables
    QString getTitle() const{
        return title;
    };
    QString getAuthor() const{
        return author;
    };
};
//Braedan M
class Library{//library class holds the vecotr of stored book objects
public:
    //the vector for book objects is created here
    QVector<Book> books;
};
//Bernadette
class FeatBook{
private:
    QString title, author;
    bool availability;

public:
    QString getTitle(){
        return title;
    }
    QString getAuthor(){
        return author;
    }
};
class BookLog{
public:
    FeatBook bleach, america, bones, unrest;
};

//Braedan M

class Login{//this is for the login functions
public:/*these are the functions used for login that take in user input
    and give a true or false if they are correct or not*/
    bool bLogin(const QString username, const QString password);
    bool aLogin(const QString username, const QString password, const QString code);
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    //when a slot is created, it is automatically declared here
    void on_pushButton_admin_clicked();

    void on_pushButton_bckhome_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_bckadmin_clicked();

    void on_pushButton_adminlogin_clicked();

    void on_pushButton_addmodBook_clicked();

    void on_pushButton_bckadminMan_clicked();

    void on_pushButton_bckadminMan_2_clicked();

    void on_pushButton_new_user_clicked();

    void on_pushButton_addmodUser_clicked();

    void on_pushButton_bckaddmodU_clicked();

    void on_pushButton_addBook_clicked();

    void on_pushButton_bckaddmodB_clicked();

    void on_pushButton_bckmenu_clicked();

    void on_pushButton_menu_clicked();

    void on_pushButton_account_clicked();

    void on_pushButton_bckaddmodbook_clicked();

    void on_pushbutton_admin_m_book_clicked();

    void on_pushbutton_admin_a_book_clicked();

    void on_plainTextEdit_bookVector_textChanged();

    void on_pushButton_bookmod_clicked();

    void on_pushButton_feat_book_1_clicked();

    void on_pushButton_odr_book_clicked();

    void on_pushButton_addnewUser_clicked();

    void on_pushButton_modify_user_clicked();

    void on_pushButton_bckaddmodUser_clicked();

    void on_plainTextEdit_userList_textChanged();

    void on_pushButton_userMod_clicked();

private:
    Ui::MainWindow *ui;
    //Braedan M
     Library library;//creating a library object
    Login login;//creating a login object
};



#endif // MAINWINDOW_H
