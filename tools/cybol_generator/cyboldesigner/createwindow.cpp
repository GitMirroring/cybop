#include "window.h"
#include "createwindow.h"

CreateWindow::CreateWindow( CybolMainWindow * parent ) :
    m_mainWindow( parent )
{
    if( m_mainWindow->m_window != 0 ) {
        delete m_mainWindow->m_window;
        m_mainWindow->m_window = 0;
    }
}

// CreateWindow::createNewWindow **************************************************************************************
//
//*********************************************************************************************************************
void
CreateWindow::createNewWindow(
        void ) {
    if( m_mainWindow->m_window != 0 ) {
        delete m_mainWindow->m_window;
        m_mainWindow->m_window = 0;
    }
    m_mainWindow->m_window = new Window();

    m_mainWindow->m_window->setGeometry( 20, 20, 500, 300);
    m_mainWindow->m_window->setWindowTitle( "Neues Fenster" );

    QPalette palette = m_mainWindow->m_window->palette();
    palette.setColor( QPalette::Window, QColor( 255, 255, 255) );
    m_mainWindow->m_window->setPalette( palette );

    QVBoxLayout vboxlayout;
    vboxlayout.addWidget(m_mainWindow->m_window);
    m_mainWindow->m_ui->centralWidget->setLayout( &vboxlayout );
}
