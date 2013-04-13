#ifndef QMLHELPER_H
#define QMLHELPER_H

#include <QObject>
#include <QColor>

class QMLHelper : public QObject
{
    Q_OBJECT

public:
    QMLHelper(QObject *parent = 0);
    virtual ~QMLHelper();

    Q_INVOKABLE QColor getRandomColor();

private:
    int randInt(int low, int high);
};

#endif // QMLHELPER_H
