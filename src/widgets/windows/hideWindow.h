//
// Created by genas on 29.07.2022.
//

#ifndef SRC_HIDEWINDOW_H
#define SRC_HIDEWINDOW_H

#include <QMenu>
#include <QRect>
#include <QTimer>
#include <QPoint>
#include <QStyle>
#include <QPointF>
#include <QObject>
#include <QWidget>
#include <QCursor>
#include <QWindow>
#include <QMenuBar>
#include <QPainter>
#include <QToolBar>
#include <QtGlobal>
#include <QStatusBar>
#include <QSizePolicy>
#include <QMetaMethod>
#include <QMetaObject>
#include <QDockWidget>
#include <QMainWindow>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QStyleOption>
#include <QDir>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include "../../widgets/titleBars/hideTitlebar.h"
#include "../../widgets/QHoverWatcher.h"

class HideWindow : public QWidget
{
    Q_OBJECT

public:
    enum OperationType {
        NONE = 0x00,
        CUSTOM_MOVE = 0x01,
        CUSTOM_RESIZE = 0x02,
        SYSTEM_MOVE = 0x04,
        SYSTEM_RESIZE = 0x08,
    };

    Q_DECLARE_FLAGS(OperationTypes, OperationType)

    HideWindow(QWidget *parent = nullptr);
    ~HideWindow();

    inline bool isMoving(){ return this->cOpStatus & (OperationType::CUSTOM_MOVE | OperationType::SYSTEM_MOVE); }
    inline bool isResizing(){ return this->cOpStatus & (OperationType::CUSTOM_RESIZE | OperationType::SYSTEM_RESIZE); }

    inline QWidget* mainWidget(){ return this->privWidget; }
    inline QCustomTitleBar* titleBar(){ return this->tb; }

    void connectTitleBar();

    inline void setForceCustomMove(bool force = true){ this->forceCustomMove = force; }
    inline void setForceCustomResize(bool force = true){ this->forceCustomResize = force; }

protected:
    const int RESIZE_THRESHOLD, CLIENT_MARGIN;
    HideTitleBar* tb;
    QWidget *privWidget;

    bool eventFilter(QObject *, QEvent *event) override;

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    virtual void customMouseMoveEvent(QMouseEvent* event);

    void setTitleBar(HideTitleBar* _tb);

private:
    bool forceCustomMove;
    bool forceCustomResize;

    OperationType cOpStatus;

    QVBoxLayout *privLayout;
    QVBoxLayout *privHWLayout;

    QHoverWatcher *privHW;

    Qt::Edges mLock;
    QPoint mPosCursor;

    void redefineCursor(const QPoint &pos);

signals:
    void closed();
    void hided();
};


#endif //SRC_HIDEWINDOW_H
