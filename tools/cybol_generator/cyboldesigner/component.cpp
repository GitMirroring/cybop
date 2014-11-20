#include <QStyle>

#include "component.h"

// Component::Component ***********************************************************************************************
//
//*********************************************************************************************************************
Component::Component(
        QString &iconpath,
        QString & text,
        QToolButton *parent ) :
    QToolButton(parent)
{
    this->setStyleSheet( "border:0" );

    if( iconpath != "" ) {
        this->setIcon( QIcon( iconpath ) );
    }

    this->setToolButtonStyle( Qt::ToolButtonTextBesideIcon );
    this->setText( text );
}

// Component::Component ***********************************************************************************************
//
//*********************************************************************************************************************
Component::Component(
        QString &icon,
        QToolButton *parent ) {

    QString text="";
    Component( icon, text, parent );
}

// Component::Component ***********************************************************************************************
//
//*********************************************************************************************************************
Component::Component(QString &text, bool noIcon,
        QToolButton *parent ) {

    QString icon = "";
    Component( icon, text, parent );
}

// Component::mousePressEvent *****************************************************************************************
//
//*********************************************************************************************************************
void
Component::mousePressEvent(
        QMouseEvent *e )
{
}
