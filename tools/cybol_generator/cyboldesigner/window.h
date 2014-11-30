#ifndef WINDOW_H
#define WINDOW_H

#include <QMouseEvent>
#include <QDockWidget>
#include <QPoint>

#include "widget.h"
#include "variables.h"

class Window : public QDockWidget, public Widget
{


public:
    explicit Window(QWidget *parent = 0);
    explicit Window( QString & title, QWidget * parent =  0 );

private:
    QPoint m_offset;

protected:
    virtual void mousePressEvent( QMouseEvent * e );

signals:

public slots:

};

#endif // WINDOW_H
