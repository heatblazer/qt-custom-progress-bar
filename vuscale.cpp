#include "vuscale.h"

#include <QPainter>

VuScale::VuScale(int w, int h, QFont *font, QWidget *parent)
    : QWidget(parent),
      m_width(w),
      m_height(h),
      p_font(font)
{

}

VuScale::~VuScale()
{

}

void VuScale::paintEvent(QPaintEvent *ev)
{
    (void) ev;
    QPainter pnt(this);
    QPainterPath path;

    _drawBaseLine(QPoint(m_width, 0), QPoint(m_width, m_height), QColor(255,0,0), &pnt, &path);

    // for now OK, I need a better aspect ratio algorithm
    int step = (m_height / 30);
    _drawRuler(step, QColor(255,0,0), &pnt, &path);


}

void VuScale::_drawBaseLine(QPoint x1, QPoint x2, QColor color, QPainter * const pnt, QPainterPath *path)
{
    path->moveTo(x1.x(), x1.y());
    pnt->setPen(color);
    pnt->setBrush(Qt::NoBrush);
    pnt->drawLine(x1, x2);
}

void VuScale::_drawRuler(int step, QColor color, QPainter * const pnt, QPainterPath *path)
{
    path->moveTo(m_width ,0);
    int j;
    if (step % 2==0) {
        j = 1;
    } else {
        j = 0;
    }
    int i=0;

    pnt->drawLine(QPoint(m_width, i), QPoint(0, i));

    // these are the steps needed to paint the proportional ruler
    int true_steps = (m_width)/step;
    for(i=0; i < m_height; i+= true_steps, j++) {
        pnt->setPen(color);
        if (j % 2 == 0) {
            pnt->drawLine(QPoint(m_width, i), QPoint(m_width-(m_width/2), i));
        } else {
            pnt->drawLine(QPoint(m_width, i), QPoint(0, i));
           // _drawText(QPoint(0, i), QString("-20db"), pnt, path);

        }
    }

    pnt->drawLine(QPoint(m_width, m_height), QPoint(0, m_height));


}

/// TODO (later)
/// \brief VuScale::_drawText
/// \param pos
/// \param txt
/// \param pnt
/// \param path
///
void VuScale::_drawText(QPoint pos, QString txt, QPainter * const pnt, QPainterPath *path)
{
    pnt->drawText(QRect(pos.x(), pos.y(), 15, 15), txt);
}
