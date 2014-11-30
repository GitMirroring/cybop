#include <QFile>
#include <QXmlStreamReader>
#include <QDir>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QToolBox>
#include <QPicture>
#include <QIcon>

#include "component.h"
#include "inireader.h"
#include "createwidgetbox.h"

// CreateWidgetBox::CreateWidgetBox ***********************************************************************************
// default Constructor
//*********************************************************************************************************************
CreateWidgetBox::CreateWidgetBox(CybolMainWindow *parent )
    : m_mainWindow( parent )
{
}

// CreateWidgetBox::CreateWidgetBox ***********************************************************************************
//
//*********************************************************************************************************************
CreateWidgetBox::CreateWidgetBox(
        CybolMainWindow * parent,
        QString operDir,
        QString filename )
    : m_mainWindow( parent )
{
    m_operDir = operDir;
    m_filename = filename;

    m_layout = new QVBoxLayout();
}

// CreateWidgetBox::~CreateWidgetBox **********************************************************************************
//
//*********************************************************************************************************************
CreateWidgetBox::~CreateWidgetBox( void ) {
}

// CreateWidgetBox::scanElementFile ***********************************************************************************
//
//*********************************************************************************************************************
void
CreateWidgetBox::scanElementFile(
        void ) {
    iniReader ini = iniReader::getInstance();

    QFile * file = new QFile( QDir::toNativeSeparators( ini.getValue( "elementsFile" ) ) );

    if( !file->open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        QMessageBox::critical( 0,
                               "File not found.",
                               "File: " + ini.getValue( "elementsFile" )
                               + "\n The File can not opened.",
                               QMessageBox::Ok );

        return;
    }

    QXmlStreamReader xml(file);

    QString key ="";

    while( !xml.atEnd() && !xml.hasError() ) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if( token == QXmlStreamReader::StartDocument ) {
            continue; //the model tag is not necessary
        }

        if( token == QXmlStreamReader::StartElement ) {
            if( xml.name() == "widgetgroup" ) {
                displayGroupLabel( xml, key );
            }

            if( xml.name() == "widget" ) {
                displayWidget( xml, key );
            }
        }
    }

    displayAll();

}

// CreateWidgetBox::displayGroupLabel *********************************************************************************
//
//*********************************************************************************************************************
void
CreateWidgetBox::displayGroupLabel(
        QXmlStreamReader & xml,
        QString & key) {

    QXmlStreamAttributes attributes = xml.attributes();

    if( attributes.hasAttribute( "title" ) ) {
        key = attributes.value( "title" ).toString();

        ToolboxWidget widget;
        widget.name ="";
        widget.icon ="";
        widget.path ="";

        m_values.insert( key, widget );
    }
}

// CreateWidgetBox::displayWidget *************************************************************************************
//
//*********************************************************************************************************************
void
CreateWidgetBox::displayWidget(
        QXmlStreamReader & xml,
        QString & key ) {

    QXmlStreamAttributes attributes = xml.attributes();
    ToolboxWidget widget;

    if( attributes.hasAttribute( "name" ) ) {
        widget.name = attributes.value( "name" ).toString();
    }

    if( attributes.hasAttribute( "file" ) ) {
        widget.path = attributes.value( "file" ).toString();
    }

    if( attributes.hasAttribute( "icon" ) ) {
        widget.icon = attributes.value( "icon" ).toString();
    }

    m_values.insert( key, widget );
}

// CreateWidgetBox::displayAll ****************************************************************************************
//
//*********************************************************************************************************************
void
CreateWidgetBox::displayAll(
        void ) {
    QMultiMap<QString, ToolboxWidget>::iterator iterVal;

    QToolBox * toolbox = new QToolBox();
    QString aktTitle = "";

    // count downwards, because it was read upwards
    for( iterVal = m_values.end(); iterVal != m_values.begin(); --iterVal ) {
        if( iterVal.key() == "" ) {
            continue;
        }

        ToolboxWidget aktWidget = iterVal.value();

        if( aktWidget.name == "" ) {
            aktTitle = iterVal.key();
        } else {

            QWidget * widget = new QWidget();
            QVBoxLayout * layout = new QVBoxLayout();
            int count = 0;
            for( iterVal; iterVal != m_values.begin(); -- iterVal ) {

                aktWidget = iterVal.value();

                if( aktWidget.name == "" ) {
                    ++iterVal;
                    break;
                }

                Component * icon = new Component( aktWidget.icon, aktWidget.name );
                layout->addWidget( icon );

                ++count;
            }

            widget->setMaximumHeight( count * 20 + 30 );
            widget->setLayout( layout );

            toolbox->addItem( widget, aktTitle );

        }

        if( iterVal == m_values.begin() ) {
            break;
        }
    }

    m_mainWindow->m_ui->widgetbox->setWidget( toolbox );
}
