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

    //House outer frame
    draw_line(150,100,100,150);
    draw_line(110,140,110,250);
    draw_line(110,250,190,250);
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

    //chymney
    draw_line(430,40,430,100);
    draw_line(400,90,430,80);
    draw_line(400,70,430,60);

    //door
    draw_line(130,200,170,200);
    draw_line(160,200,160,250);
    draw_line(130,200,130,250);
    draw_line(170,200,170,250);

    draw_line(140,210,150,210);
    draw_line(140,220,150,220);
    draw_line(140,210,140,220);
    draw_line(150,210,150,220);
    //floor
    draw_line(130,250,170,250);
    draw_line(120,280,130,250);
    draw_line(170,250,160,280);
    draw_line(120,280,160,280);

//    draw_line();

  //  outtextxy(140,225,"o");
   // outtextxy(155,225,"o");

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
      draw_line(272,155,272,205);
      draw_line(275,155,275,205);
     //2nd window

      draw_line(400,130,450,120);
      draw_line(450,120,450,170);
      draw_line(450,170,400,180);
      draw_line(400,130,400,180);
      draw_line(422,125,422,175);
      draw_line(425,125,425,175);

      //fencing
	for(i=10;i<115;i=i+5)
	{
		draw_line(i,160,i,200);
	}
	for(i=0;i<115;i=i+5)
	{
		draw_line(5+(i/2),160+i,5+(i/2),300+i);
	}

	for(i=500;i<1000;i=i+5)
	{
		draw_line(i,160,i,200);
	}
	for(i=0;i<500;i=i+5)
	{
		draw_line(150+i,290-i/5,150+i,400-i/5);
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