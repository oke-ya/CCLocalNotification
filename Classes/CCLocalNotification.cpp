//
//  CCLocalNotification.cpp
//  CCLocalNotification
//
//  Created by Atsushi Yoshida on 2016/08/23.
//
//

#include "CCLocalNotification.h"

namespace oke_ya{

LocalNotification* LocalNotification::s_sharedLocalNotification = nullptr;

bool LocalNotification::init()
{
    return true;
}

}