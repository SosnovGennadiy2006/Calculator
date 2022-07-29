#include "abstractPanelWindow.h"

AbstractPanelWindow::AbstractPanelWindow(QWidget* parent) : HideWindow{parent}
{
    widgetLayout = new QVBoxLayout(privWidget);
}

void AbstractPanelWindow::setPanelWidget(AbstractPanelWidget* widget)
{
    panelWidget = widget;
    widgetLayout->addWidget(panelWidget, Qt::AlignCenter);
}