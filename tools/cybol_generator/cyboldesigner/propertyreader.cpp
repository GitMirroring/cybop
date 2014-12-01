#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>

#include "propertyreader.h"

propertyReader* propertyReader::m_self = 0;

// propertyReader::propertyReader *************************************************************************************
//
//*********************************************************************************************************************
propertyReader::propertyReader()
    : m_key( "default" )
{
}

// propertyReader::getInstance ****************************************************************************************
//
//*********************************************************************************************************************
propertyReader *
propertyReader::getInstance(
        void )
{
    if( !m_self ) {
        m_self = new propertyReader();
    }

    return m_self;
}

// propertyReader::readFile *******************************************************************************************
//
//*********************************************************************************************************************
void
propertyReader::readFile(
        QString file )
{
    QFile * xmlfile = new QFile( file );

    if( !xmlfile->open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        QMessageBox::critical( 0,
                               "File not found.",
                               "File: " + file + "\n The File can not opened.",
                               QMessageBox::Ok );

        return;
    }

    QXmlStreamReader xml(xmlfile);

    QString key;

    while( !xml.atEnd() && !xml.hasError() ) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if( token == QXmlStreamReader::StartDocument ) {
            continue; //the model tag is not necessary
        }

        if( token == QXmlStreamReader::StartElement ) {
            if( xml.name() == "propertyGroup" ) {
                readPropertyGroup( xml );
            }

            if( xml.name() == "property" ) {
                readProperty( xml );
            }

            if( xml.name() == "singlepro" ) {
                readSinglepro( xml );
            }
        }

        if( token == QXmlStreamReader::EndElement ) {
            if( xml.name() == "property" ) {
                m_properties.insert( m_key, m_lastProp );
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
}


// propertyReader::readPropertyGroup **********************************************************************************
//
//*********************************************************************************************************************
void
propertyReader::readPropertyGroup(
        QXmlStreamReader & xml )
{
    QXmlStreamAttributes attributes = xml.attributes();

    if( attributes.hasAttribute( "name" ) ) {
        m_key = attributes.value( "name" ).toString();
    } else {
        m_key = "default";
    }
}

// propertyReader::readProperty ***************************************************************************************
//
//*********************************************************************************************************************
void
propertyReader::readProperty(
        QXmlStreamReader & xml )
{
    QXmlStreamAttributes attributes = xml.attributes();

    if( attributes.hasAttribute( "name" ) ) {
        m_lastProp.setName( attributes.value( "name" ).toString() );
    }

    if( attributes.hasAttribute( "type" ) ) {
        m_lastProp.setType( attributes.value( "type" ).toString() );
    }

    if( attributes.hasAttribute( "default" ) ) {
        m_lastProp.setDefault( attributes.value( "default" ).toString() );
    }
}

// propertyReader::readSinglepro **************************************************************************************
//
//*********************************************************************************************************************
void
propertyReader::readSinglepro(
        QXmlStreamReader &xml )
{
    Qualities qual;
    QXmlStreamAttributes attributes = xml.attributes();

    if( attributes.hasAttribute( "name" ) ) {
        qual.setName( attributes.value( "name" ).toString() );
    }

    if( attributes.hasAttribute( "type" ) ) {
        qual.setType( attributes.value( "type" ).toString() );
    }

    if( attributes.hasAttribute( "default" ) ) {
        qual.setDefault( attributes.value( "default" ).toString() );
    }

    m_lastProp.addSub( qual );
}

// propertyReader::getProperties **************************************************************************************
//
//**********************************************************************************************************************
QList<Qualities>
propertyReader::getProperties(
        ELEMENT ele )
{
    QString key;

    switch( ele )
    {
    case WINDOW:
        key = "Window";
        break;

    case LABEL:
        key = "Label";
        break;

    case BUTTON:
        key = "Button";
        break;

    case EDITFIELD:
        key = "Edit";
        break;

    case SCROLLBAR:
        key = "Scrollbar";
        break;

    case TABLEVIEW:
        key = "TableView";
        break;

    case LISTVIEW:
        key = "ListView";
        break;

    case TREEVIEW:
        key = "TreeView";
        break;

    case TABWIDGET:
        key = "TabWidget";
        break;

    case PANEL:
        key = "Panel";
        break;

    case COMBOBOX:
        key = "ComboBox";
        break;

    case CHECKBOX:
        key = "CheckBox";
        break;

    case RADIOBUTTON:
        key = "RadioButton";
        break;

    case SPINBOX:
        key = "SpinBox";
        break;

    case PROGRESSBAR:
        key = "ProgressBar";
        break;

    case LINE:
        key = "Line";
        break;

    case RECTANGLE:
        key = "Rectangle";
        break;

    case TRIANGEL:
        key = "Triangel";
        break;

    case SLIDER:
        key = "Slider";
        break;

    case CALENDAR:
        key= "Calendar";
        break;

    case GROUPBOX:
        key = "GroupBox";
        break;

    case VERTICAL_LAYOUT:
        key = "VerticalLayout";
        break;

    case HORIZONTAL_LAYOUT:
        key = "HorizontalLayout";
        break;

    case GRID_LAYOUT:
        key = "GridLayout";
        break;

    case ABSOLUTE_LAYOUT:
        key = "AbsoluteLayout";
        break;

    default:
        break;
    }

    QList< Qualities > result = m_properties.values( "default" );
    result += m_properties.values( key );

    return result;
}
