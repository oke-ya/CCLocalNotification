#include "CCLocalNotification.h"
#include "CCLocalNotification-android.h"
#include "platform/android/jni/JniHelper.h"
#include "cocos2d.h"

using namespace cocos2d;

namespace oke_ya{


static const std::string helperClassName = "com/oke_ya/cc_local_notification/CCLocalNotification";

LocalNotification* LocalNotification::getInstance()
{
    if (s_sharedLocalNotification == nullptr)
    {
        s_sharedLocalNotification = new (std::nothrow) LocalNotificationAndroid();
        if(!s_sharedLocalNotification->init())
        {
            delete s_sharedLocalNotification;
            s_sharedLocalNotification = nullptr;
            CCLOG("ERROR: Could not init CCLocalNotificationAndroid");
        }
    }
    return s_sharedLocalNotification;
}

bool LocalNotificationAndroid::init()
{
  JniHelper::callStaticVoidMethod(helperClassName, "init");
  return true;
}
  
void LocalNotificationAndroid::setSchedule(const int interval, const std::string& message, const int tag)
{
    JniMethodInfo methodInfo;
    if(JniHelper::getStaticMethodInfo(methodInfo, helperClassName.c_str(), "setSchedule", "(ILjava/lang/String;I)V"))
    {
        JNIEnv* env = JniHelper::getEnv();
        jstring jmessage = env->NewStringUTF(message.c_str());
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, interval, jmessage, tag);
        env->DeleteLocalRef(jmessage);
    }
}

void LocalNotificationAndroid::setEnabled(bool b)
{
    JniMethodInfo methodInfo;
    if(JniHelper::getStaticMethodInfo(methodInfo, helperClassName.c_str(), "setEnabled", "(Z)V"))
    {
        JNIEnv* env = JniHelper::getEnv();
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, b);
    }
}

}
