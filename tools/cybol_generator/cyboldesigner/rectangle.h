#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QLabel>

#include "variables.h"

class Rectangle : public QLabel
{
    Q_OBJECT
public:
    explicit Rectangle( QWidget *parent = 0 );
    explicit Rectangle( QString & text, QWidget * parent = 0 );

    void setLineColor( RGB color );
    void setFillColor( RGB color );
    void setFontColor( RGB color );
protected:
    virtual void mousePressEvent( QMouseEvent * e );

signals:

public slots:

};

#endif // RECTANGLE_H
