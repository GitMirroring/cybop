#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include "cybolmainwindow.h"

class CybolMainWindow;

class CreateWindow
{

public:
    CreateWindow(CybolMainWindow *parent);
    void createNewWindow();

private:
    CybolMainWindow * m_mainWindow;
    QDockWidget * m_window;

};

#endif // CREATEWINDOW_H
