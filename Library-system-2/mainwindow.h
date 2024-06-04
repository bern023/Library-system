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

   /* void page1Widget();
    void page2Widget();
*/

    void on_pushButton_admin_clicked();

    void on_pushButton_bckhome_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
