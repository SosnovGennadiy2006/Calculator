#include "historyPanelSection.h"

HistoryPanelSection::HistoryPanelSection(QWidget* parent) :
    AbstractPanelSection{new HistoryWidget(), parent}
{
    tb->setWindowIcon(QIcon(":/icons/history.png"));
    tb->setWindowTitle("History");
}

void HistoryPanelSection::viewWindow()
{
    hide();

    window = new HistoryWindow();

    window->setGeometry(mapToGlobal(QPointF(0, 0)).rx(),
                        mapToGlobal(QPointF(0, 0)).ry(),
                        width(), height());
    window->setMinimumSize(500, 500);

    window->show();

    connect(window, &HistoryWindow::closed, this, &HistoryPanelSection::closeWindow);
    connect(window, &HistoryWindow::hided, this, &HistoryPanelSection::hideWindow);

    emit HistoryPanelSection::viewed();
}

void HistoryPanelSection::closeWindow()
{
    emit windowClosed();
}

void HistoryPanelSection::hideWindow()
{
    show();
    window->close();

    emit windowHided();
}
