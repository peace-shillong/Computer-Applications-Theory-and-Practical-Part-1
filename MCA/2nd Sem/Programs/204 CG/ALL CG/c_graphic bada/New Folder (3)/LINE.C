//program to draw line using Equation of a line
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{

	int i,m,x,y,x1,y1,x2,y2;
	int driver=DETECT,mode;
	printf("\n\n Enter the starting point(x1 and y1): ");
	scanf("%d %d",&x1,&y1);
	printf("\n\n Enter the ending point(x2 and y2): ");
	scanf("%d %d",&x2,&y2);
	initgraph(&driver,&mode,"c:\\tc\bgi");
	m=(y2-y1)/(x2-x1);
	for(i=x1;i<=x2;i=i+m)
	{
		x=i;
		y=m*(x-x1)+y1;
		putpixel(x,y,WHITE);
	}

	getch();
	closegraph();
}







