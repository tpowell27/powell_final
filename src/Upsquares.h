
#ifndef __powell_final__Upsquares__
#define __powell_final__Upsquares__

#include <stdio.h>
#include <ofMain.h>

class Upsquares{
    
public:
    Upsquares();
    
    void setup();
    void update();
    void draw();

    
    float urads;
    float ur;
    float ug;
    float ub;
    float ua;

    
    ofVec2f ustart;
    ofVec2f upos;
    ofVec2f uvel;
    ofColor ucol;

};
#endif /* defined(__Bubbles___Balls__) */
