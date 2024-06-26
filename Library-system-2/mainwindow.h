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
    FeatBook( const QString FeatTitle, const QString FeatAuthor) : title(FeatTitle), author(FeatAuthor) {
        availability = 1;
    }
    QString getTitle(){
        return title;
    }
    void setTitle(QString bookTitle){
        title = bookTitle;
    }
    QString getAuthor(){
        return author;
    }
    void setAuthor(QString bookAuthor){
        author = bookAuthor;
    }
    bool getAvail(){
        return availability;
    }
    void setAvail(bool bookAvail){
        availability = bookAvail;
    }
};
class BookLog {
public:
    FeatBook bleach, america, bones, unrest;

    BookLog()
        : bleach("Bleach, vol.20", "Tite Kobe"),
        america("America", "Rachel Khong"),
        bones("Bones", "Renee Watson"),
        unrest("Unrest", "Erik Larson") {}
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

    void on_pushButton_feat_book_2_clicked();

    void on_pushButton_feat_book_3_clicked();

    void on_pushButton_feat_book_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_back_feat_book_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_menu_feat_book_1_clicked();

    void on_pushbutton_feat_book_1_return_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_feat_book_2_home_clicked();

    void on_pushButton_feat_book_2_menu_clicked();

    void on_pushButton_feat_book_2_order_clicked();

    void on_pushButton_feat_book_menu_clicked();

    void on_pushButton_feat_book_3_back_clicked();

    void on_pushButton_feat_book_3_home_clicked();

    void on_pushButton_feat_book_3_menu_clicked();

    void on_pushButton_feat_book_3_order_clicked();

    void on_pushButton_feat_book_3_return_clicked();

    void on_pushButton_feat_book_2_return_clicked();

    void on_pushButton_feat_book_4_back_clicked();

    void on_pushButton_feat_book_4_home_clicked();

    void on_pushButton_feat_book_4_menu_clicked();

    void on_pushButton_feat_book_4_order_clicked();

    void on_pushButton_feat_book_4_return_clicked();

    void on_pushbutton_returns_clicked();

    void on_pushButton_feat_book_2_back_clicked();

    void on_pushButton_featured_clicked();

    void on_pushButton_book_returns_back_clicked();


    void on_pushButton_preorderedbooks_clicked();

    void on_pushButton_bckhome_2_clicked();

    void on_pushButton_feat_book_back_2_clicked();

    void on_pushButton_logs_clicked();

    void on_pushButton_new_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_returnhomePage_clicked();

private:
    Ui::MainWindow *ui;
    //Braedan M
     BookLog booklog;
     Library library;//creating a library object
    Login login;//creating a login object

};



#endif // MAINWINDOW_H
