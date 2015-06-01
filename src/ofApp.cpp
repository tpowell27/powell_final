#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    ofSetFrameRate(1);

    twitterClient.setDiskCache(true);
    
    string const CONSUMER_KEY = "sxkC3z0mHGEUzWHjNrJBMMWWv";
    string const CONSUMER_SECRET = "ins31Rr1wigG4WRtuAl85y3ptGAnwwXtC3o193ddS00UFqRTcW";
    
    twitterClient.authorize(CONSUMER_KEY, CONSUMER_SECRET);
    
    actualTweet = 0;
    
    float ram;
}

//--------------------------------------------------------------
void ofApp::update(){

    ram = ofRandom(0,5);
    
    Downsquares tempDown;
    tempDown.setup(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()));
    downs.push_back(tempDown);
    
    for(int i=0; i<downs.size(); i++) {
        downs[i].update();
        float distance=ofDist(downs[i].start.x,downs[i].start.y,downs[i].pos.x,downs[i].pos.y);
        if(distance>500){
            downs.erase(bubbleys.begin()+i);
            i--;
        }
    }
    
    for(int i=0; i<ups.size(); i++) {
        balls[i].update();
        float distance=ofDist(ups[i].start.x,ups[i].start.y,ups[i].pos.x,ups[i].pos.y);
        if(distance>800){
            ups.erase(ups.begin()+i);
            i--;
        }
    }
    
    if(ofGetMousePressed()){
        
        Upsquares tempUp;
        tempUp.setup();
        ups.push_back(tempUp);
    }

}

//--------------------------------------------------------------
void ofApp::draw() {
    
    // Print tweets:
    
    int maxLineSize = 90;
    
    ofSetColor(0);
    ofDrawBitmapString(ofToString(ram), ofPoint(220,420));
    
    
    if(twitterClient.getTotalLoadedTweets() > 0) {
        
        tweet = twitterClient.getTweetByIndex(actualTweet);
        
        ofSetColor(255, 255, 255, 125);
        if(tweet.isBannerImageLoaded()) {
            tweet.user.profile_banner.draw(0, 0, ofGetWidth(), ofGetHeight());
        }
        
        ofSetColor(0);
        
//        ofDrawBitmapString("User:", ofPoint(120,150));
//        ofDrawBitmapStringHighlight(tweet.user.screen_name, ofPoint(220,150));
//        
//        ofDrawBitmapString("Location:", ofPoint(120,180));
//        ofDrawBitmapStringHighlight(tweet.user.location, ofPoint(220,180));
        
//        ofDrawBitmapString("Descript.:", ofPoint(120,210));
//        string desc = tweet.user.description;
//        for(int i=0;i<(desc.length()/maxLineSize)+1;i++) {
//            ofDrawBitmapStringHighlight(desc.substr(i*maxLineSize,maxLineSize), ofPoint(220,210+(30*i)));
//        }
        
//        ofDrawBitmapString("Text:", ofPoint(10,10));
//it goes here
        
//        ofSetColor(0);
//        string nav = "Now showing tweet: " + ofToString(actualTweet+1) + " of "+ofToString(twitterClient.getTotalLoadedTweets());
//        ofDrawBitmapString(nav, ofPoint(220,420));
        
    }
    
    ofSetColor(0);
    string info;
    //info += "\nPress 'l' to load previous query from disk if avilable";
    //info += "\nPress UP/DOWN to navigate tweets";
    //ofDrawBitmapString(info, ofPoint(20,20));
    
    twitterClient.printDebugInfo();
//    
//    ofxTwitterSearch search;
//    search.count = 50;
//    search.query = "%23BlackLivesMatter+:)";

    if((rand()<=2.005)&&(rand()>=1.995)) {
        ofxTwitterSearch search;
        search.count = 1;
        search.query = "%23BlackLivesMatter+:)";
        twitterClient.startSearch(search);
        
        ofSetColor(255, 0, 0);
        ofRect(400, 400, 100, 100);
    }
    
    if((rand()<=1.005)&&(rand()>=0.995)) {
        ofxTwitterSearch search;
        search.count = 1;
        search.query = "cat";
        twitterClient.startSearch(search);
        
        ofSetColor(255, 0, 0);
        ofRect(400, 400, 100, 100);
    }
    
    if((rand()<=3.005)&&(rand()>=2.995)) {
        ofxTwitterSearch search;
        search.count = 1;
        search.query = "dog";
        twitterClient.startSearch(search);
        
        ofSetColor(255, 0, 0);
        ofRect(400, 400, 100, 100);
    }
    
    if((rand()<=4.005)&&(rand()>=3.995)) {
        ofxTwitterSearch search;
        search.count = 1;
        search.query = "bathroom";
        twitterClient.startSearch(search);
        
        ofSetColor(255, 0, 0);
        ofRect(400, 400, 100, 100);
    }
    
    string text = tweet.text;
    for(int i=0;i<(tweet.text.length()/maxLineSize)+1;i++) {
        ofDrawBitmapStringHighlight(text.substr(i*maxLineSize,maxLineSize), ofPoint(20,20+(30*i)));
    }
    
    ofSetColor(255, 255, 255);
    if(tweet.isProfileImageLoaded()) {
        tweet.user.profile_image.draw(40, 150);
    }
    
    ofSetCircleResolution(100);
    for(int i=0; i<ups.size(); i++) {
        ups[i].draw();
    }
    
    ofSetCircleResolution(3);
    for(int i=0; i<downs.size(); i++) {
        downs[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'q') {
        // Simple Query. You can find tweets containing that word.
        ofxTwitterSearch search;
        search.count = 1;
        search.query = "%23BlackLivesMatter+:)";
        twitterClient.startSearch(search);
        
        ofSetColor(255, 0, 0);
    }

//    if(key == 's') {
//        // Complex search. You can specify more params.
//        ofxTwitterSearch search;
//        search.query = "%23BlackLivesMatter+:)";
//        search.count = 1;
//        //search.geocode = ofVec2f(41.3850640,2.1734030);
//        //search.geocode_radius = 2;
//        //search.bUseMiles = false;
//        search.lang = "es";
//        twitterClient.startSearch(search);
//    }
    
    if(key == 'l') {
        twitterClient.loadCacheFile();
    }
    
    if(key == OF_KEY_UP) {
        if(actualTweet < twitterClient.getTotalLoadedTweets()-1) actualTweet += 1;
    }
    
    if(key == OF_KEY_DOWN) {
        if(actualTweet > 0) actualTweet -= 1;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
