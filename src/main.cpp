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


UPlatform* createPlatform(ListModel* parent, int id)
{
    UPlatform* platform = new UPlatform(parent);
    platform->id("id" + QString::number(id));
    platform->firmwareVersion("FirmwareVersion" + QString::number(id));
    platform->name("Name" + QString::number(id));
    platform->port(5000 + id);
    platform->room("Room" + QString::number(id));
    platform->enabled(true);
    platform->ip("192.168.0." + QString::number(id));
    parent->appendRow(platform);

    return platform;
}

UDevice* createDevice(ListModel* parent, int id)
{
    UDevice* device = new UDevice(parent);
    device->id("id" + QString::number(id));
    device->type(id);
    device->description("description" + QString::number(id));
    device->enabled(true);
    device->isTriggerValue(true);
    device->maxValue(0);
    device->minValue(id);
    device->name("name" + QString::number(id));
    device->precision(id);
    device->status(id);
    device->unitLabel("unitLabel" + QString::number(id));
    parent->appendRow(device);

    return device;
}

UScenario* createScenario(ListModel* parent, int id)
{
    UScenario* scenario = new UScenario(parent);
    scenario->id("id" + QString::number(id));
    scenario->name("name" + QString::number(id));
    scenario->active(true);
    parent->appendRow(scenario);

    return scenario;
}

UTask* createTask(ListModel* parent, int id)
{
    UTask* task = new UTask(parent);
    task->id("id" + QString::number(id));
    task->name("name" + QString::number(id));
    task->status(true);
    task->suspended(false);
    parent->appendRow(task);

    return task;
}

UCondition* createCondition(ListModel* parent, int id)
{
    UCondition* condition = new UCondition(parent);
    condition->id("id" + QString::number(id));
    parent->appendRow(condition);

    return condition;
}


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;

    NestedListModel* platforms = new NestedListModel(new UPlatform);

    UPlatform* platform1 = createPlatform(platforms, 1);
    UPlatform* platform2 = createPlatform(platforms, 2);
    UPlatform* platform3 = createPlatform(platforms, 3);

    ListModel* devices1 = platform1->nestedModel();
    ListModel* devices2 = platform2->nestedModel();
    ListModel* devices3 = platform3->nestedModel();

    UDevice* device1 = createDevice(devices1, 1);
    UDevice* device2 = createDevice(devices2, 2);
    UDevice* device3 = createDevice(devices3, 3);

    ListModel* scenarios1 = device1->nestedModel();
    ListModel* scenarios2 = device2->nestedModel();
    ListModel* scenarios3 = device3->nestedModel();

    UScenario* scenario1 = createScenario(scenarios1, 1);
    UScenario* scenario2 = createScenario(scenarios2, 2);
    UScenario* scenario3 = createScenario(scenarios3, 3);

    ListModel* tasks1 = scenario1->nestedModel();
    ListModel* tasks2 = scenario2->nestedModel();
    ListModel* tasks3 = scenario3->nestedModel();

    UTask* taks1 = createTask(tasks1, 1);
    UTask* taks2 = createTask(tasks2, 2);
    UTask* taks3 = createTask(tasks3, 3);

    ListModel* conditions1 = taks1->nestedModel();
    ListModel* conditions2 = taks2->nestedModel();
    ListModel* conditions3 = taks3->nestedModel();

    createCondition(conditions1, 1);
    createCondition(conditions2, 2);
    createCondition(conditions3, 3);

    QQmlContext* ctxt = viewer.rootContext();
    ctxt->setContextProperty("platformsModel", platforms);

    viewer.setSource(QUrl("qrc:///qml/main.qml"));
    viewer.show();

    return app.exec();
}
