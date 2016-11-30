#pragma once

#include <array>

namespace ppm{
	// RGB color
	struct color{
		// Construct a color, black by default
		color(unsigned short r = 0, unsigned short g = 0, unsigned short b = 0);

		// The RGB values
		unsigned char r, g, b;

		// Primary color constants
		static const color black, white, red, green, blue, yellow, magenta, cyan;
	};

	// PPM image
	template<std::size_t width, std::size_t height>
	class image{
	public:
		// The type of the pixel array
		typedef std::array<color, width * height> pixel_array;

		// Construct an image from a pixel array optionally
		image(pixel_array pixels = {});

		// Return a pixel's color value
		color& at(std::size_t x, std::size_t y);

		// Upload the image to a stream
		std::ostream& operator<<(std::ostream& os);

		// Download the image from a stream
		std::istream& operator>>(std::istream& is);
	private:
		// The image pixels
		pixel_array pixels;
	};
};
