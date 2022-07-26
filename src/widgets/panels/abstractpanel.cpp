#include "abstractpanel.h"

AbstractPanel::AbstractPanel(QWidget *parent)
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
    mainWidget->setStyleSheet("background: #fff;");

    widgetLayout = new QVBoxLayout(mainWidget);

    mainLayout->addWidget(tb);
    mainLayout->addWidget(mainWidget, 1);
}
