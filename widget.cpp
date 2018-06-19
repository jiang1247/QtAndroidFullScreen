#include "widget.h"
#include "jfullscreen.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    JFullScreen *pManager = new JFullScreen;
    int sum = pManager->addTest(1, 2);
    Q_ASSERT(sum == 3);
//    pManager->fullScreenLeanBack();
//    pManager->fullScreenImmersive();
    pManager->fullScreenStickyImmersive();
}

Widget::~Widget()
{

}
