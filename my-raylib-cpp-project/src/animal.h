#ifndef ANIMAL_H
#define ANIMAL_H
#include "raylib.h"  
#include <random>
#include "point.h"

class Animal {
protected:
    Point position;
    double health;
    double stamina;
    Color originalColor;

public:
    Animal();

    void move();

    virtual void fight(Animal& opponent);
    virtual void takeDamage(double dmg);
    virtual void draw();
    virtual Color getHealthColor();
    virtual Color getOriginalColor() const;
    virtual ~Animal();
    
    
    double getHealth();
    double getStamina();
    int getXPosition();
    int getYPosition();

};

#endif // ANIMAL_H
