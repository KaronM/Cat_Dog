#include "cat.h"
#include "dog.h" // Needed for typeid(Dog)
#include <iostream>
#include <typeinfo>

using namespace std;

// Constructor
Cat::Cat(int xposition, int yposition) {
    position.x = xposition;
    position.y = yposition;
    health = 120.0;
    stamina = 80.0;
    originalColor = ORANGE;
}

// Fighting logic
void Cat::fight(Animal& opponent) {
    cout << "Cat fights!\n";

    // Compare actual types safely
    if (typeid(opponent) == typeid(Dog)) {
        opponent.takeDamage(25);
        stamina -= 7.5;
        takeDamage(10);

        if (opponent.getHealth() <= 30) {
            cout << "The Dog has been turned into a Cat!\n";
        }
    }
}

// Taking damage
void Cat::takeDamage(double dmg) {
    health -= dmg;
    if (health <= 0) {
        cout << "Cat has lost the fight!\n";
    }
}


// Drawing
void Cat::draw() {
    Color healthColor = getHealthColor();
    DrawCircle(position.x*20, position.y*20, 10, healthColor);
}
//getting color based on health
Color Cat::getHealthColor() {
    if (health <= 36.0) { // If health is below 30% of max health
        return RED; // Turn completely red
    } else {
        return originalColor; // Otherwise, keep original color
    }
}
//getting color
Color Cat::getOriginalColor() const {return originalColor;}
