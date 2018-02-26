
#pragma once
#include "ofMain.h"
#include "Artifact.h"

class Plane : public Artifact{
    
public:
    Plane();
    
    void setup();

    int width, height, spacing;
    
};

