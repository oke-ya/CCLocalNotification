//
//  CCLocalNotification-ios.m
//  CCLocalNotification
//
//  Created by Atsushi Yoshida on 2016/08/23.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
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

bool LocalNotificationIos::init()
{
    return true;
}

void LocalNotificationIos::setSchedule(const int interval, const std::string& message, const int tag)
{
    if(!isEnabled()){
        return;
    }
    UILocalNotification *notification = [[UILocalNotification alloc] init];
    notification.fireDate = [[NSDate date] dateByAddingTimeInterval:interval];
    notification.timeZone = [NSTimeZone defaultTimeZone];
    notification.alertBody = [NSString stringWithUTF8String:message.c_str()];
    notification.alertAction = @"Open";
    notification.soundName = UILocalNotificationDefaultSoundName;
    NSNumber* nsTag = [NSNumber numberWithInteger:tag];
    NSDictionary *infoDict = [NSDictionary dictionaryWithObject:nsTag forKey:@"ID"];
    notification.userInfo = infoDict;
    [[UIApplication sharedApplication] scheduleLocalNotification:notification];
}

void LocalNotificationIos::setEnabled(bool b)
{
    UIApplication* application = [UIApplication sharedApplication];
    if(b){
        UIUserNotificationType types = UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert;
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:types categories:nil];
        [application registerUserNotificationSettings:settings];
    }else{
        [application cancelAllLocalNotifications];
        [application unregisterForRemoteNotifications];
    }
}

bool LocalNotificationIos::isEnabled()
{
    return [[UIApplication sharedApplication] isRegisteredForRemoteNotifications];
}

}
