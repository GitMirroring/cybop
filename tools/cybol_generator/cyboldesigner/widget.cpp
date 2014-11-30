#include "widget.h"

void
Widget::setElement(
        Elements element )
{
    m_element = element;
}

Elements
Widget::element(
        void )
{
    return m_element;
}
