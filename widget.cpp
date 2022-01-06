#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money>=200);
    ui->pbTea->setEnabled(money>=150);
    ui->pbMilk->setEnabled(money>=100);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Here is your change");

    //Calculating the number of 500 coin
    int coin500 = money / 500;
    money = money - 500 * coin500;
    //Calculating the number of 100 coin
    int coin100 = money / 100;
    money = money - 100 * coin100;
    //Calculating the number of 50 coin
    int coin50 = money / 50;
    money = money - 50 * coin50;
    //Calculating the number of 10 coin
    int coin10 = money / 10;
    money = money - 10 * coin10;
    //money reset. (to zero)
    changeMoney(money);

    //information string about number of each coins.
    char str[] = "%d 500 coin(s)\n%d 100 coin(s)\n%d 50 coin(s)\n%d 10 coin(s)\n returned.";
    sprintf(str, str, coin500, coin100, coin50, coin10);

    msgBox.setText(str);
    msgBox.exec();
}

