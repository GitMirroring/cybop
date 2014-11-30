#include "aktuelleselement.h"

#include "button.h"

// Button::Button *****************************************************************************************************
//
//*********************************************************************************************************************
Button::Button( QWidget * parent )
{
    this->QPushButton::setParent( parent );
}

// Button::Button *****************************************************************************************************
//
//*********************************************************************************************************************
Button::Button( QString & text, QWidget *parent)
{
    this->QPushButton::setParent( parent );
    this->setText( text );
}

// Button::mousePressEvent ********************************************************************************************
//
//*********************************************************************************************************************
void
Button::mousePressEvent(
        QMouseEvent *e ) {

    if( e->button() == Qt::LeftButton ) {
        aktuellesElement * ele = aktuellesElement::getInstance();
        ele->setElement( m_element );

        m_offset = e->pos();

        this->setCursor( Qt::SizeAllCursor );
    }
}

// Button::mouseMoveEvent *********************************************************************************************
//
//*********************************************************************************************************************
void
Button::mouseMoveEvent(
        QMouseEvent *e ) {
    aktuellesElement * ele = aktuellesElement::getInstance();

    if( e->buttons() & Qt::LeftButton ) {
        this->move( mapToParent( e->pos() - m_offset ) );
        m_element.properties.find( POSITION ).value() = QString(
                    QString::number( this->x() )
                    + ","
                    + QString::number( this->y() ) );

        ele->setElement( m_element );
    }
}

// Button::mouseReleaseEvent ******************************************************************************************
//
//*********************************************************************************************************************
void
Button::mouseReleaseEvent(
        QMouseEvent *e )
{
    this->setCursor( Qt::ArrowCursor );
}

// Button::resizeEvent ************************************************************************************************
//
//*********************************************************************************************************************
void
Button::resizeEvent(
        QResizeEvent *e ) {

    m_element.properties.find( SIZE ).value() = QString::number( this->width() ) + "," + QString::number( this->height() );
    m_element.properties.find( POSITION ).value() = QString::number( this->x() ) + "," + QString::number( this->y() );

    aktuellesElement * ele = aktuellesElement::getInstance();

    ele->setElement( m_element );
}

// Button::moveEvent **************************************************************************************************
//
//*********************************************************************************************************************
void
Button::moveEvent(
        QMoveEvent *e ) {
    aktuellesElement * ele = aktuellesElement::getInstance();

    ele->setElement( m_element );
}
