#include "hideTitlebar.h"

HideTitleBar::HideTitleBar(QWidget *parent)
    : QCustomTitleBar{parent}
{
    this->btnHide.setIcon(QIcon(":/icons/hide.png"));
    this->btnHide.setObjectName("btnView");
    this->btnHide.setMinimumSize(FRAME_BUTTON_SIZE);
    this->btnHide.setCursor(Qt::CursorShape::PointingHandCursor);

    this->mLayout.insertWidget(3, &this->btnHide);

    connect(&this->btnHide, &QPushButton::clicked, this, [this](){ emit hideBtnClicked(); });
}
