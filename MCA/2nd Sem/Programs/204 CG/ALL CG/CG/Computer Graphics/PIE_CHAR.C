#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void dline(int,int,int,int);
void dcircle();
void fillp(int,int,int,int);

void main()
{
      int driver=DETECT,mode;
      clrscr();

      initgraph(&driver,&mode,"c:\\tc\\bgi");

      dcircle();

      dline(200,200,250,290);
      dline(200,200,230,295); //Arunachal Pradesh
      dline(200,200,208,300); //Mizoram
      dline(200,200,285,255);//Meghalaya
      dline(200,200,300,200);//Tripura
      dline(200,200,200,300);//Assam
      dline(200,200,272,140);

      fillp(185,200,1,WHITE);//Assam
      fillp(270,195,3,WHITE);//Tripura
      fillp(230,210,5,WHITE);//Meghalaya
      fillp(283,220,5,WHITE);

      fillp(250,250,7,WHITE);//Manipur
      fillp(220,220,7,WHITE);
      fillp(210,210,7,WHITE);
      fillp(205,205,7,WHITE);

      fillp(206,213,2,WHITE);//Nagaland
      fillp(232,275,2,WHITE);
      fillp(225,262,2,WHITE);
      fillp(216,233,2,WHITE);
      fillp(209,217,2,WHITE);
      fillp(212,222,2,WHITE);

      fillp(204,225,4,WHITE); //Arunachal Pradesh
      fillp(209,250,4,WHITE);
      fillp(215,280,4,WHITE);


      fillp(205,295,6,WHITE);//Mizoram
      fillp(201,290,6,WHITE);

      outtextxy(150,410,"Fig:- Pie-Chart: Northeast Population");
      dline(370,220,390,220);
      dline(370,230,390,230);
      dline(370,220,370,230);
      dline(390,220,390,230);
      fillp(371,221,1,15);
      outtextxy(400,220,"Assam=69.30%");

     dline(370,240,390,240);
      dline(370,250,390,250);
      dline(370,240,370,250);
      dline(390,240,390,250);
      fillp(371,241,3,15);
      outtextxy(400,240,"Tripura=8.16%");

      dline(370,260,390,260);
      dline(370,270,390,270);
      dline(370,260,370,270);
      dline(390,260,390,270);
      fillp(371,261,5,15);
      outtextxy(400,260,"Meghalaya=6.59%");

    dline(370,280,390,280);
      dline(370,290,390,290);
      dline(370,280,370,290);
      dline(390,280,390,290);
      fillp(371,281,7,15);
      outtextxy(400,280,"Manipur=6.05%");

      dline(370,300,390,300);
      dline(370,310,390,310);
      dline(370,300,370,310);
      dline(390,300,390,310);
      fillp(371,301,2,15);
      outtextxy(400,300,"Nagaland=4.40%");

      dline(370,320,390,320);
      dline(370,330,390,330);
      dline(370,320,370,330);
      dline(390,320,390,330);
      fillp(371,321,4,15);
      outtextxy(400,323,"Arunachal Pradesh=3.07%");

      dline(370,340,390,340);
      dline(370,350,390,350);
      dline(370,340,370,350);
      dline(390,340,390,350);
      fillp(371,341,6,15);
      outtextxy(400,343,"Mizoram=2.43%");

      getch();
      closegraph();
}

void dline(int x1,int y1,int x2,int y2)
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

void dcircle()
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

void fillp(int x, int y, int fcolor, int bcolor)
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


