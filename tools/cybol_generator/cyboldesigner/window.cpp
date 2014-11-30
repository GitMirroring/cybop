
#include "aktuelleselement.h"

#include "window.h"

// Window::Window *****************************************************************************************************
//
//*********************************************************************************************************************
Window::Window(QWidget *parent) :
    QDockWidget(parent)
{
}

// Window::Window *****************************************************************************************************
//
//*********************************************************************************************************************
Window::Window(
        QString &title,
        QWidget *parent ) :
    QDockWidget( parent )
{
    this->setWindowTitle( title );
}

// Window::mousePressEvent ********************************************************************************************
//
//*********************************************************************************************************************
void
Window::mousePressEvent(
        QMouseEvent *e )
{
    if( e->button() == Qt::LeftButton ) {
        aktuellesElement * ele = aktuellesElement::getInstance();
        ele->setElement( m_element );

        m_offset = e->pos();

        this->setCursor( Qt::SizeAllCursor );
    }
}

