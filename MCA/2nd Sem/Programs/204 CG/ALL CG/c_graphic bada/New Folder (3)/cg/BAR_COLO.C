#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void drawline(int x1,int y1,int x2,int y2);
void draw();
void bar_fill(int x, int y, int fcolor, int bcolor);

void main()
{
      int gd,gm;
      gd=DETECT;
      clrscr();
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      draw();
      getch();
      closegraph();
}

void draw()
{
      drawline(350,220,370,220);
      drawline(350,230,370,230);
      drawline(350,220,350,230);
      drawline(370,220,370,230);
      bar_fill(360,221,4,15);
      outtextxy(380,220,"Meghalaya = 2,964,009");

      drawline(350,240,370,240);
      drawline(350,250,370,250);
      drawline(350,240,350,250);
      drawline(370,240,370,250);
      bar_fill(360,241,1,15);
      outtextxy(380,240,"Tripura = 3,671,032");

      drawline(350,260,370,260);
      drawline(350,270,370,270);
      drawline(350,260,350,270);
      drawline(370,260,370,270);
      bar_fill(360,261,7,15);
      outtextxy(380,260,"Mizoram = 1,071,014");

      drawline(350,280,370,280);
      drawline(350,290,370,290);
      drawline(350,280,350,290);
      drawline(370,280,370,290);
      bar_fill(360,281,11,15);
      outtextxy(380,280,"Manipur = 2,721,756");

      drawline(350,300,370,300);
      drawline(350,310,370,310);
      drawline(350,300,350,310);
      drawline(370,300,370,310);
      bar_fill(360,301,5,15);
      outtextxy(380,300,"Nagaland = 1,980,602");


      drawline(350,320,370,320);
      drawline(350,330,370,330);
      drawline(350,320,350,330);
      drawline(370,320,370,330);
      bar_fill(360,321,6,15);
      outtextxy(380,323,"Arunachal Pradesh = 1,382,611");

      drawline(350,340,370,340);
      drawline(350,350,370,350);
      drawline(350,340,350,350);
      drawline(370,340,370,350);
      bar_fill(360,341,2,15);
      outtextxy(380,343,"Assam = 31,169,272");

      drawline(100,5,100,410);
      drawline(100,410,390,410);
      outtextxy(350,180,"Scale : 4 Unit =4,000,000 million");

      drawline(95,360,105,360);
      outtextxy(80,360,"4");

      drawline(95,310,105,310);
      outtextxy(80,310,"8");

      drawline(95,260,105,260);
      outtextxy(75,260,"12");

      drawline(95,210,105,210);
      outtextxy(75,210,"16");

      drawline(95,160,105,160);
      outtextxy(75,160,"20");

      drawline(95,110,105,110);
      outtextxy(75,110,"24");

      drawline(95,60,105,60);
      outtextxy(75,60,"28");

      drawline(95,10,105,10);
      outtextxy(75,10,"32");

      settextstyle(SMALL_FONT,1,5);
      drawline(50,180,50,260);
      outtextxy(40,100,"Population");

      settextstyle(SMALL_FONT,0,5);
      drawline(145,430,250,430);
      outtextxy(260,420,"States");


      drawline(145,20,145,410); //Assam
      drawline(175,20,175,410);
      drawline(145,20,175,20);
      bar_fill(150,380,2,WHITE);

      drawline(115,368,115,410);//Tripura
      drawline(145,368,145,410);
      drawline(115,368,145,368);
      bar_fill(120,400,1,WHITE);

      drawline(295,375,295,410);//Meghalaya
      drawline(325,375,325,410);
      drawline(295,375,325,375);
      bar_fill(300,390,4,WHITE);


      drawline(205,378,205,410);//Manipur
      drawline(235,378,235,410);
      drawline(205,378,235,378);
      bar_fill(215,380,3,WHITE);


      drawline(235,385,235,410); //Nagaland
      drawline(265,385,265,410);
      drawline(235,385,265,385);
      bar_fill(245,390,5,WHITE);

      drawline(265,390,265,410); //Arunachal Pradesh
      drawline(295,390,295,410);
      drawline(265,390,295,390);
      bar_fill(285,400,6,WHITE);

      drawline(175,398,175,410); //Mizoram
      drawline(205,398,205,410);
      drawline(175,398,205,398);
      bar_fill(180,400,7,WHITE);

      settextstyle(SMALL_FONT,0,5);
      outtextxy(110,440,"Fig: North-East India Population");
}
void drawline(int x1,int y1,int x2,int y2)
{
	int x,y;
	if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,WHITE);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,WHITE);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,WHITE);
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
