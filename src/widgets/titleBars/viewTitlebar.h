#ifndef VIEWTITLEBAR_H
#define VIEWTITLEBAR_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include "../../widgets/titleBars/titlebar.h"

class ViewTitleBar : public QCustomTitleBar
{
    Q_OBJECT

    QPushButton btnView;
public:
    explicit ViewTitleBar(QWidget *parent = nullptr);

signals:
    void viewBtnClicked();
};

#endif // VIEWTITLEBAR_H
