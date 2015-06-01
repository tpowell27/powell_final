
#include "Downsquares.h"

Downsquares::Downsquares(){
    dpos = ofVec2f(ofRandom(0,ofGetWidth()-(ofGetWidth()/4)),ofRandom(0,ofGetHeight()));
    dvel = ofVec2f(0.5,0);
    dr = ofRandom(50,255);
    dg = 0;
    db = 0;
    da = ofRandom(25,200);
    dcol = ofColor(dr,dg,db,da);
    drads = ofRandom(10,30);
}

void Downsquares::setup(){
    dstart = dpos;
}

void Downsquares::update(){
    dpos+=dvel;
    ofSetCircleResolution(4);
}

void Downsquares::draw(){
    ofPushMatrix();
    ofTranslate(dpos);
    ofCircle(0,0,drads);
    ofPopMatrix();
}