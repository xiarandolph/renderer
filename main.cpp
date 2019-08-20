#include "tgaimage.h"
#include "gl.hpp"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	image.set(52, 41, red);
	line(13, 20, 80, 40, image, white); 
	line(20, 13, 40, 80, image, red); 
	line(80, 40, 13, 20, image, red);
	line(0, 0, 100, 20, image, white);
	image.flip_vertically(); // have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

