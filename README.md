
##API Moods
This projects analyzes the moods of twitter users regarding the hastags #BlackLivesMatter and #itgetsbetter. Based on incoming tweets the diamonds on the screen change.

The squares move and die based on the length of the tweet. The length is scale to a certain distance.

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
    
The objects are generated randomly based on tweets containing either :) or :(.

        if(ram==0){
        search.count = 1;
        search.query = "%23BlackLivesMatter+:)";
        twitterClient.startSearch(search);
        
        blh = true;

        }
        
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


   