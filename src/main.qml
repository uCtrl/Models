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
                    text: id +" | " + firmwareVersion + " | " + name + " | " + port + " | " + room + " | " + isEnabled + " | " + ip
                    wrapMode: Text.WordWrap
                    MouseArea {
                        anchors.fill: parent
                        height: parent.height; width: parent.width;
                        onClicked: {
                            console.log(model.id);
                            devices.model = platformsModel.nestedModelFromId(model.id);
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
                    text: id +" | " + type + " | " + description + " | " + isEnabled + " | " + isTriggerValue + " | " + maxValue + " | " + minValue + " | " + name + " | " + precision + " | " + status + " | " + unitLabel
                    wrapMode: Text.WordWrap
                }
            }
        }
    }
}


