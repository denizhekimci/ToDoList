#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    if(itm){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "", "Are you sure you want to delete the item?", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            int i = ui->treeWidget->indexOfTopLevelItem(itm);
            ui->treeWidget->takeTopLevelItem(i);
            delete itm;
            toDoList.removeAt(i);
        }
    }
}

void MainWindow::AddChild(QTreeWidgetItem *parent,Item item)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,item.getEndDate().toString());
    parent->addChild(itm);
}

void MainWindow::moveTask(QTreeWidget *widget1, QTreeWidget *widget2, QList<Item> list1, QList<Item> list2)
{

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
    toDoList.append(item);
    ui->treeWidget->setColumnCount(1);
    AddRoot(toDoList.last());
}

void MainWindow::on_pushButton_2_clicked()
{
    RemoveRoot();

}


void MainWindow::on_pushButton_3_clicked()
{
    QTreeWidgetItem *itm = ui->treeWidget->currentItem();

    if(itm != NULL)
    {
        int i = ui->treeWidget->indexOfTopLevelItem(itm);
        ui->treeWidget->takeTopLevelItem(i);
        ui->treeWidget_2->addTopLevelItem(itm);

        toDoList.removeAt(i);
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    QTreeWidgetItem *itm = ui->treeWidget_2->currentItem();

    if(itm != NULL)
    {
        int i = ui->treeWidget_2->indexOfTopLevelItem(itm);
        ui->treeWidget_2->takeTopLevelItem(i);
        ui->treeWidget->addTopLevelItem(itm);

        doneList.removeAt(i);
    }
}
