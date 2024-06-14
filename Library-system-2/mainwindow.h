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
class Book{
private:
    QString title, author, amount;

public:
    Book( const QString Title, const QString Author) : title(Title), author(Author){}

    QString getTitle() const{
        return title;
    };
    QString getAuthor() const{
        return author;
    };
};
//Braedan M
class Library{
public:

    QVector<Book> books;
};

//Braedan M

class Login{
public:
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


    void on_pushButton_addnewUser_clicked();

private:
    Ui::MainWindow *ui;
    //Braedan M
     Library library;
    Login login;
};



#endif // MAINWINDOW_H
