//
//  MyAccelerometer.cpp
//  Accelerometer
//
//  Created by K3 on 8/29/13.
//
//

#include "MyAccelerometer.h"

MyAccelerometer::MyAccelerometer(){
    accelerationValue = new MyAccelerationRotate();
    snakeValue = new MyAccelerationSnake();
}

MyAccelerometer::~MyAccelerometer(){
    delete accelerationValue;
    delete snakeValue;
}

bool MyAccelerometer::init(){
    myDelegate = NULL;
    CCDirector::sharedDirector()->getAccelerometer()->setDelegate(this);
    return true;
}

void MyAccelerometer::setDelegate(MyAccelerometerDelegate *_myDelegate){
    myDelegate = _myDelegate;
}

void MyAccelerometer::didAccelerate(cocos2d::CCAcceleration *pAccelerationValue){
    if (!myDelegate) {
        return;
    }
    
    float x = pAccelerationValue->x;
    float y = pAccelerationValue->y;
    float z = pAccelerationValue->z;
    
    if (firstTime) {
        currentX = x;
        currentY = y;
        currentZ = z;
        firstTime = false;
    }
    
    if (fabsf(currentX - x) > epsilon) {
        arrayX.push_back(x);
        isShake = true;
    }else{
        isShake = false;
    }
    
    if (fabsf(currentY - y) > epsilon) {
        arrayY.push_back(y);
        isShake = true;
    }else{
        isShake = false;
    }
    
    if (fabsf(currentZ - z) > epsilon) {
        arrayZ.push_back(z);
        isShake = true;
    }else{
        isShake = false;
    }
    
    currentX = x;
    currentY = y;
    currentZ = z;
    
    /*
     *  device rotate in axis itself
     *
     */
    
    accelerationValue->x = pAccelerationValue->x;
    accelerationValue->y = pAccelerationValue->y;
    accelerationValue->z = pAccelerationValue->z;
    
    myDelegate->acceleration(accelerationValue);
    
    
    /*
     *  check device snake
     *
     */
    
    // set default value snake and flag delegate
    this->setValueSnakeIsNULL();
    flag = false;
    
    if (!isShake && arrayX.size() >= kSampleArray) {
        float min = *std::min_element(arrayX.begin(), arrayX.end());
        float max = *std::max_element(arrayX.begin(), arrayX.end());
                
        if (fabs(min - max) > kSnakeSensitive) {
            
            int posMin = std::find(arrayX.begin(),
                                   arrayX.end(),
                                   min) - arrayX.begin();
            
            int posMax = std::find(arrayX.begin(),
                                   arrayX.end(),
                                   max) - arrayX.begin();
                        
            if (posMax > posMin) {
                snakeValue->xRight = max;
            } else{
                snakeValue->xLeft  = min;
            }
            
            flag = true;
        }
        arrayX.erase(arrayX.begin(), arrayX.end ());
    }
    
    if (!isShake && arrayY.size() >= kSampleArray) {
        
        float min = *std::min_element(arrayY.begin(), arrayY.end());
        float max = *std::max_element(arrayY.begin(), arrayY.end());
        
        
        if (fabs(min - max) > kSnakeSensitive) {            
            int posMin = std::find(arrayY.begin(),
                                   arrayY.end(),
                                   min) - arrayY.begin();
            
            int posMax = std::find(arrayY.begin(),
                                   arrayY.end(),
                                   max) - arrayY.begin();
            
            if (posMax > posMin) {
                snakeValue->yRight = max;
            } else{
                snakeValue->yLeft = min;
            }
            
            flag = true;
        }        
        arrayY.erase(arrayY.begin(), arrayY.end ());
    }
    
    if (!isShake && arrayZ.size() >= kSampleArray) {
        
        float min = *std::min_element(arrayZ.begin(), arrayZ.end());
        float max = *std::max_element(arrayZ.begin(), arrayZ.end());
        
        
        if (fabs(min - max) > kSnakeSensitive) {
            int posMin = std::find(arrayZ.begin(),
                                   arrayZ.end(),
                                   min) - arrayZ.begin();
            
            int posMax = std::find(arrayZ.begin(),
                                   arrayZ.end(),
                                   max) - arrayZ.begin();
            
            if (posMax > posMin) {
                snakeValue->zRight = max;
            } else{
                snakeValue->zLeft = min;
            }
            
            flag = true;
        }        
        arrayZ.erase(arrayZ.begin(), arrayZ.end ());
    }
    
    if (flag) {
        myDelegate->snake(snakeValue);
    }
    
}

void MyAccelerometer::setValueSnakeIsNULL(){
    snakeValue->xLeft = kNULLSnake;
    snakeValue->xRight = kNULLSnake;
    snakeValue->yLeft = kNULLSnake;
    snakeValue->yRight = kNULLSnake;
    snakeValue->zLeft = kNULLSnake;
    snakeValue->zRight = kNULLSnake;
}
