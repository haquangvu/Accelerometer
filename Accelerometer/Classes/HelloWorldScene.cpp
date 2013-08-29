#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

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
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    labelX = CCLabelTTF::create("labelX = ", "Arial", 24);
    labelY = CCLabelTTF::create("labelY = ", "Arial", 24);
    labelZ = CCLabelTTF::create("labelZ = ", "Arial", 24);
    
    labelY->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    labelX->setPosition(ccp(labelY->getPositionX(), labelY->getPositionY() + labelY->getContentSize().height));
    labelZ->setPosition(ccp(labelY->getPositionX(), labelY->getPositionY() - labelY->getContentSize().height));
    
    this->addChild(labelX);
    this->addChild(labelZ);
    this->addChild(labelY);
    
    this->scheduleUpdate();
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::onEnter(){
    CCLayer::onEnter();
    this->setAccelerometerEnabled(true);
}

void HelloWorld::onExit(){
    CCLayer::onExit();
}



void HelloWorld::didAccelerate(cocos2d::CCAcceleration *pAccelerationValue){
    labelX->setString(CCString::createWithFormat("labelX = %3.2f", pAccelerationValue->x)->getCString());
    labelY->setString(CCString::createWithFormat("labelY = %3.2f", pAccelerationValue->y)->getCString());
    labelZ->setString(CCString::createWithFormat("labelZ = %3.2f", pAccelerationValue->z)->getCString());
    
    float x = pAccelerationValue->x;
//    float y = pAccelerationValue->y;
//    float z = pAccelerationValue->z;
    
    if (firstTime) {
        currentX = x;
        firstTime = false;
    }
    
    if (fabsf(currentX - x) > epsilon) {
        arrayX.push_back(x);
        isShake = true;
    }else{
        isShake = false;
    }
    
    currentX = x;
    
    if (!isShake && arrayX.size() >= 3) {
//        CCLOG("-----count = %d------", arrayX.size());
//        for (int i=0 ; i<arrayX.size() ; i++) {
//            CCLOG("+++ %f", arrayX.at(i));
//        }
        
        float min = *std::min_element(arrayX.begin(), arrayX.end());
        float max = *std::max_element(arrayX.begin(), arrayX.end());
        CCLOG("min %f", min);
        CCLOG("max %f", max);
        
        if (fabs(min - max) > 0.5f) {
            if (fabs(min) > fabs(max)) {
                CCLOG("Right");
            } else{
                CCLOG("Left");
            }
        }
        
        arrayX.erase(arrayX.begin(), arrayX.end ());
    }
    
    /*
    arrayX.push_back(x);
    if (arrayX.size() == kSampleArray) {
        arrayX.erase(arrayX.begin());
    }
    
    for (int i=0 ; i<arrayX.size() ; i++) {
        
    }
    */
}

void HelloWorld::update(float delta)
{
    if (moveRight) {
        CCLOG("moveRight");
        moveRight = false;   // <- here
    }
    if (moveLeft) {
        CCLOG("moveLeft");
        moveLeft = false;     // <- here
    }
    if (moveUP) {
        CCLOG("moveUP");
        moveUP = false;      // <- here
    }
    if (moveDown) {
        CCLOG("moveDown");
        moveDown = false;   // <- here
    }
}



