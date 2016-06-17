#include "item.h"
#include <QtCore>
#include <QtGui>
Item::Item()
{

}

void Item::setDescription(QString desc)
{
    Description = desc;
}
void Item::setEnterDate(QDate enterDate)
{
    EnterDate = enterDate;
}

void Item::setEndDate(QDate endDate)
{
    EndDate = endDate;
}

QString Item::getDescription()
{
    return Description;
}

QDate Item::getEnterDate()
{
    return EnterDate;
}

QDate Item::getEndDate()
{
    return EndDate;
}
