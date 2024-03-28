#pragma once
#include "tgaimage.h"

// the goal of Bresenham's line algorithm is to avoid floatin gpoint multiplication
// and addition to computer the value of a line; y=mx+b
// we do this at the pixel level... no trying to optimize entire lines
// this results in no holes, no rounding erorrs (hence no f-point arithmetic)

/// <summary>
/// Draws a line from (x0,y0) to (x1, y0) using Bresneham's line algorithm
/// </summary>
/// <param name="x0">Starting x pixel</param>
/// <param name="y0">Starting y pixel</param>
/// <param name="x1">Ending x pixel</param>
/// <param name="y1">Ending y pixel</param>
/// <param name="img">Our raster to draw on</param>
/// <param name="clr">Color to make the line</param>
void drawLine(int x0, int y0, int x1, int y1, TGAImage& img, TGAColor clr) {
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

	const int deltaY{ y1 - y0 };
	const int deltaX{ x1 - x0 };
	const int errorPos{ 2 * (deltaY - deltaX) };
	const int errorNeg{ 2 * deltaY };
	bool steep{};

	// transpose the line if it is deemed steep
	int absX = std::abs(deltaX), absY = std::abs(deltaY);

	if (absX < absY)	// means x is 'longer' than y
	{
		std::swap(x0, y0);
		std::swap(x1, y1);
		steep = true;
	}

	if (x0 > x1)	// means line is going from top-left of raster to bottom-right of raster
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	int d{ errorNeg };
	for (int x = x0, y = y0; x <= x1; x++) {
		if (d > 0) {
			y++;
			d += errorPos;
		}
		else {
			d += errorNeg;
		}

		if (steep) 
			img.set(y, x, clr);
		else img.set(x, y, clr);
	}
}