#ifndef VARIABLES_H
#define VARIABLES_H

#define STRSHAPE "Shape"
#define STRSIZE "Size"
#define STRPOSITION "Position"
#define STRCOLOR "Color"
#define STRBACKGROUND "Background-Colour"
#define STRENABLED "Enabled"
#define STRTEXT "Text"
#define STRICON "Icon"
#define STRTOOLTIP "ToolTip"
#define STRTOOLTIPDURATION "ToolTip Duration"
#define STRCURSOR "Cursor"
#define STROPACITY "Opacity"

#include <QWidget>
#include <QMap>

//!Struct for properties of a tag
struct properties{
    QString name;
    QString channel;
    QString format;
    QString model;
    bool property = true;
};

//!Struct for RGB-Color definition
struct RGB{
    int red;
    int green;
    int blue;
};

enum ELEMENT{
    WINDOW,
    BUTTON,
    LABEL,
    RECTANGLE,
    VERTICAL_LAYOUT,
    HORIZONTAL_LAYOUT,
    GRID_LAYOUT,
    ABSOLUTE_LAYOUT,
    COMBOBOX,
    EDITFIELD,
    SCROLLBAR,
    TABLEVIEW,
    LISTVIEW,
    TREEVIEW,
    TABWIDGET,
    PANEL,
    CHECKBOX,
    RADIOBUTTON,
    SPINBOX,
    PROGRESSBAR,
    LINE,
    TRIANGEL,
    SLIDER,
    CALENDAR,
    GROUPBOX
};

struct Size{
    int width;
    int height;
};

struct Position{
    int x;
    int y;
};

struct Tooltip{
    bool used;
    QString text;
    int duration;
};

enum PROPERS {
    SHAPE,
    SIZE,
    POSITION,
    COLOR,
    BACKGROUNDCOLOR,
    ENABLED,
    VISIBLE,
    TEXT,
    ICON,
    TOOLTIP,
    TOOLTIPDURATION,
    CURSOR,
    OPACITY,
    MARGIN,
    PADDING,
    FONT,
    HORIZONTALALIGN,
    VERTICALALIGN,
    ORIENTATION,
    BORDER,
    BORDERTOP,
    BORDERBOTTOM,
    BORDERLEFT,
    NUMBERSONLY,
    READONLY,
    PASSWORDCHAR,
    MINIMUM,
    MAXIMUM,
    SINGLESTEP,
    PAGESTEP,
    SLIDERPOSITION,
    COLCOUNT,
    ROWCOUNT,
    ROWHEIGHT,
    COLWIDHT,
    EDITABLE,
    FIXEDROW,
    FIXEDCOL,
    SORTINGENABLED,
    WORDWRAP,
    ICONSALLOWED,
    CHECKABLE,
    ITEMSEXPANDABLE,
    EXPANDSONDOUBLECLICK,
    USEIMAGES,
    TABPOSITION,
    TABS,
    CURRENTINDEX,
    MOVABLE,
    CURRENTTABTEXT,
    CURRENTTABNAME,
    CURRENTTABICON,
    CURRENTTABTOOLTIP,
    CURRENTTABTOOLTIPDURATION,
    TABSCLOSABLE,
    AUTOSIZE,
    CURRENTTEXT,
    MAXVISIBLEITEMS,
    ITEMS,
    AUTOCOMPLETE,
    SELECTIONSTART,
    SORTED,
    TRISTATE,
    CHECKED,
    DECIMALS,
    VALUE,
    TEXTVISIBLE,
    IMAGE,
    ROUNDEDEDGES,
    USESCALA,
    SCALAFREQUENCY,
    SELECTEDDATE,
    MINIMUMDATE,
    MAXIMUMDATE,
    FIRSTDAYOFWEEK,
    HORIZONTALHEADERFORMAT
};

//! Struct foreach Element
//! Each properties is setting here
struct Elements{
    ELEMENT elementtype;
    QWidget * self;
    QString name;
    QMap<PROPERS, QString> properties;
};

struct ToolboxWidget{
    QString name;
    QString path;
    QString icon;
};

enum FOCUSPOINTPOS {
    TOPLEFT,
    TOP,
    TOPRIGHT,
    RIGHT,
    BOTTOMRIGHT,
    BOTTOM,
    BOTTOMLEFT,
    LEFT
};

enum tabPos {
    NORTH,
    SOUTH,
    WEST,
    EAST
};

#endif // VARIABLES_H
