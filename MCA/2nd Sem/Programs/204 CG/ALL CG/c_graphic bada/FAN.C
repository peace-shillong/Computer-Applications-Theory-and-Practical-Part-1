#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#define RAD 0.01745329

void draw_line(float,float,float,float);
void c_fan(float,float,float);

void main()
{
	int r,tx,ty;  // Radian and coordinate of fan.
	int rc,rq,d;
	int driver=DETECT,mode,i;
	int c1[8];
	int c2[8];
	int c3[8];
     //	int c4[8];

	// Initial
	initgraph(&driver,&mode,"c:\\tc\\bgi");

	tx=getmaxx()/2;
	ty=getmaxy()/3;
	c1[0]=c1[6]=tx;c1[1]=c1[7]=ty;
	c2[0]=c2[6]=tx;c2[1]=c2[7]=ty;
	c3[0]=c3[6]=tx;c3[1]=c3[7]=ty;
   //	c4[0]=c4[6]=tx;c4[1]=c4[7]=ty;
	d=0;
	r=100;
	rq=r-20;
	rc=50;

	// Draw fan

	c_fan(tx,ty,90);
	c_fan(tx,ty,110);


	draw_line(300,268,300,330);
	draw_line(335,268,335,330);

	draw_line(220,330,420,330);
	draw_line(220,330,220,380);
	draw_line(420,330,420,380);
	draw_line(220,380,420,380);

	while(!kbhit())
	{
		setcolor(BLACK);

		c1[2]=tx+rq*sin(d*RAD);
		c1[3]=ty-rq*cos(d*RAD);
		c1[4]=tx+rq*sin((d+rc)*RAD);
		c1[5]=ty-rq*cos((d+rc)*RAD);

		c2[2]=tx+rq*sin((d+120)*RAD);
		c2[3]=ty-rq*cos((d+120)*RAD);
		c2[4]=tx+rq*sin((d+120+rc)*RAD);
		c2[5]=ty-rq*cos((d+120+rc)*RAD);

		c3[2]=tx+rq*sin((d+240)*RAD);
		c3[3]=ty-rq*cos((d+240)*RAD);
		c3[4]=tx+rq*sin((d+240+rc)*RAD);
		c3[5]=ty-rq*cos((d+240+rc)*RAD);

	    /*	c4[2]=tx+rq*sin((d+270)*RAD);
		c4[3]=ty-rq*cos((d+270)*RAD);
		c4[4]=tx+rq*sin((d+270+rc)*RAD);
		c4[5]=ty-rq*cos((d+270+rc)*RAD);  */

		setfillstyle(2,15);
		fillpoly(4,c1);
		fillpoly(4,c2);
		fillpoly(4,c3);
//		fillpoly(4,c4);

		delay(3);
		setfillstyle(4,8);
		fillpoly(4,c1);
		fillpoly(4,c2);
		fillpoly(4,c3);
	     //	fillpoly(4,c4);

		d+=4;
		if(d==360) d=0;
	}
	getch();
	closegraph();
}

void c_fan(float xc,float yc,float rad)
{
	int xk,yk,dp;
	xk=0;
	yk=rad;
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
		putpixel(xc+xk,yc+yk,3);
		putpixel(xc+yk,yc+xk,3);
		putpixel(xc+yk,yc-xk,3);
		putpixel(xc+xk,yc-yk,3);
		putpixel(xc-xk,yc-yk,3);
		putpixel(xc-yk,yc-xk,3);
		putpixel(xc-yk,yc+xk,3);
		putpixel(xc-xk,yc+yk,3);
		xk++;
	}
}

void draw_line(float x1,float y1,float x2,float y2)
{
	int x,y;
	if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,3);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,3);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,3);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,3);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,3);

	}
}
/*void c_fan(float xc,float yc,float rad)
{
	float x1,y1,x[10],y[10];
	for(x1=-rad;x1<=rad;x1++)
	{
		y1=sqrt((rad*rad)-(x1*x1));
		putpixel(x1+xc,y1+yc,3);
		putpixel(x1+xc,-y1+yc,3);

	}
} */