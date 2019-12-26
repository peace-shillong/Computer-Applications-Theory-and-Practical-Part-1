#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
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
			int x1,y1,x2,y2;

		       int gd=DETECT,gm;
		       clrscr();
		       initgraph(&gd,&gm,"C:\\TC\\BGI");

			printf("\n\t\t\t\t:::::CLOCK:::::");
		      /* linedda(40,200,140,60);

		       linedda(140,60,240,200);

		       linedda(40,200,240,200);
		       linedda(40,200,40,400);
		       linedda(240,200,240,400);
		       linedda(40,400,240,400);
		       linedda(140,60,300,60);

		       linedda(300,60,400,200);
		       linedda(400,200,40,200);
		       linedda(400,200,400,400);
		       linedda(400,400,40,400);
		       linedda(100,400,100,280);
		       linedda(100,280,180,280);
		       linedda(180,280,180,400);
		       //linedda(100,280,180,400);*/
		      // setcolor(WHITE);
		      // linedda(300,300,300,400);
		      // linedda(300,200,300,120);
		       circle(300,200,100);
		       circle(300,200,80);
		       circle(300,200,1);
		       linedda(300,200,220,200);
		       linedda(300,200,380,200);

		       //linedda(250,350,30,200);
		      // linedda(100,200,230,80);
			 linedda(40,200,140,60);

		       linedda(140,60,240,200);

		       linedda(40,200,240,200);
		       linedda(40,200,40,400);
		       linedda(240,200,240,400);
		       linedda(40,400,240,400);
		      // linedda(140,60,300,60);

		       delay(20);
		       //linedda(200,180,150,150);
		       //linedda();
		       //linedda(205,185,130,130);





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
		       linedda(150,50,150,150);*/



		       getch();



		}

