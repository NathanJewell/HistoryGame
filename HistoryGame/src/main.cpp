#include "ofMain.h"
#include "ofApp.h"
#include <iostream>
//========================================================================
int main( ){
    std::cout << "here" << std::endl;
	ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context
        std::cout << "here" << std::endl;
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp());

}
