#include "HelloWorldScene.h"

USING_NS_CC;

const EventKeyboard::KeyCode RIGHT_ARROW = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
const EventKeyboard::KeyCode LEFT_ARROW = EventKeyboard::KeyCode::KEY_LEFT_ARROW;

Scene* HelloWorld::createScene()
{
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
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    label = Label::createWithTTF("Hello Test", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
    keyListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

    // add "HelloWorld" splash screen"
        auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to tzzhis layer
    this->addChild(sprite, 0);
    
    this->schedule(schedule_selector(HelloWorld::update));
    
    return true;
}

void HelloWorld::update(float dt){
    auto pos = label->getPosition();
    if(std::find(heldKeys.begin(), heldKeys.end(), RIGHT_ARROW) != heldKeys.end()){
        label->setPosition(Vec2(label->getPosition().x+1.0f, label->getPosition().y));
    }
    else if(std::find(heldKeys.begin(), heldKeys.end(), LEFT_ARROW) != heldKeys.end()){
        label->setPosition(Vec2(label->getPosition().x-1.0f, label->getPosition().y));
    }
}

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    if(std::find(heldKeys.begin(), heldKeys.end(), keyCode) == heldKeys.end()){
        heldKeys.push_back(keyCode);
    }
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    heldKeys.erase(std::remove(heldKeys.begin(), heldKeys.end(), keyCode), heldKeys.end());
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
