#include "customButton.h"

CustomButton::CustomButton(QWidget* parent) : QPushButton{parent}
{
    QFont basicFont;
    basicFont.setPixelSize(24);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setCursor(Qt::CursorShape::PointingHandCursor);
    setFont(basicFont);
    setStyleSheet("CustomButton{\n"
                  "    color: #ffffff;\n"
                  "    border: none;\n"
                  "    border-radius: 5px;\n"
                  "}\n"
                  "CustomButton:enabled{\n"
                  "    background: #2154B9;\n"
                  "}\n"
                  "CustomButton:enabled:hover{\n"
                  "    background: #1D4AA2;\n"
                  "}\n"
                  "CustomButton:disabled{\n"
                  "    background: #AED6F1;\n"
                  "}");
}
