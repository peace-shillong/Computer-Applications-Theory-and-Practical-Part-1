#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void main()
{
	float rad,xc=0,yc=0,y=0,x=0,y1=0;
	float xmin=0,xmax=0;
	float a=0;
	int driver=DETECT,mode;
	clrscr();

	printf("\n Enter the center for x and y: ");
	scanf("%f %f",&xc,&yc);

	printf("\nEnter radius :");
	scanf("%f",&rad);

	initgraph(&driver,&mode,"C:\\tc\\bgi");

	xmin=xc-rad;
	xmax=xc+rad;

	for(x=xmin;x<xmax;x++)
	{

		a=x-xc;
		y=sqrt((rad*rad)-(a*a))+yc;
		y1=-sqrt((rad*rad)-(a*a))+yc;

		putpixel(x,y,WHITE);
		putpixel(x,y1,WHITE);
	}

	getch();
	closegraph();
}
