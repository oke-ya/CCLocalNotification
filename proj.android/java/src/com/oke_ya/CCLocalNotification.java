package com.oke_ya.cc_local_notification;

import org.cocos2dx.lib.Cocos2dxHelper;
import org.cocos2dx.lib.Cocos2dxActivity;
import android.util.Log;
import java.util.Calendar;
import android.app.Activity;
import android.app.AlarmManager;
import android.app.NativeActivity;
import android.app.PendingIntent;
import android.content.Intent;
import android.os.Bundle;
import android.content.Context;

public class CCLocalNotification {
    private static final String TAG = CCLocalNotification.class.getSimpleName();

    public static void setSchedule(int interval, String message, int tag) {
        Activity activity = Cocos2dxHelper.getActivity();
        PendingIntent sender = getPendingIntent(message, tag);

        Calendar calendar = Calendar.getInstance();
        calendar.setTimeInMillis(System.currentTimeMillis());
        calendar.add(Calendar.SECOND, interval);

        AlarmManager am = (AlarmManager)activity.getSystemService(Context.ALARM_SERVICE);
        am.set(AlarmManager.RTC_WAKEUP, calendar.getTimeInMillis(), sender);
    }

    private static PendingIntent getPendingIntent(String message, int tag) {
        Activity activity = Cocos2dxHelper.getActivity();
        Intent i = new Intent(activity.getApplicationContext(), LocalNotificationReceiver.class);
        i.putExtra("notification_id", tag);
        i.putExtra("message", message);
        PendingIntent sender = PendingIntent.getBroadcast(activity,  tag, i, PendingIntent.FLAG_UPDATE_CURRENT);
        return sender;
    }
}
