#pragma once
#include "ofMain.h"
#include "Vert.h"

class Artifact{
    
public:
    Artifact();

    virtual void setup();
    
    void update();
    void draw(bool wireFrame);
    
    void addMeshToShape(ofMesh mesh);
    void updatePosition(ofVec3f _position);
    void updateRotation(ofVec3f _rotation);
    void updateScale(ofVec3f _scale);
    void pushVert(ofVec3f pos, int i);
    
    void exportMesh(string fileName);
    
    //ofParameters for the GUI
    ofParameter<float> AMPLITUDE{"Amplitude", 0, 0, 800};
    ofParameter<float> FREQUENCY{"Frequency", 0, 0, 10};
    
    of3dPrimitive primitive3d;//has ofNode for moving and rotating in space etc
    ofMesh *meshPointer;
    
    vector<Vert> vertices;
    ofVec3f position;
    ofVec3f rotation;
    ofVec3f scale;
    
};
