#pragma once
#include "pch.h"
#include "Screen.h"

class Object
{
	vector<string> _body;
	string _name = "unknown";
	RGB _color = { 255, 255, 255 };
	Pos _pos = { 1, 1 }; // (1,1) 이 시작점
    Pos _size = { 0, 0 };
private:
    void set_size();
public:
	Object();
    virtual ~Object() {}
	Object(string filename);
	void set_name(string name);
	void set_color(RGB color);
	void set_body(vector<string>& body);
	void set_pos(Pos p);
	string get_name() const;
	RGB get_color() const;
	vector<string> get_body() const;
	Pos get_pos() const;
    Pos get_size() const;
	void load_from_txt(string path);
};

