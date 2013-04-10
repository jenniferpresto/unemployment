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
    
    // Shoulder points are temporary until attached to Kinect.
    // Actual shoulder should probably be used to set hand positions,
    // but then should be fixed before the player starts to stretch
    // for them.
    leftShoulderPoint.x = ofGetWidth()/2 - 150;
    leftShoulderPoint.y = ofGetHeight()/2 - 180;
    rightShoulderPoint.x = ofGetWidth()/2 - 50;
    rightShoulderPoint.y = ofGetHeight()/2 - 180;
    
    // neutral hand positions; would correspond to
    // zero unemployment
    leftHandPoint.x = ofGetWidth()/2 - 150;
    leftHandPoint.y = ofGetHeight()/2 - 80;
    rightHandPoint.x = ofGetWidth()/2 - 50;
    rightHandPoint.y = ofGetHeight()/2 - 80;
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    float distanceToCenterPoint = ofDist(centerPoint.x, centerPoint.y, rootPoint.x, rootPoint.y);
    
    // let's calculate where the other circle should be based on the unemployment rate
    otherLegPoint.x = centerPoint.x + cos(ofDegToRad(unemploymentRates[currentIndex])- PI/2) * distanceToCenterPoint;
    otherLegPoint.y = centerPoint.y - sin(ofDegToRad(unemploymentRates[currentIndex])- PI/2) * distanceToCenterPoint;
    
    // let's calculate where the hands should be
    // as unemployment rises, hands are lifted up, and go further away
    // from the shoulders. Results will be random within a 30-degree range.
    handShoulderDistance = ofMap(unemploymentRates[currentIndex], 0, 32, 100, 200);
    baseArmAngle = ofMap(unemploymentRates[currentIndex], 0, 32, 0, 180);
    rightArmAngle = ofMap(baseArmAngle, 0, 180, 360, 180); // swings in opposite direction
    
    leftHandPoint.x = leftShoulderPoint.x + cos(ofDegToRad(baseArmAngle + leftRandom) + PI/2) * handShoulderDistance;
    leftHandPoint.y = leftShoulderPoint.y + sin(ofDegToRad(baseArmAngle + leftRandom) + PI/2) * handShoulderDistance;
    
    rightHandPoint.x = rightShoulderPoint.x + cos(ofDegToRad(rightArmAngle + rightRandom) + PI/2) * handShoulderDistance;
    rightHandPoint.y = rightShoulderPoint.y + sin(ofDegToRad(rightArmAngle + rightRandom) + PI/2) * handShoulderDistance;
    
    cout << "Unemployment: " << unemploymentRates[currentIndex] << "  Angle: " << baseArmAngle << endl;
    cout << "Distance: " << handShoulderDistance << endl;
    

    
}

//--------------------------------------------------------------
void testApp::draw(){
    // draw lines
    ofSetColor(0);
    ofFill();
    
    ofLine(centerPoint, rootPoint);
    ofLine(centerPoint, otherLegPoint);
    
    ofLine(centerPoint, leftShoulderPoint);
    ofLine(centerPoint, rightShoulderPoint);
    
    // draw root circle
    ofCircle(rootPoint, 30);
    
    // draw other leg circle
    ofCircle(otherLegPoint, 30);
    
    // draw smaller shoulder circles
    ofCircle(leftShoulderPoint, 10);
    ofCircle(rightShoulderPoint, 10);
    
    // draw hands
    ofCircle(leftHandPoint, 30);
    ofCircle(rightHandPoint, 30);
    
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
    // determine randomeness for arms at the moment the mouse is released
    // so that they don't continue to change
    
    rightRandom = ofRandom(-15, 15);
    leftRandom = ofRandom(-15, 15);
    
    
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