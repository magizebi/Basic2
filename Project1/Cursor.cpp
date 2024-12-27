#include "Cursor.h"

void Cursor::move_up(int count) {
	cout << ESC << count << "A";
}

void Cursor::move_down(int count) {
	cout << ESC << count << "B";
}

void Cursor::move_left(int count) {
	cout << ESC << count << "D";
}

void Cursor::move_right(int count) {
	cout << ESC << count << "C";
}

void Cursor::set_position(int row, int col) {
	cout << ESC << "["<< row << ";" << col << "H";
}

void Cursor::set_position(Pos pos) {
	cout << ESC << "[" << pos.raw << ";" << pos.col << "H";
}

void Cursor::clear_screen() {
	cout << ESC << "[J";
}

void Cursor::clear_line(int line) {
	set_position(line, 1);
	clear_current_line();
}

void Cursor::clear_current_line()
{
	cout << ESC << "[2K";
}

void Cursor::hide_cursor()
{
	cout << ESC << "[?25l";
}

void Cursor::show_cursor()
{
	cout << ESC << "[?25h";
}

void Cursor::set_text_color(ForeColor color)
{
	cout << ESC << "[" << (int)color << "m";
}
void Cursor::set_text_color(RGB color)
{
	cout << ESC << "[38;2;" << color.r << ";" << color.g << ";" << color.b << "m";
}

void Cursor::reset_text_color()
{
	set_text_color(ForeColor::Default);
}

void Cursor::set_background_color(BackColor color)
{
	cout << ESC << "[" << (int)color << "m";
}

void Cursor::reset_background_color()
{
	set_background_color(BackColor::Default);
}
void Cursor::reset_all_style()
{
	reset_text_color();
	reset_background_color();
	reset_text_style();
}

template <typename... Args>
void Cursor::set_text_style(Args... textstyle_args)
{
	cout << ESC << "[";
	((cout << (int)textstyle_args << ";"), ...);
	cout << "m";
}

void Cursor::reset_text_style()
{
	set_text_style(TextStyle::Reset);
}