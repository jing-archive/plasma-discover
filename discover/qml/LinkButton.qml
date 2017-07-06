import QtQuick 2.2
import org.kde.kirigami 2.0 as Kirigami

Kirigami.Label {
    id: control

    property QtObject action: null //some older Qt versions don't support the namespacing in Kirigami.Action
    text: action ? action.text : ""
    enabled: !action || action.enabled
    onClicked: if (action) action.trigger()

    font: control.font
    color: enabled ? Kirigami.Theme.linkColor : Kirigami.Theme.textColor
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter

    signal clicked()
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onContainsMouseChanged: {
            control.font.underline = containsMouse && control.enabled
        }

        onClicked: control.clicked()
    }
}
