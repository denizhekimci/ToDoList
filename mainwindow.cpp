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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    data.push_back(ui->lineEdit->text());
    QMessageBox::information(this, "title", data.at(0));
}
