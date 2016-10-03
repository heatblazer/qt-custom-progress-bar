#ifndef DRAWINGINTERFACE_H
#define DRAWINGINTERFACE_H

class QRect;
class QPoint;

class DrawingInterface
{
public:

    virtual void drawLine(QPoint* p1, QPoint* p2) = 0;
    virtual void fillRect(QRect* rect) = 0;

};


#endif // DRAWINGINTERFACE_H
