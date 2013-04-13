#include "QMLHelper.h"
#include <QTime>

QMLHelper::QMLHelper(QObject *parent)
    : QObject(parent)
{
    qsrand((uint)QTime::currentTime().msec());
}

QMLHelper::~QMLHelper()
{
}

int QMLHelper::randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

QColor QMLHelper::getRandomColor()
{
    return QColor(randInt(0,255), randInt(0,255), randInt(0,255));
}
