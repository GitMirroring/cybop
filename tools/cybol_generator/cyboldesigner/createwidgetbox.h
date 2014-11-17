#ifndef CREATEWIDGETBOX_H
#define CREATEWIDGETBOX_H

#include <QXmlStreamReader>
#include <QMultiMap>
#include <QVBoxLayout>

#include "cybolmainwindow.h"

class CybolMainWindow;

/*!
 * \brief The CreateWidgetBox class
 */
class CreateWidgetBox
{
public:
    /*!
     * \brief CreateWidgetBox
     */
    CreateWidgetBox( CybolMainWindow *parent);

    /*!
     * \brief CreateWidgetBox
     * \param parent
     * \param operDir
     * \param filename - Defaultvalue : elements.xml
     */
    CreateWidgetBox( CybolMainWindow *parent, QString operDir, QString filename = "../widgets/elements.xml" );
    ~CreateWidgetBox();

    /*!
     * \brief scanElementFile
     *
     * Funktion liest die elements.xml Datei und erzeugt daraus die Widgetbox.
     */
    void scanElementFile( void );

private:

    //! \brief m_operDir - operating directory
    QString m_operDir;

    //! \brief m_filename - filename of the describing file
    QString m_filename;

    QMultiMap< QString, QString> m_values;

    //! \brieg m_mainWindow
    CybolMainWindow * m_mainWindow;

    QVBoxLayout * m_layout;

    /*!
     * \brief displayGroupLabel
     *
     * Erzeugt das Label mit dem Titel.
     */
    void displayGroupLabel( QXmlStreamReader &xml, QString & key );

    /*!
     * \brief displayWidget
     */
    void displayWidget(QXmlStreamReader &xml , QString &key);

    /*!
     * \brief displayAll
     */
    void displayAll( void );

};

#endif // CREATEWIDGETBOX_H
