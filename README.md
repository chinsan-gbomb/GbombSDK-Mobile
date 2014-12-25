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
  <meta-data android:name="com.gbombgames.sdk.3rd" android:value="false"/>
  <meta-data android:name="com.gbombgames.sdk.gameId" android:value="YOUR_GAME_ID"/>
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
	protected void onResume() {
		GbombClient.onResume();
		super.onResume();
	}
```
and add the following lines into your AppDelegate
``` cpp
  IGbombClient *client = GbombClient::getInstance();
	client->init("YOUR_GAME_ID");
```

###Callback
1. code: 100 is okay, others is failed
2. data: The format is using [JSend](http://labs.omniti.com/labs/jsend)
3. sample:
``` json
{
  "status": "success", 
  "data": { }
}
```
More documentation is still to come. For now, please see header/IGbombClient.h and GbombSDKSample.
