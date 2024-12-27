#include "Cat.h"

Cat::Cat()
{
    load_texture();
}
void Cat::make_sound()
{
    this->create_box("¾ß¿Ë~~");
}
void Cat::load_texture()
{
    this->load_from_txt("Cat");
}