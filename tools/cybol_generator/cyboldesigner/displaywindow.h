#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMultiMap>
#include <QString>

#include "variables.h"
#include "cybolmainwindow.h"
#include "ui_cybolmainwindow.h"

class CybolMainWindow;

/*!
 * \brief The DisplayWindow class
 *
 * Is used to display the created window.
 */
class DisplayWindow
{
public:
    DisplayWindow( CybolMainWindow * mainWindow );
    virtual ~DisplayWindow();

    void showWidget(QString &filename, QMultiMap< QString, properties > widgets );
    int deleteOldOne( void );

private:

    CybolMainWindow * m_mainWindow;
    QDockWidget * m_window;

    void createWindow( QMultiMap<QString, properties> widgets, QString & key );
    void createButton( QMultiMap<QString, properties> widgets, QString & key );
    void createCheckBox( QMultiMap<QString, properties> widgets, QString & key );
    void createRadioButton( QMultiMap<QString, properties> widgets, QString & key );
    void createImage( QMultiMap<QString, properties> widgets, QString & key );
    void createRectangle( QMultiMap<QString, properties> widgets, QString & key );
    void createGroupBox( QMultiMap<QString, properties> widgets, QString & key );

};

#endif // DISPLAYWINDOW_H
