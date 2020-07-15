import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import Qt.labs.qmlmodels 1.0

import SqlRelationalTableModel 1.0

ApplicationWindow {
    id: window
    visible: true
    width: Constants.width
    height: Constants.height
    title: qsTr("Voyages Accounting")
    color: "#303030"

    Component.onCompleted: {
        //console.log("At root created: " + driversModel)
    }

    RowLayout {
        anchors.fill: parent
        SideBar { //Left-side menu
            Layout.alignment: Qt.AlignLeft
            Layout.fillHeight: true

            ListModel {
                id: sideMenuModel
                ListElement { title: "Головна" }
                ListElement { title: "Водії" }
                ListElement { title: "Транспорт" }
                ListElement { title: "Маршрути" }
                ListElement { title: "Рейси" }
                ListElement { title: "Про програму" }
            }

            ListView {
                id: list
                anchors.fill: parent
                anchors.topMargin: 150
                model: sideMenuModel
                spacing: 5

                focus: true
                highlightFollowsCurrentItem: true
                highlight: sideBarHighlight
                clip: true
                delegate: Rectangle {
                    width: parent.width
                    height: 50
                    color: "#232323"
                    Text {
                        anchors.centerIn: parent
                        text: model.title//title
                        font.pointSize: 16
                        color: "white"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: list.currentIndex = index
                    }
                }
                Component {
                    id: sideBarHighlight
                    Rectangle {
                        width: parent.width
                        height: 51
                        color: "transparent"
                        border.color: Material.color(Material.DeepOrange)
                        border.width: 3
                        z: 5
                    }
                }

            }
        }

        StackLayout {
            id: formStack
            currentIndex: list.currentIndex

            LoginForm {

            }
            DriversForm {
                //model: driversModel
            }
        }
    }
}






//    header: ToolBar {
//        contentHeight: toolButton.implicitHeight

//        ToolButton {
//            id: toolButton
//            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
//            font.pixelSize: Qt.application.font.pixelSize * 1.6
//            onClicked: {
//                if (stackView.depth > 1) {
//                    stackView.pop()
//                } else {
//                    drawer.open()
//                }
//            }
//        }

//        Label {
//            text: stackView.currentItem.title
//            anchors.centerIn: parent
//        }
//    }

//    TableView {
//        id: tableView
//    }


//    Drawer {
//        id: drawer
//        width: window.width * 0.66
//        height: window.height

//        Column {
//            anchors.fill: parent

//            ItemDelegate {
//                text: qsTr("Page 1")
//                width: parent.width
//                onClicked: {
//                    stackView.push("Page1Form.ui.qml")
//                    drawer.close()
//                }
//            }
//            ItemDelegate {
//                text: qsTr("Page 2")
//                width: parent.width
//                onClicked: {
//                    stackView.push("Page2Form.ui.qml")
//                    drawer.close()
//                }
//            }
//        }
//    }

//    StackView {
//        id: stackView
//        initialItem: "HomeForm.ui.qml"
//        anchors.fill: parent
//    }
