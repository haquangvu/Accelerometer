#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PAccelerometer.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer, public PAccelerometerDelegate
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    CCLabelTTF *labelXLeft;
    CCLabelTTF *labelXRight;
    CCLabelTTF *labelYLeft;
    CCLabelTTF *labelYRight;
    CCLabelTTF *labelZLeft;
    CCLabelTTF *labelZRight;
    
    CCLabelTTF *labelXLeftA;
    CCLabelTTF *labelXRightA;
    CCLabelTTF *labelYLeftA;
    CCLabelTTF *labelYRightA;
    
    void onEnter();
    void onExit();
    
    void disableAll();
    void disableA();
    
    virtual void didAccelerate(PAccelerationRotate *pAccelerationValue, PAccelerationSnake *pSnakeValue);
    
};

#endif // __HELLOWORLD_SCENE_H__
