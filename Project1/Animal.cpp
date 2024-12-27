#include "Animal.h"

Animal::Animal()
{
    load_texture();
}
void Animal::load_texture()
{
    this->load_from_txt("example");
}
void Animal::create_box(string text)
{
    if (!_box) {
        Pos pos = this->get_pos();
        pos.raw += this->get_size().raw;
        _box = new TextBox(pos);
        _box->set_text(text);
    }
}
void Animal::delete_box()
{
    if (_box) {
        delete _box;
    }
}