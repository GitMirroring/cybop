#include <QDir>
#include <QLayout>
#include <QLabel>
#include <QMessageBox>
#include <QMultiMap>
#include <QFileDialog>

#include "cybolwriter.h"
#include "cybolreader.h"
#include "variables.h"
#include "displaywindow.h"
#include "createwidgetbox.h"
#include "inireader.h"
#include "cybolmainwindow.h"
#include "ui_cybolmainwindow.h"
#include "propertyreader.h"

// CybolMainWindow::CybolMainWindow ***********************************************************************************
//
//*********************************************************************************************************************
CybolMainWindow::CybolMainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::CybolMainWindow),
    m_disp( new DisplayWindow( this ) ),
    m_cwb( new CreateWidgetBox( this ) ),
    m_cw( new CreateWindow( this ) ),
    m_aktEle( aktuellesElement::getInstance() ),
    m_window( 0 )
{
    m_filepath.clear();

    m_aktEle->setMainWindow( this );
    m_ui->setupUi(this);
    iniReader ini = iniReader::getInstance();

    propertyReader * prop = propertyReader::getInstance();
    prop->readFile( ini.getValue( "propFile" ) );

    int builded = buildWidgetBox();

    switch( builded ) {

    //-----------------------------------------------------------------------------------------------------------------
    case -1:
        //directory not found
        return;

    //-----------------------------------------------------------------------------------------------------------------
    default:
        break;

    }

    QAction * dwa = m_ui->widgetbox->toggleViewAction();
    QAction * doa = m_ui->objectinspector->toggleViewAction();


    connect( m_ui->action_OEffnen, &QAction::triggered, this, &CybolMainWindow::openFile );
    connect( m_ui->actionWidgetbox, &QAction::triggered, this, &CybolMainWindow::chgWidgetbox );
    connect( dwa, &QAction::toggled, this, &CybolMainWindow::chgWidgetBoxView );
    connect( m_ui->actionObjektinspektor, &QAction::triggered, this, &CybolMainWindow::chgObjektinspektor );
    connect( doa, &QAction::toggled, this, &CybolMainWindow::chgObjektinspektorView );
    connect( m_ui->action_Neu, &QAction::triggered, this, &CybolMainWindow::createWindow );
    connect( m_ui->action_Speichern, &QAction::triggered, this, &CybolMainWindow::saveFile );
}

// CybolMainWindow::~CybolMainWindow **********************************************************************************
//
//*********************************************************************************************************************
CybolMainWindow::~CybolMainWindow()
{
    if( m_disp != 0 ) {
        m_disp = 0;
        delete m_disp;
    }

    if( m_ui != 0) {
        m_ui = 0;
        delete m_ui;
    }
}

// CybolMainWindow::buildWidgetBox ************************************************************************************
//
//*********************************************************************************************************************
int
CybolMainWindow::buildWidgetBox(
        void )
{
    QDir workingDir = QDir::currentPath(); //Read working directory

    CreateWidgetBox cwb( this, workingDir.absolutePath() );

    cwb.scanElementFile();

    return 0;
}

// CybolMainWindow::openFile ******************************************************************************************
//
//*********************************************************************************************************************
void
CybolMainWindow::openFile(
        void )
{
    if ( m_ui->centralWidget->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = m_ui->centralWidget->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete m_ui->centralWidget->layout();
    }

    QMultiMap< QString, properties > widgets;

    QString filename = QFileDialog::getOpenFileName( this, "Open File...", QDir::current().absolutePath(), tr( "*.cybol" ) );
    if( filename.isEmpty() || filename.isNull() ) {
        //Do nothing
    } else {
        CybolReader::scanFile( filename, widgets );

        this->setCursor( Qt::WaitCursor );
        m_disp->showWidget( filename, widgets );
    }
}

// CybolMainWindow::chgWidgetbox **************************************************************************************
//
//*********************************************************************************************************************
void
CybolMainWindow::chgWidgetbox(
        void )
{
    if( m_ui->actionWidgetbox->isChecked() ) {
        m_ui->widgetbox->setVisible( true );
    } else {
        m_ui->widgetbox->setVisible( false );
    }
}

// CybolMainWindow::chgWidgetboxView **********************************************************************************
//
//*********************************************************************************************************************
void
CybolMainWindow::chgWidgetBoxView(
        void )
{
    if( m_ui->widgetbox->isVisible() ) {
        m_ui->actionWidgetbox->setChecked( true );
    } else {
        m_ui->actionWidgetbox->setChecked( false );
    }
}


// CybolMainWindow::chgObjektinspektor ********************************************************************************
//
//*********************************************************************************************************************
void
CybolMainWindow::chgObjektinspektor(
        void )
{
    if( m_ui->actionObjektinspektor->isChecked() ) {
        m_ui->objectinspector->setVisible( true );
    } else {
        m_ui->objectinspector->setVisible( false );
    }
}

// CybolMainWindow::chgObjektinspektor ********************************************************************************
//
//*********************************************************************************************************************
void
CybolMainWindow::chgObjektinspektorView(
        void )
{
    if( m_ui->objectinspector->isVisible() ) {
        m_ui->actionObjektinspektor->setChecked( true );
    } else {
        m_ui->actionObjektinspektor->setChecked( false );
    }
}

// CybolMainWindow::createWindow **************************************************************************************
//
//*********************************************************************************************************************
void
CybolMainWindow::createWindow(
        void ) {
    m_cw->createNewWindow();
}

void
CybolMainWindow::saveFile(
        void )
{
    if( m_filepath.isEmpty() ) {
        m_filepath = QFileDialog::getExistingDirectory( this, "Speichern..." );
    }

    this->setCursor( Qt::BusyCursor );

    CybolWriter writer( m_filepath );
    writer.saveToFile( m_window );

    this->setCursor( Qt::ArrowCursor );
}

