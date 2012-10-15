/*
 * VideoGrabber.cpp
 *
 *  Created on: 08/04/2012
 *      Author: arturo
 */

#include "VideoGrabber.h"

void VideoGrabber::setup( bool _usePBO){
	usePBO = _usePBO;
    camWidth = 320;
	camHeight = 240;
	
	ps3eye.listDevices();
	
	ps3eye.setDesiredFrameRate(180);
	ps3eye.initGrabber(camWidth,camHeight);
	
	ps3eye.setAutoGainAndShutter(false); // otherwise we can't set gain or shutter
//	ps3eye.setGain(0.5);
//	ps3eye.setShutter(1.0);
//	ps3eye.setGamma(0.5);
//	ps3eye.setBrightness(0.6);
//	ps3eye.setContrast(1.0);
//	ps3eye.setHue(0.0);
	
//	ps3eye.setFlicker(1);
	if(usePBO){
		tex.allocate(camWidth,camHeight,GL_RGB);
		pbo.allocate(tex,1);
	}else{
		fbo.allocate(camWidth,camHeight,GL_RGB);
		tex = fbo.getTextureReference();
	}
	updateTex = false;

}

void VideoGrabber::newFrame(ofPixels & pixels){
	pbo.loadData(ps3eye.getPixelsRef());
	updateTex = true;
}




void VideoGrabber::update(){
	ps3eye.update();
	
	// Blink the led everytime there is a new frame
	if(ps3eye.isFrameNew()){
        ps3eye.setLed(true);
		if(usePBO){
			//cout << "new frame" << endl;
			//time = ofGetElapsedTimeMicros();
			//cout << "time tex" << ofGetElapsedTimeMicros() - time << endl;
			//int time = ofGetElapsedTimeMicros();
			pbo.loadData(ps3eye.getPixelsRef());
			//cout << ofGetElapsedTimeMicros() - time << endl;
			updateTex = true;
		}else{
			//int time = ofGetElapsedTimeMicros();
			fbo.begin();
			glDrawPixels(camWidth,camHeight,GL_RGB, GL_UNSIGNED_BYTE, ps3eye.getPixels());
			fbo.end();
			//cout << ofGetElapsedTimeMicros() - time << endl;
		}
	}else{
        ps3eye.setLed(false);
		//cout << "not new frame" << endl;
	}
}

bool VideoGrabber::isFrameNew(){
	return ps3eye.isFrameNew();
}
float VideoGrabber::getRealFrameRate()
{
    return ps3eye.getRealFrameRate();
}
void VideoGrabber::draw(){
	if(updateTex){
		pbo.updateTexture();
		updateTex = false;
	}
	tex.draw(0,0);
    if(ofGetLogLevel()==OF_LOG_VERBOSE)
        ofDrawBitmapString("Ps3Eye FPS: "+ ofToString(getRealFrameRate()), 20,15);
}
