#pragma once

#include "ofMain.h"
#include "Artifact.h"
#include "ofxGui.h"
#include "Plane.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
    
        void drawAxis();
        void drawGrid();
        void updateButtonPressed();
        void exportMeshButtonPressed();

		void keyPressed(int key);
		
        //Gui
        ofxPanel gui;
        //Booleans
        ofxToggle toggle_axis;
        ofxToggle toggle_grid;
        ofxToggle wire_frame;
        ofxToggle auto_update;
        //Buttons
        ofxButton exportMeshButton;
        //Sliders
        ofxFloatSlider param_A;
        ofxFloatSlider param_B;
        ofxFloatSlider param_C;

        ofEasyCam cam;
        Plane plane;
    
};
