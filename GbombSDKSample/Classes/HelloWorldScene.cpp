#define COCOS2D_DEBUG 1

#include "HelloWorldScene.h"
#include "GbombClient.h"

USING_NS_CC;

Scene* HelloWorld::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
	//////////////////////////////
	// 1. super init first
	if (!Layer::init()) {
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create("CloseNormal.png",
			"CloseSelected.png",
			CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(
			Vec2(
					origin.x + visibleSize.width
							- closeItem->getContentSize().width / 2,
					origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto item1 = MenuItemFont::create("GetProductList", [&](Ref* sender) {
		IGbombClient *client = GbombClient::getInstance();
		client->getProductList("", [](const int code, const std:: string data) {
					CCLOG("start callback");
					CCLOG("code: %d", code);
					CCLOG("%s", data.c_str());
				});
	});
	item1->setFontSize(40);
	item1->setFontName("Marker Felt");
	auto menu1 = Menu::create(item1, NULL);
	menu1->setPosition(Point(item1->getContentSize().width / 2, 400));
	addChild(menu1);

	auto item2 = MenuItemFont::create("Login", [&](Ref* sender) {
		IGbombClient *client = GbombClient::getInstance();
		client->login([](const int code, const std::string data) {
					CCLOG("start callback");
					CCLOG("code: %d", code);
					CCLOG("%s", data.c_str());
				});
	});
	item2->setFontSize(40);
	item2->setFontName("Marker Felt");
	auto menu2 = Menu::create(item2, NULL);
	menu2->setPosition(Point(item2->getContentSize().width / 2, 500));
	addChild(menu2);

	auto item3 = MenuItemFont::create("Purchase", [&](Ref* sender) {
		IGbombClient *client = GbombClient::getInstance();
		client->purchase(
				"Steve Jobs",
				"s1",
				"gbomb005",
				"5",
				"Gbomb",
				"",
				"9cf1bce9b2dad318871853116ab0027e51b674f0",
				[](const int code, const std::string data) {
					CCLOG("start callback");
					CCLOG("code: %d", code);
					CCLOG("%s", data.c_str());
				});
	});
	item3->setFontSize(40);
	item3->setFontName("Marker Felt");
	auto menu3 = Menu::create(item3, NULL);
	menu3->setPosition(Point(item3->getContentSize().width / 2, 300));
	addChild(menu3);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = LabelTTF::create("GbombSDK Sample", "Arial", 24);

	// position the label on the center of the screen
	label->setPosition(
			Vec2(origin.x + visibleSize.width / 2,
					origin.y + visibleSize.height
							- label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(
			Vec2(visibleSize.width / 2 + origin.x,
					visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	return true;
}

void test() {
	CCLOG("start sub");

//	client->unsubPush("regid1234", [](const int code, const std::string data) {
//		CCLOG("start callback");
//		CCLOG("code: %d", code);
//		CCLOG("%s", data.c_str());
//	});

//	client->callService([](const int code, const std::string data) {
//		CCLOG("start callback");
//		CCLOG("code: %d", code);
//		CCLOG("%s", data.c_str());
//	});
}

void HelloWorld::menuCloseCallback(Ref* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
