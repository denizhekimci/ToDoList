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
void Item::setEnterDate(QDateTime enterDate)
{
    EnterDate = enterDate;
}

void Item::setEndDate(QDateTime endDate)
{
    EndDate = endDate;
}

QString Item::getDescription()
{
    return Description;
}

QDateTime Item::getEnterDate()
{
    return EnterDate;
}

QDateTime Item::getEndDate()
{
    return EndDate;
}
