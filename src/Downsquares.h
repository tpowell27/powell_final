//
//  Downsquares.h
//  powell_final
//
//  Created by Travis Powell on 6/1/15.
//
//

#ifndef __powell_final__Downsquares__
#define __powell_final__Downsquares__

#include <stdio.h>
#include <ofMain.h>
#include <Upsquares.h>

class Downsquares{
    
public:
    Downsquares();
    
    void setup(float _x,float _y);
    void update();
    void draw();
    
    float rads;
//    float rot;
//    float winx;
//    float winy;
    float r;
    float g;
    float b;
    float a;
    float res;
    
    ofVec2f start;
    ofVec2f pos;
    ofVec2f vel;
    ofColor col;
    
    vector <Upsquares> ups;
};

#endif /* defined(__Bubbles___bubbles__) */