#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include "abstractPanelWindow.h"
#include <QObject>
#include <QWidget>
#include "../../../widgets/panelWidgets/historyWidget.h"

class HistoryWindow : public AbstractPanelWindow
{
    Q_OBJECT

    HistoryWidget* panelWidget;

public:
    explicit HistoryWindow(QWidget* parent = nullptr);

    void setupUI() override;

    [[nodiscard]] double getValue() const;

    void setNumbers(const QVector<double>& _items);
    [[nodiscard]] QVector<double> getNumbers() const;

public slots:
    void clearMemory();
    void memoryPlus(double number);
    void memoryMinus(double number);

    void addNumber(double number);
};

#endif // HISTORYWINDOW_H
