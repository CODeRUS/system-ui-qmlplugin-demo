TEMPLATE      = lib
QT += core dbus declarative gui
CONFIG       += plugin gui meegotouch

INCLUDEPATH += $$(SYSROOT_DIR)/usr/include/meegotouch
INCLUDEPATH += $$(SYSROOT_DIR)/usr/include/system-ui/statusindicatormenu

TARGET        = statusindicatormenu-qmlplugin-demo
target.path = /usr/lib/meegotouch/applicationextensions

desktop.files = statusindicatormenu-qmlplugin-demo.desktop
desktop.path = /usr/share/meegotouch/applicationextensions

qml.files = qml/main.qml
qml.path = /usr/share/statusmenu-qmlplugin-demo

INSTALLS += target desktop qml

HEADERS += \
    ExtensionPlugin.h \
    QMLWidget.h \
    QMLHelper.h

SOURCES += \
    ExtensionPlugin.cpp \
    QMLWidget.cpp \
    QMLHelper.cpp

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    qtc_packaging/debian_harmattan/prerm \
    qtc_packaging/debian_harmattan/preinst \
    qtc_packaging/debian_harmattan/postrm \
    qtc_packaging/debian_harmattan/postinst
