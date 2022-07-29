#include "abstractPanelWidget.h"

AbstractPanelWidget::AbstractPanelWidget(QWidget *parent)
    : QWidget{parent}
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
