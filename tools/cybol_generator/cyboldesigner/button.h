#ifndef BUTTON_H
#define BUTTON_H

#include <QMouseEvent>
#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button( QPushButton * parent = 0 );
    explicit Button( QString & text, QPushButton *parent = 0);

protected:
    virtual void mousePressEvent( QMouseEvent * e );
    virtual void dragEnterEvent( QDragEnterEvent * e );
    virtual void dragLeaveEvent( QDragLeaveEvent * e );
    virtual void dragMoveEvent( QDragMoveEvent * e );

signals:

public slots:

};

#endif // BUTTON_H
