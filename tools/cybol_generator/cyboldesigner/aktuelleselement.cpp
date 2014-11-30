#include <QLabel>

#include <QStandardItem>
#include <QStandardItemModel>
#include <QTableView>

#include <QMessageBox>

#include "aktuelleselement.h"
#include "propertyconverter.h"

#define PROPERTIECOL 0
#define SELECTIONPOINTS 6

aktuellesElement* aktuellesElement::m_self = 0;

// aktuellesElement::aktuellesElement *********************************************************************************
//
//*********************************************************************************************************************
aktuellesElement::aktuellesElement( QObject * parent ):
    QObject( parent )
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
    m_model = new QStandardItemModel();

    m_model->connect( m_model, &QStandardItemModel::itemChanged, this, &aktuellesElement::changedItem );

    m_model->setHorizontalHeaderItem( 0, new QStandardItem( "Eigenschaft" ) );
    m_model->setHorizontalHeaderItem( 1, new QStandardItem( "Wert" ) );

    QMap< PROPERS, QString >::Iterator iterElements;

    for( iterElements = m_element.properties.begin();
         iterElements != m_element.properties.end();
         ++iterElements )
    {
        QList< QStandardItem *> list;


        QStandardItem * prop = new QStandardItem();
        QStandardItem * value = new QStandardItem();

        switch( iterElements.key() ) {
        case SHAPE:
            prop->setText( STRSHAPE );
            value->setEditable( false );
            break;

        case SIZE:
            prop->setText( STRSIZE );
            break;

        case POSITION:
            prop->setText( STRPOSITION );
            break;

        case COLOR:
            prop->setText( STRCOLOR );
            break;

        case BACKGROUNDCOLOR:
            prop->setText( STRBACKGROUND );
            break;

        case ENABLED:
            prop->setText( STRENABLED );
            break;

        case TEXT:
            prop->setText( STRTEXT );
            break;

        case ICON:
            prop->setText( STRICON );
            break;

        case TOOLTIP:
            prop->setText( STRTOOLTIP );
            break;

        case TOOLTIPDURATION:
            prop->setText( STRTOOLTIPDURATION );
            break;

        case CURSOR:
            prop->setText( STRCURSOR );
            break;

        case OPACITY:
            prop->setText( STROPACITY );
            break;
        }

        prop->setEditable( false );

        value->setText( iterElements.value() );

        list.append( prop );
        list.append( value );

        m_model->appendRow( list );
    }

    view->setModel( m_model );

    m_mainWindow->m_ui->objectinspector->setWidget( view );
}

void
aktuellesElement::changedItem(
        QStandardItem * item )
{
    int row = item->row();

    if( row != PROPERTIECOL ) {

        QStandardItem * prop = m_model->item( row, PROPERTIECOL );

        QMap< PROPERS, QString>::const_iterator iterElements;

        PROPERS toRemove;

        if( prop->text().compare( STRSIZE, Qt::CaseInsensitive ) == 0 ) {
            toRemove = SIZE;

            QMessageBox::information( 0, "", item->text(), QMessageBox::Ok );
            if( !item->text().contains( QRegExp( "^\\d+,\\d+$" ) ) ) {
                item->setText( m_element.properties.value( toRemove ) );
            }

            QString strsize = item->text();

            Size size = PropertyConverter::getSize( strsize );

            m_element.self->resize( size.width, size.height );
        } else if( prop->text().compare( STRPOSITION, Qt::CaseInsensitive ) == 0 ) {
            toRemove = POSITION;

            if( !item->text().contains( QRegExp( "^\\d+,\\d+$" ) ) ) {
                item->setText( m_element.properties.value( toRemove ) );
            }

            QString pos = item->text();

            Position ppos = PropertyConverter::getPosition( pos );

            m_element.properties.remove( toRemove );
            m_element.properties.insert( toRemove, pos );

            m_element.self->move( ppos.x, ppos.y );

        } else if( prop->text().compare( STRCOLOR, Qt::CaseInsensitive ) == 0 ) {
            toRemove = COLOR;
        } else if( prop->text().compare( STRBACKGROUND, Qt::CaseInsensitive ) == 0 ) {
            toRemove = BACKGROUNDCOLOR;
        } else if( prop->text().compare( STRENABLED, Qt::CaseInsensitive )  == 0 ) {
            toRemove = ENABLED;

            if( !item->text().compare( "true", Qt::CaseInsensitive )
                    && !item->text().compare( "false", Qt::CaseInsensitive ) ) {
                item->setText( m_element.properties.value( toRemove ) );
            }
        } else if( prop->text().compare( STRTEXT, Qt::CaseInsensitive ) == 0 ) {
            toRemove = TEXT;

            // !!TODO!!
        } else if( prop->text().compare( STRICON, Qt::CaseInsensitive ) == 0 ) {
            toRemove = ICON;

            // !!TODO!!
        } else if( prop->text().compare( STRTOOLTIP, Qt::CaseInsensitive ) == 0 ) {
            toRemove = TOOLTIP;
        } else if( prop->text().compare( STRTOOLTIPDURATION, Qt::CaseInsensitive ) == 0 ) {
            toRemove = TOOLTIPDURATION;
        } else if( prop->text().compare( STRCURSOR, Qt::CaseInsensitive ) == 0 ) {
            toRemove = CURSOR;
        } else if( prop->text().compare( STROPACITY, Qt::CaseInsensitive ) == 0 ) {
            toRemove = OPACITY;
        } else {
            //No Propertie

            return;
        }

        //Getting the positoin for insert
        for( iterElements = m_element.properties.cbegin();
             iterElements != m_element.properties.cend();
             ++iterElements )
        {
            if( iterElements.key() == toRemove) {

                break;
            }
        }

        m_element.properties.remove( toRemove );
        m_element.properties.insert( toRemove, item->text() );
    }
}
