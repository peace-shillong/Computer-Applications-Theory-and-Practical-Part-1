#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void polydraw(float,float,float,float);
void cir(float,float,float);
#define RAD 0.01745329
void main()
{
    int r,tx,ty;  // Radian and coordinate of fan.
    int rc,rq,d;
    int gd =0,gm,i;
    int c1[8];
    int c2[8];
    int c3[8];

    // Initial
    initgraph(&gd,&gm,"");

    tx=getmaxx()/2;
    ty=getmaxy()/3;
    c1[0]=c1[6]=tx;c1[1]=c1[7]=ty;
    c2[0]=c2[6]=tx;c2[1]=c2[7]=ty;
    c3[0]=c3[6]=tx;c3[1]=c3[7]=ty;
    d=0;
    r=100;
    rq=r-20;
    rc=30;

    // Draw fan

	cir(tx,ty,r);
	cir(tx,ty,85);



    polydraw(300,260,300,350);
    polydraw(340,260,340,350);

    polydraw(220,350,420,350);
    polydraw(220,350,220,400);
    polydraw(420,350,420,400);
    polydraw(220,400,420,400);
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


	setfillstyle(2,BLUE);
	fillpoly(4,c1);
	fillpoly(4,c2);
	fillpoly(4,c3);


	delay(8);
	setfillstyle(2,WHITE);
	fillpoly(4,c1);
	fillpoly(4,c2);
	fillpoly(4,c3);

	d+=2;
	if(d==360) d=0;
    }
    getch();
    closegraph();
}


void cir(float xc,float yc,float rad)
{
	float x1,y1,x[10],y[10];
	//xc=300;
	//yc=200;
	//r=100;
	//initgraph(&gd,&gm,"c:\\tc\\bgi");
	for(x1=-rad;x1<=rad;x1++)
	{

		y1=sqrt((rad*rad)-(x1*x1));
		putpixel(x1+xc,y1+yc,3);
		putpixel(x1+xc,-y1+yc,3);

	}
}



void polydraw(float x1,float y1,float x2,float y2)
{
	int x,y;
	if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,13);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,13);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,13);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,13);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,13);

	}
}