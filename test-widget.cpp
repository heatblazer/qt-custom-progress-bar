#include "test-widget.h"

#include "vumeter.h"
#include "vuscale.h"

Test::Test(QWidget *parent)
    : QWidget(parent),
      p_meter(nullptr),
      p_scale(nullptr)
{

    p_meter = new VuMeter(50, 200, this);
    p_meter->setPixDiff(1);
    p_meter->setRoundingRadius(3);
    p_scale = new VuScale(this);

    m_vbox.addWidget(p_meter);
    m_vbox.addWidget(p_scale);
    setLayout(&m_vbox);
    setMinimumSize(QSize(100, 500));
}

Test::~Test()
{

}

void Test::showAll()
{
    show();
    p_meter->show();

}
