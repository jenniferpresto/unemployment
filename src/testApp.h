#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofPoint centerPoint;
    ofPoint rootPoint;
    ofPoint otherLegPoint;
    ofPoint leftShoulderPoint;
    ofPoint rightShoulderPoint;
    ofPoint leftHandPoint;
    ofPoint rightHandPoint;
    
    float unemploymentRates[4]; 
    float amplifier;
    int currentIndex;
    
    float baseArmAngle;
    float rightArmAngle;
    float handShoulderDistance;
    
    float rightRandom;
    float leftRandom;
    
};
