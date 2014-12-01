#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QList>

#include "variables.h"

class Widget : public QObject
{
    Q_OBJECT
public:
    void setElement( Elements element );
    Elements element( void );

    void addChild(Widget *child );
    int removeChild( Widget * child );
    QList< Widget * > children( void );
    bool hasChild( void );

protected:
    Elements m_element;
    QList< Widget * > m_child;
    bool m_hasChilds;

signals:

public slots:

};

#endif // WIDGET_H
