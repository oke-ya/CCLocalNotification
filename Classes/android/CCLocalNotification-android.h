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
    virtual void showAds() const override;
};

}

#endif /* CCLocalNotification_android_h */
