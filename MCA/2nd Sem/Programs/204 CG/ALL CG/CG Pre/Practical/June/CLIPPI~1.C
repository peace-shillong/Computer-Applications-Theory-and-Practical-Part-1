//*HOUSE*
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define ROUND(a) ((int)a+0.5)
union REGS in,out;
void dda(int x1,int y1,int x2,int y2,int c)        //DDA Line Algorithm
{
	int dx,dy,k,steps;
	float ddx,ddy,x=x1,y=y1;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	ddx=dx/(float)steps;
	ddy=dy/(float)steps;
	//putpixel(ROUND(x),ROUND(y),c);
	for(k=0;k<=steps;k++)
	{
		putpixel(ROUND(x),ROUND(y),c);
		x+=ddx;
		y+=ddy;
		//putpixel(ROUND(x),ROUND(y),c);
	}
}
void house()
{
	dda(200,150,400,150,WHITE);
	dda(150,200,200,150,WHITE);
	dda(450,200,400,150,WHITE);
	dda(250,200,200,150,WHITE);
	dda(150,200,150,350,WHITE);
	dda(250,200,250,350,WHITE);
	dda(450,200,450,350,WHITE);
	dda(150,350,450,350,WHITE);
	dda(150,200,450,200,WHITE);

	//door
	dda(180,350,180,250,WHITE);
	dda(180,250,220,250,WHITE);
	dda(220,250,220,350,WHITE);

	dda(330,350,330,260,WHITE);
	dda(370,350,370,260,WHITE);
	dda(330,260,370,260,WHITE);
	//window
	dda(250,250,300,250,WHITE);
	dda(250,300,300,300,WHITE);
	dda(300,250,300,300,WHITE);

	dda(400,250,450,250,WHITE);
	dda(400,250,400,300,WHITE);
	dda(400,300,450,300,WHITE);
       //	dda(250,300,300,300,WHITE);
	//dda(300,250,300,300,WHITE);

	/*
	dda(390,250,390,250,WHITE);
	dda(390,250,420,280,WHITE);
	dda(420,250,420,280,WHITE);
	dda(390,280,420,280,WHITE); */

}
initmouse()
{
	in.x.ax=0;
	int86(0x33,&in,&out);
	return(out.x.ax);
}
void showmouse()
{
	in.x.ax=1;
	int86(0x33,&in,&out);
}
void mouseclick(int *button,int *x,int *y)
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*button=out.x.bx;
	*x=out.x.cx;
	*y=out.x.dx;
	//return;

}
void rect(int x,int y,int x1,int y1)
{
	dda(x,y,x1,y,WHITE);
	dda(x,y,x,y1,WHITE);
	dda(x,y1,x1,y1,WHITE);
	dda(x1,y,x1,y1,WHITE);
}
void main()
{
	int gd=DETECT,gm,minx,miny,maxx,maxy,b,x,y,i=0,j=0,col;
	initgraph(&gd,&gm,"..\\bgi");
	if(!initmouse())
	{
		closegraph();
		printf("\n Mouse not loaded");
		return;
	}
	showmouse();
	house();
       // outtextxy(300,20,"" CLIPPING A HOUSE ""/");
       while(1)
	{
		mouseclick(&b,&x,&y);
		if(b==1)
		{
			minx=x;
			miny=y;
			while(1)
			{
				mouseclick(&b,&x,&y);
				if(b==0)
				{
					maxx=x;
					maxy=y;
					break;
				}
			}
			break;
		}
	}
	rect(minx,miny,maxx,maxy);
	getch();
	while(i!=getmaxx())
	{
		while(j!=getmaxy())
		{
			if((i<minx||i>maxx)||(j<miny||j>maxy))
			{
				col = getpixel(i,j);
				if(col == WHITE)
				{
					putpixel(i,j,BLACK);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}

	getch();
	closegraph();
}


