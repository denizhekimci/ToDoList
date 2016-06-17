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
void MainWindow::AddRoot(Item item)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0,item.getDescription());
    ui->treeWidget->addTopLevelItem(itm);
    AddChild(itm, item);
}

void MainWindow::RemoveRoot()
{
    QTreeWidgetItem *itm = ui->treeWidget->currentItem();
    if(itm)
        QMessageBox::question(this, "", "Are you sure you want to delete the item?", QMessageBox::Yes | QMessageBox::No);
    int i = ui->treeWidget->indexOfTopLevelItem(itm);
    ui->treeWidget->takeTopLevelItem(i);
    delete itm;
}

void MainWindow::AddChild(QTreeWidgetItem *parent,Item item)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,item.getEndDate().toString());
    parent->addChild(itm);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Item item;
    item.setDescription(ui->lineEdit->text());
    item.setEndDate(ui->dateEdit->date());
    data.append(item);
    ui->treeWidget->setColumnCount(1);
    AddRoot(data.last());
}

void MainWindow::on_pushButton_2_clicked()
{
    RemoveRoot();

}
