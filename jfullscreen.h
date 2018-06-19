#ifndef JFULLSCREEN_H
#define JFULLSCREEN_H

#include <QAndroidJniObject>

class JFullScreen
{
public:
    JFullScreen();
    void fullScreenLeanBack();
    void fullScreenImmersive();
    void fullScreenStickyImmersive();
    int addTest(int value0, int value1);

private:
    QAndroidJniObject _javaClass;
};

#endif // JFULLSCREEN_H
