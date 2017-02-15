/*
 *   Copyright (C) 2012 Aleix Pol Gonzalez <aleixpol@blue-systems.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library/Lesser General Public License
 *   version 2, or (at your option) any later version, as published by the
 *   Free Software Foundation
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library/Lesser General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import org.kde.kquickcontrolsaddons 2.0
import org.kde.discover.app 1.0
import QtQuick.Window 2.1
import org.kde.kcoreaddons 1.0
import "navigation.js" as Navigation
import org.kde.kirigami 2.0 as Kirigami

Kirigami.AbstractListItem
{
    id: delegateArea
    property alias application: installButton.application
    property bool compact: false

    function trigger() {
        if (ListView.view)
            ListView.view.currentIndex = index
        Navigation.openApplication(application)
    }
    highlighted: ListView.isCurrentItem
    Keys.onReturnPressed: trigger()
    onClicked: trigger()

    RowLayout {
        id: lowLayout
        anchors {
            left: parent.left
            right: parent.right
            margins: Kirigami.Units.largeSpacing
        }
        implicitHeight: conts.implicitHeight

        QIconItem {
            id: resourceIcon
            icon: application.icon

            readonly property real contHeight: lowLayout.height * 0.8
            Layout.minimumWidth: contHeight
            height: contHeight
            anchors.verticalCenter: parent.verticalCenter
        }

        ColumnLayout {
            id: conts
            Layout.fillWidth: true

            RowLayout {
                Layout.fillWidth: true
                Heading {
                    Layout.fillWidth: true
                    elide: Text.ElideRight
                    text: delegateArea.application.name
                    maximumLineCount: 1
                }
                Label {
                    Layout.fillWidth: true
                    elide: Text.ElideRight
                    horizontalAlignment: Text.AlignRight
                    text: delegateArea.application.categoryDisplay
                    color: Kirigami.Theme.linkColor
                    visible: conts.width > implicitWidth
                }
            }

            Rectangle {
                color: Kirigami.Theme.linkColor
                Layout.fillWidth: true
                height: Kirigami.Units.devicePixelRatio
            }

            Label {
                Layout.fillWidth: true

                elide: Text.ElideRight
                text: delegateArea.application.comment
                maximumLineCount: 1
                font: SystemFonts.titleFont
            }

            Label {
                Layout.fillWidth: true

                horizontalAlignment: Text.AlignJustify
                wrapMode: Text.WordWrap
                elide: Text.ElideRight
                textFormat: Text.StyledText
                text: delegateArea.application.longDescription
                maximumLineCount: delegateArea.compact ? 1 : 3
            }
            InstallApplicationButton {
                id: installButton
                Layout.alignment: Qt.AlignRight
                canUpgrade: false
            }
        }
    }
}
