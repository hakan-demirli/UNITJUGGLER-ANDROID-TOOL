#include "mainwindow.h"
#include "ui_mainwindow.h"
static double multiplier_unit;
static double multiplier_unit_dest;
static QString unit_start;
static QString unit_dest;
static double output;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setInputMethodHints(Qt::ImhPreferNumbers);

    connect(ui->terahertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->megahertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->decahertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->gigahertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->hectohertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->milihertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->centihertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->petahertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->decihertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->hertz,      SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(ui->kilohertz, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    connect(ui->terahertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->megahertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->decahertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->gigahertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->hectohertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->milihertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->centihertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->petahertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->decihertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->hertz_2,      SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));
    connect(ui->kilohertz_2, SIGNAL(clicked()), this, SLOT(buttonClicked_dest()));


    connect(ui->minute, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked()));
    connect(ui->second, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked()));
    connect(ui->milisecond, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked()));
    connect(ui->microsecond, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked()));
    connect(ui->nanosecond, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked()));

    connect(ui->minute_2, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked_dest()));
    connect(ui->second_2, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked_dest()));
    connect(ui->milisecond_2, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked_dest()));
    connect(ui->microsecond_2, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked_dest()));
    connect(ui->nanosecond_2, SIGNAL(clicked()), this, SLOT(buttonPeriodClicked_dest()));

    multiplier_unit = 1;
    multiplier_unit_dest = 1;
    unit_dest = "hertz";
    unit_start = "hertz";
    output = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::buttonClicked()
{
    QPushButton *button = (QPushButton *)sender();
    QString unit = button->objectName();

    if(unit == "terahertz"){
        multiplier_unit = pow(10,12);
    }else if(unit == "megahertz"){
        multiplier_unit = pow(10,6);
    }else if(unit == "decahertz"){
        multiplier_unit = pow(10,1);
    }else if(unit == "gigahertz"){
        multiplier_unit = pow(10,9);
    }else if(unit == "hectohertz"){
        multiplier_unit = pow(10,2);
    }else if(unit == "milihertz"){
        multiplier_unit = pow(10,-3);
    }else if(unit == "centihertz"){
        multiplier_unit = pow(10,-2);
    }else if(unit == "petahertz"){
        multiplier_unit = pow(10,15);
    }else if(unit == "decihertz"){
        multiplier_unit = pow(10,-1);
    }else if(unit == "hertz"){
        multiplier_unit = pow(10,0);
    }else if(unit == "kilohertz"){
        multiplier_unit = pow(10,3);
    }else{
        unit = unit_start;
    }

    //ui->section_one->setText(number);
    QString i_from_user  = ui->lineEdit->text();
    i_from_user.remove(",");
    double final = 0;
    if(unit_dest.contains("hertz")){
        final = i_from_user.toDouble()*(multiplier_unit/multiplier_unit_dest);
    }else{
        final = ((1)/(multiplier_unit_dest*i_from_user.toDouble()*multiplier_unit));
    }
    output = final;
    QString outtext = QString().setNum(final, 'g', 15);


    int i = 0;
    if(-1 != outtext.lastIndexOf('.') || -1 != outtext.indexOf('-')){
        i = outtext.lastIndexOf('.');
    }else{
        i = outtext.length();
    }

    if(i >0 && outtext.toDouble()>1)
    {
       i -= 3;
       while(i > 0)
       {
         outtext.insert(i, ',');
         i -= 3;
       }
    }

    outtext = outtext.append(" ").append(unit_dest);
    //QString number = QString().setNum(multiplier_unit, 'g', 15);
    ui->lineEdit_2->setText(outtext);
    ui->section_one->setText(unit);
    unit_start = unit;
}


void MainWindow::buttonClicked_dest()
{
    QPushButton *button = (QPushButton *)sender();
    QString unit = button->objectName();

    if(unit == "terahertz_2"){
        multiplier_unit_dest = pow(10,12);
    }else if(unit == "megahertz_2"){
        multiplier_unit_dest = pow(10,6);
    }else if(unit == "decahertz_2"){
        multiplier_unit_dest = pow(10,1);
    }else if(unit == "gigahertz_2"){
        multiplier_unit_dest = pow(10,9);
    }else if(unit == "hectohertz_2"){
        multiplier_unit_dest = pow(10,2);
    }else if(unit == "milihertz_2"){
        multiplier_unit_dest = pow(10,-3);
    }else if(unit == "centihertz_2"){
        multiplier_unit_dest = pow(10,-2);
    }else if(unit == "petahertz_2"){
        multiplier_unit_dest = pow(10,15);
    }else if(unit == "decihertz_2"){
        multiplier_unit_dest = pow(10,-1);
    }else if(unit == "hertz_2"){
        multiplier_unit_dest = pow(10,0);
    }else if(unit == "kilohertz_2"){
        multiplier_unit_dest = pow(10,3);
    }

    QString i_from_user  = ui->lineEdit->text();
    i_from_user.remove(",");
    double final = 0;
    if(unit_start.contains("hertz")){
        final = i_from_user.toDouble()*(multiplier_unit/multiplier_unit_dest);
    }else{
        final = ((1)/(multiplier_unit_dest*i_from_user.toDouble()*multiplier_unit));
    }
    output = final;
    QString outtext = QString().setNum(final, 'g', 15);


    int i = 0;
    if(-1 != outtext.lastIndexOf('.') || -1 != outtext.indexOf('-')){
        i = outtext.lastIndexOf('.');
    }else{
        i = outtext.length();
    }

    if(i >0 && outtext.toDouble()>1)
    {
       i -= 3;
       while(i > 0)
       {
         outtext.insert(i, ',');
         i -= 3;
       }
    }
    outtext = outtext.append(" ").append(unit);
    //QString number = QString().setNum(multiplier_unit, 'g', 15);
    outtext.chop(2);
    unit.chop(2);
    ui->lineEdit_2->setText(outtext);
    ui->section_one_2->setText(unit);

    unit_dest = unit;
}


void MainWindow::buttonPeriodClicked(){

    QPushButton *button = (QPushButton *)sender();
    QString unit = button->objectName();

    if(unit == "minute"){
        multiplier_unit = 60;
    }else if(unit == "second"){
        multiplier_unit = 1;
    }else if(unit == "milisecond"){
        multiplier_unit = pow(10,-3);
    }else if(unit == "microsecond"){
        multiplier_unit = pow(10,-6);
    }else if(unit == "nanosecond"){
        multiplier_unit = pow(10,-9);
    }else{
        unit = unit_start;
    }

    QString i_from_user  = ui->lineEdit->text();
    i_from_user.remove(",");
    double final = 0;
    if(unit_dest.contains("hertz")){
        final = ((1)/(multiplier_unit_dest*i_from_user.toDouble()*multiplier_unit));
    }else{
        final = i_from_user.toDouble()*(multiplier_unit/multiplier_unit_dest);
    }
    output = final;
    QString outtext = QString().setNum(final, 'g', 15);




    int i = 0;
    if(-1 != outtext.lastIndexOf('.') || -1 != outtext.indexOf('-')){
        i = outtext.lastIndexOf('.');
    }else{
        i = outtext.length();
    }

    if(i >0 && outtext.toDouble()>1)
    {
       i -= 3;
       while(i > 0)
       {
         outtext.insert(i, ',');
         i -= 3;
       }
    }

    outtext = outtext.append(" ").append(unit_dest);
    //QString number = QString().setNum(multiplier_unit, 'g', 15);
    ui->lineEdit_2->setText(outtext);
    ui->section_one->setText(unit);
    unit_start = unit;

}

void MainWindow::buttonPeriodClicked_dest(){
    QPushButton *button = (QPushButton *)sender();
    QString unit = button->objectName();
    if(unit == "minute_2"){
        multiplier_unit_dest = 60;
    }else if(unit == "second_2"){
        multiplier_unit_dest = 1;
    }else if(unit == "milisecond_2"){
        multiplier_unit_dest = pow(10,-3);
    }else if(unit == "microsecond_2"){
        multiplier_unit_dest = pow(10,-6);
    }else if(unit == "nanosecond_2"){
        multiplier_unit_dest = pow(10,-9);
    }

    QString i_from_user  = ui->lineEdit->text();
    i_from_user.remove(",");
    double final = 0;
    if(unit_start.contains("hertz")){
        final = ((1)/(multiplier_unit_dest*i_from_user.toDouble()*multiplier_unit));
    }else{
        final = i_from_user.toDouble()*(multiplier_unit/multiplier_unit_dest);
    }
    output = final;
    QString outtext = QString().setNum(final, 'g', 15);

    int i = 0;
    if(-1 != outtext.lastIndexOf('.') || -1 != outtext.indexOf('-')){
        i = outtext.lastIndexOf('.');
    }else{
        i = outtext.length();
    }

    if(i >0 && outtext.toDouble()>1)
    {
       i -= 3;
       while(i > 0)
       {
         outtext.insert(i, ',');
         i -= 3;
       }
    }
    outtext = outtext.append(" ").append(unit);
    //QString number = QString().setNum(multiplier_unit, 'g', 15);
    outtext.chop(2);
    unit.chop(2);
    ui->lineEdit_2->setText(outtext);
    ui->section_one_2->setText(unit);

    unit_dest = unit;
}





void MainWindow::on_switch_2_clicked()
{
    std::swap(multiplier_unit,multiplier_unit_dest);
    std::swap(unit_start,unit_dest);
    double hold = ui->lineEdit->text().toDouble();
    std::swap(hold, output);

    ui->lineEdit->setText(QString().setNum(hold, 'g', 15));
    ui->lineEdit_2->setText(QString().setNum(output, 'g', 15).append(" ").append(unit_dest));
    ui->section_one->setText(unit_start);
    ui->section_one_2->setText(unit_dest);


}

void MainWindow::on_clear_clicked()
{
    output = 1;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();

}



void MainWindow::on_lineEdit_textEdited()
{
    if(unit_start.contains("hertz")){
        this->buttonClicked();
    }else if(unit_start.contains("second")){
        this->buttonPeriodClicked();
    }
}
