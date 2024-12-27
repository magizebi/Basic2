#include "Dog.h"

Dog::Dog()
{
    load_texture();
}
void Dog::make_sound()
{
    this->create_box("¸Û¸Û!!");
}
void Dog::load_texture()
{
    this->load_from_txt("Dog");
}