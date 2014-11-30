#include "border.h"

Border::Border( int w, QColor color, BORDERSTYLE style )
{
    m_width = w;
    m_color = color;
    m_style = style;
}

void
Border::setBorderwidth(
        int w )
{
    m_width = w;
}

int
Border::borderwidth(
        void )
{
    return m_width;
}

void
Border::setColor(
        QColor color )
{
    m_color = color;
}

QColor
Border::color(
        void )
{
    return m_color;
}

void
Border::setStyle(
        BORDERSTYLE style)
{
    m_style = style;
}

Border::BORDERSTYLE
Border::style(
        void )
{
    return m_style;
}
