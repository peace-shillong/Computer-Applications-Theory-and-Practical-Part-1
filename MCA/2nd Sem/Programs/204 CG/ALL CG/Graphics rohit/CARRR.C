#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
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

	void linedda(int x1,int y1,int x2,int y2)
	 {
		float  x,y,xinc,yinc,dx,dy;
		int k,step;
		dx=x2-x1;
		dy=y2-y1;
		if(abs(dx)>abs(dy))
		step=abs(dx);
		else
		step=abs(dy);
		xinc=dx/step;
		yinc=dy/step;
		x=x1;
		y=y1;
		putpixel(x,y,WHITE);

		for(k=1;k<=step;k++)
		{

		       x=x+xinc;
		       y=y+yinc;
		       putpixel(x,y,WHITE);

		}
		}

			void main()
		{
			int x1,y1,x2,y2,i,j,maxx,midy,m,n;

		       int gd=DETECT,gm;
		       clrscr();
		       initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
		       settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(24,240,"Press any key to view the moving car");

   getch();


    for( i = 0 ; i <= 420 ; i = i + 10, j++ )
   {
	int t=10;

     // linedda(50+i,275,150+i,400);
      //linedda(150+i,350,200+i,400);
      //circle(75+i,410,10);
		     linedda(0,400,getmaxx(),400);
			linedda(2,390,getmaxx(),390);
linedda(400+i,350,450+i,350);
linedda(450+i,370,450+i,350);
linedda(450+i,370,400+i,370) ;
linedda(400+i,370,400+i,350);
linedda(450+i,370,470+i,370);
linedda(400+i,370,380+i,370);
linedda(380+i,385,470+i,385);
linedda(470+i,385,470+i,370);
linedda(380+i,385,470+i,385);
linedda(380+i,370,380+i,385);
circleMidpoint(400+i,385,10);
circleMidpoint(450+i,385,10);



B:linedda(50+t,280,50+t,320);
linedda(50+t,320,60+t,320);
linedda(60+t,320,70+t,320);
linedda(70+t,320,80+t,320);
linedda(130+t,320,80+t,320);
linedda(70+t,320,70+t,300);
linedda(60+t,300,60+t,320);
linedda(70+t,300,60+t,300);
linedda(80+t,320,80+t,280);
linedda(130+t,320,130+t,280);
linedda(80+t,280,130+t,280);
linedda(50+t,280,80+t,280);
linedda(50+t,280,65+t,260);
linedda(65+t,260,80+t,280);
linedda(65+t,260,110+t,260);
linedda(130+t,280,110+t,260);
if(t==10)
{
t=320;
goto B;

}



setcolor(WHITE);
setfillstyle(HATCH_FILL,WHITE);
sector(getmaxx()*0.25,getmaxy()*0.25,0,360,30,30);
sector(getmaxx()*0.25+20,getmaxy()*0.25,0,360,30,30);
sector(getmaxx()*0.25+30,getmaxy()*0.25-30,0,360,30,30);
sector(getmaxx()*0.25+40,getmaxy()*0.25-10,0,360,30,30);
sector(getmaxx()*0.25+60,getmaxy()*0.25-20,0,360,30,30);
sector(getmaxx()*0.25+50,getmaxy()*0.25+10,0,360,30,30);
for( m=1, n=0; m<=6, n<=getmaxx()*0.04; m++,n++)
{
setcolor(m);
arc(getmaxx()*0.5,getmaxy()*0.75,0,180,getmaxx()*0.40+n);
}


setcolor(WHITE);
setfillstyle(HATCH_FILL,WHITE);
sector(getmaxx()*0.60,getmaxy()*0.18,0,360,30,30);
sector(getmaxx()*0.60+20,getmaxy()*0.18,0,360,30,30);
sector(getmaxx()*0.60+30,getmaxy()*0.18-30,0,360,30,30);
sector(getmaxx()*0.60+40,getmaxy()*0.18-10,0,360,30,30);
sector(getmaxx()*0.60+60,getmaxy()*0.18-20,0,360,30,30);
sector(getmaxx()*0.60+50,getmaxy()*0.18+10,0,360,30,30);
 line(0,80,80,10);
 linedda(80,10,160,80);
 linedda(160,80,240,10);
 linedda(240,10,320,80);
 linedda(320,80,400,10);
 linedda(400,10,480,80);
 linedda(480,80,560,10);
 linedda(560,10,640,80);
/*draw the Sun*/
arc(321,45,0,180,40);
// setfillstyle(SOLID_FILL,LIGHTCYAN);
// floodfill(20,60,DARKGRAY);
/*Fill color in mountains*/
/*setcolor(GREEN);
 setfillstyle(SOLID_FILL,BROWN);
 floodfill(70,50,DARKGRAY);
 floodfill(230,50,DARKGRAY);
 floodfill(260,50,DARKGRAY);
 floodfill(380,50,DARKGRAY);
 floodfill(555,50,DARKGRAY);
/*Fill color in Sun*/
/* setcolor(GREEN);
 setfillstyle(SOLID_FILL,YELLOW);
 floodfill(340,50,DARKGRAY);  */

/* circleMidpoint(300,36,25);
 circleMidpoint(280,26,25);
 circleMidpoint(260,36,25);
  setcolor(GREEN);
setfillstyle(SOLID_FILL,WHITE);
circleMidpoint(300,36,25);
floodfill(300,36,GREEN);
 setcolor(GREEN);
setfillstyle(SOLID_FILL,WHITE);
circleMidpoint(280,26,25);
floodfill(280,26,GREEN);
 setcolor(GREEN);
setfillstyle(SOLID_FILL,WHITE);
circleMidpoint(260,36,25);
floodfill(260,36,GREEN);*/


/*linedda(350+i,300,400+i,300);
linedda(400+i,320,400+i,300);
linedda(400+i,320,350+i,330) ;
linedda(350+i,320,350+i,300);
linedda(400+i,320,420+i,320);
linedda(350+i,320,330+i,320);
linedda(330+i,335,420+i,335);
linedda(420+i,335,420+i,320);
linedda(330+i,335,420+i,335);
linedda(330+i,320,330+i,335);
circleMidpoint(400+i,385,10);
circleMidpoint(450+i,385,10);
*/

		     /*	linedda(20+i,100,50+i,30);
			linedda(20+i,100,290+i,100);
			linedda(50+i,30,170+i,30);
			linedda(170+i,30,210+i,100);
			linedda(290+i,100,290+i,150);
			linedda(290+i,150,5+i,150);
			linedda(5+i,150,5+i,100);
			linedda(5+i,100,210+i,100);
			linedda(70+i,30,70+i,100);
			linedda(150+i,30,150+i,100);
			       //	setcolor(WHITE);
			circleMidpoint(50+i,150,20);
			circleMidpoint(180+i,150,20);*/

     /*			setcolor(GREEN);
setfillstyle(SOLID_FILL,YELLOW);
circleMidpoint(540,50,30);
floodfill(540,50,GREEN);*/

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
linedda(300,280,300,310);
linedda(290,280,290,310);
linedda(290,310,300,310);

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
linedda(505,290,505,320);
linedda(495,290,495,320);
linedda(495,320,505,320);





	       //	circle(175+i,410,10);
		 setcolor(BLUE);
	     //  setfillstyle(SOLID_FILL,GREEN);
	      // circleMidpoint(50+i,150,20);
	      // floodfill(50,150,20);
	      delay(100);

      if( i == 420 )
	 break;

clearviewport();


   }


    //	maxx = getmaxx();
	/* mid position in y-axis */
       //	midy = getmaxy() / 2;
// for (i = 0; i < maxx - 125; i = i + 3) {
		/* clears the graphic screen */
	      //	cleardevice();

		/* draw a white road */
	       //	setcolor(WHITE);
	       //	line(0, midy + 37, maxx, midy + 37);

		/* body of the car */
	/*	setcolor(YELLOW);
		setfillstyle(SOLID_FILL, YELLOW);

		linedda(0 + i, midy + 23, 0 + i, midy);
		linedda(0 + i, midy, 20 + i, midy);
		linedda(20 + i, midy, 40 + i, midy - 20);
		linedda(40 + i, midy - 20, 80 + i, midy - 20);
		linedda(80 + i, midy - 20, 100 + i, midy);
		linedda(100 + i, midy, 120 + i, midy);
		linedda(120 + i, midy, 120 + i, midy + 23);
		linedda(0 + i, midy + 23, 18 + i, midy + 23);
		arc(30 + i, midy + 23, 0, 180, 12);
		linedda(42 + i, midy + 23, 78 + i, midy + 23);
		arc(90 + i, midy + 23, 0, 180, 12);
		linedda(102 + i, midy + 23, 120 + i, midy + 23);

		linedda(28 + i, midy, 43 + i, midy - 15);
		linedda(43 + i, midy - 15, 57 + i, midy - 15);
		linedda(57 + i, midy - 15, 57 + i, midy);
		linedda(57 + i, midy, 28 + i, midy);

		linedda(62 + i, midy - 15, 77 + i, midy - 15);
		linedda(77 + i, midy - 15, 92 + i, midy);
		linedda(92 + i, midy, 62 + i, midy);
		linedda(62 + i, midy, 62 + i, midy - 15);
		floodfill(5 + i, midy + 22, YELLOW);
		setcolor(DARKGRAY);

		/* draw wheels of the car */
	       /*	if (i % 2 == 0) {
			setfillstyle(SLASH_FILL, DARKGRAY);
		} else {
			setfillstyle(BKSLASH_FILL, DARKGRAY);
		}

		circleMidpoint(30 + i, midy + 25, 9);
		circleMidpoint(90 + i, midy + 25, 9);
		floodfill(30 + i, midy + 25, DARKGRAY);
		floodfill(90 + i, midy + 25, DARKGRAY);
		delay(10);*/
	}



   getch();
  // closegraph();
  // return 0;
		      /*	printf("\n\t\t\t:::::CAR:::::");
			  setviewport(0,0,639,440,1);

			linedda(20,100,50,30);
			linedda(20,100,290,100);
			linedda(50,30,170,30);
			linedda(170,30,210,100);
			linedda(290,100,290,150);
			linedda(290,150,5,150);
			linedda(5,150,5,100);
			linedda(5,100,210,100);
			linedda(70,30,70,100);
			linedda(150,30,150,100);
			       //	setcolor(WHITE);
			circle(50,150,20);
			circle(180,150,20);
			  delay(100);

		       //	floodfill(50,150,WHITE);
		       //	floodfill(180,150,WHITE);
		       //linedda(40,200,140,60);

		     //  linedda(140,60,240,200);

		     /*  linedda(40,200,240,200);
		       linedda(40,200,40,400);
		       linedda(240,200,240,400);
		       linedda(40,400,240,400);*/

		       //linedda(400,200,300,500);
		       //linedda(200,100,100,100);


		      /* linedda(200,200,200,400);
		       linedda(100,200,100,400);*///coordiantes
		       //linedda(100,100,100,200);


		      // linedda(50,200,100,200);
		     /*  linedda(50,200,100,200);
		       linedda(100,50,100,200);
		       linedda(100,50,300,50);*/

		    /* linedda(50,50,150,50);
		       linedda(50,50,50,150);
		       linedda(50,150,150,150);
		       linedda(150,50,150,150);  */



		       getch();



