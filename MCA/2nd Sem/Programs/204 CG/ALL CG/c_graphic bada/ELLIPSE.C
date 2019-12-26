//Program To Display Ellipse Using Mid Point Algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void e_Mdpt(float, float, float, float);
void draw_e(float, float, float, float);

void main()
{
	float xc, yc, radx,rady;
	int driver=DETECT,mode;

	printf("\nEnter the X Axis of Ellipse       : ");
	scanf("%f",&xc);
	printf("\nEnter the Y Axis of Ellipse       : ");
	scanf("%f",&yc);
	printf("\nEnter The Semi-Major Axis OF The Ellipse : ");
	scanf("%f",&radx);
	printf("\nEnter The Semi-Minor Axis OF The Ellipse : ");
	scanf("%f",&rady);

	initgraph(&driver, &mode,"C:\\TC\\BGI");

	e_Mdpt(xc,yc,radx,rady);

	getch();
	closegraph();
}

void e_Mdpt(float xc, float yc, float rx, float ry)
{
	float rxSq = rx * rx;
	float rySq = ry * ry;
	float x = 0, y = ry, p;
	float px = 0, py = 2 * rxSq * y;

	draw_e(xc, yc, x, y);

	//Region 1

	p = rySq-(rxSq * ry) + (0.25 * rxSq);
	while (px < py)
	{
		x++;
		px = px + 2 * rySq;
		if (p < 0)
			p = p + rySq + px;
		else
		{
			y--;
			py = py-2 * rxSq;
			p = p + rySq + px-py;
		}
		draw_e(xc, yc, x, y);
	}

	//Region 2

	p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1)-rxSq*rySq;
	while (y > 0)
	{
		y--;
		py = py-2 * rxSq;
		if (p > 0)
			p = p + rxSq-py;
		else
		{
			x++;
			px = px + 2 * rySq;
			p = p + rxSq-py + px;
		}
		draw_e(xc, yc, x, y);
	}
}

void draw_e(float xc,float yc,float xk,float yk)
{
	putpixel(xc+xk, yc+yk, 2);
	putpixel(xc-xk, yc+yk, 2);
	putpixel(xc+xk, yc-yk, 2);
	putpixel(xc-xk, yc-yk, 2);
}