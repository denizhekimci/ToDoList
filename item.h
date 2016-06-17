#ifndef ITEM_H
#define ITEM_H
#include <QtCore>
#include <QtGui>
#include <QApplication>

class Item
{
public:
    Item();
    QString Description;
    QDate EnterDate;
    QDate EndDate;

    QString getDescription();
    QDate getEnterDate();
    QDate getEndDate();

    void setDescription(QString desc);
    void setEnterDate(QDate enterDate);
    void setEndDate(QDate endDate);
};

#endif // ITEM_H
