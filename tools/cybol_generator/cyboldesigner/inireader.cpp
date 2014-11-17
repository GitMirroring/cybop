#include <QSettings>
#include <QMessageBox>
#include <QFile>

#include "inireader.h"

iniReader::iniReader()
{
    readValues();
}

// iniReader::getInstance *********************************************************************************************
//
//*********************************************************************************************************************
iniReader
iniReader::getInstance( void ) {
    static iniReader self;

    return self;
}

// iniReader::readValues **********************************************************************************************
//
//*********************************************************************************************************************
void
iniReader::readValues(
        void ) {
    QFile file("configDesigner.ini");
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        QMessageBox::critical( 0, "Failed", file.errorString(),
                               QMessageBox::Ok );

        return;
    }
    QSettings settings( "configDesigner.ini", QSettings::IniFormat );

    settings.beginGroup( "Default" );
    m_values.insert( "elementsFile", qvariant_cast<QString>( settings.value( "elementsFile" ) ) );
}

// iniReader::getValue ************************************************************************************************
//
//*********************************************************************************************************************
QString
iniReader::getValue(
        QString key )
{
    return m_values.value( key );
}
