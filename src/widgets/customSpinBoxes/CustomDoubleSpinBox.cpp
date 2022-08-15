//
// Created by genas on 02.08.2022.
//

#include "CustomDoubleSpinBox.h"

CustomDoubleSpinBox::CustomDoubleSpinBox(QWidget* parent) : QDoubleSpinBox{parent}
{
    QFont basicFont;
    basicFont.setPixelSize(24);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    setFont(basicFont);

    setStyleSheet("QDoubleSpinBox {\n"
                  "        padding-right: 15px;\n"
                  "        padding-bottom: -9px;\n"
                  "        border-radius: 3px;\n"
                  "        border: 1px solid #555;\n"
                  "}\n"
                  "QDoubleSpinBox::up-button {\n"
                  "        subcontrol-origin: border;\n"
                  "        subcontrol-position: top right;\n"
                  "        width: 16px;\n"
                  "        border: none;\n"
                  "        background: #2154B9;\n"
                  "        border-radius: 3px;\n"
                  "}\n"
                  "QDoubleSpinBox::up-button:hover {\n"
                  "        background: #1D4AA2;\n"
                  "}\n"
                  "QDoubleSpinBox::up-arrow {\n"
                  "        image: url(:/icons/arrow-up.png);\n"
                  "}\n"
                  "QDoubleSpinBox::down-button {\n"
                  "        subcontrol-origin: border;\n"
                  "        subcontrol-position: bottom right;\n"
                  "        width: 16px;\n"
                  "        border: none;\n"
                  "        background: #2154B9;\n"
                  "        border-radius: 3px;\n"
                  "}\n"
                  "QDoubleSpinBox::down-button:hover {\n"
                  "        background: #1D4AA2;\n"
                  "}\n"
                  "QDoubleSpinBox::down-arrow {\n"
                  "        image: url(:/icons/arrow-down.png);\n"
                  "}\n");
}
