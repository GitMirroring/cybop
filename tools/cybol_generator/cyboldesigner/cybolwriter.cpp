#include <QDebug>
#include <QDockWidget>
#include <QFile>
#include <QString>
#include <QXmlStreamWriter>

#include "widget.h"
#include "cybolwriter.h"

// CybolWriter::CybolWriter *******************************************************************************************
//
//*********************************************************************************************************************
CybolWriter::CybolWriter()
{
}

// CybolWriter::CybolWriter *******************************************************************************************
//
//*********************************************************************************************************************
CybolWriter::CybolWriter(
        QString &file )
{
    m_file = file;
}

int
CybolWriter::saveToFile(
        Window * window,
        QString file )
{
    if( window == 0 ) {
        return 2;
    }

    if( !file.isEmpty() ) {
        m_file = file;
    }

    QFile * saveFile = new QFile( m_file + "/gui.cybol" );
    if( !saveFile->open( QIODevice::ReadWrite ) ) {
        return 1;
    }

    QXmlStreamWriter xmlWriter( saveFile );


    int val = writePart( xmlWriter, window, window->element() );

    if( val != 0 ) {
        return val;
    }

    return 0;
}

// CybolWriter::writeFenster ******************************************************************************************
//
//*********************************************************************************************************************
int
CybolWriter::writePart(
        QXmlStreamWriter & xmlWriter,
        Widget *widget,
        Elements element )
{
    QString newFilename = element.name + ".cybol";

    QFile file;
    if( element.elementtype != WINDOW ){
        file.setFileName( m_file + "/" + newFilename );
    } else {
        file.setFileName( m_file + "/gui.cybol" );
    }


    if( !file.open( QIODevice::ReadWrite ) ) {
        qDebug() << file.errorString();
        return 1;
    }
    xmlWriter.setDevice( &file );

    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement( "model" );

    xmlWriter.writeStartElement("model");

    xmlWriter.writeStartElement( "part" );

    xmlWriter.writeAttribute( "name", element.name );
    xmlWriter.writeAttribute( "channel", "inline" );
    xmlWriter.writeAttribute( "format", "text/plain");
    xmlWriter.writeAttribute( "model", element.name + ".cybol" );

    //generelle properties

    QMap<PROPERS,QString>::iterator iter;

    for( iter = element.properties.begin();
         iter != element.properties.end();
         ++iter ){
           xmlWriter.writeStartElement( "property" );

           QString propname;

           switch( iter.key() ) {
           case SHAPE:
               propname = STRSHAPE;
               break;

           case SIZE:
               propname = STRSIZE;
               break;

           case POSITION:
               propname = STRPOSITION;
               break;

           case COLOR:
               propname = STRCOLOR;
               break;

           case BACKGROUNDCOLOR:
               propname = STRBACKGROUND;
               break;

           case ENABLED:
               propname = STRENABLED;
               break;

           case TEXT:
               propname = STRTEXT;
               break;

           case ICON:
               propname = STRICON;
               break;

           case TOOLTIP:
               propname = STRTOOLTIP;
               break;

           case TOOLTIPDURATION:
               propname = STRTOOLTIPDURATION;
               break;

           case CURSOR:
               propname = STRCURSOR;
               break;

           case OPACITY:
               propname = STROPACITY;
               break;
           }

           xmlWriter.writeAttribute( propname, iter.value() );
           xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
    switch( element.elementtype ) {
    case WINDOW:
        break;
    case BUTTON:
        break;
    }
    xmlWriter.writeEndElement();
    QObjectList childs = widget->children();
    int i = 0;
    while( i < childs.size() ) {

        Widget * aktWidget = qobject_cast<Widget *>( childs[i] );

        writePart( xmlWriter, aktWidget, aktWidget->element() );
        ++i;
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.flush();

}
