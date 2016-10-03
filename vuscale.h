#ifndef VUSCALE_H
#define VUSCALE_H

#include <QWidget>

class Test;

class VuScale : public QWidget
{
public:

    explicit VuScale(int w, int h, QFont* font, QWidget* parent=0); // support older qt sdk
    virtual ~VuScale();

    void paintEvent(QPaintEvent* ev);

private:
    void _drawBaseLine(QPoint x1, QPoint x2, QColor color, QPainter * const pnt, QPainterPath* path);
    void _drawRuler(int step, QColor color, QPainter* const pnt, QPainterPath *path);
    void _drawText(QPoint pos, QString txt, QPainter* const pnt, QPainterPath* path);
private:
    int m_width;
    int m_height;
    QFont* p_font;
    friend class Test;

};

#endif // VUSCALE_H
