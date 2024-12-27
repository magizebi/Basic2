#include "Cow.h"

Cow::Cow()
{
    load_texture();
}
void Cow::make_sound()
{
    this->create_box("À½¸Å--");
}
void Cow::load_texture()
{
    this->load_from_txt("Cow");
}