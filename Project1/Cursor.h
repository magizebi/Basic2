#pragma once
#include "pch.h"

const string ESC = "\x1B";
const string CSI = "\x9B";
const string DCS = "\x90";
const string OSC = "\x9D";

enum class ForeColor : int
{
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
    Default = 39,
    BrightBlack = 90,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightBlue = 94,
    BrightMagenta = 95,
    BrightCyan = 96,
    BrightWhite = 97,
    Reset = 0,
};

enum class BackColor : int
{
    Black = 40,
    Red = 41,
    Green = 42,
    Yellow = 43,
    Blue = 44,
    Magenta = 45,
    Cyan = 46,
    White = 47,
    Default = 49,
    BrightBlack = 100,
    BrightRed = 101,
    BrightGreen = 102,
    BrightYellow = 103,
    BrightBlue = 104,
    BrightMagenta = 105,
    BrightCyan = 106,
    BrightWhite = 107,
    Reset = 0,
};

enum class TextStyle : int
{
    Reset,
    Bold,
    Dim,
    Italic,
    Underline,
    Blinking,
    Inverse,
    Invisible,
    Strikethrough,
};

class Cursor
{
public:
    // 커서 조작
    static void move_up(int count);
    static void move_down(int count);
    static void move_left(int count);
    static void move_right(int count);
    static void set_position(int row, int col);
    static void set_position(Pos pos);
    // 지우기
    static void clear_screen();
    static void clear_line(int line);
    static void clear_current_line();
    // 커서 숨기기/보이기
    static void hide_cursor();
    static void show_cursor();
    // 색 변경 
    static void set_text_color(ForeColor color);
    static void set_text_color(RGB color);
    static void reset_text_color();
    static void set_background_color(BackColor color);
    static void reset_background_color();
    static void reset_all_style();
    // 텍스트 스타일
    template <typename... Args>
    static void set_text_style(Args... args);
    static void reset_text_style();
};

