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
    m_timer.setInterval(50);
    connect(&m_timer, SIGNAL(timeout()),
            this, SLOT(hTimeout()));
    m_timer.start();
    show();
    p_meter->show();

}

void Test::hTimeout()
{
    int i = rand() % 200;
    int j = rand() % 200;
    int h = rand() % 200;
    p_meter->setPeakPos(i);
    p_meter->setRMSPost(j);
    p_meter->setVUPos(h);
}
