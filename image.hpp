#pragma once

#include <array>
#include <fstream>

#include "color.hpp"

namespace ppm{
// PPM image
template<std::size_t width, std::size_t height>
class image{
	// The pixel array
	std::array<color, width * height> pixels;

public:
	// Construct an image from a pixel array optionally
	image(std::array<color, width * height> pixels = {}): pixels(pixels){};

	// Return a pixel's color value
	const color& at(std::size_t x, std::size_t y) const{
		return pixels.at(x + y * width);
	}

	// Return a pixel's color value
	color& at(std::size_t x, std::size_t y){
		return pixels.at(x + y * width);
	}

	// Download the image from an istream
	friend std::istream& operator>>(std::istream& is, image<width, height>& rhs){
		// The current line
		std::string line;

		// Skip the header
		for(auto i = 0; i < 4; i++) is >> line;
		is.get();

		// Read the pixel data
		for(std::size_t y = 0; y < height; y++){
			for(std::size_t x = 0; x < width; x++){
				rhs.at(x, y) = {(unsigned char)is.get(), (unsigned char)is.get(), (unsigned char)is.get()};
			}
		}

		return is;
	}

	// Upload the image to an ostream
	friend std::ostream& operator<<(std::ostream& os, const image<width, height>& rhs){
		// Write the header
		os << "P6\n"
		   << std::to_string(width)
		   << ' '
		   << std::to_string(height)
		   << std::endl
		   << "255\n"; // Maximum color value

		// Write the pixel data
		for(auto& i: rhs.pixels){
			os << i.r << i.g << i.b;
		}

		return os;
	}
};
};
