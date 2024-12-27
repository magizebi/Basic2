#pragma once
#include "Animal.h"

class Cow : public Animal
{
public:
    Cow();
    void make_sound() override;
    void load_texture() override;
};

