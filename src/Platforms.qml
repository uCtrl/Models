import QtQuick 2.0

Rectangle {

    id: platformsList

    color: "#EDEDED"

    property var marginSize: 20

    Rectangle {
        id: filters

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: parent.marginSize

        height: 40
        width: (parent.width/2) - parent.marginSize

        color: "yellow"
    }

    Rectangle {
        id: rectPlatforms

        anchors.top: filters.bottom
        anchors.bottom: parent.bottom

        anchors.left: parent.left

        anchors.margins: parent.marginSize

        width: filters.width

        color: "#EDEDED"

        ListView {
            id: platforms
            anchors.fill: parent
            model: platformsModel
            delegate: Column {
                width: parent.width
                Rectangle {
                    width: parent.width
                    height: 60

                    color: "white"

                    Text {
                        text: name

                        color: "black"

                        font.bold: true
                        font.pixelSize: 18

                        anchors.top: parent.top
                    }

                    Rectangle {
                        width: parent.width
                        height: 1

                        anchors.bottom: parent.bottom

                        color: "#D4D4D4"
                    }

                    MouseArea {
                        anchors.fill: parent
                        height: parent.height; width: parent.width;
                        onClicked: {
                            platformInfo.model = model
                        }
                    }
                }
            }
        }
    }

    Platform {
        id: platformInfo

        anchors.top: parent.top
        anchors.margins: parent.marginSize
        anchors.bottom: parent.bottom

        anchors.left: rectPlatforms.right
        anchors.right: parent.right

        width: (parent.width/2)
    }
}
