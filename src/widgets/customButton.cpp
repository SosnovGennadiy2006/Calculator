#include "customButton.h"

CustomButton::CustomButton(QWidget* parent) : QPushButton{parent}
{
    QFont basicFont;
    basicFont.setPixelSize(24);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setCursor(Qt::CursorShape::PointingHandCursor);
    setFont(basicFont);
}
