#ifndef FOCUSELEMENT_H
#define FOCUSELEMENT_H

#include <QWidget>

class focusElement : QWidget
{
    Q_OBJECT

public:
    focusElement();

public slots:
    void focusWindow( void );

};

#endif // FOCUSELEMENT_H
