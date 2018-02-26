#include "Plane.h"

Plane::Plane(){ 
    width = 126;
    height = 126;
    spacing = 10;
}

// create a flat plane of vertices
void Plane::setup(){
    
    ofMesh tempMesh; 
    
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            ofVec3f pos = ofVec3f(x*spacing, y*spacing, 0);
            tempMesh.addVertex(pos); // make a new vertex
            tempMesh.addColor(ofColor(255));
        }
    }
    
    // what this is basically doing is figuring out based on the way we inserted vertices
    // into our vertex array above, which array indices of the vertex array go together
    // to make triangles. the numbers commented show the indices added in the first run of
    // this loop - re-use indices 1 and 10
    for (int x = 0; x < width-1; x++){
        for (int y=0; y < height-1; y++){
            tempMesh.addIndex(x+y*width);         // 0
            tempMesh.addIndex((x+1)+y*width);     // 1
            tempMesh.addIndex(x+(y+1)*width);     // 10
            
            tempMesh.addIndex((x+1)+y*width);     // 1
            tempMesh.addIndex((x+1)+(y+1)*width); // 11
            tempMesh.addIndex(x+(y+1)*width);     // 10
        }
    }
    
     addMeshToShape(tempMesh);
}
