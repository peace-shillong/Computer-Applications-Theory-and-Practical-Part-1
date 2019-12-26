#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	float xc,yc,r,xcur,ycur,p;
	clrscr();
	printf("\nEnter the radius of the circle : ");
	scanf("%f",&r);
	if(r<0)
	{
		printf("\nRadius cannot be negative ");
		getch();
		exit(0);
	}
	printf("\nEnter the center coordinates of the circle: ");
	scanf("%f",&xc);
	scanf("%f",&yc);
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	if((xc+r)>getmaxx() || (xc-r)<0 || (yc+r)>getmaxy() || (yc-r)<0)
	{
		printf("\nCircle is not possible!");
		getch();
		exit(0);
	}
	xcur=0;
	ycur=r;
	putpixel(xcur+xc,ycur+yc,WHITE);
	p=(xcur+1)*(xcur+1)+(ycur-0.5)*(ycur-0.5)-(r*r);
	while(xcur<=ycur && r>0)
	{
		if(p>=0)
		{
			p=p+2*xcur-2*ycur+5;
			ycur=ycur-1;
		}
		else
		{
			p=p+2*xcur+3;
		}
		xcur=xcur+1;
		putpixel(xcur+xc,ycur+yc,WHITE);
		putpixel(-xcur+xc,-ycur+yc,WHITE);
		putpixel(-xcur+xc,ycur+yc,WHITE);
		putpixel(xcur+xc,-ycur+yc,WHITE);
		putpixel(-ycur+xc,xcur+yc,WHITE);
		putpixel(ycur+xc,xcur+yc,WHITE);
		putpixel(ycur+xc,-xcur+yc,WHITE);
		putpixel(-ycur+xc,-xcur+yc,WHITE);
	}
	getch();
	closegraph();
}