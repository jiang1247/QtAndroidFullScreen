#include "jfullscreen.h"

#include <functional>
#include <QtAndroid>

// JFS: JFullScreen
#define JFS_CLASSNAME "org/qtproject/junj/JFullScreen"
#define JFS_SIGNTURE_INSTANCE "()Lorg/qtproject/junj/JFullScreen;"

void realFullScreenLeanBackMethod() {
    QAndroidJniObject javaCustomFunction = QAndroidJniObject::callStaticObjectMethod(JFS_CLASSNAME, "instance", JFS_SIGNTURE_INSTANCE);
    javaCustomFunction.callMethod<void>("fullScreenLeanBack", "()V");
}
void realFullScreenImmersiveMethod() {
    QAndroidJniObject javaCustomFunction = QAndroidJniObject::callStaticObjectMethod(JFS_CLASSNAME, "instance", JFS_SIGNTURE_INSTANCE);
    javaCustomFunction.callMethod<void>("fullScreenImmersive", "()V");
}
void realFullScreenStickyImmersiveMethod() {
    QAndroidJniObject javaCustomFunction = QAndroidJniObject::callStaticObjectMethod(JFS_CLASSNAME, "instance", JFS_SIGNTURE_INSTANCE);
    javaCustomFunction.callMethod<void>("fullScreenStickyImmersive", "()V");
}

JFullScreen::JFullScreen()
{
    if(!QAndroidJniObject::isClassAvailable(JFS_CLASSNAME)) {
        qDebug("JFullScreen is unavailable.");
        return;
    }

    _javaClass = QAndroidJniObject::callStaticObjectMethod(JFS_CLASSNAME, "instance", JFS_SIGNTURE_INSTANCE);

    if(!_javaClass.isValid()) {
        qDebug(" JFullScreen instance is invalid.");
    }

    _javaClass.callMethod<void>("setContext", "(Landroid/content/Context;)V", QtAndroid::androidActivity().object<jobject>());
}

//use runOnAndroidThread() in order to run on android ui thread
void JFullScreen::fullScreenLeanBack()
{
    QtAndroid::Runnable runnable = realFullScreenLeanBackMethod;
    QtAndroid::runOnAndroidThread(runnable);
}

void JFullScreen::fullScreenImmersive()
{
    QtAndroid::Runnable runnable = realFullScreenImmersiveMethod;
    QtAndroid::runOnAndroidThread(runnable);
}

void JFullScreen::fullScreenStickyImmersive()
{
    QtAndroid::Runnable runnable = realFullScreenStickyImmersiveMethod;
    QtAndroid::runOnAndroidThread(runnable);
}

int JFullScreen::addTest(int value0, int value1)
{
    jint sum = _javaClass.callMethod<jint>("addTest", "(II)I", value0, value1);
    return sum;
}
