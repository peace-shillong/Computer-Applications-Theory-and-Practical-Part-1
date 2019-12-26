#include<stdio.h>
#include<graphics.h>
void putpixl(float xcen,float ycen,float x,float y);
void plotpoint(float xcen,float ycen,float rx,float ry);
void main()
{
	float ry,rx;
	float xcen,ycen;
	int k;
	int driver,mode;
	driver=DETECT;
	clrscr();
	printf("\n Enter The first co-ordinate of the major axis:");
	scanf("%f",&xcen);
	printf("\n Enter The second co-ordinate of the major axis:");
	scanf("%f",&ycen);
	printf("\n Enter The first co-ordinate of the minor axis:");
	scanf("%f",&rx);
	printf("\n Enter The second co-ordinate of the minor axis:");
	scanf("%f",&ry);
	clrscr();
	initgraph(&driver,&mode,"h:\\tc\\bgi");
	plotpoint(xcen,ycen,rx,ry);
	getch();
}
void putpixl(float xcen,float ycen,float x,float y)
{
		putpixel((int)(xcen+x),(int)(ycen+y),2);
		putpixel((int)(xcen+x),(int)(ycen-y),2);
		putpixel((int)(xcen-x),(int)(ycen+y),2);
		putpixel((int)(xcen-x),(int)(ycen-y),2);
}
void plotpoint(float xcen,float ycen,float rx,float ry)
{
	float x=0,y=ry,p1,p2,t1,t2;
	int k;
	p1=ry*ry-rx*rx*ry+0.25*rx*rx;
	putpixl(xcen,ycen,x,y);
	for(k=0;(2*ry*ry*x)<=(2*rx*rx*y);k++)
	{
		t1=2*ry*ry*x+2*ry*ry;
		t2=2*rx*rx*y-2*rx*rx;
		if(p1<0)
			p1=p1+t1+ry*ry;
		else
		{
			p1=p1+t1-t2+ry*ry;
			y--;
		}
		x++;
		putpixl(xcen,ycen,x,y);
	}
	p2=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
	putpixl(xcen,ycen,x,y);

	for(k=0;y>=0;k++)
	{
		t1=2*ry*ry*x+2*ry*ry;
		t2=2*rx*rx*y-2*rx*rx;
		if(p2>0)
			p2=p2-t2+rx*rx;
		else
		{
			p2=p2+t1-t2+rx*rx;
			x++;
		}
		y--;
		putpixl(xcen,ycen,x,y);
	}
}





