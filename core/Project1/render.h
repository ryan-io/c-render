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
	*	if this holds true, then we will chose (x0+1,y0+1)
	*		else
	*			choose (x0+1,y0)
	*/
	// slope; rise/run

	int m = (y1 - y0) / (x1 - x0);
	float error{};

	for (int x = x0; x <= x; ++) {

	}


		img.set(x, y, clr);
}