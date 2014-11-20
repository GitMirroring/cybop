#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <QRadioButton>

class RadioButton : public QRadioButton
{
    Q_OBJECT
public:
    explicit RadioButton(QWidget *parent = 0);
    explicit RadioButton( QString & text, QWidget *parent = 0 );

protected:
    virtual void mousePressEvent( QMouseEvent * e );

signals:

public slots:

};

#endif // RADIOBUTTON_H
