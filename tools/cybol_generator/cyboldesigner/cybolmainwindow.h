#ifndef CYBOLMAINWINDOW_H
#define CYBOLMAINWINDOW_H

#include <QMainWindow>
#include "displaywindow.h"
#include "createwidgetbox.h"
#include "inireader.h"


namespace Ui {
class CybolMainWindow;
}

class DisplayWindow;
class CreateWidgetBox;

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
    DisplayWindow * m_disp;
    CreateWidgetBox * m_cwb;

    int buildWidgetBox( void );
    void setupWidgetBox(QMultiMap<QString, QString> &widgets );

private slots:
    void openFile( void );
};

#endif // CYBOLMAINWINDOW_H
