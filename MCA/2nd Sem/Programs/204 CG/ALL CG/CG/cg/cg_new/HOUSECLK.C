#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void ddaline(float,float,float,float);
void main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	//printf("%d %d",getmaxx(),getmaxy());
	ddaline(210,50,450,50);
	ddaline(450,50,490,120);
	ddaline(210,50,250,120);
	ddaline(250,120,490,120);
	ddaline(210,50,160,120);
	ddaline(160,120,160,240);
	ddaline(250,240,250,120);
	ddaline(160,240,250,240);
	ddaline(250,240,490,240);
	ddaline(490,120,490,240);
	ddaline(195,180,195,240);
	ddaline(195,180,225,180);
	ddaline(225,180,225,240);
	ddaline(270,150,330,150);
	ddaline(330,150,330,190);
	ddaline(270,190,330,190);
	ddaline(270,150,270,190);
	ddaline(300,150,300,190);
	ddaline(270,170,330,170);
	ddaline(420,150,480,150);
	ddaline(480,150,480,190);
	ddaline(420,190,480,190);
	ddaline(420,150,420,190);
	ddaline(450,150,450,190);
	ddaline(420,170,480,170);
       //	ddaline();
	getch();
	closegraph();
}
void ddaline(float x1,float y1,float x2,float y2)
{

	float m,mh,xcur,ycur;
	if(x1<0 || x2<0 || y1<0 || y2<0 || x1>getmaxx() || x2>getmaxx() || y1>getmaxy() || y2>getmaxy())
	{
		printf("\nCoordinate value(s) out of bound");
		getch();
		exit(0);
	}
	xcur=x1;
	ycur=y1;
	if(x1==x2)
	{
		if(y1<=y2)
		{
			while(ycur<=y2)
			{
				putpixel(xcur,ycur,WHITE);
				ycur++;
			}
		}
		else
		{
			while(ycur>=y2)
			{
				putpixel(xcur,ycur,WHITE);
				ycur--;
			}
		}
	}else if(y1==y2)
	{
		if(x1<=x2)
		{
			while(xcur<=x2)
			{
				putpixel(xcur,ycur,WHITE);
				xcur++;
			}
		}
		else
		{
			while(xcur>=x2)
			{
				putpixel(xcur,ycur,WHITE);
				xcur--;
			}
		}

	}
	else
	{
		m=(y2-y1)/(x2-x1);
		//printf("\n\n%f",m);
		if(m<=1)
		{
			if(x1<x2)
			{
				while(xcur<=x2)
				{
					putpixel(xcur,ycur,WHITE);
					ycur=ycur+m;
					xcur++;
				}
			}
			else
			{
				while(xcur>=x2)
				{
					putpixel(xcur,ycur,WHITE);
					ycur=ycur-m;
					xcur--;
				}
			}
		}else{
			mh=1/m;
			if(y1<y2)
			{
				while(ycur<=y2)
				{
					putpixel(xcur,ycur,WHITE);
					xcur=xcur+mh;
					ycur++;
				}
			}
			else
			{
				while(ycur>=y2)
				{
					putpixel(xcur,ycur,WHITE);
					xcur=xcur-mh;
					ycur--;
				}
			}
		}
	}
}