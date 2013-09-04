//
//  MyAccelerometerProtocol.h
//  Accelerometer
//
//  Created by K3 on 9/4/13.
//
//

#ifndef Accelerometer_MyAccelerometerProtocol_h
#define Accelerometer_MyAccelerometerProtocol_h

#import "cocos2d.h"

using namespace cocos2d;

class MyAccelerationRotate {
public:    
    double x;
    double y;
    double z;
};

class MyAccelerationSnake {
public:
    double xLeft;
    double yLeft;
    double zLeft;
    
    double xRight;
    double yRight;
    double zRight;
};



class MyAccelerometerDelegate {
public:
    virtual void acceleration(MyAccelerationRotate *pAccelerationValue) { CC_UNUSED_PARAM(pAccelerationValue); };
    
    virtual void snake(MyAccelerationSnake *pSnakeValue) { CC_UNUSED_PARAM(pSnakeValue); };
    
};

#endif
