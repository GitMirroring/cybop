#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>

#include "variables.h"

class Widget : public QObject
{
    Q_OBJECT
public:
    void setElement( Elements element );
    Elements element( void );

protected:
    Elements m_element;

signals:

public slots:

};

#endif // WIDGET_H
