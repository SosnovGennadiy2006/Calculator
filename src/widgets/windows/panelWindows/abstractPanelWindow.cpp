#include "abstractPanelWindow.h"

AbstractPanelWindow::AbstractPanelWindow(QWidget* parent) : HideWindow{parent}
{
    widgetLayout = new QVBoxLayout(privWidget);

    panelLayoutWidget = new QWidget(privWidget);
    panelLayout = new QHBoxLayout(panelLayoutWidget);

    widgetLayout->addWidget(panelLayoutWidget, Qt::AlignCenter);
}

void AbstractPanelWindow::setPanelWidget(AbstractPanelWidget* widget)
{
    panelWidget = widget;
    panelLayout->addWidget(panelWidget, Qt::AlignCenter);
}