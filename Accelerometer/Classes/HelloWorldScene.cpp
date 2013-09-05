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
    
    /*
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);
    */
    /*
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    */
    
    labelXLeft  = CCLabelTTF::create("-", "Arial", 24);
    labelXRight = CCLabelTTF::create("+", "Arial", 24);
    labelYLeft  = CCLabelTTF::create("-", "Arial", 24);
    labelYRight = CCLabelTTF::create("+", "Arial", 24);
    labelZLeft  = CCLabelTTF::create("-", "Arial", 20);
    labelZRight = CCLabelTTF::create("+", "Arial", 40);
    
    labelXLeft->setPosition(ccp(24, visibleSize.height/2));
    labelXRight->setPosition(ccp(visibleSize.width - 24, visibleSize.height/2));
    labelYLeft->setPosition(ccp(visibleSize.width/2, 24));
    labelYRight->setPosition(ccp(visibleSize.width/2, visibleSize.height - 24));
    labelZLeft->setPosition(ccp(visibleSize.width/3, visibleSize.height/2));
    labelZRight->setPosition(ccp(visibleSize.width*2/3, visibleSize.height/2));

    labelXLeftA  = CCLabelTTF::create("-", "Arial", 24);
    labelXLeftA->setColor(ccBLUE);
    labelXRightA = CCLabelTTF::create("+", "Arial", 24);
    labelXRightA->setColor(ccBLUE);
    labelYLeftA  = CCLabelTTF::create("-", "Arial", 24);
    labelYLeftA->setColor(ccBLUE);
    labelYRightA = CCLabelTTF::create("+", "Arial", 24);
    labelYRightA->setColor(ccBLUE);
    
    labelXLeftA->setPosition(ccp(labelXLeft->getPositionX(), labelXLeft->getPositionY() + 24));
    labelXRightA->setPosition(ccp(labelXRight->getPositionX(), labelXRight->getPositionY() + 24));
    labelYLeftA->setPosition(ccp(labelYLeft->getPositionX(), labelYLeft->getPositionY() + 24));
    labelYRightA->setPosition(ccp(labelYRight->getPositionX(), labelYRight->getPositionY() - 24));
    
    this->addChild(labelXLeft);
    this->addChild(labelXRight);
    this->addChild(labelYLeft);
    this->addChild(labelYRight);
    this->addChild(labelZLeft);
    this->addChild(labelZRight);
    
    this->addChild(labelXLeftA);
    this->addChild(labelXRightA);
    this->addChild(labelYLeftA);
    this->addChild(labelYRightA);

    this->disableAll();
    this->disableA();
    
    this->scheduleUpdate();
        
    
    PAccelerometer::sharedAccelerometer()->setDelegate(this);
    
    return true;
}


void HelloWorld::didAccelerate(PAccelerationRotate *pAccelerationValue, PAccelerationSnake *pSnakeValue){
    if (pSnakeValue->isSnake) {
        disableAll();
        if (pSnakeValue->xLeft != kNULLSnake) {
            labelXLeft->setString(CCString::createWithFormat("%3.2f", pSnakeValue->xLeft)->getCString());
            labelXLeft->setVisible(true);
        }
        if (pSnakeValue->xRight != kNULLSnake) {
            labelXRight->setString(CCString::createWithFormat("%3.2f", pSnakeValue->xRight)->getCString());
            labelXRight->setVisible(true);
        }
        if (pSnakeValue->yLeft != kNULLSnake) {
            labelYLeft->setString(CCString::createWithFormat("%3.2f", pSnakeValue->yLeft)->getCString());
            labelYLeft->setVisible(true);
        }
        if (pSnakeValue->yRight != kNULLSnake) {
            labelYRight->setString(CCString::createWithFormat("%3.2f", pSnakeValue->yRight)->getCString());
            labelYRight->setVisible(true);
        }
        if (pSnakeValue->zLeft != kNULLSnake) {
            labelZLeft->setString(CCString::createWithFormat("%3.2f", pSnakeValue->zLeft)->getCString());
            labelZLeft->setVisible(true);
        }
        if (pSnakeValue->zRight != kNULLSnake) {
            labelZRight->setString(CCString::createWithFormat("%3.2f", pSnakeValue->zRight)->getCString());
            labelZRight->setVisible(true);
        }
    }
}

void HelloWorld::disableAll(){
    labelXLeft->setVisible(false);
    labelXRight->setVisible(false);
    labelYLeft->setVisible(false);
    labelYRight->setVisible(false);
    labelZLeft->setVisible(false);
    labelZRight->setVisible(false);       
}

void HelloWorld::disableA(){
    labelXLeftA->setVisible(false);
    labelXRightA->setVisible(false);
    labelYLeftA->setVisible(false);
    labelYRightA->setVisible(false);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    
}

void HelloWorld::onEnter(){
    CCLayer::onEnter();
}

void HelloWorld::onExit(){
    CCLayer::onExit();
}



