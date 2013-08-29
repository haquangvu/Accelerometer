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

using namespace cocos2d;

class MyAccelerometer:public CCObject {
    
public:
    bool init();
    void accelerate(CCAcceleration* pAccelerationValue);
    void update(float dt);
};

#endif /* defined(__Accelerometer__MyAccelerometer__) */
