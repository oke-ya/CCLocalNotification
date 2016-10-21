//
//  CCLocalNotification-android.h
//  CCLocalNotification
//
//  Created by Atsushi Yoshida on 2016/08/23.
//
//

#ifndef CCLocalNotification_android_h
#define CCLocalNotification_android_h

#include <memory>
#include <string>
#include <vector>

#include "CCLocalNotification.h"

namespace oke_ya{

class LocalNotificationAndroid : public LocalNotification
{
    bool init();
    void setSchedule(const int interval, const std::string& message, const int tag = 0);
    void setEnabled(bool b, bool jumpToNativeSetting = false);
    bool isEnabled();
};

}

#endif /* CCLocalNotification_android_h */
