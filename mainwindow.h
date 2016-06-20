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
    void readJson();
    void read(const QJsonObject &json);
    void write() ;

    QJsonArray openJsonFile();

private slots:
    void on_addTask_clicked();

    void on_deleteTask_clicked();

    void on_markAsDone_clicked();

    void on_sortAlpha_clicked();

    void on_sortEndDate_clicked();

    void on_sortAddDate_clicked();

    void on_markAsUndone_clicked();

    void on_delFinished_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_sortPrior_clicked();

    void on_filterTask_clicked();

    void on_saveTasks_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *toDoModel;
    QStandardItemModel *doneModel;
    QSortFilterProxyModel *proxyModel;

    QDate minDate;
    QDate maxDate;
};

#endif // MAINWINDOW_H
