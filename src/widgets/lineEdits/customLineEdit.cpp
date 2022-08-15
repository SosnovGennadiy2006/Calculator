//
// Created by genas on 29.07.2022.
//

#include "customLineEdit.h"

CustomLineEdit::CustomLineEdit(QWidget *parent) : QLineEdit(parent)
{
    QFont basicFont;
    basicFont.setPixelSize(42);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    setFont(basicFont);
    setAlignment(Qt::AlignmentFlag::AlignRight);
    setPlaceholderText("0");
    setStyleSheet("QLineEdit{"
            "   border: 2px solid #555;"
            "   border-radius: 5px;"
            "   padding: 0px 0px -11px 0px;"
            "}"
            "QLineEdit:focus{"
            "   border: 2px solid #2154B9;"
            "}");
}
