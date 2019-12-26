#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void drawline(int x1,int y1,int x2,int y2);
void drawcircle(int xc,int yc,int rad);
void fill(int,int,int,int);

void main()
{
	int driver=DETECT,mode;
	clrscr();
	initgraph(&driver,&mode,"C:\\tc\\bgi");
	setcolor(BLUE);

//clock boundary line

	drawline(200,20,300,20);
	drawline(200,20,170,50);
	drawline(300,20,330,50);
	drawline(170,50,170,150);
	drawline(170,150,200,180);
	drawline(200,180,300,180);
	drawline(330,50,330,150);
	drawline(330,150,300,180);

	drawline(203,30,297,30);
	drawline(180,53,180,147);
	drawline(203,30,180,53);
	drawline(320,53,320,147);
	drawline(297,30,320,53);
	drawline(203,170,297,170);
	drawline(180,147,203,170);
	drawline(320,147,297,170);

	outtextxy(240,33,"12");
	outtextxy(247,160,"6");
	outtextxy(185,95,"9");
	outtextxy(310,95,"3");
	putpixel(250,100,WHITE);

	drawline(250,100,260,90); //second hand
	drawline(250,100,280,100);//hour hand
	drawline(250,100,230,80); //min hand

	drawline(210,180,210,300);
	drawline(205,180,205,300);
	drawline(290,180,290,300);
	drawline(295,180,295,300);
	drawline(205,300,210,300);
	drawline(290,300,295,300);
//stand
	drawline(190,290,205,290);
	drawline(295,290,310,290);

	drawline(170,330,330,330);
	drawline(190,290,170,330);
	drawline(310,290,330,330);
	drawline(210,290,290,290);

	fill(200,300,3,15);
	fill(220,295,3,15);
	fill(300,293,3,15);

//2nd box
	drawline(170,350,330,350);
	drawline(170,350,170,330);
	drawline(330,330,330,350);
	drawline(210,195,240,195);
	drawline(260,195,290,195);
	fill(250,340,15,15);

      //pendulum
	drawline(250,180,250,240);
	drawcircle(250,250,10);

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

