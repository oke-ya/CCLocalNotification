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
    bool init() override;
    void setSchedule(const int interval, const std::string& message, const int tag) override;
};

}

#endif /* CCLocalNotification_ios_h */
