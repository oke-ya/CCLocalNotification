//
//  CCLocalNotification.h
//  
//
//  Created by Atsushi Yoshida on 2016/08/23.
//
//

#ifndef CCLocalNotification_h
#define CCLocalNotification_h

namespace oke_ya{

class LocalNotification
{
public:
    static LocalNotification* getInstance();
    static LocalNotification* s_sharedLocalNotification;
    virtual bool init();
    virtual void showAds() const = 0;
};

}

#endif /* CCLocalNotification_h */
