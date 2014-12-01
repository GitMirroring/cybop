#include <QDebug>
#include <QDockWidget>
#include <QFile>
#include <QString>
#include <QXmlStreamWriter>

#include "widget.h"
#include "cybolwriter.h"

#define STRBOOL     "logicalvalue/boolean"
#define STRINT      "number/integer"
#define STRPLAINTEXT     "text/plain"
#define STRRGB      "colour/rgb"
#define STRFILE     "file"
#define STRINLINE   "inline"

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

    m_new = false;

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
    if( m_new ){
        file.setFileName( m_file + "/" + m_newFilename + ".cybol");

        if( !file.open( QIODevice::ReadWrite ) ) {
            qDebug() << file.errorString();
            return 1;
        }
        xmlWriter.setDevice( &file );

        xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement( "model" );
        m_new = false;
    } else if (element.elementtype == WINDOW) {
        xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement( "model" );
    }

    xmlWriter.setAutoFormatting( true );

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

           QString propname, channel, format;

           switch( iter.key() ) {
           case SHAPE:
               propname = STRSHAPE;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case SIZE:
               propname = STRSIZE;
               channel = STRINLINE;
               format = STRINT;
               break;

           case POSITION:
               propname = STRPOSITION;
               channel = STRINLINE;
               format = STRINT;
               break;

           case COLOR:
               propname = STRCOLOR;
               channel = STRINLINE;
               format = STRRGB;
               break;

           case BACKGROUNDCOLOR:
               propname = STRBACKGROUND;
               channel = STRINLINE;
               format = STRRGB;
               break;

           case ENABLED:
               propname = STRENABLED;
               channel = STRINLINE;
               format = STRBOOL;
               break;

           case TEXT:
               propname = STRTEXT;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case ICON:
               propname = STRICON;
               channel = STRFILE;
               format = iter.value().right( iter.value().indexOf( "." ) + 1 );
               break;

           case TOOLTIP:
               propname = STRTOOLTIP;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case TOOLTIPDURATION:
               propname = STRTOOLTIPDURATION;
               channel = STRINLINE;
               format = STRBOOL;
               break;

           case CURSOR:
               propname = STRCURSOR;
               channel = STRFILE;
               format = iter.value().right( iter.value().indexOf( "." ) + 1 );
               break;

           case OPACITY:
               propname = STROPACITY;
               channel = STRINLINE;
               format = STRINT;
               break;

           case VISIBLE:
               propname = STRVISIBLE;
               channel = STRINLINE;
               format = STRBOOL;
               break;

           case MARGIN:
               propname = STRMARGIN;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case PADDING:
               propname = STRPADDING;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case FONT:
               propname = STRFONT;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case HORIZONTALALIGN:
               propname = STRHORALIGN;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case VERTICALALIGN:
               propname = STRVERALIGN;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case ORIENTATION:
               propname = STRORIENTATION;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case BORDER:
               propname = STRBORDER;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case BORDERBOTTOM:
               propname = STRBORDERBOTTOM;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case BORDERTOP:
               propname = STRBORDERTOP;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case BORDERLEFT:
               propname = STRBORDERLEFT;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case BORDERRIGHT:
               propname = STRBORDERRIGHT;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           case LAYOUT:
               propname = STRLAYOUT;
               channel = STRINLINE;
               format = STRPLAINTEXT;
               break;

           default:
               continue;

           }
           xmlWriter.writeStartElement( "property" );

           xmlWriter.writeAttribute( "name", propname );
           xmlWriter.writeAttribute( "channel", channel );
           xmlWriter.writeAttribute( "format", format );
           xmlWriter.writeAttribute( "model", iter.value() );

           xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement(); // part
    switch( element.elementtype ) {
    case WINDOW:
        break;
    case BUTTON:
        break;
    }
    QList<Widget *> childs = widget->children();
    int i = 0;
    while( i < childs.size() ) {
        m_newFilename = element.name;

        if( i == 0 ) {
            m_new = true;
        }
        m_close = false;
        Widget * aktWidget = childs[i];

        writePart( xmlWriter, aktWidget, aktWidget->element() );

        ++i;
        if( i == childs.size() ) {
            m_close = true;
        }
    }

    if ( m_close ) {
        xmlWriter.writeEndDocument();
    }
    file.flush();

}
