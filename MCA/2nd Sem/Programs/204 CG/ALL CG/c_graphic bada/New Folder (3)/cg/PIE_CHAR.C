#include<stdio.h>
#include<conio.h>
#include<graphics.h>


void draw_line(int x1,int y1,int x2,int y2);
void draw_circle();
void main()
{
      int gd=DETECT,gm;
      clrscr();
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      draw_circle();

      setcolor(GREEN);
      outtextxy(200,150,"ASSAM (69.30%)");
      draw_line(250,200,350,200);

      draw_line(250,200,230,290);
      bar_fill(360,221,4,15);
      //setcolor(YELLOW);

      outtextxy(250,310,"TRIPURA (08.16%)");

      draw_line(250,200,270,300);
      setcolor(WHITE);
      outtextxy(295,290,"MEGHALAYA (06.59%)");

      draw_line(250,200,310,280);
      setcolor(GREEN);
      outtextxy(325,270,"MANIPUR (06.05%)");

      draw_line(250,200,340,250);
      setcolor(CYAN);
      outtextxy(345,240,"NAGALAND (04.40%)");

      draw_line(250,200,345,230);
      setcolor(BLUE);
      outtextxy(350,220,"ARUNACHAL PRADESH (03.07%)");

      draw_line(250,200,350,210);
      setcolor(RED);
      outtextxy(355,202,"MIZORAM (02.43%)");

      draw_line(135,345,490,345);
      setcolor(WHITE);
      outtextxy(140,350,"PIE-CHART REPRESENTING NORTHEAST POPULATION");
      draw_line(135,365,490,365);

      getch();
      closegraph();
}
void draw_line(int x1,int y1,int x2,int y2)
{
	int x,y,dx,dy,pk,i,x3,y3,dk;
	float m=0;
	dx = x2-x1; dy = y2-y1;
	x = x1;y = y1;
	if(dx!=0)
		m = (float)dy/(float)dx;
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
				x = x2;
				y = y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,RED);
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
					putpixel(x,y,GREEN);
					x= x+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,BLUE);
					x= x+1;
				}
			}
		}
	}
	else if((m>=-1)&&(m<0))
	{
		pk = (2*dy)-dx;
		if(x1<x2)
		{
			x = x1;
			y = y1;
			x3 = x2;
		}
		else
		{
			x = x2;
			y= y2;
			x3=x1;
		}
		while(x<x3)
		{
			putpixel(x,y,CYAN);
			if(pk<0)
			{
				pk = pk+(2*dy);
				y = y-1;
			}
			else
			{
				pk = pk+(2*(dy-dx));
			}
			x = x+1;
		}
	}
	else if((m>0)&&(m<=1))
	{
		pk = (2*dy)-dx;
		if(x1<x2)
		{
			x = x1;
			y = y1;
			x3 = x2;
		}
		else
		{
			x = x2;
			y= y2;
			x3 = x1;
		}
		while(x<x3)
		{
			putpixel(x,y,YELLOW);
			if(pk<0)
			{
				pk = pk+(2*dy);
			}
			else
			{
				pk = pk+(2*(dy-dx));
				y = y+1;
			}
			x = x+1;
		}
	}
	else if(m>1)
	{

		pk = (2*dy)-dx;
		if(y1<y2)
		{
			x= x1;
			y = y1;
			y3 = y2;
		}
		else
		{
			x = x2;
			y = y2;
			y3 = y1;
		}
		while(y<y3)
		{
			putpixel(x,y,CYAN);
			if(pk<0)
			{
				pk = pk+(2*dx);
				x = x;
			}
			else
			{
				pk = pk+(2*(dx-dy));
				x = x+1;
			}
			y = y+1;
		}
	}
	else if(m<-1)
	{

		dk = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(y1<y2)
		{
			x= x1;
			y = y1;
			y3 = y2;
		}
		else
		{
			x = x2;
			y = y2;
			y3 = y1;
		}
		while(y<y3)
		{
			putpixel(x,y,RED);
			if(dk<0)
			{
				dk = dk-(dy*x1);
				x = x-1;
			}
			else
			{
				dk = dk-(dy*x1)-(3*dx*dy);
				x = x;
			}
			y = y+1;
		}
	}

}

void draw_circle()
{
	int xc,yc,r;
	int x,maxx,i,y,pk;
	xc=250;
	yc=200;
	r=100;
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
		putpixel(xc+y,yc+x,RED);
		putpixel(xc+y,yc-x,GREEN);
		putpixel(xc+x,yc-y,BLUE);
		putpixel(xc-x,yc-y,CYAN);
		putpixel(xc-y,yc-x,YELLOW);
		putpixel(xc-y,yc+x,BLUE);
		putpixel(xc-x,yc+y,RED);
	}
}

