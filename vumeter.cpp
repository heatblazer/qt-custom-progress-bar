#include "vumeter.h"

#include <QRect>
#include <QPainter>

VuMeter::VuMeter(int width, int height, QWidget *parent)
    : QWidget(parent),
      m_totalWidth(width),
      m_totalHeight(height),
      m_roundRad(0.0),
      m_pixDiff(0)
{
    m_fillWidth = m_totalWidth - 2; // one pixel per each side
    m_fillHeight = m_totalHeight - 2; // one pixel per each side
    setMinimumSize(QSize(m_totalWidth, m_totalHeight));
}

VuMeter::~VuMeter()
{

}

void VuMeter::setPixDiff(unsigned int pdiff)
{
    m_pixDiff = pdiff;
}

void VuMeter::setRoundingRadius(qreal r)
{
    m_roundRad = r;
}

void VuMeter::paintEvent(QPaintEvent *ev)
{
    (void) ev;

    QPainter pnt(this);
    QPainterPath path;
    //draw bounds

    _fillFromTo(QPoint(m_pixDiff, m_totalHeight), QPoint(m_pixDiff, m_totalWidth), QColor(255, 0, 0), &pnt, &path);
    _drawBorders(QColor(0,0,0), QRect(0, 0, m_totalWidth, m_totalHeight), &pnt);
    _fillFromTo(QPoint(m_pixDiff, 15), QPoint(m_pixDiff, m_fillHeight), QColor(0, 0, 255), &pnt, &path);
    _drawLine(QPoint(m_pixDiff, 150), QColor(255, 0, 0), &pnt, &path);

}

void VuMeter::_fillFromTo(QPoint p1, QPoint p2, QColor color, QPainter * const pnt, QPainterPath * const path)
{
    path->moveTo(p1.x(), p1.y());
    pnt->setPen(Qt::NoPen);
    pnt->setBrush(color);
    QRect r(p1.x(), p1.y(), m_fillWidth+m_pixDiff, p2.y()-p1.y());
    path->addRect(r);
    pnt->fillPath(*path, pnt->brush());
}

void VuMeter::_drawLine(QPoint p1, QColor color, QPainter * const pnt, QPainterPath *path)
{
    path->moveTo(p1.x(), p1.y());
    QPen pen(color);
    pen.setWidth(m_pixDiff);
    pnt->setPen(pen);
    pnt->drawLine(p1.x(), p1.y(), p1.x()+m_fillWidth, p1.y());
}

void VuMeter::_drawBorders(QColor color, QRect rect, QPainter * const pnt)
{
    QPen pen(color);
    pen.setWidth(1);
    pnt->setPen(pen);
    pnt->setBrush(Qt::NoBrush);
    pnt->drawRoundedRect(rect, m_roundRad, m_roundRad);
}

