#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"

#include <QQmlEngine>
#include <QQmlContext>
#include <QtQml>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickView>

#include "nestedlistitem.h"
#include "nestedlistmodel.h"
#include "uplatform.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;

    NestedListModel* platforms = new NestedListModel(new UPlatform);

    UPlatform* item1 = new UPlatform(platforms);
    item1->id("id1");
    item1->firmwareVersion("FirmwareVersion1");
    item1->name("Name1");
    item1->port(5001);
    item1->room("Room1");
    item1->enabled(true);
    item1->ip("192.168.0.1");

    ListModel* devices1 = item1->nestedModel();

    UDevice* subItem1 = new UDevice(devices1);
    subItem1->id("subId1");
    subItem1->type(1);
    subItem1->description("description1");
    subItem1->enabled(true);
    subItem1->isTriggerValue(true);
    subItem1->maxValue(0);
    subItem1->minValue(1);
    subItem1->name("name1");
    subItem1->precision(1);
    subItem1->status(1);
    subItem1->unitLabel("unitLabel1");
    devices1->appendRow(subItem1);

    UDevice* subItem2 = new UDevice(devices1);
    subItem2->id("subId2");
    subItem2->type(2);
    subItem2->description("description2");
    subItem2->enabled(true);
    subItem2->isTriggerValue(true);
    subItem2->maxValue(0);
    subItem2->minValue(2);
    subItem2->name("name2");
    subItem2->precision(2);
    subItem2->status(2);
    subItem2->unitLabel("unitLabel2");
    devices1->appendRow(subItem2);

    platforms->appendRow(item1);

    UPlatform* item2 = new UPlatform(platforms);
    item2->id("id2");
    item2->firmwareVersion("FirmwareVersion2");
    item2->name("Name2");
    item2->port(5002);
    item2->room("Room2");
    item2->enabled(false);
    item2->ip("192.168.0.2");
    platforms->appendRow(item2);

    ListModel* devices2 = item2->nestedModel();

    UDevice* subItem3 = new UDevice(devices2);
    subItem3->id("subId3");
    subItem3->type(3);
    subItem3->description("description3");
    subItem3->enabled(true);
    subItem3->isTriggerValue(true);
    subItem3->maxValue(0);
    subItem3->minValue(3);
    subItem3->name("name3");
    subItem3->precision(3);
    subItem3->status(3);
    subItem3->unitLabel("unitLabel3");
    devices2->appendRow(subItem3);

    UPlatform* item3 = new UPlatform(platforms);
    item3->id("id3");
    item3->firmwareVersion("FirmwareVersion3");
    item3->name("Name3");
    item3->port(5003);
    item3->room("Room3");
    item3->enabled(true);
    item3->ip("192.168.0.3");
    platforms->appendRow(item3);

    ListModel* devices3 = item3->nestedModel();

    UDevice* subItem4 = new UDevice(devices3);
    subItem4->id("subId4");
    subItem4->type(4);
    subItem4->description("description4");
    subItem4->enabled(true);
    subItem4->isTriggerValue(true);
    subItem4->maxValue(0);
    subItem4->minValue(4);
    subItem4->name("name4");
    subItem4->precision(4);
    subItem4->status(4);
    subItem4->unitLabel("unitLabel4");
    devices3->appendRow(subItem4);

    QQmlContext* ctxt = viewer.rootContext();
    ctxt->setContextProperty("platformsModel", platforms);

    viewer.setSource(QUrl("qrc:///main.qml"));
    viewer.show();

    return app.exec();
}
