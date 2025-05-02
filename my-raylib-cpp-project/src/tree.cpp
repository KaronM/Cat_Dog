#include "tree.h"

Tree::Tree(float xPos, float yPos) {
    position.x = xPos;
    position.y = yPos;

    // Random size for the tree (radius between 10 and 30)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(10.0f, 30.0f);

    radius = dis(gen);  // Random radius
}

void Tree::draw() const {
    DrawCircle((int)position.x*20, (int)position.y*20, radius, DARKGREEN);
}
