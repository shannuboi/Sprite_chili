#pragma once

#include "Colors.h"

class Surface
{
public:
	Surface(int width, int height);
	const Color& GetColor(int x, int y) const;
	void SetColor(int x, int y, const Color& c);
	int GetWidth() const;
	int GetHeight() const;
private:
	const int width, height;
	Color* pPixels = nullptr;
};