import Qt 4.7
import QtQuick 1.0

Item {
    id: root
    height: 200

    Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Rectangle {
        id: rectOne
        width: 50
        height: 50
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 100
        color: "red"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.height = 200
            }
        }
    }

    Rectangle {
        width: 50
        height: 50
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 100
        color: "green"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.height = 100
                rectOne.color = QMLHelper.getRandomColor()
            }
        }
    }
}
