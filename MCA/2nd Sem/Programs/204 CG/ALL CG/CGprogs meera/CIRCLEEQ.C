#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void drawcircle(float,float,float);
void main()
{
	int driver,mode;
	float xc,yc,r;
	clrscr();
	driver = DETECT;
	printf("\n\n\tEnter the centre point:");
	scanf("%f %f",&xc,&yc);
	printf("\n\n\tEnter the radius:");
	scanf("%f",&r);
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
	drawcircle(xc,yc,r);
	getch();
	closegraph();
}
void drawcircle(float xc,float yc,float r)
{
	float x,y,maxx;
	int i;
	x = xc - r;
	maxx= xc + r;
	for(i=x;i<=maxx;i++)
	{
		y  = sqrt((r*r)-((x-xc)*(x-xc)))+yc;
		putpixel(x,y,WHITE);
		y  = -sqrt((r*r)-((x-xc)*(x-xc)))+yc;
		putpixel(x,y,WHITE);
		x= x+1;
	}
}