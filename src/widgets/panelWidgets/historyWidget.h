#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>
#include <QSpacerItem>
#include <QScrollArea>
#include "../../widgets/panelWidgets/historyItem.h"
#include "../../widgets/panelWidgets/abstractPanelWidget.h"

class HistoryWidget : public AbstractPanelWidget
{
    Q_OBJECT

    QVector<double> items;

    QVBoxLayout* mainLayout;
    QLabel* isEmptyHistoryLabel;

    QScrollArea* mainArea;

    QWidget* itemsWidget;
    QVBoxLayout* itemsLayout;

public:
    explicit HistoryWidget(QWidget *parent = nullptr);

    void setupUI() override;
    void setupConnections() override;

    void setNumbers(const QVector<double>& _items);
    [[nodiscard]] QVector<double> getNumbers() const;

    [[nodiscard]] double getValue() const;

public slots:
    void addNumber(double number);
    void deleteNumber(HistoryItem* number_item);

    void memoryPlus(double number);
    void memoryMinus(double number);

    void clear();

signals:

};

#endif // HISTORYWIDGET_H
