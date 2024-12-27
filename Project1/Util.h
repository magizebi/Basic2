#pragma once
#include "pch.h"
#include <fstream>

class Util
{
private:
static string set_resource_path(string filename);
public:
static vector<string> read_text(string path);
static string get_longest_string(vector<string>& text);
};
