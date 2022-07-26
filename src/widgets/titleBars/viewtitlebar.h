#ifndef VIEWTITLEBAR_H
#define VIEWTITLEBAR_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <widgets/titleBars/titlebar.h>

class ViewTitleBar : public QCustomTitleBar
{
    Q_OBJECT
public:
    explicit ViewTitleBar(QWidget *parent = nullptr);

private:
    QPushButton btnView;

    bool state;

signals:
    void viewBtnClicked();

private slots:
    void view();
};

#endif // VIEWTITLEBAR_H
