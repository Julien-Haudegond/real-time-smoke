import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import SceneGraphRendering 1.0

ApplicationWindow {
    title: qsTr("Smoke")
    visible: true

    width: 1440
    height: 720
    minimumWidth: 600
    minimumHeight: 500

    RowLayout {
        anchors.fill: parent

        ColumnLayout {
            id : column1

            anchors.fill: parent
            Layout.fillWidth: true
            Layout.minimumWidth: 400
            Layout.maximumWidth: 2000


                        Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredHeight: 100
                color: "blue"

                Text {
                    text: "This rectangle is a QML Item !"
                    color: "white"
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                ListView {
                    width: 180; height: 200
                    model: fbo.sdfRendererProperties.attributes

                    delegate: Slider {
                        value: object.value
                        from : 0
                        to : 1
                        stepSize : 0.01
                        onMoved: {
                            object.value = value
                        }
                    }
                }
            }



            MyQuickFBO {
                id: fbo
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredHeight: 380
                MouseArea {
                    anchors.fill: parent
                    onPressed: fbo.onMousePress()
                    onReleased: fbo.onMouseRelease()
                    onWheel: fbo.onWheelScroll(wheel.angleDelta.y / 120)
                    onPositionChanged: if (pressed) fbo.update()
                }
            }


        }

        ColumnLayout {
            id : column2
            anchors.left: column1
            Layout.fillWidth: true
            Layout.minimumWidth: 200
            Layout.maximumWidth: 2000


            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredHeight: 100
                color: "blue"

                Text {
                    text: "This rectangle is a QML Item !"
                    color: "white"
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
}