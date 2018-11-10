#!/bin/sh
#
# clean_result_directory.sh
#
# Copyright (C) 2010-2016. Christian Heller.
#
# This script is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# This script is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this script. If not, see <http://www.gnu.org/licenses/>.
#
# First Version: 2010-04-23
# Current Version: 2016-07-04
# Autor: Christian Heller <christian.heller@ba-leipzig.de>
#

#
# Shell Script zum Löschen nicht benötigter Verzeichnisse
# und Dateien aus dem Ergebnisverzeichnis einer Klausur,
# welches in Form eines komprimierten Archives vorliegt.
#
# ACHTUNG! Damit das Script funktioniert, muss es in das Verzeichnis
# kopiert werden, in welchem die komprimierte Archivdatei liegt!
# Der Name der Archivdatei ist als Kommandozeilenargument anzugeben.
#
# Sicherheitshalber, um aus Versehen keine vorhandenen Daten zu zerstören,
# wird empfohlen, die Archivdatei zusammen mit diesem Script vor
# dessen Ausführung in ein temporäres Verzeichnis zu kopieren.
#

echo;
echo "*";
echo "* Shell Script zum Löschen nicht benötigter Verzeichnisse";
echo "* und Dateien aus dem Ergebnisverzeichnis einer Klausur,";
echo "* welches in Form eines komprimierten Archives vorliegt.";
echo "*";
echo "* First Version: 2010-04-23";
echo "* Current Version: 2016-07-04";
echo "* Autor: Christian Heller <christian.heller@ba-leipzig.de>";
echo "*";

echo;
echo "Definiere globale Variablen.";
ARCHIVE="";

echo;
echo "Lese Namen des Archives als Kommandozeilen-Argument.";

# Prüfe Kommandozeilen-Argument.
if [ -n "$1" ]; then
    # Setze Namen des Archives.
    ARCHIVE=$1;
else
    echo "Fehler: Kein Archivname vorhanden. Bitte als Argument angeben!";
    echo "Aufruf: clean_result_directory.sh ARCHIVEFILE.tar.gz";
    exit 1;
fi

echo;
echo "Setze Lese- und Schreibrechte, damit Datei ohne interaktive Rückfrage gelesen und später gelöscht werden kann.";
chmod u+rw $ARCHIVE;

echo;
echo "Entpacke Inhalt des komprimierten Ergebnisverzeichnisses.";
tar -xvzf $ARCHIVE;

#echo;
#echo "Lösche komprimiertes Ergebnisverzeichnis.";
#rm $ARCHIVE;

echo;
echo "Setze Lese- und Schreibrechte, damit Unterverzeichnisse und Dateien ohne interaktive Rückfrage bearbeitet werden können.";

# Set all rights for directories and files.
# CAUTION! Put "export" in quotation marks, because it would
# otherwise be interpreted as keyword, by the shell!
chmod -R a+rwx "export"

# Unset executable flag for all files.
# The search is recursive by default.
# Parameters: -type d means "directory"; -type f means "file".
# CAUTION! Put "export" in quotation marks, because it would
# otherwise be interpreted as keyword, by the shell!
find "export" -type f -exec chmod a-x {} \;

echo;
echo "Verschiebe Unterverzeichnis auf die aktuelle Ebene.";
mv -v export/home/klausur .;

echo;
echo "Lösche verbliebenen, nicht benötigten Inhalt rekursiv.";
# CAUTION! Put "export" in quotation marks, because it would
# otherwise be interpreted as keyword, by the shell!
rm -rv "export";

echo;
echo "Benenne Verzeichnis um in 'home'.";
mv -v ./klausur home;

echo;
echo "Lösche nicht benötigte Klausur user login Dateien.";
rm -rv home/klausuruser-login*;

echo;
echo "Lösche nicht benötigte Verzeichnisse rekursiv.";
rm -rv home/klaus*/.AbiSuite;
rm -rv home/klaus*/.adobe;
rm -rv home/klaus*/.android;
rm -rv home/klaus*/.beagle;
rm -rv home/klaus*/.cache;
rm -rv home/klaus*/.codelite-dbg;
rm -rv home/klaus*/.config;
rm -rv home/klaus*/.dbus;
rm -rv home/klaus*/.emacs.d;
rm -rv home/klaus*/.fontconfig;
rm -rv home/klaus*/.fonts;
rm -rv home/klaus*/.gconf;
rm -rv home/klaus*/.gconfd;
rm -rv home/klaus*/.gimp-2.6;
rm -rv home/klaus*/.gnome2;
rm -rv home/klaus*/.gnome2_private;
rm -rv home/klaus*/.gstreamer-0.10;
rm -rv home/klaus*/.gvfs;
rm -rv home/klaus*/.hplip;
rm -rv home/klaus*/.icedteaplugin;
rm -rv home/klaus*/.Idea*;
rm -rv home/klaus*/.java;
rm -rv home/klaus*/.kde;
rm -rv home/klaus*/.kde4;
rm -rv home/klaus*/.local;
rm -rv home/klaus*/.macromedia;
rm -rv home/klaus*/.mc;
rm -rv home/klaus*/.mcop;
rm -rv home/klaus*/.mozilla;
rm -rv home/klaus*/.mysql;
rm -rv home/klaus*/.mysqlgui;
rm -rv home/klaus*/.netbeans;
rm -rv home/klaus*/.netbeans-registration;
rm -rv home/klaus*/.netx;
rm -rv home/klaus*/.ooo-2.0;
rm -rv home/klaus*/.ooo3;
rm -rv home/klaus*/.pulse;
rm -rv home/klaus*/.qt;
rm -rv home/klaus*/.rcc;
rm -rv home/klaus*/.skel;
rm -rv home/klaus*/.ssh;
rm -rv home/klaus*/.subversion;
rm -rv home/klaus*/.svnqt;
rm -rv home/klaus*/.thumbnails;
rm -rv home/klaus*/.wapi;
rm -rv home/klaus*/.wine;
rm -rv home/klaus*/.xemacs;
rm -rv home/klaus*/.xine;
rm -rv home/klaus*/Bilder;
rm -rv home/klaus*/bin;
rm -rv home/klaus*/Desktop;
# CAUTION! Do NOT uncomment these two lines!
# Some students use these directories to store their results.
#rm -rv home/klaus*/Documents;
#rm -rv home/klaus*/Dokumente;
rm -rv home/klaus*/Downloads;
rm -rv home/klaus*/Eclipse3_Workspace/org.eclipse*;
rm -rv home/klaus*/Musik;
rm -rv home/klaus*/MySQL*;
rm -rv home/klaus*/Öffentlich;
rm -rv home/klaus*/public_html;
rm -rv home/klaus*/Schreibtisch;
rm -rv home/klaus*/Videos;
rm -rv home/klaus*/Vorlagen;

echo;
echo "Lösche nicht benötigte Dateien.";
rm -v home/klaus*/.bash_history;
rm -v home/klaus*/.bashrc;
rm -v home/klaus*/.bouml;
rm -v home/klaus*/.boumlrc;
rm -v home/klaus*/.DCOPserver*;
rm -v home/klaus*/.directory;
rm -v home/klaus*/.dmrc;
rm -v home/klaus*/.dvipsrc;
rm -v home/klaus*/.emacs;
rm -v home/klaus*/.esd_auth;
rm -v home/klaus*/.exrc;
rm -v home/klaus*/.gtkrc*;
rm -v home/klaus*/.ICEauthority;
rm -v home/klaus*/.inputrc;
rm -v home/klaus*/.kermrc;
rm -v home/klaus*/.muttrc;
rm -v home/klaus*/.mysql_history;
rm -v home/klaus*/.pgadmin*;
rm -v home/klaus*/.pgpass*;
rm -v home/klaus*/.profile;
rm -v home/klaus*/.pulse-cookie;
rm -v home/klaus*/.recently-used;
rm -v home/klaus*/.recently-used.xbel;
rm -v home/klaus*/.urlview;
rm -v home/klaus*/.viminfo;
rm -v home/klaus*/.vimrc;
rm -v home/klaus*/.Xauthority;
rm -v home/klaus*/.xcoralrc;
rm -v home/klaus*/.xim.template;
rm -v home/klaus*/.xinitrc.template;
rm -v home/klaus*/.xsession*;
rm -v home/klaus*/.xtalkrc;
rm -v home/klaus*/*~;
rm -v home/klaus*/*.class;
rm -v home/klaus*/*.pdf;
rm -v home/klaus*/*.sql;
rm -v home/klaus*/*.sql~;
rm -v home/klaus*/pgadmin*;

echo;
echo "Lösche leere home Verzeichnisse.";

#
# Counts the directories and files contained within the given sub directory.
#
# @param $1 sub directory
# @return the function has no return value;
#         the result is stored in variable n which is global within the file
#
count() {

    # List all directories and files.
    # The -a option is necessary to also list hidden directories, e.g. ".eclipse".
    # Forward result list to "Word Count" programme.
    # Count lines in result list.
    # CAUTION! Argument "-l" means "lines" and NOT the number one.
    #
    # Command substitution is used here by putting the command in $(...).
    # An alternative notation would be to put it into backquotes `...`.
    # That way, the output of the command is stored in the variable,
    # instead of printing it on the shell.
    #
    n=$(ls -a $1 | wc -l);
}

# The loop variable.
j=1;
# The maximum loop count.
c=50;
# The number of directories and files contained within the given sub directory.
n=0;

echo "Anzahl der enthaltenen Verzeichnisse und Dateien:";

while [ 1 ]; do
    if [ $j -gt $c ]; then
        break;
    fi

    # Call "count" function.
    # Parameter specifies sub directory.
    # The return value is stored in variable n which is global within the file.
    #
    # Die Verwendung einer Funktion an dieser Stelle ist eigentlich nicht nötig,
    # wurde hier aber zur Übung der Shell-Programmierung verwendet.
    count home/klaus$j;

    echo $n;

    # The variable is compared with number 2 because listing all files using
    # "ls -a" also lists the current directory "." and parent directory "..".
    # Therefore, otherwise empty directories still have these two entries.
    if [ $n -eq 2 ]; then
        rm -rv home/klaus$j;
    fi

    # Increment loop variable.
    # Verwendet die verkürzte Schreibweise für arithmetische Operationen.
    # Normalerweise wird das interne Shell-Kommando "let" oder das
    # externe Kommando "expr" verwendet, z.B.:
    # z=`expr $z + 3` # Aufruf des externen Kommandos expr
    # let z=z+3    # Aufruf des internen Kommandos
    # let "z += 3" # Mit Quotes sind Leerzeichen und special operators erlaubt.
    # z=$(($z+3))  # neue verkuerzte Schreibweise (ab Version 2.0)
    # z=$[$z+3]    # alte Schreibweise
    j=$(($j+1));
done

echo;
echo "Lösche nicht benötigte Verzeichnisse in verbliebenen home Verzeichnissen.";

# The search is recursive by default.
# Parameters: -type d means "directory"; -type f means "file".
# CAUTION! Put "export" in quotation marks, because it would
# otherwise be interpreted as keyword, by the shell!
# CAUTION! The "find" command's "-delete" option did not work,
# due to the error "Directory not empty" (non-recursive deletion).
# Therefore, the "-exec rm -rv" is used here.
find "home" -name '.eclipse' -type d -exec rm -rv {} \;
find "home" -name '.idea' -type d -exec rm -rv {} \;
find "home" -name '.metadata' -type d -exec rm -rv {} \;
find "home" -name '.recommenders' -type d -exec rm -rv {} \;
find "home" -name '.settings' -type d -exec rm -rv {} \;
find "home" -name 'bin' -type d -exec rm -rv {} \;

echo;
echo "Lösche nicht benötigte Dateien in verbliebenen home Verzeichnissen.";

# The search is recursive by default.
# Parameters: -type d means "directory"; -type f means "file".
# CAUTION! Put "home" in quotation marks, because it would
# otherwise be interpreted as keyword, by the shell!
# CAUTION! The "find" command's "-delete" option did not work,
# due to the error "Directory not empty" (non-recursive deletion).
# Therefore, the "-exec rm -rv" is used here.
find "home" -name '.class' -type f -exec rm -rv {} \;
find "home" -name '.classpath' -type f -exec rm -rv {} \;
find "home" -name '.directory' -type f -exec rm -rv {} \;
find "home" -name '.project' -type f -exec rm -rv {} \;
find "home" -name '*.jar' -type f -exec rm -rv {} \;
find "home" -name '*.pdf' -type f -exec rm -rv {} \;
find "home" -name '*.sql' -type f -exec rm -rv {} \;
find "home" -name '*.zip' -type f -exec rm -rv {} \;
find "home" -name 'WBM.mwb' -type f -exec rm -rv {} \;
find "home" -name 'WBM.mwb.bak' -type f -exec rm -rv {} \;

#echo;
#echo "Warte auf Eingabe.";
#read wait;

#sleep 1;

echo;
echo "Verlasse Programm.";
exit 0;
