#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
void MainWindow::AddRoot(QString item)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0,item);
    ui->treeWidget->addTopLevelItem(itm);
}

void MainWindow::AddChild(QTreeWidgetItem *parent,QString item)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

//    Item item;

//    item.setDescription(ui->lineEdit->text());
    data.push_back(ui->lineEdit->text());
    ui->treeWidget->setColumnCount(1);
    AddRoot(data.at(0));
}
