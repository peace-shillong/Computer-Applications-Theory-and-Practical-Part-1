#include<graphics.h>
#include<conio.h>
#include<math.h>
#define RAD 0.01745329

void draw_line(float,float,float,float);
void draw_cir(float,float,float);
void bar_fill(int x, int y, int fcolor, int bcolor);

int main()
{
    int r,tx,ty,a,b,c;
    int rc,rq,d;
    int gd =0,gm,i;
    int c1[8];
    int c2[8];
    int c3[8];
    int c4[8];
    int c5[8];

    initgraph(&gd,&gm,"c:\\tc\\bgi");

    tx=getmaxx()/2;
    ty=getmaxy()/3;
    c1[0]=c1[6]=tx;
    c1[1]=c1[7]=ty;
    c2[0]=c2[6]=tx;
    c2[1]=c2[7]=ty;
    c3[0]=c3[6]=tx;
    c3[1]=c3[7]=ty;
    c4[0]=c4[6]=tx;
    c4[1]=c4[7]=ty;
    c5[0]=c5[6]=tx;
    c5[1]=c5[7]=ty;
    d=0;
    r=140;
    rq=r-30;
    rc=40;

    //Draw fan
    for(i=0;i<30;i++)
    {
	draw_cir(tx,ty,r);
	r--;
    }
    //draw_cir(tx,ty,115);

    a=c=310;
    b=300;
    d=350;
    for(i=0;i<20;i++)
    {
	draw_line(a,b,c,d);
	a++;
	c++;
    }

    /*draw_line(310,300,310,350);
    draw_line(311,300,311,350);
    draw_line(312,300,312,350);
    draw_line(313,300,313,350);*/

    //draw_line(330,300,330,350);

    draw_line(220,350,420,350);
    draw_line(220,350,220,400);
    draw_line(420,350,420,400);
    draw_line(220,400,420,400);
    bar_fill(221,351,BROWN,BROWN);

    while(!kbhit())
    {
	setcolor(BLACK);

	c1[2]=tx+rq*sin(d*RAD);
	c1[3]=ty-rq*cos(d*RAD);
	c1[4]=tx+rq*sin((d+rc)*RAD);
	c1[5]=ty-rq*cos((d+rc)*RAD);

	c2[2]=tx+rq*sin((d+70)*RAD);
	c2[3]=ty-rq*cos((d+70)*RAD);
	c2[4]=tx+rq*sin((d+70+rc)*RAD);
	c2[5]=ty-rq*cos((d+70+rc)*RAD);

	c3[2]=tx+rq*sin((d+140)*RAD);
	c3[3]=ty-rq*cos((d+140)*RAD);
	c3[4]=tx+rq*sin((d+140+rc)*RAD);
	c3[5]=ty-rq*cos((d+140+rc)*RAD);

	c4[2]=tx+rq*sin((d+210)*RAD);
	c4[3]=ty-rq*cos((d+210)*RAD);
	c4[4]=tx+rq*sin((d+210+rc)*RAD);
	c4[5]=ty-rq*cos((d+210+rc)*RAD);

	c5[2]=tx+rq*sin((d+280)*RAD);
	c5[3]=ty-rq*cos((d+280)*RAD);
	c5[4]=tx+rq*sin((d+280+rc)*RAD);
	c5[5]=ty-rq*cos((d+280+rc)*RAD);

	setfillstyle(2,BROWN);
	fillpoly(4,c1);
	fillpoly(4,c2);
	fillpoly(4,c3);
	fillpoly(4,c4);
	fillpoly(4,c5);

	delay(13);
	setfillstyle(2,BLACK);
	fillpoly(4,c1);
	fillpoly(4,c2);
	fillpoly(4,c3);
	fillpoly(4,c4);
	fillpoly(4,c5);

	d+=2;
	if(d==360)
		d=0;
    }
    getch();
    closegraph();
    return 0;
}

void draw_cir(float xc,float yc,float r)
{
	int x,maxx,i,y,pk;
	x=0;
	y=r;

	pk=1-r;
	while(x<y)
	{

		if(pk<0)
		{
			pk=pk+2*x+3;
			x=x+1;
			y=y;

		}
		else
		{
			pk=pk+2*x-2*y+5;
			x=x+1;
			y=y-1;

		}
		putpixel(xc+x,yc+y,BROWN);
		putpixel(xc+y,yc+x,BROWN);
		putpixel(xc+y,yc-x,BROWN);
		putpixel(xc+x,yc-y,BROWN);
		putpixel(xc-x,yc-y,BROWN);
		putpixel(xc-y,yc-x,BROWN);
		putpixel(xc-y,yc+x,BROWN);
		putpixel(xc-x,yc+y,BROWN);
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
			putpixel(x,y,BROWN);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,BROWN);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,BROWN);
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
	      putpixel(x,y,WHITE);

	}
}

void bar_fill(int x, int y, int fcolor, int bcolor)
{
	int a,b,c;
	int x1, y1;
	x1=x;
	y1=y;
	a=getpixel(x,y);
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x++;
			c=getpixel(x,y);
		}
		y++;
		x=x1;
		b=getpixel(x,y);
		c=getpixel(x,y);
	}
	x=x1;
	y=y1;
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x--;
			c=getpixel(x,y);
		}
	y++;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}

	x=x1;
	y=y1;
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x--;
			c=getpixel(x,y);
		}
	y--;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}
		x=x1;
		y=y1;
		b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x++;
			c=getpixel(x,y);
		}
	y--;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}
}


