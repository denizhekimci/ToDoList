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
    list << "Task: " << "Completion date:" << "Date added: ";
    toDoModel->setHorizontalHeaderLabels(list);
    doneModel->setHorizontalHeaderLabels(list);
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
    toDoModel->setData( toDoModel->index(row,2), QDate::currentDate());
}

void MainWindow::on_deleteTask_clicked()
{
    toDoModel->removeRows(ui->toDoTreeView->currentIndex().row(),1);
}

//void MainWindow::on_markAsUndone_clicked()
//{
//    QTreeWidgetItem *itm = ui->treeWidget_2->currentItem();

//    if(itm != NULL)
//    {
//        int i = ui->treeWidget_2->indexOfTopLevelItem(itm);

//        toDoList.append(doneList.at(i));

//        ui->treeWidget_2->takeTopLevelItem(i);
//        ui->treeWidget->addTopLevelItem(itm);

//        doneList.removeAt(i);
//    }
//}


//void MainWindow::on_delFinished_clicked()
//{
//    RemoveRoot(ui->treeWidget_2,doneList);
//}

void MainWindow::on_sortAlpha_clicked()
{
    toDoModel->sort(0,Qt::AscendingOrder);

}

void MainWindow::on_markAsDone_clicked()
{
    int row = toDoModel->rowCount();
    doneModel->insertRow(ui->doneTreeView->currentIndex().row());
    toDoModel->removeRow( ui->toDoTreeView->currentIndex().row());
}

void MainWindow::on_sortEndDate_clicked()
{
    toDoModel->sort(1, Qt::AscendingOrder);
}

void MainWindow::on_sortAddDate_clicked()
{
    toDoModel->sort(2, Qt::AscendingOrder);
}
