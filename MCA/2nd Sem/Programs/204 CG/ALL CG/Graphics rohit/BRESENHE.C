#include<stdio.h>
#include<conio.h>
#include<graphics.h>

	 void bresenhem(int,int,int,int);
	 void main()
{
	 int x1,y1,x2,y2;


	 int gd=DETECT,gm;
	 clrscr();
	 initgraph(&gd,&gm,"C:\\TC\\BGI");

	 printf("\n\tEnter the first coordinates x1 and y1:");
	 scanf("%d %d",&x1,&y1);
	 printf("\n\tEnter the last coordinates x2 and y2:");
	 scanf("%d %d",&x2,&y2);
	 bresenhem(x1,y1,x1,y2);
	 getch();
	 }

	 void bresenhem(int x1,int x2,int y1,int y2)
	{
	int x,y,xend;
	int dx=x2-x1,dy=y2-y1;
	int di=2*(dy-dx);
	int ds=2*dy;
	int dt=2*dy-dx;
	putpixel(x,y,WHITE);
	if(x1>x2)
	{   x=x2;
	    y=y2;
	    xend=x1;
	}
	else
	{
	     x=x1;
	     y=y1;
	     xend=x2;
	}
	putpixel(x,y,WHITE);
	while(x<xend)
	{
		x++;
		if(dt<0)
		{
		 dt=dt+ds;
		}
		else
		{
		y=y+1;
		dt=dt+ds;
		}
		putpixel(x,y,WHITE);

		}
	      if(di<0)
		{
		di=di+ds;
		}
		else
		{
			y1++;
			di=di+dt;
		}
		putpixel(x1,y1,WHITE);


	}









