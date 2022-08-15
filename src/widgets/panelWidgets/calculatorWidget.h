#ifndef CALCULATORWIDGET_H
#define CALCULATORWIDGET_H

#include <QGridLayout>
#include <QLineEdit>
#include "../../widgets/buttons/customButton.h"
#include "../../libs/muParser.h"
#include "../../widgets/panelWidgets/abstractPanelWidget.h"
#include "../../widgets/lineEdits/customLineEdit.h"

class CalculatorWidget : public AbstractPanelWidget
{
    Q_OBJECT

    mu::Parser p;

    int cnt = 0;

    QGridLayout* mainGrid;
    CustomLineEdit* mainEdit;

    CustomButton* button_power;
    CustomButton* button_sqrt;
    CustomButton* button_exp;
    CustomButton* button_abs;
    CustomButton* button_asin;
    CustomButton* button_sin;
    CustomButton* button_sinh;
    CustomButton* button_asinh;
    CustomButton* button_acos;
    CustomButton* button_cos;
    CustomButton* button_cosh;
    CustomButton* button_acosh;
    CustomButton* button_atan;
    CustomButton* button_tan;
    CustomButton* button_tanh;
    CustomButton* button_atanh;
    CustomButton* button_sec;
    CustomButton* button_csc;
    CustomButton* button_log;
    CustomButton* button_ln;
    CustomButton* button_C;
    CustomButton* button_backspace;
    CustomButton* button_MC;
    CustomButton* button_MR;
    CustomButton* button_MS;
    CustomButton* button_M_minus;
    CustomButton* button_M_plus;
    CustomButton* button_brackets;
    CustomButton* button_divide;
    CustomButton* button_7;
    CustomButton* button_8;
    CustomButton* button_9;
    CustomButton* button_multiply;
    CustomButton* button_4;
    CustomButton* button_5;
    CustomButton* button_6;
    CustomButton* button_minus;
    CustomButton* button_1;
    CustomButton* button_2;
    CustomButton* button_3;
    CustomButton* button_plus;
    CustomButton* button_0;
    CustomButton* button_comma;
    CustomButton* button_equal;

public:
    explicit CalculatorWidget(QWidget* parent = nullptr);

    void setupUI() override;
    void setupConnections() override;

    QString getLineEditText() const;
    void setLineEditText(const QString& newText);

    QString count(const QString& text);

signals:
    void memoryClearBtnClicked();
    void memoryStoreBtnClicked();
    void memoryRestoreBtnClicked();
    void memoryPlusBtnClicked();
    void memoryMinusBtnClicked();

public slots:
    void showExtraButtons();
    void closeExtraButtons();

    void memoryRestore(const QString& text);

private slots:
    void addNumber();
    void addOperation();
    void addFunction();
    void addBracket();
    void solve();

};

#endif // CALCULATORWIDGET_H
