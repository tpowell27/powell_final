//
//  Downsquares.cpp
//  powell_final
//
//  Created by Travis Powell on 6/1/15.
//
//

#include "Downsquares.h"

Downsquares::Downsquares(){
    pos = ofVec2f(ofRandom(0,ofGetWidth()-(ofGetWidth()/4)),ofRandom(0,ofGetHeight()));
//    vel = ofVec2f(ofRandom(-5,5),ofRandom(-5,5));
    r = ofRandom(50,255);
    g = ofRandom(0,120);
    b = 0;
    a = ofRandom(25,200);
    col = ofColor(r,g,b,a);
    rads = ofRandom(10,30);
    //rot = 0;
    res = 4;
//    
//    winx = ofGetWindowWidth();
//    winy = ofGetWindowHeight();
}

void Downsquares::setup(float _x,float _y){
    pos = ofVec2f(_x,_y);
    start = pos;
}

void Downsquares::update(){
    Upsquares tempUp;
    tempUp.setup();
    ups.push_back(tempUp);
    
    pos+=vel;
//    rot+=abs(vel.x);
    ofSetCircleResolution(res);
    
//    float distance = ofDist(start.x,start.y,pos.x,pos.y);
//    float bright = ofMap(distance,0,600,255,0);
//    col.a=(bright);
    
//    if((pos.x>=winx-rads)||(pos.x<=0+rads)) {
//        vel.x*=-2;
//        res=4;
//        col.r=ofRandom(0,50);
//        col.g=ofRandom(150,250);
//        col.b=ofRandom(0,50);
//    }
//    if((pos.y>=winy)||(pos.y<=0)) {
//        vel.y*=-1;
//        res=6;
//        col.r=ofRandom(0,50);
//        col.g=ofRandom(150,25);
//        col.b=ofRandom(0,50);
//    }
    
    //if((pos.x+distance==tempBall.pos.x+tempBall.distance)&&(pos.y+rads==tempBall.pos.y+tempBall.rads)) {
    //    pos.x*=-1;
    //     pos.y*=-1;
    // }
}

void Downsquares::draw(){
    ofSetColor(col);
    ofPushMatrix();
    ofTranslate(pos);
//    ofRotate(rot);
    ofCircle(0,0,rads);
    ofPopMatrix();
}