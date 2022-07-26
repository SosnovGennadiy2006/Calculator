#include "customButton.h"

CustomButton::CustomButton(QWidget* parent) : QPushButton{parent}
{
    QFont basicFont;
    basicFont.setPixelSize(24);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setCursor(Qt::CursorShape::PointingHandCursor);
    setFont(basicFont);
    setStyleSheet("CustomButton{"
                  "    background: #2154B9;"
                  "    color: #ffffff;"
                  "    border: none;"
                  "    border-radius: 5px;"
                  "}"
                  "CustomButton:hover{"
                  "    background: #1D4AA2;"
                  "}");
}
