#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	//ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetFrameRate(180);
	grabber.setup(true);
}


//--------------------------------------------------------------
void testApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0xffffff);
	
	grabber.draw();
	
}



//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 	

	
		
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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
