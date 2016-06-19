#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QTreeView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//    void AddRoot(Item item);
//    void AddChild(QTreeWidgetItem *parent,Item item);
//    void RemoveRoot(QTreeWidget *treeWidget, QList<Item> list);

//    void MainWindow::moveTask(QTreeWidget *widget1, QTreeWidget *widget2, QList<Item> list1, QList<Item> list2);

private slots:
    void on_addTask_clicked();

    void on_deleteTask_clicked();

    void on_markAsDone_clicked();

//    void on_markAsUndone_clicked();

//    void on_delFinished_clicked();

//    void on_pushButton_clicked();

    void on_sortAlpha_clicked();



    void on_sortEndDate_clicked();

    void on_sortAddDate_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *toDoModel;
    QStandardItemModel *doneModel;
};

#endif // MAINWINDOW_H
