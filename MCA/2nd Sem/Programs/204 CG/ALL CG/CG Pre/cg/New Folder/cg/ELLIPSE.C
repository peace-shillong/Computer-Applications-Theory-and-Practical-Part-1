/*** Program to Draw an Ellipse using Mid - Point Algorithm ***/
#include <stdio.h>
#include<conio.h>
#include <graphics.h>
void e_Midpoint(float, float, float, float);
void draw_e(float, float, float, float);

void main()
{
	float xc, yc, radx, rady;
	int driver=DETECT,mode;
	initgraph(&gd, &gm, "c://tc//BGI");
	printf("\nEnter the Center Coordinates of Ellipse: ");
	scanf("%f %f", &xc, &yc);
	printf("\nEnter x-radius coordinate: ");
	scanf("%f", &radx);
	printf("\nEnter y-radius coordiante: ");
	scanf("%f", &rady);

	e_Midpoint(xc, yc, rx, ry);
	getch();
	closegraph();
}
void e_Midpoint(float xc, float yc, float rx, float ry)
{
	float rxSq = rx * rx;
	float rySq = ry * ry;
	float x = 0, y = ry, p;
	float px = 0, py = 2 * rxSq * y;

	draw_e(xc, yc, x, y);
//Region 1
	p = rySq - (rxSq * ry) + (0.25 * rxSq);
	while (px < py)
	{
		x++;
		px = px + 2 * rySq;
		if (p < 0)
			p = p + rySq + px;
		else
		{
			y--;
			py = py - 2 * rxSq;
			p = p + rySq + px - py;
		}
		draw_e(xc, yc, x, y);
	}
//Region 2
	p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;
	while (y > 0)
	{
		y--;
		py = py - 2 * rxSq;
		if (p > 0)
			p = p + rxSq - py;
		else
		{
			x++;
			px = px + 2 * rySq;
			p = p + rxSq - py + px;
		}
		draw_e(xc, yc, x, y);
	}
}
void draw_e(float xc, float yc, float xk, float yk)
{
	putpixel(xc+xk, yc+yk, RED);
	putpixel(xc-xk, yc+yk, RED);
	putpixel(xc+xk, yc-yk, RED);
	putpixel(xc-xk, yc-yk, RED);
}