#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    //Polymorphism in c++ / openframeworks
    //http://www.cplusplus.com/doc/tutorial/polymorphism/
    plane.setup();
    plane.updatePosition(ofVec3f(-100,-100,0));
    
    model.setup("tree.obj");
    model.updatePosition(ofVec3f(-20,-20,0));
    model.updateScale(ofVec3f(20,20,20));
//    model.updateRotation(ofVec3f(0,0,0));//ofVec3f not working if anyone wants to figure out Quaternions
    
    //GUI
    gui.setup();
    
    //Button listeners calling functions below
    exportMeshButton.addListener(this, &ofApp::exportMeshButtonPressed);

    //Toggles declared in ofApp.h
    gui.add(toggle_axis.setup("axis", true));
    gui.add(toggle_grid.setup("grid", true));
    gui.add(wire_frame.setup("wire frame", true));
    gui.add(auto_update.setup("auto update", true));
    
    //Buttons declared in ofApp.h
    gui.add(exportMeshButton.setup("Export Mesh"));

    //Sliders declared in ofApp.h
    gui.add(param_A.setup("param_A", 4, 0, 5));
    gui.add(param_B.setup("param_B", 1400, 0, 3000));
    gui.add(param_C.setup("param_C", 10, 0, 130));
    
    //Add ofParameters declared in Artifact.h class into Gui
    gui.add(plane.AMPLITUDE);
    gui.add(plane.FREQUENCY);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(auto_update){
        plane.update();
        model.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    //enables depth test for 3D camera
    ofEnableDepthTest();
    
    //Do any 3D drawing inside of easy cam instance
    cam.begin();
    
    if(toggle_axis){
        drawAxis();
    }
    if(toggle_grid){
        drawGrid();
    }
    
    //wire_frame toggles render mode
    plane.draw(wire_frame);
    model.draw(wire_frame);
    
    cam.end();
    
    //disables depth so gui text is visible in 2D in top of 3D cam
    ofDisableDepthTest();
    ofSetColor(255);
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::drawAxis() {
    ofPushStyle();
    // X
    ofSetLineWidth(3);
    ofSetColor(255, 0, 0);
    ofDrawLine(0, 0, 0, 100, 0, 0);

    // Y
    ofSetLineWidth(3);
    ofSetColor(0, 255, 0);
    ofDrawLine(0, 0, 0, 0, 100, 0);

    // Z
    ofSetLineWidth(3);
    ofSetColor(0, 0, 255);
    ofDrawLine(0, 0, 0, 0, 0, 100);
    
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::drawGrid() {
    ofPushStyle();
    ofPushMatrix();
    ofSetLineWidth(1);
    ofSetColor(200);
    float sz = 100;
    int nm = 8;
    // draw lines along the flat XY plane
    for(int i = 0; i <= nm; i++){
        ofDrawLine( (i * sz) - (sz*nm/2), -sz*nm/2, 0, (i * sz) - (sz*nm/2), sz*nm/2, 0);
        ofDrawLine( -sz*nm/2, (i * sz) - (sz*nm/2), 0, sz*nm/2, (i * sz) - (sz*nm/2), 0);
    }
    ofPopMatrix();
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::exportMeshButtonPressed(){
    plane.exportMesh("artifact_"+ofGetTimestampString()+".ply");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

