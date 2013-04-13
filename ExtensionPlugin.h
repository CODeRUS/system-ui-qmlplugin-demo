#ifndef APPLICATIONEXTENSIONPLUGIN_H
#define APPLICATIONEXTENSIONPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <MLibrary>
#include <MStatusIndicatorMenuExtensionInterface>
#include <MApplicationExtensionInterface>
#include <QGraphicsWidget>

class QMLWidget;

class MQExtensionsPlugin : public QObject, public MStatusIndicatorMenuExtensionInterface
{
    Q_OBJECT
    Q_INTERFACES(MStatusIndicatorMenuExtensionInterface MApplicationExtensionInterface)

public:
    explicit MQExtensionsPlugin(QObject *parent = 0);
    MStatusIndicatorMenuInterface *statusIndicatorMenuInterface() const;
    virtual void setStatusIndicatorMenuInterface(MStatusIndicatorMenuInterface &menuInterface);
    virtual bool initialize(const QString &interface);
    virtual QGraphicsWidget *widget();

private:
    MStatusIndicatorMenuInterface *statusIndicatorMenu;
    QMLWidget *qmlWidget;
};

#endif // APPLICATIONEXTENSIONPLUGIN_H
