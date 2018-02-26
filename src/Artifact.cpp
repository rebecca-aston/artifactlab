#include "Artifact.h"

////////////////////////
// SETUP SHAPE
//////////////////////
//--------------------------------------------------------------
Artifact::Artifact(){
    // set initial transformtaion vectors to be used in update
    position = ofVec3f(0,0,0);
    rotation = ofVec3f(0,0,0);
    scale = ofVec3f(1.,1.,1.);
    
    //Set point cloud point size 
    glPointSize(3);
}

void Artifact::setup(){
    
    ofMesh tempMesh;
    
    for (int x = 0; x < 20; x++){
        ofVec3f pos = ofVec3f(x*10, 0, 0);
        tempMesh.addVertex(pos); // make a new vertex
        tempMesh.addIndex(x);
    }
    
    addMeshToShape(tempMesh);

}

////////////////////////
// UPDATE VERTICES
//////////////////////
//--------------------------------------------------------------
void Artifact::update() {
    
        for(int i = 0; i < vertices.size();i++){
            
            meshPointer->setVertex(i,vertices[i].getSinMod(FREQUENCY,AMPLITUDE));

        }

}

////////////////////////
// DRAW A SHAPE
///////////////////////
//--------------------------------------------------------------
void Artifact::draw(bool wireFrame){

    ofPushMatrix();
    
    //of3dPrimitive inherits from ofNode, this allows
    //transformations to global position of Mesh
    primitive3d.setPosition(position);
    primitive3d.setOrientation(rotation);
    primitive3d.setScale(scale);
    
    //perform ofNode transforms
    primitive3d.transformGL();// is this killing the processing power?
    
    if(wireFrame){
        primitive3d.drawWireframe();
    }else{
//        primitive3d.drawFaces();
          primitive3d.drawVertices();
    }
    
    primitive3d.restoreTransformGL();
    
    ofPopMatrix();
}

//////////////////////////////////////////
//// MESH HELPERS
/////////////////////////////////////////
//--------------------------------------------------------------
void Artifact::addMeshToShape(ofMesh mesh){
    //Add mesh to of3dPrimitive
    primitive3d = of3dPrimitive(mesh);
    
    //Create a pointer to that mesh to update vertices later
    meshPointer = &primitive3d.getMesh();
    
    //Create an array of vertices that store information about Verts
    //Useful for creating objects for 3D printing
    //NOTE:if your interest is motion/shaders and not 3D printing...
    //then get rid of the vert class altogether and just transform your mesh with shaders
    for(int i = 0; i < mesh.getVertices().size(); i++){
         pushVert(mesh.getVertex(i),i);
    }
}

void Artifact::updatePosition(ofVec3f _position){
    position = _position;
}
void Artifact::updateRotation(ofVec3f _rotation){
    rotation = _rotation;
}
void Artifact::updateScale(ofVec3f _scale){
    scale = _scale;
}

//--------------------------------------------------------------
void Artifact::pushVert(ofVec3f pos, int i){
    Vert tempVert(pos,i);
    vertices.push_back(tempVert);
}

//////////////////////////////////////////
//// 3D FILE FORMAT HELPERS
////////////////////////////////////////
//--------------------------------------------------------------
void Artifact::exportMesh(string fileName){
    //exports a ply which is nice because you get per-vertex color
    primitive3d.getMesh().save(fileName);
}


