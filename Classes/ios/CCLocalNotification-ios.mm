//
//  CCLocalNotification-ios.m
//  CCLocalNotification
//
//  Created by Atsushi Yoshida on 2016/08/23.
//
//

#import <Foundation/Foundation.h>

#include "CCLocalNotification-ios.h"

#include "cocos2d.h"
using namespace cocos2d;

namespace oke_ya{
    
LocalNotification* LocalNotification::getInstance()
{
    if (s_sharedLocalNotification == nullptr)
    {
        s_sharedLocalNotification = new (std::nothrow) LocalNotificationIos();
        if(!s_sharedLocalNotification->init())
        {
            delete s_sharedLocalNotification;
            s_sharedLocalNotification = nullptr;
            CCLOG("ERROR: Could not init CCLocalNotificationIos");
        }
    }
    return s_sharedLocalNotification;
}

void LocalNotificationIos::showAds() const
{
    log("LocalNotification::showAds()");
}

}
