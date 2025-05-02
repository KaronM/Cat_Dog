#ifndef CAT_H
#define CAT_H

#include "animal.h"
#include "raylib.h"

class Cat : public Animal {

public:
    Cat(int xposition, int yposition);

    void fight(Animal& opponent) override;
    void takeDamage(double dmg) override;
    void draw() override;
    Color getHealthColor() override;
    Color getOriginalColor() const override;
};

#endif 
