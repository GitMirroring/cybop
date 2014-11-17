#ifndef COLORREADER_H
#define COLORREADER_H

#include "variables.h"

/*!
 * \brief The colorReader class
 *
 * Class for read the color constructions. New usable Colors definition are setting here.
 */
class colorReader
{
private:
    colorReader();
    virtual ~colorReader();

public:
    /*!
     * \brief getRGB
     * \param colors
     * \return struct rgb
     *
     * Wandelt den eingegebenen QString in rgb um. Aufbau des QStrings "r,g,b".
     */
    static RGB getRGB( QString & colors );
};

#endif // COLORREADER_H
