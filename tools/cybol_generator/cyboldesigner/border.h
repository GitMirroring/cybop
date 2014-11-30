#ifndef BORDER_H
#define BORDER_H

#include <QColor>

class Border
{
public:
    enum BORDERSTYLE{
        SOLID,
        DOTTED,
        DASEHD,
        NONE,
        DOUBLE,
        GROOVE,
        RIDGE,
        INSET,
        OUTSET
    };

    Border(int w = 1, QColor color = QColor( 0, 0, 0), BORDERSTYLE style = SOLID );

    void setStyle( BORDERSTYLE style );
    Border::BORDERSTYLE style( void );

    void setBorderwidth( int w );
    int borderwidth( void );

    void setColor( QColor color );
    QColor color( void );


private:
    BORDERSTYLE m_style;
    int m_width;
    QColor m_color;
};

#endif // BORDER_H
