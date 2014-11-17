#include <QFile>
#include <QXmlStreamReader>
#include <QDir>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>

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
        m_values.insert( key, "" );
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

    if( attributes.hasAttribute( "name" ) ) {
        m_values.insert( key, attributes.value( "name" ).toString() );
    }
}

// CreateWidgetBox::displayAll ****************************************************************************************
//
//*********************************************************************************************************************
void
CreateWidgetBox::displayAll(
        void ) {
    QMultiMap<QString, QString>::iterator iterVal;

    int i = 1;
    // count downwards, because it was read upwards
    for( iterVal = m_values.end(); iterVal != m_values.begin(); --iterVal ) {
        if( iterVal.key() == "" ) {
            continue;
        }

        if( iterVal.value() == "" ) {
            QLabel * label = new QLabel( iterVal.key() );
            label->setGeometry( 10, 20 * i + 10 , 100, 16);

            m_mainWindow->m_ui->widgetbox->layout()->addWidget( label );
        } else {
            QLabel * label = new QLabel( iterVal.value() );
            label->setGeometry( 20, 20 * i + 10 , 100, 16);

            m_mainWindow->m_ui->widgetbox->layout()->addWidget( label );

        }

        ++i;
    }
}
