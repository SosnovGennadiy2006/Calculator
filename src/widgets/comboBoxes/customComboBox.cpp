//
// Created by genas on 30.07.2022.
//

#include "customComboBox.h"

CustomComboBox::CustomComboBox(QWidget *parent) : QComboBox{parent}
{
    QFont basicFont;
    basicFont.setPixelSize(24);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    setFont(basicFont);
    setCursor(Qt::PointingHandCursor);

    setStyleSheet("QComboBox {\n"
    "    border-radius: 5px;\n"
    "    padding: 1px 5px 1px 3px;\n"
    "    color: #fff;\n"
    "}\n"
    "QComboBox:!editable, QComboBox::drop-down:editable {\n"
    "    background: #2154B9;\n"
    "}\n"
    "QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
    "    background: #1D4AA2;\n"
    "}\n"
    "QComboBox::drop-down {\n"
    "        subcontrol-origin: padding;\n"
    "        subcontrol-position: top right;\n"
    "        width: 24px;\n"
    "        border-left-width: 1px;\n"
    "        border-left-color: #fff;\n"
    "        border-left-style: solid;\n"
    "        border-top-right-radius: 5px;\n"
    "        border-bottom-right-radius: 5px;\n"
    "}\n"
    "QComboBox::down-arrow {\n"
    "        image: url(:/icons/expand.png);\n"
    "}\n"
    "QComboBox QAbstractItemView {\n"
    "   border: none;\n"
    "   border-bottom-left-radius: 3px;\n"
    "   border-bottom-right-radius: 3px;\n"
    "   border-top-right-radius: 3px;\n"
    "   selection-background-color: #2154B9;\n"
    "}\n");
}