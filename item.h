#ifndef ITEM_H
#define ITEM_H

#include <QtCore>
#include <QtGui>
class Item : public QObject
{
    Q_OBJECT

public:
    explicit Item(QObject *parent = 0);

    QString Description;
    QDateTime EnterDate;
    QDateTime EndDate;

    QString getDescription();
    QDateTime getEnterDate();
    QDateTime getEndDate();

    void setDescription(QString desc);
    void setEnterDate(QDateTime enterDate);
    void setEndDate(QDateTime endDate);
};

#endif // ITEM_H
