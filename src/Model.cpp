//
//  Model.cpp
//  3dArtefactLab
//
//  Created by Rebecca Aston on 3/6/18.
//

#include "Model.h"

Model::Model(){
    
}

void Model::setup(string s){
    ofxAssimpModelLoader model;
    
    model.loadModel(s);
    
    addMeshToShape(model.getMesh(0));
}
