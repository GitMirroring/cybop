#include <QXmlStreamReader>
#include <QFile>
#include <QMessageBox>
#include <QMultiMap>
#include <QList>

#include "cybolreader.h"

// CybolReader::CybolReader *******************************************************************************************
//
//*********************************************************************************************************************
CybolReader::CybolReader()
{
}

// CybolReader::~CybolReader ******************************************************************************************
//
//*********************************************************************************************************************
CybolReader::~CybolReader()
{
}

// CybolReader::scanFile **********************************************************************************************
//
//*********************************************************************************************************************
int
CybolReader::scanFile(
        QString & filename,
        QMultiMap< QString, properties > & widgets)
{
    QFile * file = new QFile( filename );

    if( !file->open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        QMessageBox::critical( 0,
                               "File not found.",
                               "File: " + filename + "\n The File can not opened.",
                               QMessageBox::Ok );

        return -1;
    }

    QXmlStreamReader xml(file);

    QString key;

    while( !xml.atEnd() && !xml.hasError() ) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if( token == QXmlStreamReader::StartDocument ) {
            continue; //the model tag is not necessary
        }

        if( token == QXmlStreamReader::StartElement ) {
            if( xml.name() == "part" ) {
                readPart( xml, widgets, key );
            }

            if( xml.name() == "property" ) {
                readProperty( xml, widgets, key);
            }
        }
    }

    //Error Handling
    if( xml.hasError() ) {
        QMessageBox::critical( 0,
                              "QXSRExample::parseXML",
                              xml.errorString(),
                              QMessageBox::Ok);
    }

    xml.clear();

    return 0;
}

// CybolReader::readPart **********************************************************************************************
//
//*********************************************************************************************************************
void
CybolReader::readPart(
        QXmlStreamReader &xml,
        QMultiMap<QString, properties > &widgets,
        QString & key)
{
    /* Let's check that we're really getting a part. */
    if(xml.tokenType() != QXmlStreamReader::StartElement &&
        xml.name() == "part") {
        return;
    }

    QXmlStreamAttributes attributes = xml.attributes();

    properties prop;

    if( attributes.hasAttribute( "name" ) ) {
        key = attributes.value( "name" ).toString();
        prop.name = attributes.value( "name" ).toString();
    }

    if( attributes.hasAttribute( "channel" ) ) {
        prop.channel = attributes.value( "channel" ).toString();
    }

    if( attributes.hasAttribute( "format" ) ) {
        prop.format = attributes.value( "format" ).toString();
    }

    if( attributes.hasAttribute( "model" ) ) {
        prop.model = attributes.value( "model" ).toString();
    }
    prop.property = false; //its part not property

    widgets.insert(key, prop);
}

// CybolReader::readProperty ******************************************************************************************
//
//*********************************************************************************************************************
void
CybolReader::readProperty(
        QXmlStreamReader &xml,
        QMultiMap<QString, properties > &widgets,
        QString & key)
{
    /* Let's check that we're really getting a property. */
    if(xml.tokenType() != QXmlStreamReader::StartElement &&
        xml.name() == "property") {
        return;
    }

    QXmlStreamAttributes attributes = xml.attributes();

    properties prop;

    if( attributes.hasAttribute( "name" ) ) {
        prop.name = attributes.value( "name" ).toString();
    }

    if( attributes.hasAttribute( "channel" ) ) {
        prop.channel = attributes.value( "channel" ).toString();
    }

    if( attributes.hasAttribute( "format" ) ) {
        prop.format = attributes.value( "format" ).toString();
    }

    if( attributes.hasAttribute( "model" ) ) {
        prop.model = attributes.value( "model" ).toString();
    }
    prop.property = true; //it is property

    widgets.insert(key, prop);
}
