#include "ExtensionPlugin.h"
#include "QMLWidget.h"

Q_EXPORT_PLUGIN2(qmlwidget-demo, MQExtensionsPlugin)

MQExtensionsPlugin::MQExtensionsPlugin(QObject *parent) :
    statusIndicatorMenu(0),
    qmlWidget(0)
{
    Q_UNUSED(parent)
}

void MQExtensionsPlugin::setStatusIndicatorMenuInterface(MStatusIndicatorMenuInterface &menuInterface)
{
    statusIndicatorMenu = &menuInterface;
}

MStatusIndicatorMenuInterface *MQExtensionsPlugin::statusIndicatorMenuInterface() const
{
    return statusIndicatorMenu;
}

bool MQExtensionsPlugin::initialize(const QString &)
{
    qmlWidget = new QMLWidget(this);

    return true;
}

QGraphicsWidget *MQExtensionsPlugin::widget()
{
    return qmlWidget;
}
