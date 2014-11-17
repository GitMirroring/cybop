#ifndef VARIABLES_H
#define VARIABLES_H

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

#endif // VARIABLES_H
