#include "CCLocalNotification-android.h"
#include "platform/android/jni/JniHelper.h"
#include "cocos2d.h"

using namespace cocos2d;

namespace oke_ya{


static const std::string helperClassName = "com/oke_ya/ccnatie_extension_template/CCLocalNotification";

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

void LocalNotificationAndroid::showAds() const
{
    JniHelper::callStaticVoidMethod(helperClassName, "showAds");
}

}
