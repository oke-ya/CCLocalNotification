//
//  CCLocalNotification.h
//  
//
//  Created by Atsushi Yoshida on 2016/08/23.
//
//

#ifndef CCLocalNotification_h
#define CCLocalNotification_h

#include <string>

namespace oke_ya{

class LocalNotification
{
public:
    static constexpr auto VERSION = "0.6.0";
    static LocalNotification* getInstance();
    static LocalNotification* s_sharedLocalNotification;
    virtual ~LocalNotification() = default;
    virtual bool init() = 0;
    virtual void setSchedule(const int interval, const std::string& message, const int tag = 0) = 0;
    virtual void setEnabled(bool b, bool jumpToNativeSetting = false) = 0;
    virtual bool isEnabled() = 0;
};

}

#endif /* CCLocalNotification_h */
