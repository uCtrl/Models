import QtQuick 2.0

import "../devices" as Devices

Rectangle {

    color: "white"
    property variant model: null
    property variant marginSize: 20

    Text {
        id: name

        text: getName()

        color: "black"

        font.bold: true
        font.pixelSize: 20

        anchors.top: parent.top
        anchors.margins: marginSize

        anchors.left: parent.left
    }

    Row {
        id: enabledRow

        anchors.top: name.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 40

        Rectangle {
            color: "white"

            width: (parent.width / 2)
            height: parent.height

            Text {
                text: "Enabled"

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.margins: 20

                color: "#AAAAAA"
                font.pixelSize: 14
                font.bold: false
            }
        }

        Rectangle {
            color: "white"

            width: (parent.width / 2)
            height: parent.height

            Text {
                text: getEnabled()

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.margins: 20

                color: "black"
                font.pixelSize: 14
                font.bold: false
            }
        }
    }

    Row {
        id: roomRow

        anchors.top: enabledRow.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 40

        Rectangle {
            color: "white"

            width: (parent.width / 2)
            height: parent.height

            Text {
                text: "Location"

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.margins: 20

                color: "#AAAAAA"
                font.pixelSize: 14
                font.bold: false
            }
        }

        Rectangle {
            color: "white"

            width: (parent.width / 2)
            height: parent.height

            Text {
                text: getRoom()

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.margins: 20

                color: "black"
                font.pixelSize: 14
                font.bold: false
            }
        }
    }

    Devices.Devices {
        id: rectDevice

        model: getDevices()

        anchors.top: roomRow.bottom
        anchors.bottom: parent.bottom

        anchors.left: parent.left
        anchors.right: parent.right

        anchors.margins: parent.marginSize

        width: filters.width
    }

    function getName() {
        if (model != null) return model.name
        else return "Test"
    }

    function getEnabled() {
        if (model != null) return model.isEnabled
        else return "null"
    }

    function getRoom() {
        if (model != null) return model.room
        else return "null"
    }

    function getDevices() {
        if (model != null) return platforms.model.nestedModelFromId(model.id);
        else return null
    }
}
