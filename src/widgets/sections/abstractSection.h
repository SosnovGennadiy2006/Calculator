#ifndef ABSTRACTPANELSECTION_H
#define ABSTRACTPANELSECTION_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include "../../widgets/titleBars/viewTitlebar.h"
#include "../../widgets/panelWidgets/abstractPanelWidget.h"

class AbstractSection : public QWidget
{
    Q_OBJECT

    QVBoxLayout* mainLayout;
    QWidget* mainWidget;

    QVBoxLayout* widgetLayout;

public:
    explicit AbstractSection(QWidget *parent = nullptr);

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
    void windowHided();
    void windowClosed();
};

#endif // ABSTRACTPANELSECTION_H
