#include "ppm.hpp"

#include <iostream>

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

ppm::color::color(unsigned short r, unsigned short g, unsigned short b): r(r), g(g), b(b){}

template<std::size_t width, std::size_t height>
ppm::image<width, height>::image(pixel_array pixels): pixels(pixels){}

template<std::size_t width, std::size_t height>
ppm::color& ppm::image<width, height>::at(std::size_t x, std::size_t y){
	return pixels.at(x + y * width);
}

template<std::size_t width, std::size_t height>
std::ostream& ppm::image<width, height>::operator<<(std::ostream& os){
	// Write the header
	os << "P6\n" // 24 bit color in binary
	   << std::to_string(width)
	   << ' '
	   << std::to_string(height)
	   << std::endl
	   << "255\n"; // 24 bit

	// Write pixel data
	for(auto& i: pixels){
		os << i.r << i.g << i.b;
	}

	return os;
}

template<std::size_t width, std::size_t height>
std::istream& ppm::image<width, height>::operator>>(std::istream& is){
	// The current line
	std::string line;

	// Skip the magic number
	is >> line;

	// Skip the image width
	is >> line;

	// Skip the image height
	is >> line;

	// Skip the trailing space
	is >> line;
	is.get();

	// Read the pixel data
	for(std::size_t y = 0; y < height; y++){
		for(std::size_t x = 0; x < width; x++){
			at(x, y) = {(unsigned char)is.get(), (unsigned char)is.get(), (unsigned char)is.get()};
		}
	}

	return is;
}

template class ppm::image<31, 31>;
