#include <QWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QDir>
#include <QLabel>
#include <QPushButton>

#include "button.h"
#include "colorreader.h"
#include "cybolreader.h"
#include "displaywindow.h"
#include "rectangle.h"
#include "window.h"

// DisplayWindow::DisplayWindow ***************************************************************************************
//
//*********************************************************************************************************************
DisplayWindow::DisplayWindow(CybolMainWindow *mainWindow):
    m_mainWindow( mainWindow )
{
    m_mainWindow->m_window = new Window();
    if( m_mainWindow->m_window != 0 ) {
        delete m_mainWindow->m_window;
        m_mainWindow->m_window = 0;
    }
}

// DisplayWindow::~DisplayWindow **************************************************************************************
//
//*********************************************************************************************************************
DisplayWindow::~DisplayWindow()
{
    if( m_mainWindow->m_window != 0 ) {
        delete m_mainWindow->m_window;
        m_mainWindow->m_window = 0;
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

        if( ( prop.name == "shape" ) && ( prop.model == "window" ) ) {
            createWindow( widgets, (QString &) iterWidgets.key() );
            continue;
        }
    }

    for( iterWidgets = widgets.begin(); iterWidgets != widgets.end(); ++iterWidgets ) {
        properties prop = iterWidgets.value();
        if( !prop.property && ( prop.format == "element/part" ) && !readedFiles.contains( prop.model ) ) {
            file += prop.model;
            CybolReader::scanFile( file, widgets );
            iterWidgets = widgets.begin();
            readedFiles.append( prop.model );
        }

        if( prop.name == "shape" ) {

            if( m_mainWindow->m_window == 0 ) {
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

    m_mainWindow->setCursor( Qt::ArrowCursor );
}

// DisplayWindow::createWindow ****************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createWindow(
        QMultiMap<QString, properties> widgets,
        QString &key )
{
    //delete the old window if exists
    if( m_mainWindow->m_window != 0 ) {
        delete m_mainWindow->m_window;
        m_mainWindow->m_window = 0;
    }
    Elements element;

    element.elementtype = WINDOW;
    m_mainWindow->m_window = new Window( m_mainWindow->m_ui->centralWidget );
    m_mainWindow->m_window->setFeatures( QDockWidget::DockWidgetClosable );
    m_mainWindow->m_window->setAllowedAreas( Qt::NoDockWidgetArea );

    m_mainWindow->m_window->setAutoFillBackground( true );

    QMultiMap<QString, properties>::iterator iterWidgets;
    bool keyFound = false;

    PROPERS pro;

    for( iterWidgets = widgets.begin(); iterWidgets != widgets.end(); ++iterWidgets ) {
        properties prop = iterWidgets.value();

        if( ( key != iterWidgets.key() ) && !keyFound ) {
            continue;
        } else{
            keyFound = true;
        }

        if( !prop.property ) {
            element.name = prop.name;
        }

        if( ( prop.name == "text" ) && prop.property ) {
            m_mainWindow->m_window->setWindowTitle( prop.model );
            pro = TEXT;
        }

        if( ( prop.name == "size" ) && prop.property ) {
            QString width = prop.model.left( prop.model.indexOf( "," ) );
            QString height = prop.model.right( prop.model.indexOf( "," ) );
            m_mainWindow->m_window->setMinimumSize( width.toInt(), height.toInt() );
            m_mainWindow->m_window->setMaximumSize( width.toInt(), height.toInt() );
            pro = SIZE;
        }

        if( ( prop.name == "position") && prop.property ) {
            QString xPos = prop.model.left( prop.model.indexOf("," ) );
            QString yPos = prop.model.right( prop.model.indexOf( "," ) );

            m_mainWindow->m_window->setGeometry( xPos.toInt(), yPos.toInt(), m_mainWindow->m_window->width(), m_mainWindow->m_window->height() );
            pro = POSITION;
        }

        if( ( prop.name == "background-color" ) && prop.property ) {
            RGB bgcolor = colorReader::getRGB( prop.model );

            QPalette palette = m_mainWindow->m_window->palette();
            palette.setColor(QPalette::Window, QColor( bgcolor.red, bgcolor.green, bgcolor.blue ) );

            m_mainWindow->m_window->setPalette( palette );

            pro = BACKGROUNDCOLOR;
        }

        if( (prop.name == "foreground-color" ) && prop.property ) {
            RGB fgcolor = colorReader::getRGB( prop.model );

            QPalette palette = m_mainWindow->m_window->palette();
            palette.setColor(QPalette::WindowText, QColor( fgcolor.red, fgcolor.green, fgcolor.blue ) );

            m_mainWindow->m_window->setPalette( palette );

            pro = COLOR;
        }

        if( ( iterWidgets.key() != key ) && keyFound ) {
            break;
        }        

        element.properties.insert( pro, prop.model );
    }

    element.self = m_mainWindow->m_window;

    m_mainWindow->m_window->setElement( element );

    m_mainWindow->m_window->show();
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
    Button * button = new Button( m_mainWindow->m_window );
    Elements element;
    element.elementtype = BUTTON;
    QMultiMap<QString, properties>::iterator iterWidgets;

    bool keyFound = false;
    QString xPos, yPos, width, height;

    PROPERS pro;

    for( iterWidgets = widgets.begin(); iterWidgets != widgets.end(); ++iterWidgets ) {
        properties prop = iterWidgets.value();

        if( ( key != iterWidgets.key() ) && !keyFound ) {
            continue;
        } else{
            keyFound = true;
        }

        //müsste der parttag sein
        if( !prop.property ) {
            element.name = prop.name;
        }

        if( ( prop.name.compare( "shape", Qt::CaseInsensitive ) == 0 ) && prop.property ) {
            pro = SHAPE;
        }

        if( ( prop.name.compare( "text", Qt::CaseInsensitive ) == 0 ) && prop.property ) {
            button->setText( prop.model );
            pro = TEXT;
        }

        if( ( prop.name == "position") && prop.property ) {
            xPos = prop.model.left( prop.model.indexOf("," ) );
            yPos = prop.model.right( prop.model.indexOf( "," ) );

            if( yPos.contains(",") ) {
                yPos.remove(",");
            }

            pro = POSITION;
        }

        if( ( prop.name == "size" ) && prop.property ) {
            width = prop.model.left( prop.model.indexOf( "," ) );
            height = prop.model.right( prop.model.indexOf( "," ) - 1 );

            pro = SIZE;
        }

        if( ( prop.name == "background-colour" ) && prop.property ) {
            RGB rgb = colorReader::getRGB( prop.model );

            QString stylesheet = "background-color:rgb(" + QString::number( rgb.red )
                    + "," + QString::number( rgb.green ) + "," + QString::number( rgb.blue ) + ")";
            button->setStyleSheet( stylesheet );

            pro = BACKGROUNDCOLOR;
        }

        if( ( prop.name == "colour" ) && prop.property ) {
            RGB rgb = colorReader::getRGB( prop.model );

            QPalette palette = button->palette();
            palette.setColor( button->foregroundRole(), QColor( rgb.red, rgb.green, rgb.blue ));

            button->setPalette( palette );

            pro = COLOR;
        }

        if( ( prop.name.compare( "enabled", Qt::CaseInsensitive ) == 0 ) && prop.property ) {
            pro = ENABLED;
        }

        if( ( prop.name.compare( "icon", Qt::CaseInsensitive ) == 0 ) && prop.property ) {
            pro = ICON;
        }

        if( ( prop.name.compare( "tooltip", Qt::CaseInsensitive ) == 0 ) && prop.property ) {
            pro = TOOLTIP;
        }

        if( ( prop.name.compare( "tooltip-duration", Qt::CaseInsensitive ) == 0 ) && prop.property ) {
            pro = TOOLTIPDURATION;
        }

        if( ( prop.name.compare( "cursor", Qt::CaseInsensitive ) == 0 ) && prop.property ) {
            pro = CURSOR;
        }

        if( ( prop.name.compare( "opacity", Qt::CaseInsensitive ) == 0 ) && prop.property ) {
            pro = OPACITY;
        }

        if( ( key != iterWidgets.key() ) && keyFound ) {
            break;
        }


        element.properties.insert( pro, prop.model );
    }

    button->setGeometry( xPos.toInt(), yPos.toInt(), width.toInt(), height.toInt());

    element.self = button;
    button->setElement( element );
    button->show();
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
    Image * image = new Image();

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
            image->setText( prop.model );
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

            image->setStyleSheet( "background-color:rgb("
                                  + QString::number( rgb.red )
                                  + ","
                                  + QString::number( rgb.green )
                                  + ","
                                  + QString::number( rgb.blue )
                                  + ")" );
        }

        if( ( prop.name == "foreground-color" ) && prop.property ) {
            RGB rgb = colorReader::getRGB( prop.model );

            image->setStyleSheet( "color:rgb("
                                  + QString::number( rgb.red )
                                  + ","
                                  + QString::number( rgb.green )
                                  + ","
                                  + QString::number( rgb.blue )
                                  + ")" );
        }

        if( ( key != iterWidgets.key() ) && keyFound ) {
            break;
        }
    }

    image->setGeometry( xPos.toInt(), yPos.toInt(), width.toInt(), height.toInt());

    m_imageList.append( image );
    m_mainWindow->layout()->addWidget( m_imageList[ m_imageList.size() - 1 ] );

}

// DisplayWindow::createRectangle ***************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createRectangle(
        QMultiMap<QString, properties> widgets,
        QString & key ) {
    Rectangle * rectangle = new Rectangle();
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
            rectangle->setText( prop.model );
        }

        if( prop.name == "text" ) {
            rectangle->setText( prop.model );
        }

        if( ( prop.name == "position") && prop.property ) {
            xPos = prop.model.left( prop.model.indexOf("," ) );
            yPos = prop.model.right( prop.model.indexOf( "," ) - 1 );
        }

        if( ( prop.name == "size" ) && prop.property ) {
            width = prop.model.left( prop.model.indexOf( "," ) );
            height = prop.model.right( prop.model.indexOf( "," ) - 1 );
        }

        if( ( prop.name == "background-color" ) && prop.property ) {
            RGB rgb = colorReader::getRGB( prop.model );

            rectangle->setFillColor( rgb );
        }

        if( ( prop.name == "foreground-color" ) && prop.property ) {
            RGB rgb = colorReader::getRGB( prop.model );

            rectangle->setFontColor( rgb );
        }

        if( ( key != iterWidgets.key() ) && keyFound ) {
            break;
        }
    }

    rectangle->setGeometry( xPos.toInt(), yPos.toInt(), width.toInt(), height.toInt());

    m_rectangleList.append( rectangle );
    m_mainWindow->layout()->addWidget( m_rectangleList[ m_rectangleList.size() - 1 ] );
}

// DisplayWindow::createGroupBox ****************************************************************************************
//
//*********************************************************************************************************************
void
DisplayWindow::createGroupBox(
        QMultiMap<QString, properties> widgets,
        QString & key ) {

}
