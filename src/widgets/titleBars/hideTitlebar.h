#ifndef HIDETITLEBAR_H
#define HIDETITLEBAR_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include "../../widgets/titleBars/titlebar.h"

class HideTitleBar : public QCustomTitleBar
{
    Q_OBJECT

    QPushButton btnHide;

public:
    explicit HideTitleBar(QWidget *parent = nullptr);

signals:
    void hideBtnClicked();
};

#endif // HIDETITLEBAR_H
