#GbombSDK-Mobile
##Interface
Our interface is in C++.
Please read header file, [IGbombClient.h](https://github.com/Asgard-Entertainment/GbombSDK-Mobile/blob/master/Android/GbombSDKWrapper/jni/include/IGbombClient.h).

Our Client is designed in Singleton pattern. So you can easily get an instance using a code below.
``` C++
IGbombClient *client = GbombClient::getInstance();
```
And the method as below.
``` C++
    /**
    	Initialize SDK, should call this before any function.
    	@param gameId, which is an id which we gave you.
    */
    void init(const string gameId);
    
    /**
    	Start a dialog and process the flow of login.
    	@param callback, APICallback has 2 returns, one is result code, and the other is result json string.
    */
    void login(const APICallback callback);

    /**
    	Open a web dialog and let user report the issues.
    	@param character_profile, make the character profile of the game in query string format.
        @param callback, APICallback has 2 returns, one is result code, and the other is result json string.
    */
    void callService(const string character_profile, const APICallback callback);
    
    /**
    	Get Product List via our server and store service.
    	@param character_profile, make the character profile of the game in query string format.
    	@param callback, APICallback has 2 returns, one is result code, and the other is result json string.
    */
    void getProductList(const string character_profile, const APICallback callback);
    
    /**
    	Start a flow of purchasing.
    	@param server_id, an identity of the server.
    	@param item_id, which is the item user would like to buy. 
    			It is from the result of getProductList.
    	@param onsales_id, which is the identity of our system for the item. 
    			   It is from the result of getProductList.
    	@param provider_id, which means the user logins via which oauth provider, like Facebook or something else.
    			    It is from the result of login.
    	@param character_profile, make the character profile of the game in query string format.
    	@param token, which is the token for the provider. It is from the result of login.
    	@param callback, APICallback has 2 returns, one is result code, and the other is result json string.
    */
    void purchase(const string cid,
                          const string server_id, 
                          const string item_id,
                          const string onsales_id,
                          const string provider_id,
                          const string character_profile,
                          const string token,
                          const APICallback callback);

    /**
    	Subscribe a device.
    	@param regid, which is an identify get from GCM or APN.
    	@param callback, APICallback has 2 returns, one is result code, and the other is result json string.
    */
    void subPush(const string regid, const APICallback callback);
    
    /**
    	Unsubscribe a device.
    	@param regid, which is an identify get from GCM or APN.
    	@param callback, APICallback has 2 returns, one is result code, the other is result json string.
    */
    void unsubPush(const string regid, const APICallback callback);
```
The result json string in APICallback are all in the same format, please read the [block of callback](https://github.com/Asgard-Entertainment/GbombSDK-Mobile/blob/master/README.md#callback)
##Android
###Setup
1. Make reference to our libraries in eclipse.
2. Add the following lines into AndroidManifest.xml
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
, add the following lines into your main AppActivity.java
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
, load our library before others
``` java
	System.loadLibrary("gbombsdk");
```
and add the following lines into your AppDelegate
``` cpp
  IGbombClient *client = GbombClient::getInstance();
	client->init("YOUR_GAME_ID");
```
##iOS
###Setup
1. Add StoreKit.framework into your project
2. Drag our frameworks into your project.
3. Add the following lines into Info.plist
``` plist
	<key>FacebookAppID</key>
	<string>855391541148444</string>
	<key>FacebookRedirectUri</key>
	<string>http://sdk.gbombgames.com/oauth_callback.php?provider_id=Facebook</string>
```
and add the following lines into your AppDelegate
``` cpp
  IGbombClient *client = GbombClient::getInstance();
	client->init("YOUR_GAME_ID");
```
##Callback
1. code: 100 is okay, others failed
2. data: The format is using [JSend](http://labs.omniti.com/labs/jsend)
3. sample:
``` json
{
  "status": "success", 
  "data": { }
}
```
4. result data
``` json
/* success data from login */
{ 
  "uid": "UNIQUE_ID", 
  "token": "ACCESS_TOKEN" , 
  "user_id":"ID_FROM_OAUTH_PROVIDER",
  "expires":"EXPIRED_TIME",
  "provider_id":"OAUTH_PROVIDER_NAME" 
}

/* success data from getProductList */
[
  {
    "currency_code": "NT", 
    "description": "DESCRIPTION_OF_ITEM", 
    "image_url": "", 
    "item_id": "ITEM_ID", 
    "onsale_id": "UNIQUE_ITEM_ID_IN_OUR_SERVER", 
    "price": 30,	/* PRICE IN NUMBER */ 
    "title": "TITLE_OF_ITEM"
  }, { /*SAME AS ABOVE */ }
]
```


More documentation is still to come. For now, please read [IGbombClient.h](https://github.com/Asgard-Entertainment/GbombSDK-Mobile/blob/master/Android/GbombSDKWrapper/jni/include/IGbombClient.h) and [GbombSDKSample](https://github.com/Asgard-Entertainment/GbombSDK-Mobile/tree/master/GbombSDKSample).
