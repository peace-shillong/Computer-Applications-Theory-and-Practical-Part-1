#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void main()
{
	int driver=DETECT, gmode, m;
	int x, x1, x2;
	int y, y1, y2;

	initgraph(&driver,&gmode,"c:\\tc\\bgi");
	printf("\nEnter the starting point(x1, y1) : ");
	scanf("%d %d",&x1,&y1);
	printf("Enter the ending point(x2, y2) : ");
	scanf("%d %d",&x2,&y2);
	m=(y2-y1)/(x2-x1);
	x=x1;
	y=y2;

	while(x<=x2 && y<=y2)
	{
		putpixel(x,y,4);
		x=m+x;
		y=(y2-y1)/(x2-x1)*(x-x1)+y1;
	}
	getch();
	closegraph();
}