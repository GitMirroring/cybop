#ifndef PROPERTYREADER_H
#define PROPERTYREADER_H

#include <QXmlStreamReader>
#include <QMultiMap>

#include "qualities.h"
#include "variables.h"

/*!
 * \brief The propertyReader class
 *
 *Singleton
 */
class propertyReader
{
public:
    static propertyReader * getInstance( void );
    static void dropInstance( void );
    void readFile( QString file = "" );
    QList<Qualities> getProperties( ELEMENT ele );

private:
    QMultiMap< QString, Qualities > m_properties;
    QString m_key;
    Qualities m_lastProp;

    static propertyReader * m_self;
    propertyReader();

    void readPropertyGroup( QXmlStreamReader &xml );
    void readProperty( QXmlStreamReader &xml );
    void readSinglepro( QXmlStreamReader &xml );
};

#endif // PROPERTYREADER_H
