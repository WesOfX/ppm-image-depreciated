# PPM Image
Easily load, save, stream, create, and edit ppm images.

```
using namespace ppm;

// Create a 600x400 PPM image
image<600, 400> img;

// Set the pixel at (555, 369) to red
img.at(555, 369) = color::red;

// Set the pixel at (123, 456) to dark magenta using rgb
img.at(123, 456) = color(127, 0, 127);

// Save the image as "out.ppm"
std::ofstream file("out.ppm");
img >> file;

// Load an image from "in.ppm"
std::ifstream file("in.ppm");
img << file;
```
