#ifndef INIREADER_H
#define INIREADER_H

#include <QMap>

/*!
 * \brief The iniReader class
 */
class iniReader
{
public:
    /*!
     * \brief getInstance
     * \return
     */
    static iniReader getInstance( void );

    /*!
     * \brief getValue
     * \param key
     * \return
     */
    QString getValue( QString key );

private:
    //! \brief m_values
    QMap<QString, QString> m_values;

    /*!
     * \brief iniReader
     */
    iniReader();

    /*!
     * \brief readValues
     */
    void readValues( void );

};

#endif // INIREADER_H
