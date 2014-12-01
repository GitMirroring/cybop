#ifndef QUALITIES_H
#define QUALITIES_H

#include <QString>
#include <QList>

class Qualities
{
public:
    Qualities( QString name = "",
               QString type = "",
               QString def = "" );

    void setName( QString name );
    QString name( void );

    void setType( QString type );
    QString type( void );

    void setDefault( QString defVal );
    QString defValue( void );

    void setSubs( QList< Qualities > subs );
    QList< Qualities > subs( void );

    void addSub( Qualities sub );

private:
    QString m_name, m_type, m_default;
    QList< Qualities > m_subs;


};

#endif // QUALITIES_H
