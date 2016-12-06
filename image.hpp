#pragma once

#include <array>
#include <fstream>

#include "color.hpp"

namespace ppm{
// PPM image
template<std::size_t width, std::size_t height>
class image{
public:
	// The type of the pixel array
	typedef std::array<color, width * height> pixel_array;

	// Construct an image from a pixel array optionally
	image(pixel_array pixels = {}): pixels(pixels){};

	// Return a pixel's color value
	color& at(std::size_t x, std::size_t y){
		return pixels.at(x + y * width);
	}

	// Download the image from a stream
	std::istream& operator<<(std::istream& is){
		// Skip the header
		for(auto i = 0; i < 5; i++) is.get();

		// The current line
		std::string line;

		// Read the pixel data
		for(std::size_t y = 0; y < height; y++){
			for(std::size_t x = 0; x < width; x++){
				at(x, y) = {(unsigned char)is.get(), (unsigned char)is.get(), (unsigned char)is.get()};
			}
		}

		return is;
	}

	// Upload the image to a stream
	std::ostream& operator>>(std::ostream& os){
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
private:
	// The image pixels
	pixel_array pixels;
};
};
