import QtQuick 2.4
import App 1.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.0

Item {
    id: element
    width: 980
    height: 720
    property alias button: button
    property alias rectangle: rectangle
    property alias element: element

    Rectangle {
        id: rectangle
        color: "#303030"
        anchors.fill: parent

        ColumnLayout {
            width: 338
            height: 187
            spacing: 10
            anchors.verticalCenterOffset: -31
            anchors.horizontalCenterOffset: 0
            //columnSpacing: 30
            //rows: 2
            //columns: 2
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            TextField {
                id: loginTextField
                x: 359
                y: 292
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                scale: 1.3
                placeholderText: qsTr("Login")
            }

            TextField {
                id: passwordTextField
                x: 359
                y: 340
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                scale: 1.3
                placeholderText: qsTr("Password")
            }

            Button {
                id: button
                text: qsTr("Sign in")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }
    }
}

/*##^##
Designer {
    D{i:5;anchors_x:440;anchors_y:425}D{i:1;anchors_height:200;anchors_width:200;anchors_x:380;anchors_y:217}
}
##^##*/

