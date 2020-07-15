import QtQuick 2.14
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.0

import SqlRelationalTableModel 1.0

Item {
    id: element
    property alias element: element
    property alias elementHeight: element.height
    property alias elementWidth: element.width
    property alias rectangle: rectangle
    property alias listView: listView
    property alias model: listView.model

    //    ListModel {
    //        id: driversTableModel
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //        ListElement {
    //            name: "Podvesotskiy"
    //            surname: "Andriy"
    //            passport_code: "00998877"
    //        }
    //    }
    Rectangle {
        id: rectangle
        color: "#303030"
        anchors.fill: parent

        ListView {
            id: listView
            width: 212
            height: 269
            orientation: ListView.Vertical
            clip: true
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            spacing: 5

            //model: driversModel //TODO: Set C++ model
            model: SqlRelationalTableModel {
                id: driversModel
                tableName: "drivers"
            }
            delegate: Rectangle {
                id: rectangle1
                width: parent.width
                height: 100
                color: "#232323"
                //border.color: Material.DeepOrange
                Text {
                    id: driverName
                    anchors.centerIn: parent
                    text: model.name + " " + model.surname
                    color: "white"
                }
                Text {
                    id: driverPasscode
                    text: model.passport_code
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: parent.height / 2 + driverName.height
                    color: "white"
                }
            }
        }
    }
}
/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.25;height:480;width:640}
}
##^##*/

