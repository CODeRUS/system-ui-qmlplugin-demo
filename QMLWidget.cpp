#include "QMLWidget.h"
#include "QMLHelper.h"
#include <QDeclarativeEngine>
#include <QDeclarativeView>
#include <QGraphicsObject>
#include <QDeclarativeComponent>
#include <QDeclarativeContext>
#include <QGraphicsLinearLayout>
#include <QImage>

QMLWidget::QMLWidget(MQExtensionsPlugin *extensionsPlugin,
                                               QGraphicsItem *parent) :
    QGraphicsWidget(parent),
    m_extensionsPlugin(extensionsPlugin)
{
    setObjectName("StatusIndicatorMenuExtensionContentItem");
    setMaximumWidth(480);
    setMinimumWidth(480);

    engine = new QDeclarativeEngine(this);
    context = new QDeclarativeContext(engine->rootContext());
    context->setContextProperty("QMLHelper", new QMLHelper(this));

    component = new QDeclarativeComponent(engine, QUrl::fromLocalFile("/usr/share/statusmenu-qmlplugin-demo/main.qml"));
    if (component->isLoading())
         QObject::connect(component, SIGNAL(statusChanged(QDeclarativeComponent::Status)),
                          this, SLOT(continueLoading()));
    else
         continueLoading();
}

void QMLWidget::continueLoading()
{
    if (component->isError()) {

    }
    else
    {
        QObject *myObject = component->create(context);
        myQML = qobject_cast<QGraphicsObject*>(myObject);
        if (myQML)
        {
            myQML->setParentItem(this);
            myQML->setProperty("width", 480);
            QDeclarativeProperty(myQML, "height").connectNotifySignal(this, SLOT(heightChanged()));
            heightChanged();
        }
    }
}

void QMLWidget::heightChanged()
{
    int height = myQML->property("height").toInt();
    setMinimumHeight(height);
    setMaximumHeight(height);
}

QMLWidget::~QMLWidget()
{
}
