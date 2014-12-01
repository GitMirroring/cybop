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

void
Widget::addChild(
        Widget * child )
{
    m_child.append( child );
    m_hasChilds = true;
}

int
Widget::removeChild(
        Widget *child )
{
    m_child.removeOne( child );
    if( m_child.isEmpty() ) {
        m_hasChilds = false;
    }
}

QList<Widget *>
Widget::children(
        void )
{
    return m_child;
}
