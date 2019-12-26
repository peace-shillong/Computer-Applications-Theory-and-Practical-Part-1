#include<stdio.h>
#include<dos.h>
#include<graphics.h>

void drawline(int x1,int y1,int x2,int y2);
union REGS in,out;
void main()
{
	int driver=DETECT,mode;
	int button,x,xco,yco,xin,yin,xout,yout,i=0,j=0,col;
	clrscr();

	initgraph(&driver,&mode,"c:\\tc\\bgi");

	drawline(90,180,200,90);
	drawline(200,70,310,180);

	drawline(100,200,200,100);
	drawline(200,100,300,200);
	drawline(100,300,300,300);

	drawline(110,190,110,300);
	drawline(290,190,290,300);

	drawline(130,200,130,240);
	drawline(130,200,150,200);
	drawline(150,200,150,240);
	drawline(130,240,150,240);

	drawline(250,200,250,240);
	drawline(250,200,270,200);
	drawline(270,200,270,240);
	drawline(250,240,270,240);

	drawline(180,230,180,300);
	drawline(220,230,220,300);
	drawline(180,230,220,230);

	in.x.ax = 1;
	int86(0X33,&in,&out);

	in.x.ax = 7;
	in.x.cx = 22;
	in.x.dx = 540;
	int86(0X33,&in,&out);
	//vertical
	in.x.ax = 8;
	in.x.cx = 22;
	in.x.dx = 436;
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

void drawline(int x1,int y1,int x2,int y2)
{
	int x,y,dx,dy,pk,i,x3,y3,dk;
	float m=0;
	dx = x2-x1; dy = y2-y1;
	x = x1;y = y1;
	if(dx!=0)
	{
		m = (float)dy/(float)dx;
	}
	//case when slope is 0
	if(m==0)
	{
		if(x1==x2)
		{
			if(y1<y2)
			{
				for(i=y1;i<=y2;i++)
				{
					putpixel(x,y,WHITE);
					y = y+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,WHITE);
					y = y+1;
				}
			}
		}
		else
		{
			if(x1<x2)
			{
				for(i=x1;i<=x2;i++)
				{
					putpixel(x,y,WHITE);
					x= x+1;
				}
			}
			else
			{
				x = x2;y = y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,WHITE);
					x= x+1;
				}
			}
		}
	}
	//case when m is -ve and more than -1
	else if(-1<=m && m<0)
	{
		pk = (2*dy)-dx;
		if(x1<x2)
		{
			x = x1;y = y1;x3 = x2;
		}
		else
		{
			x = x2;y= y2;x3=x1;
		}
		while(x<x3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk = pk+(2*dy);
				y = y-1;
			}
			else
			{
				pk = pk+(2*(dy-dx));
			}
			x  = x+1;
		}
	}
	//case when m is +ve and less than 1
	else if(0<m&&m<=1)
	{
		pk = (2*dy)-dx;
		if(x1<x2)
		{
			x = x1;y = y1,x3 = x2;
		}
		else
		{
			x = x2;y= y2;x3 = x1;
		}
		while(x<x3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk = pk+(2*dy);
			}
			else
			{
				pk = pk+(2*(dy-dx));
				y = y+1;
			}
			x  = x+1;
		}
	}
	//case when slop is >1 and +ve
	else if(m>1)
	{

		//ck = -dy*x1-2*dx*y1-2*dy*x1-2*dy-3*dx*dy;
		pk = (2*dy)-dx;
		if(y1<y2)
		{
			x= x1;y = y1;y3 = y2;
		}
		else
		{
			x = x2;y = y2;y3 = y1;
		}
		while(y<y3)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk = pk+(2*dx);
				x = x;
			}
			else
			{
				pk = pk+(2*(dx-dy));
				x = x+1;
			}
			y = y+1;
		}
	}
	//case when slop is >1 and -ve
	else if(m<-1)
	{

		dk = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(y1<y2)
		{
			x= x1;y = y1;y3 = y2;
		}
		else
		{
			x = x2;y = y2;y3 = y1;
		}
		while(y<y3)
		{
			putpixel(x,y,WHITE);
			if(dk<0)
			{
				dk = dk-(dy*x1);
				x = x-1;
			}
			else
			{
				dk = dk-(dy*x1)-(3*dx*dy);
				x = x;
			}
			y = y+1;
		}
	}

}