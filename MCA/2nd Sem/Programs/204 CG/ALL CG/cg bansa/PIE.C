#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void drawline(int,int,int,int);

void drawcircle();
void main()
{
      int driver=DETECT,mode;
      clrscr();

      initgraph(&driver,&mode,"c:\\tc\\bgi");

      drawcircle();

      outtextxy(170,180,"Assam =69.30%");
      drawline(250,200,350,200);
      drawline(250,200,230,290);
      outtextxy(240,310,"Tripura =08.16%");
      drawline(250,200,270,300);
      outtextxy(295,290,"Meghalaya =06.59%");
      drawline(250,200,310,280);
      outtextxy(325,270,"Manipur =06.05%");
      drawline(250,200,340,250);
      outtextxy(345,240,"Nagaland =04.40%");
      drawline(250,200,345,230);
      outtextxy(350,220,"Arunachal Pradesh =03.07%");
      drawline(250,200,350,210);
      outtextxy(355,202,"Mizoram =02.43%");

      outtextxy(150,410,"Diagram: Pie-Chart");
      drawline(150,420,300,420);
      drawline(30,30,600,30);
      drawline(30,30,30,450);
      drawline(30,450,600,450);
      drawline(600,30,600,450);
      drawline(50,50,580,50);
      drawline(50,50,50,430);
      drawline(50,430,580,430);
      drawline(580,50,580,430);
      getch();
      closegraph();
}
void drawline(int x1,int y1,int x2,int y2)
{
	int x,y,dx,dy,pk,i,x3,y3,dk;
	float m=0;
	dx = x2-x1; dy = y2-y1;
	x = x1;y = y1;
	if(dx!=0)
	{
		m = (float)dy/(float)dx;
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
					putpixel(x,y,YELLOW);
					y = y+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,YELLOW);
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
					putpixel(x,y,YELLOW);
					x= x+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,YELLOW);
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
			x = x1;y = y1;x3 = x2;
		}
		else
		{
			x = x2;y= y2;x3=x1;
		}
		while(x<x3)
		{
			putpixel(x,y,YELLOW);
			if(pk<0)
			{
				pk = pk+(2*dy);
				y = y-1;
			}
			else
			{
				pk = pk+(2*(dy-dx));
			}
			x  = x+1;
		}
	}
	//case when m is +ve and less than 1
	else if(0<m&&m<=1)
	{
		pk = (2*dy)-dx;
		if(x1<x2)
		{
			x = x1;y = y1,x3 = x2;
		}
		else
		{
			x = x2;y= y2;x3 = x1;
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
			x  = x+1;
		}
	}
	//case when slop is >1 and +ve
	else if(m>1)
	{

		//ck = -dy*x1-2*dx*y1-2*dy*x1-2*dy-3*dx*dy;
		pk = (2*dy)-dx;
		if(y1<y2)
		{
			x= x1;y = y1;y3 = y2;
		}
		else
		{
			x = x2;y = y2;y3 = y1;
		}
		while(y<y3)
		{
			putpixel(x,y,YELLOW);
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
	//case when slop is >1 and -ve
	else if(m<-1)
	{

		dk = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(y1<y2)
		{
			x= x1;y = y1;y3 = y2;
		}
		else
		{
			x = x2;y = y2;y3 = y1;
		}
		while(y<y3)
		{
			putpixel(x,y,YELLOW);
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
		putpixel(xc+x,yc+y,RED);
		putpixel(xc+y,yc+x,RED);
		putpixel(xc+y,yc-x,RED);
		putpixel(xc+x,yc-y,RED);
		putpixel(xc-x,yc-y,RED);
		putpixel(xc-y,yc-x,RED);
		putpixel(xc-y,yc+x,RED);
		putpixel(xc-x,yc+y,RED);
	}
}


