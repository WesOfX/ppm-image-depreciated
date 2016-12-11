# PPM Image
Easily load, save, stream, create, and edit ppm images.

```
using namespace ppm;

// Create a 600 by 400 PPM image
image<600, 400> img;

// Set the pixel at (555, 369) to red
img.at(555, 369) = color::red;

// Set the pixel at (123, 456) to dark magenta using rgb
img.at(123, 456) = color(127, 0, 127);

// Save the image as "out.ppm"
std::ofstream os("out.ppm");
os << img;

// Load an image from "in.ppm"
std::ifstream is("in.ppm");
is >> img;
```
