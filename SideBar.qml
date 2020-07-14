import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

Item {
    width: 300
    height: 720
    Material.theme: "Dark"

    Rectangle {
        anchors.fill: parent
        color: '#191919'
        clip: true

        Rectangle {
            id: rectangle
            x: 181
            y: -23
            width: 200
            height: 100
            color: "#404040"
            rotation: 45
        }

    }
}
