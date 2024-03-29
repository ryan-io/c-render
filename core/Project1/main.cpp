#include "tgaimage.h"


const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

void drawLine(int x0, int y0, int x1, int y1, TGAImage& img, const TGAColor& clr)
{
	/*start at(x0, y0)
	* 'x' will always increment by 1
	* need to pick a value between
	*	(x0+1, y0) and (x0+1, y0+1)
	* need a decision parameter to decide which to pick
	* we can keep track of slope error >0.5 (closer up towards y0+1)
	*	if this holds true, then we will choose (x0+1,y0+1)
	*		else
	*			choose (x0+1,y0)
	*/
	// slope; rise/run

	const int deltaY{y1 - y0};
	const int deltaX{x1 - x0};
	const int errorPos{2 * (deltaY - deltaX)};
	const int errorNeg{2 * deltaY};
	bool steep{};

	// transpose the line if it is deemed steep
	int absX = std::abs(deltaX), absY = std::abs(deltaY);

	if (absX < absY) // means x is 'longer' than y
	{
		std::swap(x0, y0);
		std::swap(x1, y1);
		steep = true;
	}

	if (x0 > x1) // means line is going from top-left of raster to bottom-right of raster
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	int d{errorNeg};
	for (int x = x0, y = y0; x <= x1; x++)
	{
		if (d > 0)
		{
			y++;
			d += errorPos;
		}
		else
		{
			d += errorNeg;
		}

		if (steep)
			img.set(y, x, clr);
		else img.set(x, y, clr);
	}
}

int main(int argc, char** argv)
{
	TGAImage image(100, 100, TGAImage::RGB);
	const TGAColor& whiteRef{white};
	const TGAColor& redRef{red};
	// g++ main.cpp tgaimage.cpp -pg -no-pie -fno-builtin
	//	 -no-pie: position independent code is disable
	//	 -fno-builtin: compiler won't optimize code with inline functions

	drawLine(13, 20, 80, 40, image, whiteRef);
	drawLine(20, 13, 40, 80, image, redRef);
	drawLine(80, 40, 13, 20, image, redRef);
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	//image.write_tga_file("output.tga");

	return 0;
}
