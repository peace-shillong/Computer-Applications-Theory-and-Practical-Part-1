#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void draw_line(float ,float ,float ,float );
void main()
{

    int x,y,i,j;
    int d=DETECT,gm;
    initgraph(&d,&gm,"c:\\tc\\bgi");
    outtextxy(50,50,"HOUSE");

    //House outer frame
    draw_line(150,100,100,150);
    draw_line(110,140,110,250);

    draw_line(110,250,190,250);
    draw_line(110,250,50,350);
    draw_line(190,250,130,350);
    //draw_line(140,200,150,150);
   // draw_line(100,250,150,200);
    draw_line(190,140,190,250);
    for(i=0;i<300;i++)
    {
	draw_line(150+i,100-(i/6),200+i,150-(i/6));
    }
    draw_line(150,100,450,50);
    draw_line(450,50,500,100);
    draw_line(500,100,200,150);
    draw_line(500,100,500,180);
    draw_line(190,250,500,180);
    draw_line(400,40,430,40);
    draw_line(400,40,400,100);

    //chimni
    draw_line(430,40,430,100);
    draw_line(400,90,430,80);
    draw_line(400,70,430,60);

    //door
    draw_line(130,200,170,200);
    draw_line(150,200,150,250);
    draw_line(130,200,130,250);
    draw_line(170,200,170,250);
    outtextxy(140,225,"o");
    outtextxy(155,225,"o");

    //antenna
    draw_line(125,75,125,125);
    draw_line(126,75,126,126);
    draw_line(100,85,150,65);
    draw_line(100,85,150,65);

    //codes for the window
      //1st window
      draw_line(250,160,300,150);
      draw_line(300,150,300,200);
      draw_line(300,200,250,210);
      draw_line(250,160,250,210);
      draw_line(250,185,300,175);
      draw_line(275,155,275,205);
     //2nd window

      draw_line(400,130,450,120);
      draw_line(450,120,450,170);
      draw_line(450,170,400,180);
      draw_line(400,130,400,180);
      draw_line(400,155,450,145);
      draw_line(425,125,425,175);

      //fencing
	for(i=10;i<115;i=i+5)
	{
		draw_line(i,180-20,i,180+20);
	}
	for(i=0;i<100;i=i+5)
	{
		draw_line(5+(i/2),160+i,5+(i/2),300+i);
	       //	draw_line(15,160,15,400);
	}
	for(i=500;i<1000;i=i+5)
	{
		draw_line(i,180-10,i,180+10);
	}
	for(i=0;i<500;i=i+5)
	{
		draw_line(150+i,290-i/4,150+i,400-i/4);
	}
	getch();
	closegraph();
}

void draw_line(float x1,float y1,float x2,float y2)
{
   int x,y;
   if(x1<x2)

	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,BROWN);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,BROWN);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,GREEN);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,RED);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,RED);

	}
}