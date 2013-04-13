#ifndef QMLWIDGET_H
#define QMLWIDGET_H

#include <QGraphicsWidget>
#include <QDeclarativeEngine>
#include <QDeclarativeView>
#include <QGraphicsObject>
#include <QDeclarativeComponent>
#include <QDeclarativeContext>
#include <QGraphicsLinearLayout>
#include <QDeclarativeProperty>
#include <QObject>

#include "ExtensionPlugin.h"

class MStatusIndicatorMenuInterface;

class QMLWidget : public QGraphicsWidget
{
    Q_OBJECT

public:
    explicit QMLWidget(MQExtensionsPlugin *extensionsPlugin, QGraphicsItem *parent = NULL);
    virtual ~QMLWidget();

private:
    MQExtensionsPlugin *m_extensionsPlugin;

    QGraphicsWidget *myWidget;
    QGraphicsLinearLayout *layout;
    QDeclarativeEngine *engine;
    QDeclarativeContext *context;
    QDeclarativeComponent *component;
    QGraphicsObject* myQML;

private slots:
    void continueLoading();
    void heightChanged();
};

#endif // QMLWIDGET_H
