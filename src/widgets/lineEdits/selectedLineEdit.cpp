//
// Created by genas on 30.07.2022.
//

#include "selectedLineEdit.h"

SelectedLineEdit::SelectedLineEdit(QWidget *parent) : QLineEdit(parent)
{
    _isSelected = false;

    QFont basicFont;
    basicFont.setPixelSize(42);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    setFont(basicFont);
    setAlignment(Qt::AlignmentFlag::AlignRight);
    setText("0");
    setStyleSheet("QLineEdit{"
                  "   border: 2px solid #555;"
                  "   border-radius: 5px;"
                  "   padding: 0px 0px -11px 0px;"
                  "}");
}

void SelectedLineEdit::focusInEvent(QFocusEvent *event)
{
    QLineEdit::focusInEvent(event);
    _isSelected = true;
    setStyleSheet("QLineEdit{"
                  "   border: 2px solid #2154B9;"
                  "   border-radius: 5px;"
                  "   padding: 0px 0px -11px 0px;"
                  "}");
    emit selected();
}

bool SelectedLineEdit::isSelected() const
{
    return _isSelected;
}

void SelectedLineEdit::setSelected(bool _selected)
{
    _isSelected = _selected;
    if (_isSelected)
    {
        setStyleSheet("QLineEdit{"
                      "   border: 2px solid #2154B9;"
                      "   border-radius: 5px;"
                      "   padding: 0px 0px -11px 0px;"
                      "}");
    }else
    {
        setStyleSheet("QLineEdit{"
                      "   border: 2px solid #555;"
                      "   border-radius: 5px;"
                      "   padding: 0px 0px -11px 0px;"
                      "}");
    }
}
