#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "Artifact.h"

class Model : public Artifact{
    
public:
    Model();
    
    void setup(string s);
    
};
