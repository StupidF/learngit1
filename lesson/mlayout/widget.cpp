#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMaximumSize(400,300);
    this->setMinimumSize(400,300);
    QObject::connect(ui->cmdLineEdit,SIGNAL(returnPressed()),this,SLOT(on_submithButton_clicked()));
   // QObject::connect(ui->cmdLineEdit,SIGNAL(returnPressed(),this,SLOT(on_submithButton_clicked()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_submithButton_clicked()
{
    QProcess *process=new QProcess;
    QString startProgram=ui->cmdLineEdit->text();
    process->start(startProgram.trimmed());
    ui->cmdLineEdit->clear();
//    this->close();
}
