#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
void setline(int, int, int, int);
void main()
{
	int driver=DETECT, gmode, m, n=0;
	int x, x1, x2;
	int y, y1, y2;

	initgraph(&driver,&gmode,"c:\\tc\\bgi");
	while(n<=700)
	{
		x=getmaxx();
		y=getmaxy();
		x1=rand()%x;
		x2=rand()%x;
		y1=rand()%y;
		y2=rand()%y;
		setline(x1, y1, x2, y2);
		n++;
	}

	getch();
	closegraph();
}
void setline(int x1, int y1, int x2, int y2)
{
	int m, x, y;

	x=x1;
	y=y2;

	while(x<=x2 && y<=y2)
	{
		putpixel(x,y,1);
		putpixel(x,y,4);
		x++;
		y=(y2-y1)/(x2-x1)*(x-x1)+y1;
	}


}