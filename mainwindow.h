#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>       /* pow */
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void buttonClicked();
    void buttonClicked_dest();
    void buttonPeriodClicked();
    void buttonPeriodClicked_dest();
    void on_switch_2_clicked();
    void on_clear_clicked();


    void on_lineEdit_textEdited();

private:
    Ui::MainWindow *ui;

signals:
        void textedited(QString);

private:
public:

};
#endif // MAINWINDOW_H
