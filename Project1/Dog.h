#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
    Dog();
    void make_sound() override;
    void load_texture() override;
};

