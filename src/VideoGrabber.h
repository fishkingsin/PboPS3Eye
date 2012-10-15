/*
 * VideoPlayer.h
 *
 *  Created on: 08/04/2012
 *      Author: arturo
 */

#pragma once

#include "ofConstants.h"
#include "ofxMacamPs3Eye.h"
#include "ofPBO.h"
#include "ofFbo.h"

class VideoGrabber {
public:
	void setup( bool usePBO=true);
	void play();
	void update();
	void draw();

	bool isFrameNew();
    float getRealFrameRate();
private:
	void newFrame(ofPixels & pixels);

	ofxMacamPs3Eye ps3eye;
	
    int 				camWidth;
    int 				camHeight;
	ofPBO pbo;
	ofTexture tex;
	ofFbo fbo;
	bool usePBO;
	bool updateTex;
};

