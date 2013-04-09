#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // CURRENT ORDER: LO-NATIVE, HI-NATIVE, LO-IMMIGRANT, HI-IMMIGRANT
    amplifier = 1; // this is to amplify the unemployment rates--we can apply it to all of them so they stay consistent but have more exaggerated differences. totally optional though. can be a float.
    
    unemploymentRates[0] = 32 * amplifier;
    unemploymentRates[1] = 6 * amplifier;
    unemploymentRates[2] = 19 * amplifier;
    unemploymentRates[3] = 6 * amplifier;
    
    currentIndex = 0;
    
    rootPoint.x = ofGetWidth()/2 - 100;
    rootPoint.y = 600;
    
    centerPoint.x = rootPoint.x;
    centerPoint.y = ofGetHeight()/2;
    
}

//--------------------------------------------------------------
void testApp::update(){
    float distanceToCenterPoint = ofDist(centerPoint.x, centerPoint.y, rootPoint.x, rootPoint.y);
    
    // let's calculate where the other circle should be based on the unemployment rate
    otherLegPoint.x = centerPoint.x + cos(ofDegToRad(unemploymentRates[currentIndex])- PI/2) * distanceToCenterPoint;
    otherLegPoint.y = centerPoint.y - sin(ofDegToRad(unemploymentRates[currentIndex])- PI/2) * distanceToCenterPoint;
}

//--------------------------------------------------------------
void testApp::draw(){    
    // draw lines
    ofSetColor(0);
    ofFill();
    
    ofLine(centerPoint, rootPoint);
    ofLine(centerPoint, otherLegPoint);
    
    // draw root circle
    ofCircle(rootPoint, 30);
    
    // draw other leg circle
    ofCircle(otherLegPoint, 30);
    
    // draw group name so we know what we're looking at
    string currentGroup;
    if (currentIndex == 0)      currentGroup = "LOW-ED-NATIVE";
    if (currentIndex == 1)      currentGroup = "HIGH-ED-NATIVE";
    if (currentIndex == 2)      currentGroup = "LOW-ED-IMMIGRANT";
    if (currentIndex == 3)      currentGroup = "HIGH-ED-IMMIGRANT";
    ofDrawBitmapString(currentGroup, 20, 20);
    ofDrawBitmapString(ofToString(unemploymentRates[currentIndex]/amplifier) + "%", 20, 40);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (currentIndex <= 2) {
        currentIndex++;
    } else {
        currentIndex = 0;
    }
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}