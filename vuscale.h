#ifndef VUSCALE_H
#define VUSCALE_H

#include <QWidget>


class Test;

class VuScale : public QWidget
{
public:
    explicit VuScale(QWidget* parent=nullptr);
    virtual ~VuScale();

    void paintEvent(QPaintEvent* ev);

private:

    friend class Test;

};

#endif // VUSCALE_H
