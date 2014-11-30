#include <QLabel>

#include <QStandardItem>
#include <QStandardItemModel>
#include <QTableView>

#include "aktuelleselement.h"

#define SELECTIONPOINTS 6

aktuellesElement* aktuellesElement::m_self = 0;

// aktuellesElement::aktuellesElement *********************************************************************************
//
//*********************************************************************************************************************
aktuellesElement::aktuellesElement()
{
    m_element.self = 0;

    m_imgAtXY = new FocusPoints();
    m_imgAtX = new FocusPoints();
    m_imgAtY = new FocusPoints();
    m_imgAtWidthAndHeight = new FocusPoints();
    m_halfHeightLeft = new FocusPoints();
    m_halfHeightRight = new FocusPoints();
    m_halfWidthBottom = new FocusPoints();
    m_halfWidthTop = new FocusPoints();
}

// aktuellesElement::getInstance **************************************************************************************
//
//*********************************************************************************************************************
aktuellesElement *
aktuellesElement::getInstance(
        void )
{
    if( !m_self ) {
        m_self = new aktuellesElement();
    }

    return m_self;
}

// aktuellesElement::setMainWindow ************************************************************************************
//
//*********************************************************************************************************************
void
aktuellesElement::setMainWindow(CybolMainWindow *mainWindow )
{
    m_mainWindow = mainWindow;
}

Elements
aktuellesElement::getElement(
        void )
{
    return m_element;
}

void
aktuellesElement::setElement(Elements &element )
{
    onElementChangedEvent( element );



    m_imgAtX->setParent( m_mainWindow->m_window );
    m_imgAtXY->setParent( m_mainWindow->m_window );
    m_imgAtY->setParent( m_mainWindow->m_window );
    m_imgAtWidthAndHeight->setParent( m_mainWindow->m_window );
    m_halfHeightLeft->setParent( m_mainWindow->m_window );
    m_halfHeightRight->setParent( m_mainWindow->m_window );
    m_halfWidthBottom->setParent( m_mainWindow->m_window );
    m_halfWidthTop->setParent( m_mainWindow->m_window );

    QString style = "border-color: rgb(0, 0, 0); background-color: rgb(21, 0, 255);";

    m_imgAtXY->setStyleSheet( style );
    m_imgAtXY->setGeometry( m_element.self->pos().x() - int( SELECTIONPOINTS / 2 ),
                            m_element.self->pos().y() - int( SELECTIONPOINTS / 2 ),
                            SELECTIONPOINTS,
                            SELECTIONPOINTS );
    m_imgAtXY->setPosition( TOPLEFT );
    m_imgAtXY->setElement( m_element.self );
    m_imgAtXY->show();

    m_imgAtX->setStyleSheet( style );
    m_imgAtX->setGeometry( m_element.self->pos().x() - int( SELECTIONPOINTS / 2 ),
                         m_element.self->pos().y() + m_element.self->height() - int( SELECTIONPOINTS / 2 ),
                         SELECTIONPOINTS,
                         SELECTIONPOINTS );
    m_imgAtX->setPosition( BOTTOMLEFT );
    m_imgAtX->setElement( m_element.self );
    m_imgAtX->show();

    m_imgAtY->setStyleSheet( style );
    m_imgAtY->setGeometry( m_element.self->pos().x() + m_element.self->width() - int( SELECTIONPOINTS / 2 ),
                           m_element.self->pos().y() - int( SELECTIONPOINTS / 2 ),
                            SELECTIONPOINTS,
                            SELECTIONPOINTS );
    m_imgAtY->setPosition( TOPRIGHT );
    m_imgAtY->setElement( m_element.self );
    m_imgAtY->show();

    m_imgAtWidthAndHeight->setStyleSheet( style );
    m_imgAtWidthAndHeight->setGeometry( m_element.self->pos().x() + m_element.self->width() - int( SELECTIONPOINTS / 2 ),
                                        m_element.self->pos().y() + m_element.self->height() - int( SELECTIONPOINTS / 2 ),
                                        SELECTIONPOINTS,
                                        SELECTIONPOINTS );
    m_imgAtWidthAndHeight->setPosition( BOTTOMRIGHT );
    m_imgAtWidthAndHeight->setElement( m_element.self );
    m_imgAtWidthAndHeight->show();

    m_halfHeightLeft->setStyleSheet( style );
    m_halfHeightLeft->setGeometry( m_element.self->pos().x() - int ( SELECTIONPOINTS / 2 ),
                                   m_element.self->pos().y() + int( m_element.self->height() / 2 ) - int( SELECTIONPOINTS / 2 ),
                                   SELECTIONPOINTS,
                                   SELECTIONPOINTS );
    m_halfHeightLeft->setPosition( LEFT );
    m_halfHeightLeft->setElement( m_element.self );
    m_halfHeightLeft->show();

    m_halfHeightRight->setStyleSheet( style );
    m_halfHeightRight->setGeometry( m_element.self->pos().x() + m_element.self->width() - int ( SELECTIONPOINTS / 2 ),
                                   m_element.self->pos().y() + int( m_element.self->height() / 2 ) - int( SELECTIONPOINTS / 2 ),
                                   SELECTIONPOINTS,
                                   SELECTIONPOINTS );
    m_halfHeightRight->setPosition( RIGHT );
    m_halfHeightRight->setElement( m_element.self );
    m_halfHeightRight->show();

    m_halfWidthTop->setStyleSheet( style );
    m_halfWidthTop->setGeometry( m_element.self->pos().x() + int( m_element.self->width() / 2 ) - int( SELECTIONPOINTS / 2 ),
                                 m_element.self->pos().y() - int( SELECTIONPOINTS / 2 ),
                                 SELECTIONPOINTS,
                                 SELECTIONPOINTS);
    m_halfWidthTop->setPosition( TOP );
    m_halfWidthTop->setElement( m_element.self );
    m_halfWidthTop->show();

    m_halfWidthBottom->setStyleSheet( style );
    m_halfWidthBottom->setGeometry( m_element.self->pos().x() + int( m_element.self->width() / 2 ) - int( SELECTIONPOINTS / 2 ),
                                 m_element.self->pos().y() + m_element.self->height() - int( SELECTIONPOINTS / 2 ),
                                 SELECTIONPOINTS,
                                 SELECTIONPOINTS);
    m_halfWidthBottom->setPosition( BOTTOM );
    m_halfWidthBottom->setElement( m_element.self );
    m_halfWidthBottom->show();

}

void
aktuellesElement::onElementChangedEvent(
        Elements &element )
{
    if( m_element.name != element.name ){
        m_element = element;
        showObjectInspector();
    }
}

void
aktuellesElement::showObjectInspector(
        void )
{
    QTableView * view = new QTableView();
    QStandardItemModel * model = new QStandardItemModel();

    model->setHorizontalHeaderItem( 0, new QStandardItem( "Eigenschaft" ) );
    model->setHorizontalHeaderItem( 1, new QStandardItem( "Wert" ) );

    view->setModel( model );

    m_mainWindow->m_ui->objectinspector->setWidget( view );
}
