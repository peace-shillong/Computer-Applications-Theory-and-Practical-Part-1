#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>

void polydraw(float x1,float y1,float x2,float y2)
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
			putpixel(x,y,RED);
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
				putpixel(x,y,RED);
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
void drawcircle(int xc,int yc,int r)
{
	int x,maxx,i,y,pk;
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
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc-y,RED);
		putpixel(xc-y,yc-x,RED);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc-x,yc+y,WHITE);
	}
}

void main()
 {
 int gd=DETECT,i=0,j=0;
 initgraph(&gd,&gd,"c:\\turboc3\\bgi");
 while(!kbhit())
 {
	for(j=0;j<2;j++)
	{
		 for(i=0;i<400;i+=1)
		{
			setcolor(RED);
			//truck body
			polydraw(50+i,100+j*100,200+i,100+j*100);
			polydraw(200+i,100+j*100,250+i,100+j*100);
			polydraw(200+i,100+j*100,200+i,200+j*100);
			polydraw(50+i,200+j*100,250+i,200+j*100);

			polydraw(50+i,100+j*100,50+i,200+j*100);
			//polydraw(125+i,110+j*100,125+i,195+j*100);
			polydraw(250+i,100+j*100,250+i,200+j*100);

			polydraw(100+i,120+j*100,120+i,120+j*100);
			polydraw(100+i,150+j*100,120+i,150+j*100);
			polydraw(100+i,120+j*100,100+i,150+j*100);
			polydraw(120+i,120+j*100,120+i,150+j*100);

			polydraw(70+i,120+j*100,90+i,120+j*100);
			polydraw(70+i,150+j*100,90+i,150+j*100);
			polydraw(70+i,120+j*100,70+i,150+j*100);
			polydraw(90+i,120+j*100,90+i,150+j*100);

			polydraw(130+i,120+j*100,150+i,120+j*100);
			polydraw(130+i,150+j*100,150+i,150+j*100);
			polydraw(130+i,120+j*100,130+i,150+j*100);
			polydraw(150+i,120+j*100,150+i,150+j*100);

			polydraw(160+i,120+j*100,190+i,120+j*100);
			polydraw(160+i,200+j*100,190+i,200+j*100);
			polydraw(160+i,120+j*100,160+i,200+j*100);
			polydraw(190+i,120+j*100,190+i,200+j*100);

			polydraw(215+i,120+j*100,235+i,120+j*100);
			polydraw(215+i,150+j*100,235+i,150+j*100);
			polydraw(215+i,120+j*100,215+i,150+j*100);
			polydraw(235+i,120+j*100,235+i,150+j*100);
			//front body
			polydraw(250+i,150+j*100,290+i,150+j*100);
			polydraw(250+i,200+j*100,290+i,200+j*100);
			polydraw(290+i,150+j*100,290+i,200+j*100);
			setfillstyle(SOLID_FILL,BROWN);
			floodfill(160+i,150+j*100,WHITE);

			setfillstyle(SOLID_FILL,CYAN);
			floodfill(205+i,110+j*100,WHITE);

			setfillstyle(SOLID_FILL,BROWN);
			floodfill(255+i,155+j*100,WHITE);
			//tyres

			drawcircle(110+i,215+j*100,15);
			drawcircle(110+i,215+j*100,10);

			polydraw(95+i,215+j*100,95+i,215+j*100);
			polydraw(100+i,215+j*100,100+i,215+j*100);
			polydraw(110+i,200+j*100,110+i,200+j*100);
			polydraw(110+i,205+j*100,110+i,205+j*100);
			polydraw(125+i,215+j*100,125+i,215+j*100);
			polydraw(120+i,215+j*100,120+i,215+j*100);
			polydraw(110+i,225+j*100,110+i,225+j*100);
			polydraw(110+i,230+j*100,110+i,230+j*100);
			//setfillstyle(SOLID_FILL,DARKGRAY);
			//floodfill(112+i,212+j*100,GREEN);

			circle(250+i,215+j*100,15);
			circle(250+i,215+j*100,10);
			polydraw(235+i,215+j*100,235+i,215+j*100);
			polydraw(240+i,215+j*100,240+i,215+j*100);
			polydraw(250+i,200+j*100,250+i,200+j*100);
			polydraw(250+i,205+j*100,250+i,205+j*100);
			polydraw(265+i,215+j*100,265+i,215+j*100);
			polydraw(260+i,215+j*100,260+i,215+j*100);
			polydraw(250+i,225+j*100,250+i,225+j*100);
			polydraw(250+i,230+j*100,250+i,230+j*100);
			//setfillstyle(SOLID_FILL,BROWN);
			//floodfill(250+i,215+j*100,WHITE);

			clearviewport();
			if(kbhit()) break;
		}
	}
 }
 closegraph();

}