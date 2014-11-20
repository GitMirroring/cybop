#ifndef AKTUELLESELEMENT_H
#define AKTUELLESELEMENT_H

#include "variables.h"

class aktuellesElement
{
public:
    static aktuellesElement getInstance( void );

    void setElement( Elements & element );
    Elements getElement( void );

private:
    Elements m_element;
    aktuellesElement();
};

#endif // AKTUELLESELEMENT_H
