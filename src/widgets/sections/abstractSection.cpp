#include "abstractSection.h"

AbstractSection::AbstractSection(QWidget *parent)
    : QWidget{parent}
{
    setMaximumSize(500, 500);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(8);
    effect->setXOffset(0);
    effect->setYOffset(0);
    effect->setColor(QColor(100, 100, 100));
    setGraphicsEffect(effect);

    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    tb = new ViewTitleBar(this);

    mainWidget = new QWidget(this);
    mainWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainWidget->setStyleSheet("QWidget{background: #fff;}");

    widgetLayout = new QVBoxLayout(mainWidget);

    mainLayout->addWidget(tb);
    mainLayout->addWidget(mainWidget, 1);

    connect(tb, &ViewTitleBar::closeRequest, this, [this](){
        emit closed();
    });
    connect(tb, &ViewTitleBar::viewBtnClicked, this, &AbstractSection::viewWindow);
}

void AbstractSection::setPanelWidget(AbstractPanelWidget* _panelWidget)
{
    panelWidget = _panelWidget;
    panelWidget->setParent(mainWidget);
    widgetLayout->addWidget(panelWidget);
}