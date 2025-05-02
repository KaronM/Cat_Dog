#include "animal.h"
#include <iostream>
#include <random>

// Constructor
Animal::Animal() {
    position = {0, 0};
    health = 100;
    stamina = 100;
    originalColor = ORANGE;
}

// Movement
void Animal::move() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distrib(-1, 1);

    position.x += distrib(generator);
    position.y += distrib(generator);

    if (position.x >= 50) position.x -= 1;
    if (position.x <= 0) position.x += 1;
    if (position.y <= 0) position.y += 1;
    if (position.y >= 50) position.y -= 1;
}

// Virtuals 
void Animal::fight(Animal& opponent) {}

void Animal::takeDamage(double dmg) {}

void Animal::draw() {}

Color Animal::getHealthColor() {
    return WHITE;
}

Color Animal::getOriginalColor() const {
    return WHITE;
}
// Getters
double Animal::getHealth(){
     return health; 
}

double Animal::getStamina(){ 
    return stamina; 
}
int Animal::getXPosition(){ 
    return position.x; 
}
int Animal::getYPosition(){ 
    return position.y; 
}
//color change 



// Destructor
Animal::~Animal() {
    // Any cleanup if necessary when a cat is deleted
    std::cout << "An animal has been deleted!" << std::endl;  // For debugging
}



