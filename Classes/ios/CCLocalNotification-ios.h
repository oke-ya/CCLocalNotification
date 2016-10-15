//
//  CCLocalNotification-ios.h
//  CCLocalNotification
//
//  Created by Atsushi Yoshida on 2016/08/23.
//
//

#ifndef CCLocalNotification_ios_h
#define CCLocalNotification_ios_h

#include <memory>
#include <string>
#include <vector>

#include "CCLocalNotification.h"

namespace oke_ya{

class LocalNotificationIos : public LocalNotification
{
    virtual void showAds() const override;
};

}

#endif /* CCLocalNotification_ios_h */
