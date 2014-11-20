#ifndef WINDOW_H
#define WINDOW_H

#include <QMouseEvent>
#include <QDockWidget>

class Window : public QDockWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    explicit Window( QString & title, QWidget * parent =  0 );

protected:
    virtual void mousePressEvent( QMouseEvent * e );

signals:

public slots:

};

#endif // WINDOW_H
