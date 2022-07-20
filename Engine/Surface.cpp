#include "Surface.h"
#include <assert.h>

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width * height])
{
}

Surface::Surface(const Surface & src)
	:
	width(src.width),
	height(src.height),
	pPixels(new Color[width * height])
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			pPixels[y * width + x] = src.pPixels[y * width + x];
		}
	}
}

Surface::~Surface()
{
	delete[] pPixels;
	pPixels = nullptr;
}

Surface & Surface::operator=(const Surface & rhs)
{
	if (this != &rhs)
	{
		delete[] pPixels;
		pPixels = nullptr;

		width = rhs.width;
		height = rhs.height;
		pPixels = new Color[width * height];

		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < height; y++)
			{
				pPixels[y * width + x] = rhs.pPixels[y * width + x];
			}
		}
	}
	return *this;
}

const Color & Surface::GetColor(int x, int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
	return pPixels[y * width + x];
}

void Surface::SetColor(int x, int y, const Color & c)
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);
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
