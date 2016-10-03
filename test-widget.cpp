#include "test-widget.h"

#include "vumeter.h"
#include "vuscale.h"



Test::Test(QWidget *parent)
    : QWidget(parent),
      p_meter(0),
      p_scale(0)
{

    p_meter = new VuMeter(60, 200, this);
    p_meter->setPixDiff(1);
    p_meter->setRoundingRadius(3);

    p_scale = new VuScale(30, 200, new QFont("times", 16), this);

    m_vbox.addWidget(p_meter);
    m_vbox.addWidget(p_scale);
    setLayout(&m_vbox);
    setMinimumSize(QSize(160, 500));


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
    p_scale->show();

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
