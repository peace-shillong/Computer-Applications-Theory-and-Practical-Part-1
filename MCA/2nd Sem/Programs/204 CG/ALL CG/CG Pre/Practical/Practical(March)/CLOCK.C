
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void circle_clock(int xc,int yc,int rad);
void line_clock(int x1,int y1,int x2,int y2);

void main()
{
	int driver=DETECT,mode;
	int i;
	clrscr();
	initgraph(&driver,&mode,"C:\\TC\\BGI");

	outtextxy(285,30,"CLOCK");

	circle_clock(300,150,70);
	circle_clock(300,150,90);

/*	line_clock(295,30,305,30);
	line_clock(295,30,295,50);
	line_clock(305,30,305,50); */

	line_clock(235,50,365,50);
	line_clock(235,50,195,120);
	line_clock(195,120,195,180);
	line_clock(195,180,235,250);

	line_clock(365,50,405,120);
	line_clock(405,120,405,180);
	line_clock(405,180,365,250);
	line_clock(235,270,365,270);
	line_clock(220,277,380,277);
	line_clock(205,285,395,285);

	line_clock(235,250,235,270);
	line_clock(365,250,365,270);

	//Pendulum
	line_clock(295,240,295,290);
	line_clock(305,240,305,290);
	circle_clock(300,319,30);
	line_clock(235,270,195,290);
	line_clock(195,290,195,360);
	line_clock(405,290,405,360);
	line_clock(365,270,405,290);
	line_clock(195,360,405,360);

	for(i=200;i<405;i=i+5)
	{
		line_clock(i,320-32,i,320+40);
	}

	//Design
	line_clock(235,50,255,75);
	line_clock(365,50,345,73);
	line_clock(195,120,215,120);
	line_clock(405,120,385,120);
	line_clock(195,180,215,180);
	line_clock(405,180,385,180);
	line_clock(235,250,260,230);
	line_clock(365,250,340,230);

	//Numbers
	outtextxy(335,95,"1");
	outtextxy(355,120,"2");
	outtextxy(363,148,"3");
	outtextxy(352,180,"4");
	outtextxy(330,202,"5");
	outtextxy(298,212 ,"6");
	outtextxy(264,202,"7");
	outtextxy(243,180,"8");
	outtextxy(233,148,"9");
	outtextxy(240,120,"10");
	outtextxy(260,95,"11");
	outtextxy(293,84,"12");

	//Brand
	outtextxy(279,110,"BOLENO");
	outtextxy(279,180 ,"QUARTZ");


	//Hands
	line_clock(300,150,330,160);
	line_clock(300,150,300,200);
	line_clock(300,150,250,120);
	circle_clock(300,150,5);

	getch();
	closegraph();
}



void circle_clock(int xc,int yc,int rad)
{
	int xk,yk,dp;
	xk=0;
	yk=rad;
      //dp=((((xk+1)*(xk+1))+((yk-h)*(yk-h)))-(rad*rad));
	dp=1-rad;
	while(xk<=yk)
	{
		if(dp<0)
		{
			yk=yk;
			dp=dp+(2*xk)+3;
		}
		else if(dp>0)
		{
			yk=yk-1;
			dp=dp+(2*(xk-yk))+5;
		}
		putpixel(xc+xk,yc+yk,11);
		putpixel(xc+yk,yc+xk,11);
		putpixel(xc+yk,yc-xk,11);
		putpixel(xc+xk,yc-yk,11);
		putpixel(xc-xk,yc-yk,11);
		putpixel(xc-yk,yc-xk,11);
		putpixel(xc-yk,yc+xk,11);
		putpixel(xc-xk,yc+yk,11);

		xk++;
	}
}
void line_clock(int x1,int y1,int x2,int y2)
{
	int x,y;
	if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,11);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,11);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,WHITE);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,WHITE);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,GREEN);

	}
}