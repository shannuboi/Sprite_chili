#include "Surface.h"

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width * height])
{
}

const Color & Surface::GetColor(int x, int y) const
{
	return pPixels[y * width + x];
}

void Surface::SetColor(int x, int y, const Color & c)
{
	pPixels[y * width + x] = c;
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}
