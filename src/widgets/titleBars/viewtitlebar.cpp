#include "viewtitlebar.h"

ViewTitleBar::ViewTitleBar(QWidget *parent)
    : QCustomTitleBar{parent}
{
    state = true;

    this->btnView.setIcon(QIcon(":/icons/view.png"));
    this->btnView.setObjectName("btnView");
    this->btnView.setMinimumSize(FRAME_BUTTON_SIZE);
    this->btnView.setCursor(Qt::CursorShape::PointingHandCursor);

    this->mLayout.insertWidget(3, &this->btnView);

    this->setWindowButtonEnabled(QCustomAttrs::Maximize, false);
    this->setWindowButtonEnabled(QCustomAttrs::Minimize, false);

    view();
}

void ViewTitleBar::view()
{
    state = !state;
    if (state)
    {
        btnView.setIcon(QIcon(":/icons/hide.png"));
        this->setWindowButtonEnabled(QCustomAttrs::Maximize, true);
        this->setWindowButtonEnabled(QCustomAttrs::Minimize, true);
    }else
    {
        btnView.setIcon(QIcon(":/icons/view.png"));
        this->setWindowButtonEnabled(QCustomAttrs::Maximize, false);
        this->setWindowButtonEnabled(QCustomAttrs::Minimize, false);
    }
    emit viewBtnClicked();
}
