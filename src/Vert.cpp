#include "Vert.h"


////////////////////////
// CLASS SETUP
//////////////////////

// Constructor
Vert::Vert(ofVec3f pos, int i){
    // set position according to parameters
    initPosition  = pos;
    position = initPosition;
    index = i;
}

////////////////////////
// UPDATE PROPERTIES
//////////////////////

// modify the position on runtime
//--------------------------------------------------------------
ofVec3f Vert::updateVertex(){
    
}


//General motion modifiers
//--------------------------------------------------------------
ofVec3f Vert::getSinMod(float _freq, float _amp){
    ofVec3f res = ofVec3f(0,0,0);
    float freq = _freq;//param_A *0.0001;
    float amp = _amp;//param_B * 0.5;
    res.z  =  ( sin( (freq) * position.y ) + cos( position.x * (freq+PI)) ) * amp;
    res += initPosition;
    
    return res;
}


