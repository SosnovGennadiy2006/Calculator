#include "historywidget.h"

HistoryWidget::HistoryWidget(QWidget *parent)
    : QWidget{parent}
{
    setFixedWidth(500);

    QFont basicFont;
    basicFont.setPixelSize(16);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);

    titleBarWidget = new QWidget(this);
    titleBarWidget->setFixedHeight(30);
    titleBarWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    titleBarWidget->setStyleSheet("background: #42aaff;");
    titleBarLayout = new QHBoxLayout(titleBarWidget);

    titleName = new QLabel(this);
    titleName->setText("Calculator history");
    titleName->setStyleSheet("color: #fff;");
    titleName->setFont(basicFont);

    titleBarSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    viewButton = new QPushButton(titleBarWidget);
    viewButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    viewButton->setText("X");
    viewButton->setStyleSheet("background: #0079db; color: #fff;");
    viewButton->setCursor(Qt::CursorShape::PointingHandCursor);

    closeButton = new QPushButton(titleBarWidget);
    closeButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    closeButton->setText("X");
    closeButton->setStyleSheet("background: #0079db; color: #fff;");
    closeButton->setCursor(Qt::CursorShape::PointingHandCursor);

    titleBarLayout->addWidget(titleName);
    titleBarLayout->addItem(titleBarSpacer);
    titleBarLayout->addWidget(viewButton);
    titleBarLayout->addWidget(closeButton);

    mainWidget = new QWidget(this);

    mainLayout->addWidget(titleBarWidget);
    mainLayout->addWidget(mainWidget, 100);
}
