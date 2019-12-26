#include<graphics.h>
#include<conio.h>
#include<stdio.h>

void main()
{
	int gd=DETECT,gm,mx,my;
	int x=0,y=0,p[]={150,50,180,20,180,120,150,150,150,50},t[]={200,100,100,200,300,200},r[]={100,200,300,200,300,400,100,400},door[]={125,300,165,300,165,400,125,400},window[]={220,300,260,300,260,350,220,350};
	int sky[]={0,0,639,0,639,479,0,479},grass[]={0,400,639,400,639,479,0,479};
	initgraph(&gd,&gm,"C:\\TC\\bgi");
	mx=getmaxx();
	my=getmaxy();
      //	printf("%d %d",mx,my);
	setcolor(YELLOW);
	rectangle(0,0,mx,my);
	setlinestyle(DOTTED_LINE,1,1);
	setfillstyle(SOLID_FILL,BLUE);
	fillpoly(4,sky);
	setfillstyle(SOLID_FILL,GREEN);
	fillpoly(4,grass);
	setcolor(RED);
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
      setcolor(YELLOW);
      circle(50,50,10);
      circle(50,50,20);

      setfillstyle(SOLID_FILL,RED);


	fillpoly(5,p);
	circle(200,200,100);
	fillpoly(3,t);
	setlinestyle(SOLID_LINE,1,1);
	setfillstyle(SOLID_FILL,BROWN);
	fillpoly(4,r);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	fillpoly(4,door);
	floodfill(150,350,WHITE);
	fillpoly(4,window);
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,100);
	outtextxy(120,410,"HOUSE");
	circle(350,350,10);
	line(350,360,350,390);
	line(350,370,360,360);
	line(350,370,340,360);
	line(350,390,360,410);
	line(350,390,340,410);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	ellipse(500,200,0,360,100,200);
	floodfill(460,120,WHITE);

	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(450,100,10);
	circle(550,100,10);
	ellipse(500,200,0,360,40,40);
	floodfill(455,105,BLACK);
	floodfill(555,105,BLACK);
	floodfill(505,205,BLACK);

	getch();
	closegraph();
}