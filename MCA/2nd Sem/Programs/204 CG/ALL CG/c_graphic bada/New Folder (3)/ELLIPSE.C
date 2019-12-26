#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
void dellipse(double xc,double yc,double rx,double ry)
{
	double pk,x=0,y;
	pk=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
	y=ry;
	putpixel(xc,(y+yc),9);
	putpixel(xc,(-y+yc),9);
	// drawing the first region
	do
	{
		x++;
		if(pk<0)
			pk=pk+(2*ry*ry*x)+(ry*ry);
		else if(pk>=0)
		{
			y--;
			pk=pk+(2*ry*ry*x)+(ry*ry)-(2*rx*rx*y);
		}
		putpixel((x+xc),(y+yc),WHITE);
		putpixel((x+xc),(-y+yc),WHITE);
		putpixel((-x+xc),(y+yc),WHITE);
		putpixel((-x+xc),(-y+yc),WHITE);
	}while((ry*ry*x)<(rx*rx*y));
	// end of region 1

	// drawing the second region
	pk=(ry*ry*pow((x+1/2),2))+(rx*rx*pow((y-1),2))-(rx*rx*ry*ry);
	putpixel((x+xc),(y+yc),WHITE);
	putpixel((x+xc),(-y+yc),WHITE);
	putpixel((-x+xc),(y+yc),WHITE);
	putpixel((-x+xc),(-y+yc),WHITE);
	do
	{
		y--;
		if(pk>0)
			pk=pk-2*rx*rx*y+rx*rx;
		else
			pk=pk-2*rx*rx*y+rx*rx+2*ry*ry*++x;
		putpixel((x+xc),(y+yc),WHITE);
		putpixel((x+xc),(-y+yc),WHITE);
		putpixel((-x+xc),(y+yc),WHITE);
		putpixel((-x+xc),(-y+yc),WHITE);
	}while(y>=0);
	// end of region 2
}
void main()
{
	float xc,yc,rx,ry;
	int gd=DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	printf("\n\t Enter the center(xc,yc): ");
	scanf("%f %f",&xc,&yc);
	printf("\n\t Enter semi major axis(rx): ");
	scanf("%f",&rx);
	printf("\n\t Enter semi minor axis(ry): ");
	scanf("%f",&ry);
	dellipse(xc,yc,rx,ry);
	getch();
	closegraph();
}

