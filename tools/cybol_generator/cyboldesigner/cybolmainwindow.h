#ifndef CYBOLMAINWINDOW_H
#define CYBOLMAINWINDOW_H

#include <QMainWindow>
#include <QList>

#include "variables.h"
#include "displaywindow.h"
#include "createwidgetbox.h"
#include "inireader.h"
#include "createwindow.h"
#include "window.h"


namespace Ui {
class CybolMainWindow;
}

class DisplayWindow;
class CreateWidgetBox;
class CreateWindow;

class CybolMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CybolMainWindow(QWidget *parent = 0);
    ~CybolMainWindow();

private:
    Ui::CybolMainWindow *m_ui;
    friend class DisplayWindow;
    friend class CreateWidgetBox;
    friend class CreateWindow;
    DisplayWindow * m_disp;
    CreateWidgetBox * m_cwb;
    CreateWindow * m_cw;
    QList<Elements> m_elementList;

    Window * m_window;

    int buildWidgetBox( void );
    void setupWidgetBox(QMultiMap<QString, QString> &widgets );

private slots:
    void openFile( void );
    void chgWidgetbox( void );
    void chgWidgetBoxView( void );
    void chgObjektinspektor( void );
    void chgObjektinspektorView( void );
    void createWindow( void );
};

#endif // CYBOLMAINWINDOW_H
