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

static NSString *const KEY = @"enableNotifcation";
    
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
    UIUserNotificationType types = UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert;
    UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:types categories:nil];
    [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
    _enabled = [[NSUserDefaults standardUserDefaults] boolForKey:KEY];
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

void LocalNotificationIos::setEnabled(bool enabled)
{
    [[NSUserDefaults standardUserDefaults] setBool:enabled forKey:KEY];
    _enabled = enabled;
    if(!enabled){
        [[UIApplication sharedApplication] cancelAllLocalNotifications];
    }
    if(enabled && ![[UIApplication sharedApplication] isRegisteredForRemoteNotifications]){
        NSURL *url = [NSURL URLWithString:UIApplicationOpenSettingsURLString];
        [[UIApplication sharedApplication] openURL:url];
    }
}

bool LocalNotificationIos::isEnabled()
{
    return _enabled;
}

}
