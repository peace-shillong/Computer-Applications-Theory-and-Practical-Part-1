			/*DRAWING A POLYGON*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define ROUND(a)((int)(a+0.5))

void main()
{
	int poly[18]={100,100,200,100,110,175,150,50,175,175};
	int driver=DETECT,mode;
	initgraph(&driver,&mode,"");
	polygon(5,poly,RED);
	getch();
	closegraph();
}

line_dda(int x1,int y1,int x2,int y2,int c)
{
	int dx,dy,k,steps;
	float ddx,ddy,x=x1,y=y1;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	ddx=dx/(float)steps;
	ddy=dy/(float)steps;
	putpixel(ROUND(x),ROUND(y),c);
	for(k=0;k<=steps;k++)
	{
		x+=ddx;
		y+=ddy;
		putpixel(ROUND(x),ROUND(y),c);
	}
	return;
}

polygon(int s,int *poly,int c)
{
	int i,k,x1,x=poly[0],y1,y=poly[1],x2,y2;
	x2=x;
	y2=y;
	for(i=1,k=2;i<s;i++)
	{
		x1=poly[k+1];
		y1=poly[k++];
		line_dda(x,y,x1,y1,c);
		x=x1;
		y=y1;
	}
	line_dda(x,y,x2,y2,c);
	return;
}







