#ifndef VARIABLES_H
#define VARIABLES_H

#define MAXIMUM 999

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
    HORIZONTAL_SPACER,
    VERTICAL_SPACER,
    VERTICAL_LAYOUT,
    HORIZONTAL_LAYOUT,
    GRID_LAYOUT,
    FORM_LAYOUT,
    ABSOLUTE_LAYOUT,
    COMBOBOX,
    EDITFIELD,
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

//! Struct foreach Element
//! Each properties is setting here
struct Elements{
    ELEMENT elementtype;
    QWidget * self;
    QString name;
    QMap<QString, QString> properties;
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

#endif // VARIABLES_H
