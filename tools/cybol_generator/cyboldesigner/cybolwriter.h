#ifndef CYBOLWRITER_H
#define CYBOLWRITER_H

#include <QXmlStreamWriter>

#include "window.h"
#include "widget.h"
#include "variables.h"

class CybolWriter
{
public:
    CybolWriter();
    CybolWriter( QString & file );

    /*!
     * \brief saveToFile
     * \param file
     * \return
     *
     * Return values:
     * \t 0 :\t nothing wrong
     * \t 1 :\t Could not open File
     * \t 2 :\t QDockWidget is nullptr
     */
    int saveToFile(Window *window, QString file = "" );
    int writePart(QXmlStreamWriter &xmlWriter,
                    Widget *widget,
                    Elements element );

private:
    QString m_file;
    QString m_newFilename;
    bool m_new, m_close;
    QFile file;
};

#endif // CYBOLWRITER_H
