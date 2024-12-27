#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
    Cat();
    void make_sound() override;
    void load_texture() override;
};

