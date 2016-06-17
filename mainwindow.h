#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <item.h>
#include <QtGui>
#include <QtCore>
#include <QTreeWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<QString> data;
    void AddRoot(QString item);
    void AddChild(QTreeWidgetItem *parent,QString item);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
