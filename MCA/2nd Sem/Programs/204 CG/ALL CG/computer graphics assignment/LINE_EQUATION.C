#include <stdio.h>
#include <conio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	float x1,x2,y1,y2,x,y;
	printf("\n\tDrawing a line using line equation formula");
	printf("\n\nEnter the x1 coordinate:");
	scanf("%f", &x1);
	printf("\nEnter the y1 coordinate:");
	scanf("%f", &y1);
	printf("\nEnter the x2 coordinate:");
	scanf("%f", &x2);
	printf("\nEnter the y2 coordinate:");

	scanf("%f", &y2);
	initgraph(&gd,&gm, "C:\\TC\\BGI");
	if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,WHITE);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,WHITE);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,WHITE);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,WHITE);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,WHITE);

	}
	getch();
	closegraph();
}

