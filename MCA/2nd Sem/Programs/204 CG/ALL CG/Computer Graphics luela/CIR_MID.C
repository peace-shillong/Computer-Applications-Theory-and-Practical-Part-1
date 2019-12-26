#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void circlepoint(int xcenter,int ycenter,int xp,int yp);
void main()
{
	int x,y,p,driver,mode,rad,xcen,ycen;
	driver=DETECT;
	clrscr();
	printf("\n\n\t*****MIDPOINT CIRCLE*****");
	printf("\nEnter the rad: ");
	scanf("%d",&rad);
	printf("\nEnter the center: ");
	scanf("%d %d",&xcen,&ycen);
	initgraph(&driver,&mode,"c:\\tc\\bgi");

	x=0;
	y=rad;
	p=1-rad;
	while(x<y)
	{
		x++;
		if(p<0)
		p=p+2*x+1;
		else
		{
			y--;
			p=p+2*(x-y)+1;
		}
		circlepoint(xcen,ycen,x,y);
	}
	getch();
	closegraph();
}
void circlepoint(int xcenter,int ycenter,int xp,int yp)
{
	putpixel(xcenter+xp,ycenter+yp,WHITE);
	putpixel(xcenter-xp,ycenter+yp,WHITE);
	putpixel(xcenter+xp,ycenter-yp,WHITE);
	putpixel(xcenter-xp,ycenter-yp,WHITE);
	putpixel(xcenter+yp,ycenter+xp,WHITE);
	putpixel(xcenter-yp,ycenter+xp,WHITE);
	putpixel(xcenter+yp,ycenter-xp,WHITE);
	putpixel(xcenter-yp,ycenter-xp,WHITE);
}