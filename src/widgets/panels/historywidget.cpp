#include "historywidget.h"

HistoryWidget::HistoryWidget(QWidget *parent)
    : AbstractPanel{parent}
{
    tb->setWindowIcon(QIcon(":/icons/history.png"));
    tb->setWindowTitle("Calculator history");

    connect(tb, &ViewTitleBar::closeRequest, this, [this](){ emit closed(); });
}
