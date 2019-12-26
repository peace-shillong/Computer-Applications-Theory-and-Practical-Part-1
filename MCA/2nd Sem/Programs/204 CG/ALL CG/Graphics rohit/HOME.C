
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>


void drawline(int x1,int y1,int x2,int y2)
{
  int dx,dy,m,s;
  float xi,yi,x,y;
   dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
 s = abs(dx);
    else
 s = abs(dy);

    xi = dx / (float) s;
    yi = dy / (float) s;

    x = x1;
    y = y1;

    putpixel(x1, y1, WHITE);

    for (m = 0; m < s; m++)
{
 x += xi;
 y += yi;
 putpixel(x, y, WHITE);
    }

}
/*void tree(int t,int q)
{
int r=15;
r=15;
setfillstyle(6,BROWN);
rectangle(150+t,390+q,170+t,340+q);
//floodfill(151+t,342+q,2);
setfillstyle(11,GREEN);
fillellipse(142+t,347+q,r,r);
fillellipse(160+t,330+q,r,r);
fillellipse(175+t,340+q,r,r);
fillellipse(180+t,350+q,r,r);
}*/
void circleMidpoint(int xc, int yc, int r)
{
int x = 0, y = r;
int p = 1 - r;
while (x < y)
{
drawCircle(xc, yc, x, y);
x++;

if (p < 0)
p = p + 2 * x + 1;
else
{
y--;
p = p + 2 * (x - y) + 1;
}
drawCircle(xc, yc, x, y);

}
}
int drawCircle(int xc, int yc, int x, int y)
{
putpixel(xc+x, yc+y, GREEN);
putpixel(xc-x, yc+y, GREEN);
putpixel(xc+x, yc-y, GREEN);
putpixel(xc-x, yc-y, GREEN);
putpixel(xc+y, yc+x, GREEN);
putpixel(xc-y, yc+x, GREEN);
putpixel(xc+y, yc-x, GREEN);
putpixel(xc-y, yc-x, GREEN);
}
void main()
{

    int gd = DETECT, gm = DETECT, x1, y1, x2, y2,xc,yc;
    int i,j,t,r;
    clrscr();

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    //setbkcolor(RED);
   /* drawline(20,100,70,30);
    drawline(70,30,120,100);
    drawline(20,100,120,100);
    drawline(100,50,100,300); */
setlinestyle(3,0,2);
setcolor(WHITE);
line(getmaxx()*0.25+60,getmaxy()*0.25,
		      getmaxx()*0.25+60,getmaxy()*0.75);
line(getmaxx()*0.25+50,getmaxy()*0.25,
		      getmaxx()*0.25+50,getmaxy()*0.75);
line(getmaxx()*0.25+40,getmaxy()*0.25,
		      getmaxx()*0.25+40,getmaxy()*0.75);
line(getmaxx()*0.25+30,getmaxy()*0.25,
		      getmaxx()*0.25+30,getmaxy()*0.75);
line(getmaxx()*0.25+20,getmaxy()*0.25,
		      getmaxx()*0.25+20,getmaxy()*0.75);




		     /* line(getmaxx()*0.25+20,getmaxy()*0.25,
		      getmaxx()*0.25+20,getmaxy()*0.75);
line(getmaxx()*0.25+30,getmaxy()*0.25,
		      getmaxx()*0.25+30,getmaxy()*0.75);
line(getmaxx()*0.25+40,getmaxy()*0.25,
		      getmaxx()*0.25+40,getmaxy()*0.75);
line(getmaxx()*0.25+50,getmaxy()*0.25,
		      getmaxx()*0.25+50,getmaxy()*0.75);
line(getmaxx()*0.25+60,getmaxy()*0.25,
		      getmaxx()*0.25+60,getmaxy()*0.75);  */



//CLOUD
setcolor(WHITE);
setfillstyle(HATCH_FILL,WHITE);
sector(getmaxx()*0.25,getmaxy()*0.25,0,360,30,30);
sector(getmaxx()*0.25+20,getmaxy()*0.25,0,360,30,30);
sector(getmaxx()*0.25+30,getmaxy()*0.25-30,0,360,30,30);
sector(getmaxx()*0.25+40,getmaxy()*0.25-10,0,360,30,30);
sector(getmaxx()*0.25+60,getmaxy()*0.25-20,0,360,30,30);
sector(getmaxx()*0.25+50,getmaxy()*0.25+10,0,360,30,30);


setlinestyle(0,0,1);
/*setcolor(WHITE);
setfillstyle(HATCH_FILL,WHITE);
sector(getmaxx()*0.35,getmaxy()*0.25,0,360,30,30);
sector(getmaxx()*0.35+20,getmaxy()*0.25,0,360,30,30);
sector(getmaxx()*0.35+30,getmaxy()*0.25-30,0,360,30,30);
sector(getmaxx()*0.35+40,getmaxy()*0.25-10,0,360,30,30);
sector(getmaxx()*0.35+60,getmaxy()*0.25-20,0,360,30,30);
sector(getmaxx()*0.35+50,getmaxy()*0.25+10,0,360,30,30);


setlinestyle(0,0,2);*/ //rectangles affected by this too.
/*setcolor(RED);
setfillstyle(SOLID_FILL,YELLOW);*/
setcolor(GREEN);
setfillstyle(SOLID_FILL,YELLOW);
circleMidpoint(540,50,30);
floodfill(540,50,GREEN);
for( i=1, j=0; i<=6, j<=getmaxx()*0.04; i++,j++)
{
setcolor(i);
arc(getmaxx()*0.5,getmaxy()*0.75,0,180,getmaxx()*0.40+j);
}


/*
for(i=0;i<getmaxx();i+=120)
{
line(i,250,i+60,170);
line(i+60,170,i+120,250);
setfillstyle(SOLID_FILL,LIGHTGREEN);
floodfill(49,270,2);
}      */

 t=10;
drawline(0,400,getmaxx(),400);
drawline(2,390,getmaxx(),390);
drawline(400,350,450,350);
drawline(450,370,450,350);
drawline(450,370,400,370) ;
drawline(400,370,400,350);
drawline(450,370,470,370);
drawline(400,370,380,370);
drawline(380,385,470,385);
drawline(470,385,470,370);
drawline(380,385,470,385);
drawline(380,370,380,385);
circleMidpoint(400,385,10);
circleMidpoint(450,385,10);
B:drawline(50+t,280,50+t,320);
drawline(50+t,320,60+t,320);
drawline(60+t,320,70+t,320);
drawline(70+t,320,80+t,320);
drawline(130+t,320,80+t,320);
drawline(70+t,320,70+t,300);
drawline(60+t,300,60+t,320);
drawline(70+t,300,60+t,300);
drawline(80+t,320,80+t,280);
drawline(130+t,320,130+t,280);
drawline(80+t,280,130+t,280);
drawline(50+t,280,80+t,280);
drawline(50+t,280,65+t,260);
drawline(65+t,260,80+t,280);
drawline(65+t,260,110+t,260);
drawline(130+t,280,110+t,260);
if(t==10)
{
t=320;
goto B;

}
//tree(0,-10);
setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
circleMidpoint(295,250,18);
floodfill(295,250,GREEN);

setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
circleMidpoint(310,265,18);
floodfill(310,265,GREEN);

setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
circleMidpoint(283,265,18);
floodfill(283,265,GREEN);
drawline(300,280,300,310);
drawline(290,280,290,310);
drawline(290,310,300,310);



setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
circleMidpoint(490,270,18);
floodfill(490,270,GREEN);

setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
circleMidpoint(510,270,18);
floodfill(510,270,GREEN);

setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
circleMidpoint(500,255,18);

floodfill(500,250,GREEN);
drawline(505,290,505,320);
drawline(495,290,495,320);
drawline(495,320,505,320);
//drawline(495,290,495,290);
//tree(30,-100);
//circleMidpoint(350,-60);
//circleMidpoint(160,-50);
/*setfillstyle(SOLID_FILL,LIGHTCYAN);
floodfill(0,0,WHITE);
  */


    getch();
}
