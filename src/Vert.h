#pragma once
#include "ofMain.h"

class Vert{
    
public:
    Vert(ofVec3f pos,int i);
    
    ofVec3f updateVertex();
    ofVec3f getSinMod(float _freq, float _amp);
    
    ofVec3f initPosition;
    ofVec3f position;
    int index;
    
};

