#include "line.h"

static void draw(int x0, int y0, int x1, int y1, TGAImage& img, TGAColor clr) {
	for (float i = 0; i < 1; i += 0.1) {
		float x = x0 + (x1 - x0) * i;
		float y = y0 + (y1 - y0) * i;

		img.set(x, y, clr);
	}
}
