#include "historyWindow.h"

HistoryWindow::HistoryWindow(QWidget* parent) : AbstractPanelWindow{parent}
{
    setupUI();
}

void HistoryWindow::setupUI()
{
    tb->setWindowIcon(QIcon(":/icons/history.png"));
    tb->setWindowTitle("History");
    setPanelWidget(new HistoryWidget(this));
}
