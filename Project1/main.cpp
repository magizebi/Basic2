#include "pch.h"
#include <thread>
#include <chrono>
#include "Cursor.h"
#include "Screen.h"
#include "TextBox.h"
#include "Dog.h"
#include "Cat.h"
#include "Cow.h"

int main()
{
	//Object* object = new Object("example");
    Animal* animal[3];
    animal[0] = new Dog();
    animal[1] = new Cat();
    animal[2] = new Cow();
    animal[0]->set_pos({1,1});
    animal[0]->set_color({ 191, 191, 191 });
    animal[1]->set_pos({ 1,41 });
    animal[1]->set_color({ 252, 244, 3 });
    animal[2]->set_pos({ 21,1 });
    animal[2]->set_color({ 3, 252, 227 });
    animal[0]->make_sound();
    animal[1]->make_sound();
    animal[2]->make_sound();

	Screen::render();


	return 0;
}