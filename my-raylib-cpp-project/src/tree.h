#ifndef TREE_H
#define TREE_H
#include "point.h"
#include "raylib.h"
#include <random>

class Tree {
private:
    Point position;
    float radius;    // Radius of the tree 
    
public:
    Tree(float xPos, float yPos);
    void draw() const;
};

#endif
