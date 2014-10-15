import QtQuick 2.2
import QtQuick.Controls 1.0

Rectangle {
    Text {
        id: platLabel
        text: "PLATFORMS"
        color: "green"
    }

    Rectangle {
        id: rectPlat
        height: 100
        anchors.top: platLabel.bottom
        ListView {
            id: platforms
            anchors.fill: parent
            model: platformsModel
            delegate: Column {
                width: parent.width
                height: 20
                Text {
                    text: id + " | " + firmwareVersion + " | " + name + " | " + port + " | " + room + " | " + isEnabled + " | " + ip
                    wrapMode: Text.WordWrap
                    MouseArea {
                        anchors.fill: parent
                        height: parent.height; width: parent.width;
                        onClicked: {
                            console.log(model.id);
                            devices.model = platforms.model.nestedModelFromId(model.id);
                        }
                    }
                }
            }
        }
    }

    Text {
        id: devLabel
        anchors.top: rectPlat.bottom
        text: "DEVICES"
        color: "blue"
    }

    Rectangle {
        id: devRect
        anchors.top: devLabel.bottom
        height: 100
        ListView {
            id: devices
            anchors.fill: parent
            model: ""
            delegate: Column {
                width: parent.width
                height: 20

                Text {
                    text: id + " | " + type + " | " + description + " | " + isEnabled + " | " + isTriggerValue + " | " + maxValue + " | " + minValue + " | " + name + " | " + precision + " | " + status + " | " + unitLabel
                    wrapMode: Text.WordWrap
                    MouseArea {
                        anchors.fill: parent
                        height: parent.height; width: parent.width;
                        onClicked: {
                            console.log(id);
                            scenarios.model = devices.model.nestedModelFromId(model.id);
                        }
                    }
                }
            }
        }
    }

    Text {
        id: sceLabel
        anchors.top: devRect.bottom
        text: "SCENARIOS"
        color: "red"
    }

    Rectangle {
        id: sceRect
        anchors.top: sceLabel.bottom
        height: 100
        ListView {
            id: scenarios
            anchors.fill: parent
            model: ""
            delegate: Column {
                width: parent.width
                height: 20

                Text {
                    text: id + " | " + name + " | " + active
                    wrapMode: Text.WordWrap
                    MouseArea {
                        anchors.fill: parent
                        height: parent.height; width: parent.width;
                        onClicked: {
                            console.log(id);
                            tasks.model = scenarios.model.nestedModelFromId(model.id);
                        }
                    }
                }
            }
        }
    }

    Text {
        id: tasLabel
        anchors.top: sceRect.bottom
        text: "TASKS"
        color: "purple"
    }

    Rectangle {
        id: tasRect
        anchors.top: tasLabel.bottom
        height: 100
        ListView {
            id: tasks
            anchors.fill: parent
            model: ""
            delegate: Column {
                width: parent.width
                height: 20

                Text {
                    text: id + " | " + suspended + " | " + name + " | " + status
                    wrapMode: Text.WordWrap
                    MouseArea {
                        anchors.fill: parent
                        height: parent.height; width: parent.width;
                        onClicked: {
                            conditions.model = tasks.model.nestedModelFromId(model.id);
                        }
                    }
                }
            }
        }
    }

    Text {
        id: conLabel
        anchors.top: tasRect.bottom
        text: "CONDITIONS"
        color: "yellow"
    }

    Rectangle {
        id: conRect
        anchors.top: conLabel.bottom
        height: 100
        ListView {
            id: conditions
            anchors.fill: parent
            model: ""
            delegate: Column {
                width: parent.width
                height: 20

                Text {
                    text: id
                    wrapMode: Text.WordWrap
                }
            }
        }
    }

}


