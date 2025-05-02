#include "dog.h"
#include <iostream>

using namespace std;


// Constructor
Dog::Dog(int xposition, int yposition) {
    position.x = xposition;
    position.y = yposition;
    health = 120.0;
    stamina = 80.0;
    originalColor = BROWN;
}

// Fighting
void Dog::fight(Animal& opponent) {
    cout << "Dog fights!\n";
    opponent.takeDamage(20);
    stamina -= 7.5;
    this->takeDamage(15);
}

// Taking damage
void Dog::takeDamage(double dmg) {
    health -= dmg;
    if (health <= 0) {
        cout << "Dog has lost the fight!\n";
    }
}

//Drawing

void Dog::draw() {
    Color healthColor = getHealthColor();
    DrawCircle(position.x*20, position.y*20, 10, healthColor);
}


Color Dog::getHealthColor() {
    if (health <= 36.0) { // If health is below 30% of max health
        return RED; // Turn completely red
    } else {
        return originalColor; // Otherwise, keep original color
    }
}

Color Dog::getOriginalColor() const {return originalColor;}