#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void polydraw(float,float,float,float);
void drawcircle(int,int,int);
void drawline(int,int,int,int);
void fill(int,int,int,int);

#define RAD 0.01745329

void main()
{
    int r,xc,yc;
    int rc,rq,d;
    int driver=DETECT,mode,i;
    int cor1[8],cor2[8],cor3[8],cor4[8];

    initgraph(&driver,&mode,"c:\\tc\\bgi");

    xc=getmaxx()/2;
    yc=getmaxy()/3;
    cor1[0]=cor1[6]=xc;
    cor1[1]=cor1[7]=yc;
    cor2[0]=cor2[6]=xc;
    cor2[1]=cor2[7]=yc;
    cor3[0]=cor3[6]=xc;
    cor3[1]=cor3[7]=yc;
    cor4[0]=cor4[6]=xc;
    cor4[1]=cor4[7]=yc;
    d=0;
    r=100;
    rq=r-20;
    rc=50;

    //Draw fan
    drawcircle(xc,yc,90);
    drawline(310,250,310,280);
    drawline(330,248,330,280);

    drawline(250,280,310,280);
    drawline(330,280,390,280);
    drawline(250,280,250,310);
    drawline(390,280,390,310);
    drawline(250,310,390,310);


    fill(320,280,8,WHITE);

    while(!kbhit())
    {
	setcolor(BLACK);

	cor1[2]=xc+rq*sin(d*RAD);
	cor1[3]=yc-rq*cos(d*RAD);
	cor1[4]=xc+rq*sin((d+rc)*RAD);
	cor1[5]=yc-rq*cos((d+rc)*RAD);

	cor2[2]=xc+rq*sin((d+90)*RAD);
	cor2[3]=yc-rq*cos((d+90)*RAD);
	cor2[4]=xc+rq*sin((d+90+rc)*RAD);
	cor2[5]=yc-rq*cos((d+90+rc)*RAD);

	cor3[2]=xc+rq*sin((d+180)*RAD);
	cor3[3]=yc-rq*cos((d+180)*RAD);
	cor3[4]=xc+rq*sin((d+180+rc)*RAD);
	cor3[5]=yc-rq*cos((d+180+rc)*RAD);

	cor4[2]=xc+rq*sin((d+270)*RAD);
	cor4[3]=yc-rq*cos((d+270)*RAD);
	cor4[4]=xc+rq*sin((d+270+rc)*RAD);
	cor4[5]=yc-rq*cos((d+270+rc)*RAD);


	setfillstyle(2,RED);
	fillpoly(4,cor1);
	fillpoly(4,cor2);
	fillpoly(4,cor3);
	fillpoly(4,cor4);


	delay(8);
	setfillstyle(2,7);
	fillpoly(4,cor1);
	fillpoly(4,cor2);
	fillpoly(4,cor3);
	fillpoly(4,cor4);

	d+=4;
	if(d==360) d=0;
    }
    getch();
    closegraph();

}


void drawcircle(int xc,int yc,int rad)
{
	int x,maxx,i,y,pk;
	x=0;
	y=rad;
	pk=1-rad;
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
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+y,yc+x,WHITE);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc-y,yc-x,WHITE);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		}

		putpixel(xc-rad,yc,WHITE);
		putpixel(xc+rad,yc,WHITE);
		putpixel(xc,yc-rad,WHITE);
		putpixel(xc,yc+rad,WHITE);
}

void drawline(int x1,int y1,int x2,int y2)
{
	int d1,d2,x,y,dx,dy,pk,i,x3,y3;
	float m=0;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;
	y=y1;
	if(dx!=0)
	{
		m=(float)dy/(float)dx;
	}
	//case when slope is 0
	if(m==0)
	{
		if(x1==x2)
		{
			if(y1<y2)
			{
				for(i=y1;i<=y2;i++)
				{
					putpixel(x,y,WHITE);
					y = y+1;
				}
			}
			else
			{
				x=x2;
				y=y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,WHITE);
					y = y+1;
				}
			}
		}
		else
		{
			if(x1<x2)
			{
				for(i=x1;i<=x2;i++)
				{
					putpixel(x,y,WHITE);
					x= x+1;
				}
			}
			else
			{
				x=x2;
				y=y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,WHITE);
					x= x+1;
				}
			}
		}
	}
	//case when m is -ve and more than -1
	else if(-1<=m && m<0)
	{
		pk = (2*dy)-dx;
		if(x1<x2)
		{
			x=x1;
			y=y1;
			x3=x2;
			y3=y2;
		}
		else
		{
			x=x2;
			y=y2;
			x3=x1;
			y3=y1;
		}
		while(x<x3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk=pk+(2*dy);
				if(y>y3)
					y=y-1;
				else
					y=y+1;
			}
			else
			{
				pk = pk+(2*(dy-dx));
			}
			x=x+1;
		}
	}
	//case when m is +ve and less than 1
	else if(0<m && m<=1)
	{
		pk=(2*dy)-dx;
		if(x1<x2)
		{
			x=x1;
			y=y1;
			x3=x2;
			y3=y2;
		}
		else
		{
			x=x2;
			y=y2;
			x3=x1;
			y3=y1;
		}
		while(x<x3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk=pk+(2*dy);
			}
			else
			{
				pk=pk+(2*(dy-dx));
				if(y<y3)
					y=y+1;
				else
					y=y-1;
			}
			x=x+1;
		}
	}
	//case when slope is >1 and +ve
	else if(m>1)
	{
		pk = (2*dy)-dx;
		if(y1<y2)
		{
			x=x1;
			y=y1;
			y3=y2;
			x3=x2;
		}
		else
		{
			x=x2;
			y=y2;
			y3=y1;
			x3=x1;
		}
		while(y<y3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk=pk+(2*dx);
				x=x;
			}
			else
			{
				pk = pk+(2*(dx-dy));
				if(x<x3)
					x=x+1;
				else
					x=x-1;
			}
			y=y+1;
		}
	}
	//case when slope is >1 and -ve
	else if(m<-1)
	{

		pk = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(y1<y2)
		{
			x=x1;
			y=y1;
			y3=y2;
			x3=x2;
		}
		else
		{
			x=x2;
			y=y2;
			y3=y1;
			x3=x1;
		}
		while(y<y3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk=pk-(dy*x1);
				if(x>x3)
					x=x-1;
				else
					x=x+1;
			}
			else
			{
				pk=pk-(dy*x1)-(3*dx*dy);
				x=x;
			}
			y=y+1;
		}
	}

}

void fill(int x, int y, int fcolor, int bcolor)
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


