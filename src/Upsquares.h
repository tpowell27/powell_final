//
//  Upsquares.h
//  powell_final
//
//  Created by Travis Powell on 6/1/15.
//
//

#ifndef __powell_final__Upsquares__
#define __powell_final__Upsquares__

#include <stdio.h>
#include <ofMain.h>
#include <Downsquares.h>

class Upsquares{
    
public:
    Upsquares();
    
    void setup();
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
    
    ofVec2f start;
    ofVec2f pos;
    ofVec2f vel;
    ofColor col;

    vector <Downsquares> downs;
};
#endif /* defined(__Bubbles___Balls__) */
