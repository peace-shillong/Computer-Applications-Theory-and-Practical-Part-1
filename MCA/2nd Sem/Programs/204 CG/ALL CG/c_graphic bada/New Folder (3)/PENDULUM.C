#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void boundaryfill(int x, int y, int fcolor, int bcolor);
void drawline(int x1,int y1,int x2,int y2,int);
void rotate(int,int,int);
void drawcircle(int,int,int,int);
void main()
{
      int gd,gm,xc,yc,r,x,y;
      gd=DETECT;
      clrscr();
      xc=300;
      yc=120;
      r=100;
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      drawcircle(xc,yc,r,WHITE);
      drawcircle(xc,yc,r-20,WHITE);
      boundaryfill(xc+1,yc+1,6,WHITE);
      outtextxy(xc,yc-70,"12");
      outtextxy(xc+70,yc,"3");
      outtextxy(xc,yc+70,"6");
      outtextxy(xc-70,yc,"9");
      //putpixel(xc,yc,WHITE);
      drawline(xc,yc,xc+30,yc,GREEN); //hr
      drawline(xc,yc,xc+40,yc+15,GREEN);//min
      drawline(xc,yc,xc+50,yc+30,GREEN);  //sec
      drawline(xc,yc+100,xc,yc+200,WHITE);
      //rotate(&x,&y,30);
      drawcircle(xc,yc+220,20,WHITE);

      boundaryfill(301,341,6,WHITE);
      drawline(xc-60,yc+79,xc-60,yc+280,WHITE);
      drawline(xc-55,yc+82,xc-55,yc+275,WHITE);
      drawline(xc+60,yc+79,xc+60,yc+280,WHITE);
      drawline(xc+55,yc+82,xc+55,yc+275,WHITE);
      drawline(xc-60,yc+280,xc+60,yc+280,WHITE);
      drawline(xc-55,yc+275,xc+55,yc+275,WHITE);
      getch();
      closegraph();
}
void boundaryfill(int x, int y, int fcolor, int bcolor)
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
void drawline(int x1,int y1,int x2,int y2,int colr)
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
	//case when slop is 0
	if(m==0)
	{
		if(x1==x2)
		{
			if(y1<y2)
			{
				for(i=y1;i<=y2;i++)
				{
					putpixel(x,y,colr);
					y = y+1;
				}
			}
			else
			{
				x=x2;
				y=y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,colr);
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
					putpixel(x,y,colr);
					x= x+1;
				}
			}
			else
			{
				x=x2;
				y=y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,colr);
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
			putpixel(x,y,colr);
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
			putpixel(x,y,colr);
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
	//case when slop is >1 and +ve
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
			putpixel(x,y,colr);
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
	//case when slop is >1 and -ve
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
			putpixel(x,y,colr);
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
void drawcircle(int xc,int yc,int r,int col)
{
	//int xc,yc,r;
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
		putpixel(xc+x,yc+y,col);
		putpixel(xc+y,yc+x,col);
		putpixel(xc+y,yc-x,col);
		putpixel(xc+x,yc-y,col);
		putpixel(xc-x,yc-y,col);
		putpixel(xc-y,yc-x,col);
		putpixel(xc-y,yc+x,col);
		putpixel(xc-x,yc+y,col);
		putpixel(xc-r,yc,col);
		putpixel(xc+r,yc,col);
	}

}
/*void rotate(int *x,int *y,int theta)
{
	int x1=*x,y1=*y;
	x1=cos(theta)*x1-sin(theta)*y1;
	y1=sin(theta)*x1+sin(theta)*y1;
	*x=x1;*y=y1;
} */

