#ifndef ABSTRACTPANELWINDOW_H
#define ABSTRACTPANELWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include "../../../widgets/titleBars/hideTitlebar.h"
#include "../../../widgets/windows/hideWindow.h"
#include "../../../widgets/panelWidgets/abstractPanelWidget.h"

class AbstractPanelWindow : public HideWindow
{
    Q_OBJECT

    QVBoxLayout* widgetLayout;

protected:
    AbstractPanelWidget* panelWidget;

public:
    explicit AbstractPanelWindow(QWidget* parent = nullptr);

    virtual void setupUI(){};

    void setPanelWidget(AbstractPanelWidget* widget);
};

#endif // ABSTRACTPANELWINDOW_H
