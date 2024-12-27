#pragma once
#include "Object.h"

struct Border
{
    char top;
    char top_right;
    char right;
    char bottom_right;
    char bottom;
    char bottom_left;
    char left;
    char top_left;
};

enum class LineType : char
{
    top,
    middle,
    bottom
};

class TextBox : public Object
{   
    string _text = "";
    int _padding = 1;
    int _margin = 0;
    int _width = 4;
    int _height = 5;
    Border _border = { '-','*','|','*','-','*','|','*' };
private:
    string make_line(string& text) const;
    string make_line(LineType type) const;
    void set_body();
public:
    TextBox();
    TextBox(string text);
    TextBox(const char* text);
    TextBox(Pos pos);

    void set_text(string text);
    void set_width(int value);
    void set_height(int value);
    void set_padding(int value);
    void set_margin(int value);
    void set_border(Border border);
    void set_border_once(char style);
    void set_border_corner_once(char style);
    void set_border_middle_once(char style);
    void set_border_vertical_once(char style);
    void set_border_horizontal_once(char style);
    int get_padding() const;
    int get_margin() const;
};

