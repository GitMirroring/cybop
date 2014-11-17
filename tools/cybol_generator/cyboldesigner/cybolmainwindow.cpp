#include <QDir>
#include <QLayout>
#include <QLabel>
#include <QMessageBox>
#include <QMultiMap>
#include <QFileDialog>

#include "cybolmainwindow.h"
#include "ui_cybolmainwindow.h"
#include "cybolreader.h"
#include "variables.h"
#include "displaywindow.h"
#include "createwidgetbox.h"
#include "inireader.h"

// CybolMainWindow::CybolMainWindow ***********************************************************************************
//
//*********************************************************************************************************************
CybolMainWindow::CybolMainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::CybolMainWindow),
    m_disp( new DisplayWindow( this ) )
{
    m_ui->setupUi(this);
    iniReader::getInstance();

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

    connect( m_ui->action_OEffnen, &QAction::triggered, this, &CybolMainWindow::openFile );
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

        m_disp->showWidget( filename, widgets );
    }
}
