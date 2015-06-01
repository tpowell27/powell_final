
#ifndef __powell_final__Downsquares__
#define __powell_final__Downsquares__

#include <stdio.h>
#include <ofMain.h>

class Downsquares{
    
public:
    Downsquares();
    
    void setup();
    void update();
    void draw();

    
    float drads;
    float dr;
    float dg;
    float db;
    float da;
    float dres;
    
    ofVec2f dstart;
    ofVec2f dpos;
    ofVec2f dvel;
    ofColor dcol;
    
};

#endif /* defined(__Bubbles___bubbles__) */