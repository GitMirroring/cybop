#include <QString>

#include "colorreader.h"

// colorReader::colorReader *******************************************************************************************
//
//*********************************************************************************************************************
colorReader::colorReader( void )
{
}

// colorReadeer::~colorReader *****************************************************************************************
//
//*********************************************************************************************************************
colorReader::~colorReader( void )
{
}

// colorReader::getRGB ************************************************************************************************
//
//*********************************************************************************************************************
RGB
colorReader::getRGB(
        QString &colors ) {
    RGB clr;

    clr.red = colors.left( colors.indexOf( "," ) ).toInt();
    clr.green = colors.mid( colors.indexOf( "," ) + 1, colors.lastIndexOf(",") - colors.indexOf( "," ) - 1).toInt();
    clr.blue = colors.mid( colors.lastIndexOf( "," ) + 1 ).toInt();

    return clr;
}
