#pragma once

#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

using namespace std;

struct Pos {
	int raw;
	int col;

	Pos operator+(const Pos& other)
	{
		Pos result(0,0);
		result.raw = this->raw + other.raw;
		result.col = this->col + other.col;

		return result;
	}
};

struct RGB {
	unsigned short r;
	unsigned short g;
	unsigned short b;
};