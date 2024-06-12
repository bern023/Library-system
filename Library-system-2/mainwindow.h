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

    void on_pushButton_bckaddmodU_2_clicked();

    void on_pushButton_bckmenu_clicked();

    void on_pushButton_menu_clicked();

    void on_pushButton_account_clicked();

private:
    Ui::MainWindow *ui;
    //Braedan M
     bool bLogin(const QString username, const QString password);
     bool aLogin(const QString username, const QString password, const QString code);
};

class Book{
private:
    QString title, author;
    int amount;
public:
    Book(const QString title, const QString author, const int amount);
};

class Library{

public:
    //void addBook(QString title, QString author, int amount);
    QVector<Book> books;

};

#endif // MAINWINDOW_H
