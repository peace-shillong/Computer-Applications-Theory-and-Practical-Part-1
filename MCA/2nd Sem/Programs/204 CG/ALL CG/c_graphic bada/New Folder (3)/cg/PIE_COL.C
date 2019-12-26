#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void draw_line(int,int,int,int);
void draw_circle();
void pie_fill(int,int,int,int);

void main()
{
      int driver=DETECT,mode;
      clrscr();

      initgraph(&driver,&mode,"c:\\tc\\bgi");

      draw_circle();

      draw_line(200,200,250,290);
      draw_line(200,200,230,295); //Arunachal Pradesh
      draw_line(200,200,208,300); //Mizoram
      draw_line(200,200,285,255);//Meghalaya
      draw_line(200,200,300,200);//Tripura
      draw_line(200,200,200,300);//Assam
      draw_line(200,200,272,140);

      pie_fill(185,200,5,WHITE);//Assam
      pie_fill(270,195,6,WHITE);//Tripura
      pie_fill(230,210,7,WHITE);//Meghalaya
      pie_fill(283,220,7,WHITE);

      pie_fill(250,250,4,WHITE);//Manipur
      pie_fill(220,220,4,WHITE);
      pie_fill(210,210,4,WHITE);
      pie_fill(205,205,4,WHITE);

      pie_fill(206,213,3,WHITE);//Nagaland
      pie_fill(232,275,3,WHITE);
      pie_fill(225,262,3,WHITE);
      pie_fill(216,233,3,WHITE);
      pie_fill(209,217,3,WHITE);
      pie_fill(212,222,3,WHITE);

      pie_fill(204,225,2,WHITE); //Arunachal Pradesh
      pie_fill(209,250,2,WHITE);
      pie_fill(215,280,2,WHITE);


      pie_fill(205,295,1,WHITE);//Mizoram
      pie_fill(201,290,1,WHITE);

      draw_line(130,430,470,430);
      draw_line(130,432,470,432);
      outtextxy(150,410,"Fig:- Pie-Chart: Northeast Population");

      draw_line(370,220,390,220);
      draw_line(370,230,390,230);
      draw_line(370,220,370,230);
      draw_line(390,220,390,230);
      pie_fill(371,221,5,15);
      outtextxy(400,220,"Assam=69.30%");

      draw_line(370,240,390,240);
      draw_line(370,250,390,250);
      draw_line(370,240,370,250);
      draw_line(390,240,390,250);
      pie_fill(371,241,6,15);
      outtextxy(400,240,"Tripura=8.16%");

      draw_line(370,260,390,260);
      draw_line(370,270,390,270);
      draw_line(370,260,370,270);
      draw_line(390,260,390,270);
      pie_fill(371,261,7,15);
      outtextxy(400,260,"Meghalaya=6.59%");

      draw_line(370,280,390,280);
      draw_line(370,290,390,290);
      draw_line(370,280,370,290);
      draw_line(390,280,390,290);
      pie_fill(371,281,4,15);
      outtextxy(400,280,"Manipur=6.05%");

      draw_line(370,300,390,300);
      draw_line(370,310,390,310);
      draw_line(370,300,370,310);
      draw_line(390,300,390,310);
      pie_fill(371,301,3,15);
      outtextxy(400,300,"Nagaland=4.40%");

      draw_line(370,320,390,320);
      draw_line(370,330,390,330);
      draw_line(370,320,370,330);
      draw_line(390,320,390,330);
      pie_fill(371,321,2,15);
      outtextxy(400,323,"Arunachal Pradesh=3.07%");

      draw_line(370,340,390,340);
      draw_line(370,350,390,350);
      draw_line(370,340,370,350);
      draw_line(390,340,390,350);
      pie_fill(371,341,1,15);
      outtextxy(400,343,"Mizoram=2.43%");

      draw_line(350,200,600,200);
      draw_line(350,370,600,370);
      draw_line(350,200,350,370);
      draw_line(600,200,600,370);

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
					putpixel(x,y,WHITE);
					y = y+1;
				}
			}
			else
			{
				x = x2;y = y2;
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
				x = x2;y = y2;
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
			x = x1;y = y1;x3 = x2;
		}
		else
		{
			x = x2;y= y2;x3=x1;
		}
		while(x<x3)
		{
			putpixel(x,y,WHITE);
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
			putpixel(x,y,WHITE);
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
	//case when slope is >1 and +ve
	else if(m>1)
	{
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
			putpixel(x,y,WHITE);
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
	//case when slope is >1 and -ve
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
			putpixel(x,y,WHITE);
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
	xc=200;yc=200;r=100;
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
	}
	putpixel(100,200,WHITE);
	putpixel(200,100,WHITE);
}

void pie_fill(int x, int y, int fcolor, int bcolor)
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


