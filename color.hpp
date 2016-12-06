#pragma once

namespace ppm{
// RGB color
struct color{
	// Construct a color, black by default
	color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0);

	// The RGB values
	unsigned char r, g, b;

	// Primary color constants
	static const color black, white, red, green, blue, yellow, magenta, cyan;
};
};
