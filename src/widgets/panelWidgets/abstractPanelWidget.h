#ifndef ABSTRACTPANELWIDGET_H
#define ABSTRACTPANELWIDGET_H

#include <QObject>
#include <QWidget>

class AbstractPanelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractPanelWidget(QWidget *parent = nullptr);

    virtual void setupUI() {};
    virtual void setupConections() {};

signals:

};

#endif // ABSTRACTPANELWIDGET_H
