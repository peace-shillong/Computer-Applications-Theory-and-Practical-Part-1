#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void drawline(int x1,int y1,int x2,int y2);
void drawcircle();
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

void main()
{
      int gd,gm;
      gd=DETECT;
      clrscr();
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      drawcircle();
      //outtextxy(200,150,"Assam =69.30%");
      drawline(250,200,350,200);
      drawline(250,200,220,295);
      boundaryfill(251,199,2,WHITE);
      boundaryfill(215,202,2,WHITE);

      //drawline(250,303,250,320);//arrow
      //drawline(250,303,247,309);//arrow
      //drawline(250,303,253,309);//arrow
      //outtextxy(240,325,"Tripura =08.16%");
      drawline(250,200,270,300);
      boundaryfill(249,202,4,WHITE);

      //outtextxy(295,290,"<-Meghalaya =06.59%");
      drawline(250,200,310,280);
      boundaryfill(255,208,5,WHITE);
      boundaryfill(260,230,5,WHITE);
      boundaryfill(275,285,5,WHITE);

      boundaryfill(310,240,6,WHITE);
      //outtextxy(325,270,"<-Manipur =06.05%");
      drawline(250,200,340,250);

      //outtextxy(345,240,"<-Nagaland =04.40%");
      drawline(250,200,345,230);
      boundaryfill(260,205,1,WHITE);
      boundaryfill(270,210,1,WHITE);
      boundaryfill(280,211,1,WHITE);
      boundaryfill(290,220,1,WHITE);
      boundaryfill(300,220,1,WHITE);
      boundaryfill(310,220,1,WHITE);
      boundaryfill(337,245,1,WHITE);

      //outtextxy(350,220,"<-Arunachal Pradesh =03.07%");
      drawline(250,200,350,210);
      boundaryfill(270,204,11,WHITE);
      boundaryfill(300,215,11,WHITE);
      boundaryfill(345,215,11,WHITE);

      //outtextxy(355,202,"<-Mizoram =02.43%");
      boundaryfill(345,201,12,WHITE);

      drawline(410,180,425,180);
      drawline(410,180,410,195);
      drawline(410,195,425,195);
      drawline(425,180,425,195);
      boundaryfill(411,194,2,WHITE);
      outtextxy(430,185,"= Assam(69.30 %)");

      drawline(410,210,425,210);
      drawline(410,210,410,225);
      drawline(410,225,425,225);
      drawline(425,210,425,225);
      boundaryfill(411,224,4,WHITE);
      outtextxy(430,215,"= Tripura(08.16 %)");

      drawline(410,240,425,240);
      drawline(410,240,410,255);
      drawline(410,255,425,255);
      drawline(425,240,425,255);
      boundaryfill(411,254,5,WHITE);
      outtextxy(430,245,"= Meghalaya(06.59 %)");

      drawline(410,270,425,270);
      drawline(410,270,410,285);
      drawline(410,285,425,285);
      drawline(425,270,425,285);
      boundaryfill(411,284,6,WHITE);
      outtextxy(430,275,"= Manipur(06.05 %)");

      drawline(410,300,425,300);
      drawline(410,300,410,315);
      drawline(410,315,425,315);
      drawline(425,300,425,315);
      boundaryfill(411,314,1,WHITE);
      outtextxy(430,305,"= Nagaland(04.40 %)");

      drawline(410,330,425,330);
      drawline(410,330,410,345);
      drawline(410,345,425,345);
      drawline(425,330,425,345);
      boundaryfill(411,344,11,WHITE);
      outtextxy(430,335,"=Arunachal Pradesh(03.07%)");

      drawline(410,360,425,360);
      drawline(410,360,410,375);
      drawline(410,375,425,375);
      drawline(425,360,425,375);
      boundaryfill(411,374,12,WHITE);
      outtextxy(430,365,"= Mizoram(02.43 %)");

      outtextxy(140,410,"Fig: Pie_Chart of North_East Population");
      drawline(140,420,450,420);
      getch();
      closegraph();
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
	//case when slop is 0
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
void drawcircle()
{
	int xc,yc,r;
	int x,maxx,i,y,pk;
	xc=250;yc=200;r=100;
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
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+y,yc+x,WHITE);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc-y,yc-x,WHITE);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-r,yc,WHITE);
		putpixel(xc+r,yc,WHITE);
	}

}


