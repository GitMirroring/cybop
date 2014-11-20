#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QCheckBox>

class CheckBox : public QCheckBox
{
    Q_OBJECT
public:
    explicit CheckBox(QWidget *parent = 0);
    explicit CheckBox( QString & text, QWidget * parent = 0 );

protected:
    virtual void mousePressEvent( QMouseEvent *e );

signals:

public slots:

};

#endif // CHECKBOX_H
