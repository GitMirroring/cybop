#ifndef FOCUSPOINTS_H
#define FOCUSPOINTS_H

#include <QMouseEvent>
#include <QPoint>
#include <QLabel>

#include "variables.h"

class FocusPoints : public QLabel
{
    Q_OBJECT
public:
    explicit FocusPoints(QWidget *parent = 0);

    void setPosition( FOCUSPOINTPOS pos );
    FOCUSPOINTPOS position( void );

    void setX( int x );
    void setY( int y );

    void setElement( QWidget * element );

private:
    FOCUSPOINTPOS m_pos;
    QWidget * m_element;
    QPoint m_offset;

protected:
    virtual void mousePressEvent( QMouseEvent * e );
    virtual void mouseMoveEvent( QMouseEvent * e );

signals:

public slots:

};

#endif // FOCUSPOINTS_H
