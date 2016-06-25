# PPM Image
A small library for easily loading, saving, creating, and editing 24-bit color ppm image files.

## PPM::Image
To use this class, construct an object using either the default
constructor or the reading constructor. Use the "write" function
to write pixel data to a ppm image file. Use the "read" function
to read pixel data from a ppm image file and resize the pixel array
automatically. Examples below.

```
// Load image using read constructor
PPM::Image image("Cat.ppm");

// Set the pixel at 55, 99 to magenta
image.set(55, 99, PPM::Color(255, 0, 255));

// Write image to new file
image.write("New Cat.ppm");
```
