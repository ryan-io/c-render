#include "tgaimage.h"
#include "render.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);



int main(int argc, char** argv) {
	TGAImage image(500, 500, TGAImage::RGB);
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	
	auto halfW = image.get_width() / 2;
	auto halfH = image.get_height() / 2;

	drawLine(-100, -100, 200, 200, image, white);
	drawLine(75, 75, 200,200, image, red);

	image.write_tga_file("output.tga");


	return 0;
}