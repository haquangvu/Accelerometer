//
//  Accelerometer.h
//  Accelerometer
//
//  Created by K3 on 8/29/13.
//
//

#ifndef __Accelerometer__PAccelerometer__
#define __Accelerometer__PAccelerometer__

#include <iostream>
#include "cocos2d.h"

#define kSampleArray        3
/*
 * 
 */
#define epsilon             0.05f
/*
 *  gía trị snake = null
 */
#define kNULLSnake          -10.0f
/*
 * độ nhạy của snake
 */
#define kSnakeSensitive     0.5f

using namespace cocos2d;

class PAccelerationRotate {
public:
    double x;
    double y;
    double z;
};

class PAccelerationSnake {
public:
    double xLeft;
    double yLeft;
    double zLeft;
    
    double xRight;
    double yRight;
    double zRight;
    
    bool isSnake = false;
};



class PAccelerometerDelegate {
public:
    virtual void didAccelerate(PAccelerationRotate *pAccelerationValue, PAccelerationSnake *pSnakeValue){ CC_UNUSED_PARAM(pAccelerationValue); CC_UNUSED_PARAM(pSnakeValue); };
    
};

class PAccelerometer:public CCObject, public CCAccelerometerDelegate {
    PAccelerationRotate *accelerationValue;
    PAccelerationSnake  *snakeValue;
    
    std::vector<float> arrayX;
    std::vector<float> arrayY;
    std::vector<float> arrayZ;
    
    bool firstTime = true;
    float currentX;
    float currentY;
    float currentZ;
    bool isShake = false;
    bool flag = false;
    
    void setValueSnakeIsNULL();
    
public:
    PAccelerometer();
    ~ PAccelerometer();
    
    /** returns a shared instance of the PAccelerometer */
    static PAccelerometer* sharedAccelerometer(void);
    
    bool init();
    virtual void didAccelerate(CCAcceleration* pAccelerationValue);
    
    PAccelerometerDelegate *pDelegate;
    void setDelegate(PAccelerometerDelegate *_pDelegate);
};

#endif /* defined(__Accelerometer__Accelerometer__) */
