#ifndef BUTTON_H
#define BUTTON_H

#include <QMouseEvent>
#include <QPushButton>
#include <QPoint>
#include <QPalette>
#include <QMargins>
#include <QSize>

#include "widget.h"

#include "variables.h"

class Button : public Widget, public QPushButton
{
public:
    explicit Button( QWidget * parent = 0 );
    explicit Button( QString & text, QWidget *parent = 0 );

    QObject * self();

private:
    QPoint m_offset;

protected:
    virtual void mousePressEvent( QMouseEvent * e );
    virtual void mouseMoveEvent( QMouseEvent * e );
    virtual void mouseReleaseEvent( QMouseEvent * e );
    virtual void resizeEvent( QResizeEvent * e );
    virtual void moveEvent( QMoveEvent * e );


signals:

public slots:

};

#endif // BUTTON_H
