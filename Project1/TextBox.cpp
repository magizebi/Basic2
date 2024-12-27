#include "TextBox.h"

TextBox::TextBox()
{
    set_body();
}
TextBox::TextBox(string text)
{
    set_text(text);
}

TextBox::TextBox(const char* text)
{
    string str = text;
    set_text(str);
}
TextBox::TextBox(Pos pos)
{
    this->set_pos(pos);
    set_body();
}

string TextBox::make_line(string& text) const
{
    string temp;
    int size = (int)text.size();
    int start = _width - 2 - (_padding * 2) - size + 1;
    int index = 0;
    temp.push_back(_border.left);
    for (int i = 0; i < _width - 2; i++) {
        if (i >= start && i < start+size) {
            temp.push_back(text[index]);
            index++;
        }
        else {
            temp.push_back(' ');
        }
    }
    temp.push_back(_border.right);

    return temp;
}

string TextBox::make_line(LineType type) const
{
    string temp;
    char left = 0;
    char right = 0;
    char middle = 0;

    if (type == LineType::top) {
        left = _border.top_left;
        right = _border.top_right;
        middle = _border.top;
    }
    if (type == LineType::bottom) {
        left = _border.bottom_left;
        right = _border.bottom_right;
        middle = _border.bottom;
    }
    if (type == LineType::middle) {
        left = _border.left;
        right = _border.right;
        middle = ' ';
    }

    temp.push_back(left);
    for (int i = 0; i < _width - 2; i++) {
        temp.push_back(middle);
    }
    temp.push_back(right);

    return temp;
}
void TextBox::set_body()
{
    vector<string> body;

    body.push_back(make_line(LineType::top));
    for (int i = 0; i < _height - 2 ; i++) {
        body.push_back(make_line(LineType::middle));
    }
    body.push_back(make_line(LineType::bottom));

    int text_index = _height % 2 == 0 ? (_height / 2) - 1 : _height / 2;
    body[text_index] = make_line(_text);

    Object::set_body(body);
}
void TextBox::set_text(string text)
{
    _text = text;
    int size = (int)_text.size();
    if (size > _width - 2) {
        _width = size + 2 + _padding * 2;
    }
    set_body();
}
void TextBox::set_width(int value)
{
    _width = value;
}
void TextBox::set_height(int value)
{
    _height = value;
}
void TextBox::set_padding(int value)
{
    _padding = value;
}
void TextBox::set_margin(int value)
{
    _margin = value;
}
void TextBox::set_border(Border border)
{
    _border = border;
}
void TextBox::set_border_once(char style)
{
    set_border_middle_once(style);
    set_border_corner_once(style);
}
void TextBox::set_border_corner_once(char style)
{
    _border.top_left = style;
    _border.top_right = style;
    _border.bottom_left = style;
    _border.bottom_right = style;
}
void TextBox::set_border_middle_once(char style)
{
    set_border_horizontal_once(style);
    set_border_vertical_once(style);
}
void TextBox::set_border_vertical_once(char style)
{
    _border.left = style;
    _border.right = style;
}
void TextBox::set_border_horizontal_once(char style)
{
    _border.top = style;
    _border.bottom = style;
}
int TextBox::get_padding() const
{
    return _padding;
}
int TextBox::get_margin() const
{   
    return _margin;
}