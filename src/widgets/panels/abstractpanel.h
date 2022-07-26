#ifndef ABSTRACTPANEL_H
#define ABSTRACTPANEL_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QGraphicsDropShadowEffect>
#include <widgets/titleBars/viewtitlebar.h>

class AbstractPanel : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractPanel(QWidget *parent = nullptr);

protected:

    QVBoxLayout* mainLayout;

    ViewTitleBar* tb;
    QWidget* mainWidget;

    QVBoxLayout* widgetLayout;

signals:

};

#endif // ABSTRACTPANEL_H
