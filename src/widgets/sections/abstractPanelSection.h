#ifndef ABSTRACTPANELSECTION_H
#define ABSTRACTPANELSECTION_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include "../../widgets/titleBars/viewTitlebar.h"
#include "../../widgets/panelWidgets/abstractPanelWidget.h"

class AbstractPanelSection : public QWidget
{
    Q_OBJECT

    QVBoxLayout* mainLayout;
    QWidget* mainWidget;

    QVBoxLayout* widgetLayout;

public:
    explicit AbstractPanelSection(AbstractPanelWidget* panelWidget, QWidget *parent = nullptr);

    void setPanelWidget(AbstractPanelWidget* _panelWidget);

protected:
    ViewTitleBar* tb;
    AbstractPanelWidget* panelWidget;

protected slots:
    virtual void viewWindow(){};
    virtual void closeWindow(){};
    virtual void hideWindow(){};

signals:
    void closed();
    void viewed();
    void windowClosed();
    void windowHided();
};

#endif // ABSTRACTPANELSECTION_H
