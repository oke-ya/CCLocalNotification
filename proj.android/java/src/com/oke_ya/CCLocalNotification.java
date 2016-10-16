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
import android.content.SharedPreferences;
import android.os.Bundle;
import android.content.Context;

public class CCLocalNotification {
    private static final String TAG = CCLocalNotification.class.getSimpleName();
    private static final String KEY = "enableNotifcation";
    private static boolean mInit = false;
    private static boolean mEnabled;
    private static SharedPreferences mPref;
    private static Context mContext;
    private static AlarmManager mAlarmManager;
    private static Activity mActivity;

    public static void init() {
        if(mInit){
            return;
        }
        mInit = true;
        mActivity = Cocos2dxHelper.getActivity();
        mContext = mActivity.getApplicationContext();
        mPref = mContext.getSharedPreferences(TAG, Context.MODE_PRIVATE);
        mEnabled = mPref.getBoolean(KEY, true);

        mAlarmManager = (AlarmManager)mActivity.getSystemService(Context.ALARM_SERVICE);
    }

    public static void setSchedule(int interval, String message, int tag) {
        if(!mEnabled){
            return;
        }
        PendingIntent sender = getPendingIntent(message, tag);

        Calendar calendar = Calendar.getInstance();
        calendar.setTimeInMillis(System.currentTimeMillis());
        calendar.add(Calendar.SECOND, interval);
        mAlarmManager.set(AlarmManager.RTC_WAKEUP, calendar.getTimeInMillis(), sender);
    }

    public static void setEnabled(boolean b) {
        mPref.edit().putBoolean(KEY, b).commit();
        mEnabled = b;
        if(!mEnabled){
            Intent intent = new Intent(mContext, LocalNotificationReceiver.class);
            PendingIntent pendingIntent = PendingIntent.getBroadcast(mContext, 0, intent, 0);
            pendingIntent.cancel();
            mAlarmManager.cancel(pendingIntent);
        }
    }

    public static boolean isEnabled() {
        return mEnabled;
    }

    private static PendingIntent getPendingIntent(String message, int tag) {
        Activity activity = Cocos2dxHelper.getActivity();
        Intent i = new Intent(mContext, LocalNotificationReceiver.class);
        i.putExtra("notification_id", tag);
        i.putExtra("message", message);
        PendingIntent sender = PendingIntent.getBroadcast(activity,  tag, i, PendingIntent.FLAG_UPDATE_CURRENT);
        return sender;
    }
}
