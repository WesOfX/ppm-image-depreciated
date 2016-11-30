# PPM Image
A small library for easily loading, saving, streaming creating, and editing 24-bit color ppm image files.

```
// Create a 600x400 PPM image
ppm::image<600, 400> img;

// Set the pixel at (555, 369) to red
img.at(555, 369) = ppm::color::red;

// Set the pixel at (123, 456) to dark magenta using rgb
img.at(123, 456) = ppm::color(127, 0, 127)

// Save the image as "out.ppm"
std::ofstream file("out.ppm");
img >> file;

// Load the image from "in.ppm"
std::ifstream file("in.ppm");
img << file;
```
