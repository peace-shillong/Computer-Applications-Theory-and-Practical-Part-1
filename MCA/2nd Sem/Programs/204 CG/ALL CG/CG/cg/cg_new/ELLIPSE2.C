#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	float rx,ry,xc,yc,r,xcur,ycur,p,x,y;
	clrscr();
	printf("\nEnter the semi-major radius of the ellipse rx : ");
	scanf("%f",&rx);
	printf("\nEnter the semi-minor radius of the ellipse ry : ");
	scanf("%f",&ry);
	if(rx<0 || ry<0)
	{
		printf("\nRadius cannot be negative ");
		getch();
		exit(0);
	}
	printf("\nEnter the center coordinate of the circle \nxc : ");
	scanf("%f",&xc);
	printf("\nyc : ");
	scanf("%f",&yc);
	xcur=0;
	ycur=ry;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	putpixel(xcur+xc,ycur+yc,WHITE);
	p=(ry*ry)-(rx*rx*ry)+(rx*rx)/4;
	x=ry*ry*xcur;
	y=rx*rx*ycur;
	while(x<=y && rx>0 && ry>0)
	{
		if(p>=0)
		{
			p=p+2*ry*ry*(xcur+1)+ry*ry+2*rx*rx*(1-ycur);
			ycur=ycur-1;
		}
		else
		{
			p=p+2*ry*ry*(xcur+1)+ry*ry;
		}
		xcur=xcur+1;
		x=ry*ry*xcur;
		y=rx*rx*ycur;
		putpixel(xcur+xc,ycur+yc,WHITE);
		putpixel(-xcur+xc,-ycur+yc,WHITE);
		putpixel(-xcur+xc,ycur+yc,WHITE);
		putpixel(xcur+xc,-ycur+yc,WHITE);
	}
	p=ry*ry*(xcur+0.5)*(xcur+0.5)+rx*rx*(ycur-1)*(ycur-1)-rx*rx*ry*ry;
	while(ycur>=0 && rx>0 && ry>0){
		if(p>=0)
		{
			p=p+rx*rx*(3-2*ycur);
		}
		else
		{
			p=p+ry*ry*(2*xcur+2)+rx*rx*(3-2*ycur);
			xcur=xcur+1;
		}
		ycur=ycur-1;
		putpixel(xcur+xc,ycur+yc,WHITE);
		putpixel(-xcur+xc,-ycur+yc,WHITE);
		putpixel(-xcur+xc,ycur+yc,WHITE);
		putpixel(xcur+xc,-ycur+yc,WHITE);
	}
	getch();
	closegraph();
}