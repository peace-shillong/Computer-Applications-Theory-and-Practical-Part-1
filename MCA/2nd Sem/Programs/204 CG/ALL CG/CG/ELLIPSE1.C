#include<stdio.h>
#include<graphics.h>
void putpix(float xc,float yc,float x,float y)
{
		putpixel((int)(xc+x),(int)(yc+y),15);
		putpixel((int)(xc+x),(int)(yc-y),15);
		putpixel((int)(xc-x),(int)(yc+y),15);
		putpixel((int)(xc-x),(int)(yc-y),15);
}
void plotpoint(float xc,float yc,float rx,float ry)
{
	float x=0,y=ry,p1,p2,t1,t2;
	int k;
      p1=ry*ry-rx*rx*ry+0.25*rx*rx;
	putpix(xc,yc,x,y);
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
		putpix(xc,yc,x,y);
	}
	p2=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
	putpix(xc,yc,x,y);

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
		putpix(xc,yc,x,y);
	}
}


void main()
{
	 //clrscr();
	float ry,rx;

       //	float x=0,y=ry,p1,p2,t1,t2;
	float xc,yc;
	int k;

	int driver,mode;
	driver=DETECT;
	clrscr();
       //	initgraph(&driver,&mode,"h:\\tc\\bgi");
	printf("Enter The Co-ordinates of major axis:");
	scanf("%f %f",&xc,&yc);
	printf("Enter The coordinate of minor axis:");
	scanf("%f %f",&rx,&ry);
	clrscr();
	initgraph(&driver,&mode,"h:\\tc\\bgi");
	plotpoint(xc,yc,rx,ry);

	getch();
}


