#include "historyWidget.h"

HistoryWidget::HistoryWidget(QWidget *parent)
    : AbstractPanelWidget{parent}
{
    items = QVector<double>(0);

    setupUI();
    setupConnections();
}

void HistoryWidget::setupUI()
{
    setMaximumSize(1000, 700);

    QFont basicFont;
    basicFont.setPixelSize(24);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    mainLayout = new QVBoxLayout(this);

    isEmptyHistoryLabel = new QLabel(this);
    isEmptyHistoryLabel->setAlignment(Qt::AlignCenter);
    isEmptyHistoryLabel->setText("The history is empty!");
    isEmptyHistoryLabel->setFont(basicFont);
    isEmptyHistoryLabel->setStyleSheet("color: #DF1A2E;");

    mainArea = new QScrollArea(this);
    mainArea->setStyleSheet("QScrollArea{border:none;}");
    mainArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainArea->setWidgetResizable(true);

    itemsWidget = new QWidget(this);
    itemsWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    itemsLayout = new QVBoxLayout(itemsWidget);
    itemsLayout->setSpacing(0);
    itemsLayout->setContentsMargins(0, 0, 0, 0);

    mainArea->setWidget(itemsWidget);

    mainLayout->addWidget(isEmptyHistoryLabel, 1);
    mainLayout->addWidget(mainArea);
}

void HistoryWidget::setupConnections()
{

}

void HistoryWidget::setNumbers(const QVector<double>& _items)
{
    clear();
    for (auto& elem : _items)
    {
        addNumber(elem);
    }
}

QVector<double> HistoryWidget::getNumbers() const
{
    return items;
}

void HistoryWidget::clear()
{
    while (!itemsLayout->isEmpty())
    {
        deleteNumber(dynamic_cast<HistoryItem*>(itemsLayout->itemAt(0)->widget()));
    }
}

double HistoryWidget::getValue() const
{
    if (itemsLayout->isEmpty())
        return 0;
    return dynamic_cast<HistoryItem*>(itemsLayout->itemAt(0)->widget())->getValue();
}

void HistoryWidget::addNumber(double number)
{
    items.insert(0, number);

    HistoryItem* item = new HistoryItem(itemsWidget);
    item->setValue(number);

    itemsLayout->insertWidget(0, item);
    isEmptyHistoryLabel->hide();

    connect(item, &HistoryItem::deleted, this, [this, item](){ deleteNumber(item);});
}

void HistoryWidget::deleteNumber(HistoryItem *number_item)
{
    size_t idx = itemsLayout->indexOf(number_item);

    itemsLayout->removeWidget(number_item);
    items.erase(items.cbegin() + idx);

    delete number_item;

    if (itemsLayout->isEmpty())
    {
        isEmptyHistoryLabel->show();
    }
}

void HistoryWidget::memoryPlus(double number)
{
    if (!itemsLayout->isEmpty())
    {
        dynamic_cast<HistoryItem*>(itemsLayout->itemAt(0)->widget())->plus(number);
    }
}

void HistoryWidget::memoryMinus(double number)
{
    if (!itemsLayout->isEmpty())
    {
        dynamic_cast<HistoryItem *>(itemsLayout->itemAt(0)->widget())->minus(number);
    }
}