#pragma once

#include "ofMain.h"
#include "ofxTwitter.h"
#include "Upsquares.h"
#include "Downsquares.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        ofxTwitter twitterClient;
        ofxTwitterTweet tweet;
        int actualTweet;
        bool reloadTweet;
    
        int ram;
    
        bool blh;
        bool bls;
        bool grh;
        bool grs;

        vector <Downsquares> downs;
        vector <Upsquares> ups;
};
