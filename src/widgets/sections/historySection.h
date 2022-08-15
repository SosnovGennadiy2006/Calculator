#ifndef HISTORYPANELSECTION_H
#define HISTORYPANELSECTION_H

#include "abstractSection.h"
#include <QObject>
#include <QWidget>
#include "../../widgets/panelWidgets/historyWidget.h"
#include "../../widgets/windows/panelWindows/historyWindow.h"

class HistorySection : public AbstractSection
{
    Q_OBJECT

    HistoryWindow* window;
    HistoryWidget* panelWidget;

public:
    explicit HistorySection(QWidget* parent = nullptr);

    [[nodiscard]] double getValue() const;

protected slots:
    void viewWindow() override;
    void closeWindow() override;
    void hideWindow() override;

public slots:
    void clearMemory();
    void memoryPlus(double number);
    void memoryMinus(double number);

    void addNumber(const QString& number);
};

#endif // HISTORYPANELSECTION_H
