#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
union REGS in,out;
void drawline(float x1, float y1, float x2 , float y2 );


void main()
{
   int gd = DETECT, gm ,i , j;
   float xout ,yout ,button,xco,yco,xin,yin , colr;
   initgraph(&gd, &gm, "c:\\tc\\bgi");
   drawline(200,100,400,100 );
   drawline(200,100,150,200);
   drawline(200,100,250,200);
   drawline(400,100,450,200);
//   drawline(150,200,250,200);
   drawline(250,200,450,200);
   drawline(150,200,150,350);
   drawline(250,200,250,350);
   drawline(450,200,450,350);
   drawline(150,350,250,350);
   drawline(250,350,450,350);

   //windows//
   drawline(270,220,300,220);
   drawline(270,280,300,280);
   drawline(270,220,270,280);
   drawline(300,220,300,280);
   drawline(285,220,285,280);
//   drawline();

   drawline(405,220,435,220);
   drawline(405,280,435,280);
   drawline(405,220,405,280);
   drawline(435,220,435,280);

   drawline(335,270,370,270);
   drawline(335,350,370,350);
   drawline(335,270,335,350);
   drawline(370,270,370,350);
   drawline(355,270,355,350);


   drawline(180,270,220,270);
   drawline(180,350,220,350);
   drawline(180,270,180,350);
   drawline(220,270,220,350);


   drawline(180,150,220,150);
   drawline(180,190,220,190);
   drawline(180,150,180,190);
   drawline(220,150,220,190);

      restrictmsptr(5,5,(getmaxx()-5),(getmaxy()-5));
      showmousept();
      //mouse button press
      while(1)
      {
		in.x.ax=3;
		int86(0x33,&in,&out);
		xco=out.x.cx;
		yco=out.x.dx;
		button=out.x.bx;
		if(button==1)
		{
			xin=xco;
			yin=yco;
			while(1)
			{
				in.x.ax=3;
				int86(0x33,&in,&out);
				xco=out.x.cx;
				yco=out.x.dx;
				button=out.x.bx;
				if(button==0)
				{
					xout=xco;
					yout=yco;
					break;
				}
			}
			break;
		}
	}
	drawline(xin,yin,xout,yin);
	drawline(xin,yin,xin,yout);
	drawline(xin,yout,xout,yout);
	drawline(xout,yout,xout,yin);
	getch();
	while(i!=getmaxx())
	{
		while(j!=getmaxy())
		{
			if((i<xin||i>xout)||(j<yin||j>yout))
			{
				colr=getpixel(i,j);
				if(colr==WHITE)
				{
					putpixel(i,j,BLACK);
				}
			}
			j++;
		}
		j=0;
		i++;
	}

   getch();
   closegraph();
}
void drawline( float x1, float y1 , float x2 , float y2)
{
   float x,y;
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

showmousept()
{
	in.x.ax=1;
	int86(0x33,&in,&out);
	return(out.x.ax);
}
restrictmsptr(int x1,int y1,int x2,int y2)
{
	in.x.ax=7; //Restrict horizontal limit
	in.x.cx=x1;
	in.x.dx=x2;
	int86(0x33,&in,&out);
	in.x.ax=8;//restrict vertival limit
	in.x.cx=y1;
	in.x.dx=y2;
	int86(0x33,&in,&out);
	return;
}
