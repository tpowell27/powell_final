//
//  Upsquares.cpp
//  powell_final
//
//  Created by Travis Powell on 6/1/15.
//
//

#include "Upsquares.h"

Upsquares::Upsquares(){
    pos = ofVec2f(ofRandom((0+(ofGetWidth()/4)),ofGetWidth()),ofRandom(0,ofGetHeight()));
    vel = ofVec2f(0.05,0);
    r = 0;
    g = ofRandom(0,120);
    b = ofRandom(50,255);
    a = ofRandom(25,200);
    col = ofColor(r,g,b,255);
    rads = ofRandom(5,20);
//    rot = 0;
    
//    winx = ofGetWindowWidth();
//    winy = ofGetWindowHeight();
}

void Upsquares::setup(){
    start = pos;
    ofSetCircleResolution(4);
}

void Upsquares::update(){
    pos-=vel;
//    rot+=abs(vel.x);
    
//    float distance = ofDist(start.x,start.y,pos.x,pos.y);
//    float bright = ofMap(distance,0,500,0,255);
//    float green = ofMap(distance,0,200,150,255);
//    float blue = ofMap(distance,0,200,50,255);
//    col.a=(bright);
//    col.g=(green);
//    col.b=(blue);
//    
//    if(((pos.x>=winx)&&(pos.x<=winx+1))||((pos.x<=0)&&(pos.x>=winx-1))) {
//        ofBackground(ofRandom(100,200),ofRandom(100,200),ofRandom(100,200));
//    }
//    if(((pos.y>=winy)&&(pos.y<=winy+1))||((pos.y<=0)&&(pos.y>=winy-1))) {
//        ofBackground(ofRandom(100,200),ofRandom(100,200),ofRandom(100,200));
//    }
}

void Upsquares::draw(){
    ofSetColor(col);
    ofPushMatrix();
    ofTranslate(pos);
//    ofRotate(rot);
    ofCircle(0,0,rads);
    ofPopMatrix();

}