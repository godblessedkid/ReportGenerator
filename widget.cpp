#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    mainCreator.addHeader();
    mainCreator.addTask(":/testData/testTask.csv");
    mainCreator.addLog(":/testData/testLog.csv");
    mainCreator.addPicture(":/testData/testImg.jpg");
    mainCreator.addPicture(":/testData/testImg2.jpg");
    mainCreator.setTemplate();
    mainCreator.printReport("test2.pdf");
    mainCreator.clearReport();
}

