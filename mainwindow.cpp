#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QDebug>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    toDoModel = new QStandardItemModel(0,4,this);
    ui->toDoTreeView->setModel(toDoModel);
    doneModel = new QStandardItemModel(0,4,this);
    ui->doneTreeView->setModel(doneModel);


    QStringList list;
    list << "Task " << "Completion date" << "Date added "<< "Priority";
    toDoModel->setHorizontalHeaderLabels(list);
    doneModel->setHorizontalHeaderLabels(list);
    ui->toDoTreeView->header()->resizeSection(0,200);
    ui->doneTreeView->header()->resizeSection(0,200);
    ui->dateEdit->setDate(QDate::currentDate());

    proxyModel = new QSortFilterProxyModel(this);

    proxyModel->setSourceModel(toDoModel);
    ui->toDoTreeView->setModel(proxyModel);

    QJsonArray jsonArray = openJsonFile();

    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        read(obj);
    }
}
QJsonArray MainWindow::openJsonFile()
{
    QString val;
    QFile file("C:/Users/Deniz Hekimci/Documents/QtWorkspace/ToDoList/data.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject item = d.object();
    QJsonArray jsonArray = item["tasks"].toArray();

    return jsonArray;
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

void MainWindow::on_sortPrior_clicked()
{
    toDoModel->sort(3, Qt::DescendingOrder);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    int row = ui->toDoTreeView->currentIndex().row();

    QModelIndex index = toDoModel->index(row,3);
    toDoModel->setData(index, arg1);
}

void MainWindow::on_filterTask_clicked()
{
    proxyModel->setFilterRegExp(QRegExp(ui->lineEdit->text(), Qt::CaseInsensitive,
                                        QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(0);
}

void MainWindow::read(const QJsonObject &json)
{
    int row = toDoModel->rowCount();
    toDoModel->insertRows(row,1);

    QModelIndex index = toDoModel->index(row,0);
    ui->toDoTreeView->setCurrentIndex(index);
    QJsonValue subobj1 = json["task"];
    toDoModel->setData(index, subobj1.toString());

    index = toDoModel->index(row,1);
    ui->toDoTreeView->setCurrentIndex(index);
    QJsonValue subobj2 = json["completionDate"];
    toDoModel->setData(index, QDate::fromString(subobj2.toString(), "d.M.yyyy" ));

    index = toDoModel->index(row,2);
    ui->toDoTreeView->setCurrentIndex(index);
    QJsonValue subobj3 = json["addDate"];
    toDoModel->setData(index, QDate::fromString(subobj3.toString(), "d.M.yyyy"));

    index = toDoModel->index(row,3);
    ui->toDoTreeView->setCurrentIndex(index);
    QJsonValue subobj4 = json["priority"];
    toDoModel->setData(index, subobj4.toString());

}


void MainWindow::write()
{
    QFile File("C:/Users/Deniz Hekimci/Documents/QtWorkspace/ToDoList/data.json");
    File.open(QIODevice::ReadOnly | QIODevice::Text);

    QJsonParseError JsonParseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(File.readAll(), &JsonParseError);

    File.close();

    QJsonObject rootObject = jsonDocument.object();
    QJsonArray array = rootObject.value("tasks").toArray();

    QJsonObject obj = array.at(0).toObject();

    int row = ui->toDoTreeView->currentIndex().row();

    QModelIndex index = toDoModel->index(row,0);
    QJsonValue val1 = QJsonValue(toDoModel->data(index).toString());
    obj.insert("task", val1);

    index = toDoModel->index(row,1);
    QJsonValue val2 = QJsonValue(toDoModel->data(index).toString());
    obj.insert("completionDate", val2);


    index = toDoModel->index(row,2);
    QJsonValue val3 = QJsonValue(toDoModel->data(index).toString());
    obj.insert("addDate", val3);

    index = toDoModel->index(row,3);
    QJsonValue val4 = QJsonValue(toDoModel->data(index).toString());
    obj.insert("priority", val4);

    array.insert(array.size(), obj);
    rootObject.insert("tasks", array);
    jsonDocument.setObject(rootObject);

    File.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    File.write(jsonDocument.toJson());
    File.close();
}


void MainWindow::on_saveTasks_clicked()
{
    write();
}
