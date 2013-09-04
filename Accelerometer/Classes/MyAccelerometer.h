//
//  MyAccelerometer.h
//  Accelerometer
//
//  Created by K3 on 8/29/13.
//
//

#ifndef __Accelerometer__MyAccelerometer__
#define __Accelerometer__MyAccelerometer__

#include <iostream>
#include "cocos2d.h"
#include "MyAccelerometerProtocol.h"

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

class MyAccelerometer:public CCObject, public CCAccelerometerDelegate {
    MyAccelerationRotate *accelerationValue;
    MyAccelerationSnake  *snakeValue;
    
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
    MyAccelerometer();
    ~ MyAccelerometer();
    
    bool init();
    virtual void didAccelerate(CCAcceleration* pAccelerationValue);
    
    MyAccelerometerDelegate *myDelegate;
    void setDelegate(MyAccelerometerDelegate *_myDelegate);
};

#endif /* defined(__Accelerometer__MyAccelerometer__) */
