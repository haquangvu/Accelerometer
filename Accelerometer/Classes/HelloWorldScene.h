#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "MyAccelerometer.h"

#define kSampleArray    3
#define epsilon         0.05

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer
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
    
    CCLabelTTF *labelX;
    CCLabelTTF *labelY;
    CCLabelTTF *labelZ;
    
    bool moveUP = false;
    bool moveDown = false; 
    bool moveLeft = false;
    bool moveRight = false;
    
    void update(float delta);
    virtual void didAccelerate(CCAcceleration* pAccelerationValue);
    
    std::vector<float> arrayX;
    
    bool firstTime = true;
    float currentX;
    
    bool isShake = false;
    
    void onEnter();
    void onExit();
};

#endif // __HELLOWORLD_SCENE_H__
