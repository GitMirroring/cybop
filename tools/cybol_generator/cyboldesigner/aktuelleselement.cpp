#include "aktuelleselement.h"

// aktuellesElement::aktuellesElement *********************************************************************************
//
//*********************************************************************************************************************
aktuellesElement::aktuellesElement()
{
    m_element.self = 0;
}

// aktuellesElement::getInstance **************************************************************************************
//
//*********************************************************************************************************************
aktuellesElement
aktuellesElement::getInstance(
        void )
{
    static aktuellesElement self;
    return self;
}

Elements
aktuellesElement::getElement(
        void )
{
    return m_element;
}

void
aktuellesElement::setElement(Elements &element )
{
    if( m_element.self != 0 ) {
        m_element.self->setStyleSheet( "border:0" );
    }
    m_element = element;
    m_element.self->setStyleSheet( "border-color:yellow");
}
