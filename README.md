#GbombSDK-Mobile
##Android
Using the library is really simple, just look at the source code of the GbombSDKSample.
###Setup
add the following lines into AndroidManifest.xml
```xml
  <activity
    android:screenOrientation="landscape"
    android:theme="@android:style/Theme.NoTitleBar.Fullscreen"
    android:name="com.facebook.LoginActivity"/>
  <meta-data android:name="com.facebook.sdk.ApplicationId" android:value="@string/facebook_app_id"/>
  <activity
    android:screenOrientation="landscape"
    android:theme="@android:style/Theme.NoTitleBar.Fullscreen"
    android:name="com.gbombgames.LoginActivity"/>
  <meta-data android:name="com.gbombgames.sdk.ApplicationId" android:value="@string/gbomb_app_id"/>
  <meta-data android:name="com.gbombgames.sdk.googleplaykey" android:value="YOUR_IAP_KEY" />
  <meta-data android:name="com.gbombgames.3rd" android:value="false"/>
```
and add the following lines into your main AppActivity.java
```java
	protected void onCreate(final Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		GbombClient.init(this);
	}
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		GbombClient.onActivityResult(requestCode, resultCode, data);
		super.onActivityResult(requestCode, resultCode, data);
	}
```
and add the following lines into your AppDelegate
``` cpp
  IGbombClient *client = GbombClient::getInstance();
	client->init("YOUR_GAME_ID");
```

More documentation is still to come. For now, please see header/IGbombClient.h and GbombSDKSample.
