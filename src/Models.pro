TEMPLATE = app

include(qtquick2applicationviewer.pri)
qtcAddDeployment()

QT += qml quick

SOURCES += main.cpp \
    listmodel.cpp \
    nestedlistmodel.cpp \
    uplatform.cpp \
    udevice.cpp

HEADERS += \
    listmodel.h \
    listitem.h \
    nestedlistitem.h \
    nestedlistmodel.h \
    uplatform.h \
    udevice.h

OTHER_FILES += \
    main.qml

RESOURCES += \
    qml.qrc
