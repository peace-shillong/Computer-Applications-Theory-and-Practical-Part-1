#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

void draw_line(int x1,int y1,int x2,int y2);
void draw_circle(int x,int y,int radius);
void drawclock();

void main()
{
	int gdriver=DETECT ,gmode;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	 clrscr();
	cleardevice();

	drawclock() ;
	getch();
	closegraph();
}

/*Draw clock steps method */

void drawclock()
{
	setcolor(RED);
	setcolor(WHITE);

	/*CLOCK CIRCLES*/
	setcolor(RED);
	draw_circle(320,240,3);
	draw_line(320,240,370,250);
	draw_line(320,240,290,290);
	draw_line(320,240,370,240);
	setcolor(10);
	//outline of the clock
	draw_circle(320,240,102);
	draw_circle(320,240,100);
	draw_circle(320,240,70);

	/*CLOCK NUMBERS*/
	outtextxy(300,200,"QUARTZ");
	outtextxy(317,150,"12.");
	outtextxy(360,160,"1.");
	outtextxy(389,190,"2.");
	outtextxy(360,310,"5.");
	outtextxy(265,310,"7.");
	outtextxy(400,230,"3.");
	outtextxy(317,319,"6.");
	outtextxy(230,230,"9.");
	outtextxy(390,280,"4.");
	outtextxy(240,280,"8.");
	outtextxy(240,190,"10.");
	outtextxy(270,160,"11.");
       //outline of the pendulum box
	draw_line(255,319,255,450);
	draw_line(253,319,253,450);
	draw_line(385,319,385,450);
	draw_line(383,319,383,450);
	draw_line(255,450,385,450);
	//pendulum
	 draw_line(310,340,310,382);
	draw_line(320,340,320,382);
	//circle of the pendulum
	draw_circle(315,400,18);
}
/*Function to draw line*/
void draw_line(int x1,int y1,int x2,int y2)
{
   int x,y;
   if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,YELLOW);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,YELLOW);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,YELLOW);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,YELLOW);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,YELLOW);

	}
}

/*Function to draw the circle*/
void draw_circle(int x,int y,int radius)
{
    int i;
    float new_y,new_x;
    for(i=-radius;i<=radius;i++)
    {
		new_y=(sqrt(radius*radius-i*i));
		putpixel(x+i,y+new_y,YELLOW);
		putpixel(x+i,y-new_y,YELLOW);
    }
    for(i=-radius;i<=radius;i++)
    {
		new_x=(sqrt(radius*radius-i*i));
		putpixel(x+new_x,y+i,YELLOW);
		putpixel(x-new_x,y+i,YELLOW);

    }
}
