#pragma once

#include "Colors.h"
#include <string>

class Surface
{
public:
	Surface(int width, int height);
	Surface(const Surface& src);
	~Surface();
	Surface& operator=(const Surface& rhs);
	const Color& GetColor(int x, int y) const;
	void SetColor(int x, int y, const Color& c);
	int GetWidth() const;
	int GetHeight() const;
private:
	int width, height;
	Color* pPixels = nullptr;
};