#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
union REGS in,out;
void draw_line(float,float,float,float);
void d_line1(int,int,int,int);
void clip();
void main()
{

    int x[10],y[10],n,i;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\bgi");


	draw_line(100,50,350,50);
	draw_line(100,50,10,150);
	draw_line(10,300,450,300);
	draw_line(100,50,200,150);
	draw_line(350,50,450,150);
	draw_line(450,150,450,300);
	draw_line(10,150,10,300);
	draw_line(200,150,450,150);
	draw_line(200,150,200,300);

	draw_line(70,180,140,180);
	draw_line(70,180,70,300);
	draw_line(140,180,140,300);
       //	draw_line(100,245,100,290);
       //	draw_line(100,290,70,300);
       //	draw_line(100,245,70,230);

	draw_line(270,200,391,200);
	draw_line(270,200,270,240);
	draw_line(270,240,391,240);
	draw_line(390,200,390,240);
	draw_line(300,200,300,240);
	draw_line(330,200,330,240);
	draw_line(360,200,360,240);


	draw_line(120,50,220,150);
	draw_line(140,50,240,150);
	draw_line(160,50,260,150);
	draw_line(180,50,280,150);
	draw_line(200,50,300,150);
	draw_line(220,50,320,150);
	draw_line(240,50,340,150);
	draw_line(260,50,360,150);
	draw_line(280,50,380,150);
	draw_line(300,50,400,150);
	draw_line(320,50,420,150);
	draw_line(340,50,440,150);


       //	draw_line(150,370,1,370);
       //	draw_line(150,400,1,400);
       //	draw_line(150,430,1,430);


    clip();
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
void clip()
{
	int button, x, xco, yco, xin, yin, xout, yout, i=0, j=0, clr;
	//show pointer
	in.x.ax = 1;
	int86(0X33,&in,&out);
	//horizontal restricting
	in.x.ax = 7;
	in.x.cx = 5;
	in.x.dx = 550;
	int86(0X33,&in,&out);
	//vertical restricting
	in.x.ax = 8;
	in.x.cx = 5;
	in.x.dx = 450;
	int86(0X33,&in,&out);
	//mouse button pressed or not
	while(1)
	{
		in.x.ax = 3;
		int86(0X33,&in,&out);
		xco = out.x.cx;
		yco = out.x.dx;
		button = out.x.bx;
		if(button == 1)
		{
			xin = xco;
			yin = yco;

			while(1)
			{
				in.x.ax = 3;
				int86(0X33,&in,&out);
				xco = out.x.cx;
				yco = out.x.dx;
				button = out.x.bx;
				if(button == 0)
				{
					xout = xco;
					yout = yco;
					break;
				}
			}
			break;
		}
	}
	d_line1(xin,yin,xout,yin);
	d_line1(xin,yin,xin,yout);
	d_line1(xin,yout,xout,yout);
	d_line1(xout,yout,xout,yin);
	getch();
	while(i!=getmaxx())
	{
		while(j!=getmaxy())
		{
			if((i<xin||i>xout)||(j<yin||j>yout))
			{
				clr = getpixel(i,j);
				if(clr == WHITE)
				{
					putpixel(i,j,BLACK);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}

}
void d_line1(int x1,int y1,int x2,int y2)
{
	int p=0,x=0,y=0,xf=0,yf=0,dx=0,dy=0,m=0,end=0;
	int temp=0,k=0;

	x=x1;
	y=y1;
	xf=x2;
	yf=y2;
	if(x1==x2)
	{
		x=x1=x2;
		if(y1<y2)
		{
			y=y1;
			end=y2;
		}
		else if(y1>y2)
		{
			y=y2;
			end=y1;
		}
		else
			end=y1;
		while(y<end)
		{
			putpixel(x,y,6);
			y++;
		}
	}
	else if(y1==y2)
	{
		y=y1=y2;
		if(x1<x2)
		{
			x=x1;
			end=x2;
		}
		else if(x1>x2)
		{
			x=x2;
			end=x1;
		}
		else
			end=x1;
		while(x<end)
		{
			putpixel(x,y,6);
			x++;
		}
	}
	else
	{
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		m=dy/dx;
		if(m>1)
		{
			temp=dx;dx=dy;dy=temp;
			temp=x;x=y;y=temp;
			temp=xf;xf=yf;yf=temp;
		}
		putpixel(x,y,6);
		p=(2*dy)-dx;

		for(k=1;k<=dx;k++)
		{
			if(p<0)
			{
				if(x<xf)
				{
					x=x+1;
				}
				else
				{
					x=x-1;
				}
				p=p+2*dy;
			}
			else
			{
				if(y<yf)
				{
					y=y+1;
					if(x<xf)
					{
						x=x+1;
					}
					else
					{
						x=x-1;
					}
				}
				else
				{
					y=y-1;
					if(x<xf)
					{
						x=x+1;
					}
					else
					{
						x=x-1;
					}
				}
				p=p+2*(dy-dx);
			}
			if(m>1)
			{
				putpixel(y,x,6);
			}
			else
			{
				putpixel(x,y,6);
			}
		}
	}
}