#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(150);
    ofSetFrameRate(30);

    twitterClient.setDiskCache(true);
    
//  Authorizes the application on twitter.
    string const CONSUMER_KEY = "sxkC3z0mHGEUzWHjNrJBMMWWv";
    string const CONSUMER_SECRET = "ins31Rr1wigG4WRtuAl85y3ptGAnwwXtC3o193ddS00UFqRTcW";
    
    twitterClient.authorize(CONSUMER_KEY, CONSUMER_SECRET);
    
    actualTweet = 0;
    
//  The variable that determines the random number to choose tweets.
    int ram;
//  Sets which squares to draw based on which tweets are coming in.
    bool grh = false;
    bool grs = false;
    bool blh = false;
    bool bls = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//  Updates the squares.
    Downsquares tempDown;
    tempDown.setup();
    downs.push_back(tempDown);
    
    Upsquares tempUp;
    tempUp.setup();
    ups.push_back(tempUp);
    
//  Calls a random search every ten seconds. Recieved tweets determine which squares to draw.
    if(ofGetFrameNum()%300==0) {
        ofxTwitterSearch search;
        ram = ofRandom(0,3);
        
        if(ram==0){
        search.count = 1;
        search.query = "%23BlackLivesMatter+:)";
        twitterClient.startSearch(search);
        
        blh = true;

        }

        if(ram==1) {
        search.count = 1;
        search.query = "%23BlackLivesMatter+:(";
        twitterClient.startSearch(search);
        
        bls = true;
        }
        
        if(ram==2) {
        search.count = 1;
        search.query = "%23itgetsbetter+:)";
        twitterClient.startSearch(search);
        
        grh = true;
        }

        if(ram==3) {
        search.count = 1;
        search.query = "%23itgetsbetter+:(";
        twitterClient.startSearch(search);
        
        grs = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    
//  Sets the maximum line size to 140 characters, the same as a normal online tweet.
    int maxLineSize = 140;
    
//  Checks to make sure the
    if(twitterClient.getTotalLoadedTweets() > 0) {
        
        tweet = twitterClient.getTweetByIndex(actualTweet);

    }

    twitterClient.printDebugInfo();

//  Determines which tweet to search based on a random number generator. Each search has a different colored square.
    for (int i=0; i<ups.size(); i++) {
        ups[i].update();
        if(blh==true) {
        ofSetColor(0, 0, 255,ofRandom(50,200));
        ofSetCircleResolution(4);
        for(int i=0; i<ups.size(); i++) {
            ups[i].draw();
        }
    }
    }
    
    for (int i=0; i<downs.size(); i++) {
        downs[i].update();
        if(bls==true) {
        ofSetColor(255, 0, 0,ofRandom(50,200));
        ofSetCircleResolution(4);
        for(int i=0; i<downs.size(); i++) {
            downs[i].draw();
        }
    }
    }
    
    for (int i=0; i<ups.size(); i++) {
        ups[i].update();
    if(grh==true) {

        ofSetColor(0,ofRandom(175,255),255,ofRandom(50,200));
        ofSetCircleResolution(4);
        for(int i=0; i<ups.size(); i++) {
            ups[i].draw();
        }
    }
    }
    
    for (int i=0; i<downs.size(); i++) {
        downs[i].update();
    if(grs==true) {
        ofSetColor(255, ofRandom(175,255),0,ofRandom(50,200));
        ofSetCircleResolution(4);
        for(int i=0; i<downs.size(); i++) {
            downs[i].draw();
        }
    }
    }

    
//  Compares the distance from the starting point to the length of the tweet its self. The distance is scaled to match the tweet length and is erased after traveling the equivelant of the length of the text.
    for(int i=0; i<downs.size(); i++) {
        downs[i].update();
        float distance=ofDist(downs[i].dstart.x,downs[i].dstart.y,downs[i].dpos.x,downs[i].dpos.y);
        float lnt= ofMap(distance,0,100,0,maxLineSize);
        if(lnt>tweet.text.length()){
            downs.erase(downs.begin()+i);
            i--;
        }
    }
    for(int i=0; i<ups.size(); i++) {
        ups[i].update();
        float distance=ofDist(ups[i].ustart.x,ups[i].ustart.y,ups[i].upos.x,ups[i].upos.y);
        float lnt= ofMap(distance,0,100,0,maxLineSize);
        if(lnt>tweet.text.length()){
            ups.erase(ups.begin()+i);
            i--;
        }
    }
    
//  Draws the tweet in the upper left corner.
    string text = tweet.text;
    for(int i=0;i<(tweet.text.length()/maxLineSize)+1;i++) {
        ofDrawBitmapStringHighlight(text.substr(i*maxLineSize,maxLineSize), ofPoint(20,20+(30*i)));
    }
    
}
