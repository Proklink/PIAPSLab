#ifndef ABSTRACTIMAGE_H
#define ABSTRACTIMAGE_H

#include <QGraphicsItem>

class AbstractImage {
protected:
    QPixmap *image;
public:

    virtual ~AbstractImage();
    virtual QPixmap *getImage() = 0;
};

#endif // ABSTRACTIMAGE_H



