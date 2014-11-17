#ifndef CYBOLREADER_H
#define CYBOLREADER_H

#include <QString>
#include <QXmlStreamReader>
#include <QMultiMap>
#include <Qlist>
#include "variables.h"

/*!
 * \brief The CybolReader class
 *
 * Used to read the cybolfile
 */
class CybolReader
{

public:
    //!Scan the cybol-file
    static int scanFile(QString & filename , QMultiMap<QString, properties> &widgets);

private:
    CybolReader();
    virtual ~CybolReader();

    //!read Part tag
    static void readPart(QXmlStreamReader & xml, QMultiMap< QString, properties > & widgets , QString &key);
    //!read property tag
    static void readProperty(QXmlStreamReader & xml, QMultiMap< QString, properties > & widgets , QString &key);
};

#endif // CYBOLREADER_H
