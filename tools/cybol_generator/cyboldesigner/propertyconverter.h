#ifndef PROPERTYCONVERTER_H
#define PROPERTYCONVERTER_H

#include "variables.h"

class PropertyConverter
{
public:
    /*!
     * \brief getSize
     * \param size
     * \return
     *
     * Wandelt den gegebenen String in eine Größe um. Es wird anhand der Propertyvorgaben konvertiert.
     * width, height
     */
    static Size getSize( QString & size );

    /*!
     * \brief getPosition
     * \param pos
     * \return
     *
     * Wandelt den gegebenen String in eine Position um. Es wird anhand der Propertyvorgaben kovertiert.
     * x, y
     */
    static Position getPosition( QString & pos );
};

#endif // PROPERTYCONVERTER_H
