#include "viewTitlebar.h"

ViewTitleBar::ViewTitleBar(QWidget *parent)
    : QCustomTitleBar{parent}
{
    this->btnView.setIcon(QIcon(":/icons/view.png"));
    this->btnView.setObjectName("btnView");
    this->btnView.setMinimumSize(FRAME_BUTTON_SIZE);
    this->btnView.setCursor(Qt::CursorShape::PointingHandCursor);

    this->mLayout.insertWidget(3, &this->btnView);

    this->setWindowButtonEnabled(QCustomAttrs::Maximize, false);
    this->setWindowButtonEnabled(QCustomAttrs::Minimize, false);

    connect(&this->btnView, &QPushButton::clicked, this, [this](){ emit viewBtnClicked(); });
}
