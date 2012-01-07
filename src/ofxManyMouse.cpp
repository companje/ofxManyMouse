/*
 *  ofxManyMouse.cpp
 *  ofxManyMouse addon for OpenFrameworks
 *
 *  Created by Rick Companje on 27-10-10.
 *  Copyright 2010 Globe4D. All rights reserved.
 *
 */

#include "ofxManyMouse.h"

ofxManyMouse::ofxManyMouse() {    
	mouseCount = ManyMouse_Init();
    
	ofAddListener(ofEvents.update, this, &ofxManyMouse::update);
}

string ofxManyMouse::getDeviceName(int index) {
    return ManyMouse_DeviceName(index);
}

void ofxManyMouse::listDevices() {
    for (int i=0; i<mouseCount; i++) {
        cout << i << ": " << ManyMouse_DeviceName(i) << endl;
    }
}

void ofxManyMouse::update(ofEventArgs &e) {
	ManyMouseEvent m;
	
	while (ManyMouse_PollEvent(&m)) {
		
		switch (m.type) {
			case MANYMOUSE_EVENT_RELMOTION: mouseMoved(m.device, m.item, m.value); break;
            case MANYMOUSE_EVENT_SCROLL: mouseScroll(m.device, m.item, m.value); break;
			case MANYMOUSE_EVENT_BUTTON: 
				if (m.value==1) mousePressed(m.device, m.item);
				if (m.value==0) mouseReleased(m.device, m.item);
				break;
			case MANYMOUSE_EVENT_DISCONNECT: mouseDisconnected(m.device); break;
            case MANYMOUSE_EVENT_ABSMOTION: break;
            case MANYMOUSE_EVENT_MAX: break;
		}
	}
}

void ofxManyMouse::mouseDisconnected(int device) {
    ofLog(OF_LOG_WARNING, "mouse %d disconnected",device);
}