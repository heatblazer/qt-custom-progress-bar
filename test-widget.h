#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTimer>


class VuMeter;
class VuScale;

class Test : public QWidget
{
public:
    explicit Test(QWidget* parent=nullptr);
    virtual ~Test();

    void showAll();

private:

    VuMeter* p_meter;
    VuScale* p_scale;

    QVBoxLayout m_vbox;
    QTimer m_timers[3];

};


#endif // TESTWIDGET_H
