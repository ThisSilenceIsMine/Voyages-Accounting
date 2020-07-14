pragma Singleton
import QtQuick 2.0
import QtQuick.Window 2.12

QtObject {
    readonly property int width: 1280//Screen.desktopAvailableWidth
    readonly property int height: 720//Screen.desktopAvailableHeight
    readonly property int leftSideBarWidth: 300
    readonly property int stackWidth: width - leftSideBarWidth
    readonly property color formColor: "#303030"
}
