
#ifndef DOG_H
#define DOG_H

#include "animal.h"
#include "raylib.h"

class Dog : public Animal {

public:
    Dog(int xposition, int yposition);

    void fight(Animal& opponent) override;
    void takeDamage(double dmg) override;
    void draw() override;
    Color getHealthColor() override;
    Color getOriginalColor() const override;
};

#endif 
