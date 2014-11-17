#include <QWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QDir>
#include <QLabel>
#include <QPushButton>

#include "colorreader.h"
#include "cybolreader.h"
#include "displaywindow.h"

// DisplayWindow::DisplayWindow ***************************************************************************************
//
//*********************************************************************************************************************
DisplayWindow::DisplayWindow(CybolMainWindow *mainWindow):
    m_mainWindow( mainWindow ),
    m_window( 0 )
{
}

// DisplayWindow::~DisplayWindow **************************************************************************************
//
//*********************************************************************************************************************
DisplayWindow::~DisplayWindow()
{
    if( m_window != 0 ) {
        delete m_window;
    }
    delete m_mainWindow;
}

// DisplayWindow::showWindow ******************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::showWidget( QString & filename, QMultiMap<QString, properties> widgets )
{
    QMultiMap< QString, properties >::iterator iterWidgets;
    QString file = filename;
    if( file.contains("/") ) {
        file = file.left( file.lastIndexOf("/") + 1 );
    } else {
        file = file.left( file.lastIndexOf( QDir::separator() ) + 1 );
    }

    QList<QString> readedFiles;

    for( iterWidgets = widgets.begin(); iterWidgets != widgets.end(); ++iterWidgets ) {
        properties prop = iterWidgets.value();
        if( !prop.property && ( prop.format == "element/part" ) && !readedFiles.contains( prop.model ) ) {
            file += prop.model;
            CybolReader::scanFile( file, widgets );
            iterWidgets = widgets.begin();
            readedFiles.append( prop.model );
        }

        if( prop.name == "shape" ) {

            if( prop.model == "window" ) {
                createWindow( widgets, (QString &) iterWidgets.key() );
                continue;
            }

            if( m_window == 0 ) {
                QMessageBox::critical( m_mainWindow,
                                       "No window created",
                                       "There was not created a window, so there is no widget to fill.",
                                       QMessageBox::Ok );
               return;
            }

            if( prop.model == "button" ) {
                createButton( widgets, (QString &) iterWidgets.key() );
                continue;
            }

            if( prop.model == "label" ) {
                //createLabel( widgets, (QString &) iterWidgets.key() );
                continue;
            }

            if( prop.model == "checkbox" ) {
                createCheckBox( widgets, (QString &) iterWidgets.key() );
                continue;
            }

            if( prop.model == "radiobutton" ) {
                createRadioButton( widgets, (QString &) iterWidgets.key() );
                continue;
            }

            if( prop.model == "image" ) {
                createImage( widgets, (QString &) iterWidgets.key() );
                continue;
            }

            if( prop.model == "rectangle" ) {
                createRectangle( widgets, (QString &) iterWidgets.key() );
                continue;
            }

            if( prop.model == "groupbox" ) {
                createGroupBox( widgets, (QString &) iterWidgets.key() );
                continue;
            }
        }
    }
}

// DisplayWindow::createWindow ****************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createWindow(
        QMultiMap<QString, properties> widgets,
        QString &key )
{
    m_window = new QDockWidget( "later", m_mainWindow->m_ui->centralWidget );
    m_window->setAllowedAreas( Qt::NoDockWidgetArea );
    m_window->setFeatures( !QDockWidget::DockWidgetClosable);
    m_window->setAutoFillBackground( true );

    QMultiMap<QString, properties>::iterator iterWidgets;
    bool keyFound = false;

    for( iterWidgets = widgets.begin(); iterWidgets != widgets.end(); ++iterWidgets ) {
        properties prop = iterWidgets.value();

        if( ( key != iterWidgets.key() ) && !keyFound ) {
            continue;
        } else{
            keyFound = true;
        }

        if( ( prop.name == "title" ) && prop.property ) {
            m_window->setWindowTitle( prop.model );
        }

        if( ( prop.name == "size" ) && prop.property ) {
            QString width = prop.model.left( prop.model.indexOf( "," ) );
            QString height = prop.model.right( prop.model.indexOf( "," ) );
            m_window->setMinimumSize( width.toInt(), height.toInt() );
            m_window->setMaximumSize( width.toInt(), height.toInt() );
        }

        if( ( prop.name == "position") && prop.property ) {
            QString xPos = prop.model.left( prop.model.indexOf("," ) );
            QString yPos = prop.model.right( prop.model.indexOf( "," ) );

            m_window->setGeometry( xPos.toInt(), yPos.toInt(), m_window->width(), m_window->height() );
        }

        if( ( prop.name == "background-color" ) && prop.property ) {
            RGB bgcolor = colorReader::getRGB( prop.model );

            QPalette palette = m_window->palette();
            palette.setColor(QPalette::Window, QColor( bgcolor.red, bgcolor.green, bgcolor.blue ) );

            m_window->setPalette( palette );
        }

        if( (prop.name == "foreground-color" ) && prop.property ) {
            RGB fgcolor = colorReader::getRGB( prop.model );

            QPalette palette = m_window->palette();
            palette.setColor(QPalette::WindowText, QColor( fgcolor.red, fgcolor.green, fgcolor.blue ) );

            m_window->setPalette( palette );
        }

        if( ( iterWidgets.key() != key ) && keyFound ) {
            break;
        }
    }

    QVBoxLayout vboxlayout;
    vboxlayout.addWidget(m_window);
    m_mainWindow->m_ui->centralWidget->setLayout(&vboxlayout);
}

// DisplayWindow::deleteOldOne ****************************************************************************************
//
//*********************************************************************************************************************
int
DisplayWindow::deleteOldOne(
        void )
{
    if( m_window != 0 ) {
        delete m_window;
    }

    return 0;
}

// DisplayWindow::createButton ****************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createButton(
        QMultiMap<QString, properties> widgets,
        QString & key ) {
    QPushButton * button = new QPushButton();
    QMultiMap<QString, properties>::iterator iterWidgets;

    bool keyFound = false;
    QString xPos, yPos, width, height;

    for( iterWidgets = widgets.begin(); iterWidgets != widgets.end(); ++iterWidgets ) {
        properties prop = iterWidgets.value();

        if( ( key != iterWidgets.key() ) && !keyFound ) {
            continue;
        } else{
            keyFound = true;
        }

        //müsste theoretisch der part tag sein
        if( !prop.property ) {
            button->setText( prop.model );
        }

        if( ( prop.name == "position") && prop.property ) {
            xPos = prop.model.left( prop.model.indexOf("," ) );
            yPos = prop.model.right( prop.model.indexOf( "," ) );
        }

        if( ( prop.name == "size" ) && prop.property ) {
            width = prop.model.left( prop.model.indexOf( "," ) );
            height = prop.model.right( prop.model.indexOf( "," ) - 1 );
        }

        if( ( prop.name == "background-color" ) && prop.property ) {
            RGB rgb = colorReader::getRGB( prop.model );

            QPalette palette = button->palette();

            palette.setColor( button->backgroundRole(), QColor( rgb.red, rgb.green, rgb.blue ) );

            button->setPalette( palette );
        }

        if( ( prop.name == "foreground-color" ) && prop.property ) {
            RGB rgb = colorReader::getRGB( prop.model );

            QPalette palette = button->palette();
            palette.setColor( button->foregroundRole(), QColor( rgb.red, rgb.green, rgb.blue ));

            button->setPalette( palette );
        }

        if( ( key != iterWidgets.key() ) && keyFound ) {
            break;
        }
    }

    button->setGeometry( xPos.toInt(), yPos.toInt(), width.toInt(), height.toInt());

    m_window->layout()->addWidget( button );
}

// DisplayWindow::createCheckBox ****************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createCheckBox(
        QMultiMap<QString, properties> widgets,
        QString & key ) {

}

// DisplayWindow::createRadioButton *************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createRadioButton(
        QMultiMap<QString, properties> widgets,
        QString & key ) {

}

// DisplayWindow::createImage *******************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createImage(
        QMultiMap<QString, properties> widgets,
        QString & key ) {

}

// DisplayWindow::createRectangle ***************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createRectangle(
        QMultiMap<QString, properties> widgets,
        QString & key ) {
    QLabel * label = new QLabel();
    QMultiMap<QString, properties>::iterator iterWidgets;

    bool keyFound = false;
    QString xPos, yPos, width, height;

    for( iterWidgets = widgets.begin(); iterWidgets != widgets.end(); ++iterWidgets ) {
        properties prop = iterWidgets.value();

        if( ( key != iterWidgets.key() ) && !keyFound ) {
            continue;
        } else{
            keyFound = true;
        }

        //müsste theoretisch der part tag sein
        if( !prop.property ) {
            label->setText( prop.model );
        }

        if( ( prop.name == "position") && prop.property ) {
            xPos = prop.model.left( prop.model.indexOf("," ) );
            yPos = prop.model.right( prop.model.indexOf( "," ) );
        }

        if( ( prop.name == "size" ) && prop.property ) {
            width = prop.model.left( prop.model.indexOf( "," ) );
            height = prop.model.right( prop.model.indexOf( "," ) );
        }

        if( ( prop.name == "background-color" ) && prop.property ) {
            RGB rgb = colorReader::getRGB( prop.model );

            QPalette palette = label->palette();

            palette.setColor( label->backgroundRole(), QColor( rgb.red, rgb.green, rgb.blue ) );

            label->setPalette( palette );
        }

        if( ( prop.name == "foreground-color" ) && prop.property ) {
            RGB rgb = colorReader::getRGB( prop.model );

            QPalette palette = label->palette();
            palette.setColor( label->foregroundRole(), QColor( rgb.red, rgb.green, rgb.blue ));

            label->setPalette( palette );
        }

        if( ( key != iterWidgets.key() ) && keyFound ) {
            break;
        }
    }

    label->setGeometry( xPos.toInt(), yPos.toInt(), width.toInt(), height.toInt());

    m_window->layout()->addWidget( label );
}

// DisplayWindow::createGroupBox ****************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createGroupBox(
        QMultiMap<QString, properties> widgets,
        QString & key ) {

}
