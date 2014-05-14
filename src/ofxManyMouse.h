/*
 *  ofxManyMouseListener.h
 *  ofxManyMouseListener addon for OpenFrameworks
 *
 *  Created by Rick Companje on 27-10-10.
 *  Copyright 2010 Globe4D. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "manymouse.h"

class ofxManyMouse {
public:
	
	ofxManyMouse();
	
	virtual void mousePressed(int device, int button) {};
	virtual void mouseReleased(int device, int button) {};
	virtual void mouseMoved(int device, int axis, int delta) {};
  virtual void mouseMovedAbsolute(int device, int axis, int pos) {};
	virtual void mouseScroll(int device, int axis, int delta) {};
	virtual void mouseDisconnected(int device);
	
	void update(ofEventArgs &e);
	void listDevices();
	string getDeviceName(int index);
	int mouseCount;
};
