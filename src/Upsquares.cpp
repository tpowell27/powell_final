
#include "Upsquares.h"

Upsquares::Upsquares(){
    upos = ofVec2f(ofRandom((0+(ofGetWidth()/4)),ofGetWidth()),ofRandom(0,ofGetHeight()));
    uvel = ofVec2f(0.5,0);
    ur = 0;
    ug = 0;
    ub = ofRandom(50,255);
    ua = ofRandom(25,200);
    ucol = ofColor(ur,ug,ub,255);
    urads = ofRandom(5,20);
}

void Upsquares::setup(){
    ustart = upos;
    ofSetCircleResolution(4);
}

void Upsquares::update(){
    upos-=uvel;

}

void Upsquares::draw(){
    ofPushMatrix();
    ofTranslate(upos);
    ofCircle(0,0,urads);
    ofPopMatrix();
}