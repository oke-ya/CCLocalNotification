package com.oke_ya.cc_local_notification;

import org.cocos2dx.lib.Cocos2dxActivity;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.ActivityManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v4.app.NotificationCompat;
import android.content.res.Resources;
import android.util.Log;

public class LocalNotificationReceiver extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {
        ActivityManager am = (ActivityManager)context.getSystemService(Context.ACTIVITY_SERVICE);
        if (am.getRunningTasks(1).get(0).topActivity.getPackageName().equals(context.getPackageName())) {
            return;
        }
        int notificationId = intent.getIntExtra("notification_id", 0);
        String message = intent.getStringExtra("message");

        Intent i = new Intent(context, Cocos2dxActivity.class);
        i.setFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
        PendingIntent pendingIntent = PendingIntent.getActivity(context, 0, i, PendingIntent.FLAG_UPDATE_CURRENT);
        Resources resources = context.getResources();
        String packageName = context.getPackageName();
        String appName = context.getString(resources.getIdentifier("app_name", "string", packageName));
        int smallIcon = resources.getIdentifier("ic_notice" , "mipmap", packageName);
        int icon = resources.getIdentifier("ic_launcher" , "mipmap", packageName);
        Bitmap largeIcon = BitmapFactory.decodeResource(resources, icon);
        NotificationCompat.Builder builder = new NotificationCompat.Builder(context);

        builder.setContentTitle(appName);
        builder.setContentText(message);
        builder.setSmallIcon(smallIcon);
        builder.setLargeIcon(largeIcon);
        builder.setTicker(message);
        builder.setAutoCancel(true);
        builder.setDefaults(Notification.DEFAULT_ALL);
        builder.setContentIntent(pendingIntent);

        NotificationManager manager = (NotificationManager) context
                .getSystemService(Context.NOTIFICATION_SERVICE);
        manager.notify(notificationId, builder.build());
    }

}
