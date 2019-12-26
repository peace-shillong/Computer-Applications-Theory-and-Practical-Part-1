#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<Z:\draw.h>
void rotate(int *xp,int *yp,int xf,int yf,float *theta)
{
	float x1,y1,thta[8];
	for(int i=0;i<4;i++)
	{
		thta[i]=6.28*(theta[i]/360);
		x1=ROUND((float)(xf+(xp[i]-xf)*cos(thta[i])-(yp[i]-yf)*sin(thta[i])));
		y1=ROUND((float)(yf+(xp[i]-xf)*sin(thta[i])+(yp[i]-yf)*cos(thta[i])));
		xp[i]=ROUND(x1);yp[i]=ROUND(y1);
	}
}
void main()
{
	int gd =DETECT,mode;
	initgraph(&gd,&mode,"c:\\tc\\bgi");
	int x=getmaxx()/2,y=getmaxy()/2;

	int xp[]={x-80,x-100,x-120,x-140};//,x-140,x-180,x-200,x-220};
	int yp[]={y,y,y,y};//,y,y,y,y};
	int orbit[]={x-80,x-100,x-120,x-140};//,x-130,x-160,x-180,x-200};
	int size[]={12,13,14,16};//,10,9,9,7};
	float theta[]={6.5,5,4.5,3};    //,3,2.5,2,1.5,1};
	for(int i=0;i<1000;i++)
	{
		putpixel(random(630),random(530),random(15));
		putpixel(random(630),random(530),random(WHITE));
		delay(5);
	}

	setcolor(YELLOW);
	outtextxy(30,30,"SOLAR SYSTEM");
	outtextxy(x-10,y,"SUN");
	circle(x,y,40);
	for(i=0;i<4;i++)
	{

		circle(xp[i],yp[i],size[i]);
		setcolor(i);
	}

	while(!kbhit())
	{
	      setcolor(BLACK);
		for(i=0;i<4;i++)
		{
			circle(x,y,x-orbit[i]);

		}
		for(i=0;i<4;i++)
		{
			circle(xp[i],yp[i],size[i]);
		}
		setcolor(WHITE);
		rotate(xp,yp,x,y,theta);
		for(i=0;i<4;i++)
		{
			circle(xp[i],yp[i],size[i]);
			setcolor(i+1);
		}
		for(i=0;i<4;i++)
			circle(x,y,x-orbit[i]);
		delay(100);
	}
	getch();
}
