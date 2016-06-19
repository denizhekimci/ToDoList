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
    toDoModel = new QStandardItemModel(0,3,this);
    ui->toDoTreeView->setModel(toDoModel);
    doneModel = new QStandardItemModel(0,3,this);
    ui->doneTreeView->setModel(doneModel);


    QStringList list;
    list << "Task " << "Completion date" << "Date added ";
    toDoModel->setHorizontalHeaderLabels(list);
    doneModel->setHorizontalHeaderLabels(list);
    ui->toDoTreeView->header()->resizeSection(0,300);
    ui->doneTreeView->header()->resizeSection(0,300);
    ui->dateEdit->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addTask_clicked()
{
    int row = toDoModel->rowCount();
    toDoModel->insertRows(row,1);

    QModelIndex index = toDoModel->index(row,1);
    ui->toDoTreeView->setCurrentIndex(index);

    toDoModel->setData(index, ui->dateEdit->date());
    toDoModel->setData(toDoModel->index(row,2), QDate::currentDate());
}

void MainWindow::on_deleteTask_clicked()
{
    toDoModel->removeRows(ui->toDoTreeView->currentIndex().row(),1);
}

void MainWindow::on_delFinished_clicked()
{
    doneModel->removeRows(ui->doneTreeView->currentIndex().row(),1);
}

void MainWindow::on_sortAlpha_clicked()
{
    toDoModel->sort(0,Qt::AscendingOrder);

}

void MainWindow::on_markAsDone_clicked()
{
    QList<QStandardItem*> itemList = toDoModel->takeRow(ui->toDoTreeView->currentIndex().row());
    if(!itemList.isEmpty())
    {
        doneModel->appendRow(itemList);
        ui->doneTreeView->setModel(doneModel);
    }
}

void MainWindow::on_markAsUndone_clicked()
{
    QList<QStandardItem*> itemList = doneModel->takeRow(ui->doneTreeView->currentIndex().row());
    if(!itemList.isEmpty())
    {
        toDoModel->appendRow(itemList);
        ui->toDoTreeView->setModel(toDoModel);
    }
}

void MainWindow::on_sortEndDate_clicked()
{
    toDoModel->sort(1, Qt::AscendingOrder);
}

void MainWindow::on_sortAddDate_clicked()
{
    toDoModel->sort(2, Qt::AscendingOrder);
}



