#ifndef VUMETER_H
#define VUMETER_H

#include <QWidget>

class QPainter;
class QPathPainter;
class Test;

class VuMeter : public QWidget
{
public:
    explicit VuMeter(int width, int height, QWidget* parent=nullptr);
    virtual ~VuMeter();
    void setPixDiff(unsigned int pdiff);
    void setRoundingRadius(qreal r);
    void paintEvent(QPaintEvent* ev);

private:

    void _fillFromTo(QPoint p1, QPoint p2, QColor color, QPainter* const pnt, QPainterPath* const path);
    void _drawLine(QPoint p1, QColor color, QPainter* const pnt, QPainterPath  *path);
    void _drawBorders(QColor color, QRect rect, QPainter* const pnt);

private:
    int m_fillWidth;
    int m_totalWidth;
    int m_fillHeight;
    int m_totalHeight;
    qreal m_roundRad;
    unsigned int m_pixDiff;

    friend class Test;
};


#endif // VUMETER_H
