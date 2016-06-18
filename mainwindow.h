#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QTreeWidget>
#include "item.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QList<Item> toDoList;
    QList<Item> doneList;

    void AddRoot(Item item);
    void AddChild(QTreeWidgetItem *parent,Item item);
    void RemoveRoot();
    void moveTask(QTreeWidget *widget1, QTreeWidget *widget2, QList<Item> list1, QList<Item> list2);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
