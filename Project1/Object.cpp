#include "Object.h"
#include "util.h"

Object::Object()
{
	_body.push_back("[OBJECT]");
    Screen::add_object(this);
}
Object::Object(string filename)
{
	load_from_txt(filename);
}
//Object::~Object() {
//
//}
void Object::set_size()
{
    int raw = (int)_body.size();
    int col = (int)Util::get_longest_string(_body).size();
    _size = { raw, col };
}
void Object::set_name(string name)
{
	_name = name;
}
void Object::set_color(RGB color)
{
	_color = color;
}
void Object::set_body(vector<string>& body) {
	_body = body;
    set_size();
}
void Object::set_pos(Pos pos)
{
	_pos = pos;
}
string Object::get_name() const
{
	return _name;
}
RGB Object::get_color() const
{
	return _color;
}
vector<string> Object::get_body() const
{
	return _body;
}
Pos Object::get_pos() const
{
	return _pos;
}
Pos Object::get_size() const
{
    return _size;
}
void Object::load_from_txt(string filename)
{
	vector<string> body = Util::read_text(filename);
	set_body(body);
}
