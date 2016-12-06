#include "color.hpp"

// Define color constants
const ppm::color
	ppm::color::black = {0, 0, 0},
	ppm::color::white = {255, 255, 255},
	ppm::color::red = {255, 0, 0},
	ppm::color::green = {0, 255, 0},
	ppm::color::blue = {0, 0, 255},
	ppm::color::yellow = {255, 255, 0},
	ppm::color::magenta = {255, 0, 255},
	ppm::color::cyan = {0, 255, 255};

ppm::color::color(unsigned char r, unsigned char g, unsigned char b): r(r), g(g), b(b){}
