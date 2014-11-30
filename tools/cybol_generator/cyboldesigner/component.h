#ifndef ICON_H
#define ICON_H

#include <QToolButton>

//Widgetbox
class Component : public QToolButton
{
    Q_OBJECT
public:
    explicit Component( QString & text, bool noIcon, QToolButton * parent = 0 );
    explicit Component( QString & icon, QToolButton * parent = 0 );
    explicit Component( QString & iconpath, QString &text, QToolButton *parent = 0 );

protected:
    virtual void mousePressEvent( QMouseEvent * e);

signals:

public slots:

};

#endif // ICON_H
