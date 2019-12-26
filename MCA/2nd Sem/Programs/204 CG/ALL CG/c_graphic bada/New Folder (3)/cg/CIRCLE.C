#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void main()
{
	float r,xc=0,yc=0,y=0,x=0,y1=0;
	float minx=0,maxx=0;
	int driver=DETECT,mode;
	clrscr();

	printf("\n Enter the center for x and y: ");
	scanf("%f %f",&xc,&yc);

	printf("\nEnter radius :");
	scanf("%f",&r);

	initgraph(&driver,&mode,"C:\\tc\\bgi");

	minx=xc-r;
	maxx=xc+r;

	for(x=minx;x<maxx;x++)
	{
	   y=sqrt((r*r)-((x-xc)*(x-xc)))+yc;
	   y1=-sqrt((r*r)-((x-xc)*(x-xc)))+yc;
	   putpixel(x,y,YELLOW);
	   putpixel(x,y1,YELLOW);
	}

	getch();
	closegraph();
}




