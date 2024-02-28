#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    setWindowTitle("请选择你的英雄");

    picid=2;
    QPixmap pix("D:\\qtfiles\\QobjectTimer\\pic1.jpg");
    ui->label->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::timerEvent(QTimerEvent *event)
{
if(event->timerId()!=mytimerid)
    return;
QString path("D:\\qtfiles\\QobjectTimer\\pic");
    path+=QString::number(picid);
    path+=".jpg";

    QPixmap pix(path);
    ui->label->setPixmap(path);

    picid++;
    if(picid>4) picid=1;
}
void Widget::on_startButton_clicked()
{
    this->mytimerid = startTimer(TIMEOUT);
}


void Widget::on_stopButton_clicked()
{
    this->killTimer(mytimerid);
}

