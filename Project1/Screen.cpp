#include "Screen.h"

vector<Object*> Screen::_objects;

void Screen::add_object(Object* object)
{
	_objects.push_back(object);
}
void Screen::draw_object(Object* object)
{
    Pos pos = object->get_pos();
    RGB color = object->get_color();
    Cursor::set_text_color(color);
    for (const string& line : object->get_body()) {
        Cursor::set_position(pos);
        cout << line;
        pos.raw++;
    }
    Cursor::reset_all_style();
}
void Screen::render()
{
    for (Object* object : _objects) {
        draw_object(object);
    }
}