#pragma once
#include "pch.h"
#include "Cursor.h"
#include "Util.h"
#include "Object.h"

class Object;

class Screen
{
    static vector<Object*> _objects;
public:
	static void add_object(Object* object);
    static void draw_object(Object* object);
    static void render();
};

