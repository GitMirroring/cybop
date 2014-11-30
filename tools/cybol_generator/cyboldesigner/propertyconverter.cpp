#include "propertyconverter.h"

// PropertyConverter::getSize *****************************************************************************************
//
//*********************************************************************************************************************
Size
PropertyConverter::getSize(
        QString &size )
{
    QString width = size.left( size.indexOf( "," ) );
    QString height = size.right( size.indexOf( "," ) );

    Size conSize;
    conSize.width = width.toInt();
    conSize.height = height.toInt();

    return conSize;
}

// PropertyConverter::getPosition *************************************************************************************
//
//*********************************************************************************************************************
Position
PropertyConverter::getPosition(
        QString &pos )
{
    QString xPos = pos.left( pos.indexOf("," ) );
    QString yPos = pos.right( pos.indexOf( "," ) );

    Position conPos;
    conPos.x = xPos.toInt();
    conPos.y = yPos.toInt();

    return conPos;
}
