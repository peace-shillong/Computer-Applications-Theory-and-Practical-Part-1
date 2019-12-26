#include<graphics.h>
#include<conio.h>
#include<stdio.h>

void main()
{
	int gd=DETECT,gm,mx,my;
	int x=0,y=0;
	initgraph(&gd,&gm,"C:\\TC\\bgi");
	mx=getmaxx();
	my=getmaxy();

	setlinestyle(DOTTED_LINE,1,1);
	//setcolor(RED);
      while((x<=mx)&&(y<=my))
      {
      line(x,y,x,my);
      x=x+50;
      }
      x=0;
      while((x<=mx)&&(y<=my))
      {
      line(x,y,mx,y);
      y=y+50;
      }
	getch();
}