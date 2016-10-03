#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTimer>


class VuMeter;
class VuScale;

class Test : public QWidget
{
    Q_OBJECT
public:
    explicit Test(QWidget* parent=0);
    virtual ~Test();

    void showAll();

private slots:
    void hTimeout();
private:

    VuMeter* p_meter;
    VuScale* p_scale;

    QHBoxLayout m_vbox;
    QTimer m_timer;

};


#endif // TESTWIDGET_H
