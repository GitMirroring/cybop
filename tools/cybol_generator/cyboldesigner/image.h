#ifndef IMAGE_H
#define IMAGE_H

#include <QLabel>

class Image : public QLabel
{
    Q_OBJECT
public:
    explicit Image(QWidget *parent = 0);
    explicit Image( QString & file, QWidget * parent = 0 );

protected:
    virtual void mousePressEvent( QMouseEvent * e );

signals:

public slots:

};

#endif // IMAGE_H
