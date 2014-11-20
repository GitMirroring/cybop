#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label( QWidget *parent = 0 );
    explicit Label( QString & text, QWidget * parent = 0 );

protected:
    virtual void mousePressEvent( QMouseEvent * e );

signals:

public slots:

};

#endif // LABEL_H
