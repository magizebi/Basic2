#pragma once
#include "Object.h"
#include "TextBox.h"

class Animal : public Object
{
    TextBox* _box;
public:
    Animal();
    virtual void make_sound() = 0;
    virtual void load_texture();
    void create_box(string text);
    void delete_box();
};

