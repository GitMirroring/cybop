#ifndef AKTUELLESELEMENT_H
#define AKTUELLESELEMENT_H

#include <QStandardItem>
#include <QStandardItemModel>
#include <QObject>

#include "focuspoints.h"
#include "cybolmainwindow.h"
#include "variables.h"

class CybolMainWindow;

class aktuellesElement : public QObject
{
    Q_OBJECT
public:
    static aktuellesElement * getInstance( void );

    void setElement( Elements & element );
    void setMainWindow( CybolMainWindow * mainWindow );
    Elements getElement( void );

private:
    void showObjectInspector( void );

protected:
    void onElementChangedEvent( Elements & element );

private:
    FocusPoints * m_imgAtXY,
                * m_imgAtX,
                * m_imgAtY,
                * m_imgAtWidthAndHeight,
                * m_halfHeightLeft,
                * m_halfHeightRight,
                * m_halfWidthTop,
                * m_halfWidthBottom;

    QStandardItemModel * m_model;

    CybolMainWindow * m_mainWindow;

    static aktuellesElement * m_self;

    Elements m_element;
    aktuellesElement(QObject *parent = 0);

private slots:
    void changedItem( QStandardItem * item );
};

#endif // AKTUELLESELEMENT_H
