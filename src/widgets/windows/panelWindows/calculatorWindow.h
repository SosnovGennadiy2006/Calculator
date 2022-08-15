#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include "abstractPanelWindow.h"
#include <QObject>
#include <QWidget>
#include "../../../widgets/panelWidgets/calculatorWidget.h"

class CalculatorWindow : public AbstractPanelWindow
{
    Q_OBJECT

    CalculatorWidget* panelWidget;

public:
    explicit CalculatorWindow(QWidget* parent = nullptr);

    void setupUI() override;
    void setupConnections();

    void setLineEditText(const QString& newText);
    [[nodiscard]] QString getLineEditText() const;

    void showExtraButtons();
    void hideExtraButtons();

signals:
    void memoryClearBtnClicked();
    void memoryStoreBtnClicked();
    void memoryRestoreBtnClicked();
    void memoryPlusBtnClicked();
    void memoryMinusBtnClicked();

public slots:
    void memoryRestore(const QString& text);
};

#endif // CALCULATORWINDOW_H
