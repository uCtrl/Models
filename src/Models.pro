TEMPLATE = app

include(qtquick2applicationviewer.pri)
qtcAddDeployment()

QT += qml quick

SOURCES += main.cpp \
    listmodel.cpp \
    nestedlistmodel.cpp \
    uplatform.cpp \
    udevice.cpp \
    uscenario.cpp \
    utask.cpp \
    ucondition.cpp

HEADERS += \
    listmodel.h \
    listitem.h \
    nestedlistitem.h \
    nestedlistmodel.h \
    uplatform.h \
    udevice.h \
    uscenario.h \
    utask.h \
    ucondition.h

OTHER_FILES += \
    main.qml

RESOURCES += \
    qml.qrc
