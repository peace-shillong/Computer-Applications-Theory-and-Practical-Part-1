#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>

struct point
	{
	  int x;
	  int y;
	}p[10],r1[4];

void curve(float x1,float y1, float x2, float y2,float dx,float dy, int c)
	{  float u,xu,yu;
	   for(u=0;u<=1;u+=.0001)
	    {
	    xu=x1*(2*u*u*u- 3*u*u+1)+x2*(-2*u*u*u+3*u*u)+dx*(u*u*u- 2*u*u+u)+0*(u*u*u -u*u);
	    yu=y1*(2*u*u*u-3*u*u+1)+y2*(-2*u*u*u+3*u*u)+dy*(u*u*u- 2*u*u+u)+0*(u*u*u -u*u);
	    putpixel(xu,yu,c);
	    }
	}

void hill()
	{
	 float dx, dy;
	 p[0].x=100 ;
	 p[0].y=120;
	 p[1].x= 250;
	 p[1].y=120;
	 p[2].x= 380;
	 p[2].y=120;
	 p[3].x= 490;
	 p[3].y=120;
	 p[4].x= 580;
	 p[4].y=120;
	 dx=150;
	 dy=-750;

	 int col=3,i;

	 for(i=0;i<4;i++)
	 curve(p[i].x,p[i].y,p[i+1].x,p[i+1].y,dx,dy,col);
	 curve(100,120, 580,120, 50,50,3);
	 //setcolor(BLUE);
	 setfillstyle(SOLID_FILL,CYAN);
	 floodfill(500,100,3);
	 setcolor(WHITE);
	}

/*void rod()
{
 int  col=WHITE;
 float dx=100 ,dy= -200;
 r1[0].x=10;
 r1[0].y=420;
 r1[1].x=600;
 r1[1].y=300;
 r1[2].x=20 ;
 r1[2].y=540;
 r1[3].x=600;
 r1[3].y=350;
 curve(r1[0].x,r1[0].y,r1[1].x,r1[1].y,dx,dy,col);
 curve(r1[2].x,r1[2].y,r1[3].x,r1[3].y,dx,dy,col);
 setfillstyle(SOLID_FILL,BLUE);

}*/
void tree()
	{
	 curve(80 ,380, 100, 250, 20, 60, 8);
	 curve(100, 250, 90,180, -350,200, 13);
	 curve(90, 180,140, 180, 100,-250, 13);
	 curve(140,180,140,250,300 ,50, 13);
	 curve(140,250,140,380,-60,25,8);
	 curve(110,250,120,270,30, 70, 8);
	 curve(130,250,120,270,-50,30,8);
	 curve(80,380,140,380,60,-150, 8);
	 curve(100,250,140,250,30,-80,13);
//	 setcolor(GREEN);
	 setfillstyle(SOLID_FILL,GREEN);
	 floodfill(100,180,13);
	 //setcolor(6);
	// setfillstyle(SOLID_FILL,6);
	 //floodfill(110,280,8);
	}

/*void tree1()
	{
	 curve(80+400 ,430, 100+400, 300, 20, 60, 8);
	 curve(100+400, 300, 90+400,230, -350,200, GREEN);
	 curve(90+400, 230,140+400, 230, 100,-250, GREEN);
	 curve(140+400,230,140+400,300,300 ,50, GREEN);
	 curve(140+400,300,140+400,430,-60,25,8);
	 curve(110+400,300,120+400,320,30, 70, 8);
	 curve(130+400,300,120+400,320,-50,30,8);
	 curve(80+400,430,140+400,430,60,-150, 8);
	 curve(100+400,300,140+400,300,30,-80,GREEN);
	 setcolor(2);
	 floodfill(500,230,GREEN);
 }*/

void main()
	{
	 float dx,dy;
	 int gd=DETECT, gm,i,n;
	 initgraph(&gd,&gm,"c:\\tc");
	 hill();
       //	 rod();
		tree();
	       //	tree1();
	 getch();
	}