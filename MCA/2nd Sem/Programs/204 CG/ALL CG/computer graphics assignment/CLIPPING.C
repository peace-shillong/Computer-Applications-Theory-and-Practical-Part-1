#include<stdio.h>
#include<dos.h>
#include<graphics.h>
void drawline(int,int,int,int);
union REGS in,out;
int main()
{
	int driver = DETECT,mode,button,x,xco,yco,xin,yin,xout,yout,i=0,j=0,col;
	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");

	drawline(20,20,550,20);

	drawline(20,20,20,450);
	drawline(20,450,550,450);
	drawline(550,450,550,20);

	drawline(100,80,400,50);
	drawline(100,80,50,200);
	drawline(100,80,150,200);
	drawline(400,50,450,150);
	drawline(150,200,450,150);
	drawline(50,200,150,200);
	drawline(50,200,50,350);
	drawline(150,200,150,350);
	drawline(50,350,150,350);
	drawline(450,150,450,280);
	drawline(150,350,450,280);
	drawline(80,250,120,250);
	drawline(80,250,80,350);
	drawline(120,250,120,350);
	//show pointer
	in.x.ax = 1;
	int86(0X33,&in,&out);
	//hirizontal resctricting
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
				if(col != BLACK)//
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
	 return 0;
}
void drawline(int x1,int y1,int x2,int y2)
{
	int d1,d2,x,y,dx,dy,pk,i,xs,ck,c1,c2,ys;
	float m=0;
	dx = abs(x2-x1); dy = abs(y2-y1);
	x = x1;y = y1;
	if(dx!=0)
	{
		m = (float)dy/(float)dx;
	}
	//case when slop is 0
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
		//ck = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(x1<x2)
		{
			x = x1;y = y1;xs = x2;ys = y2;
		}
		else
		{
			x = x2;y= y2;xs=x1;ys = y1;
		}
		while(x<xs)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk = pk+(2*dy);
				//ck = ck-dy*x1;
				if(y>ys)
					y = y-1;
				else
					y = y+1;
			}
			else
			{
				pk = pk+(2*(dy-dx));
				//ck = ck-dy*x1-3*dx*dy;
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
			x = x1;y = y1,xs = x2;ys = y2;
		}
		else
		{
			x = x2;y= y2;xs = x1;ys = y1;
		}
		while(x<xs)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				pk = pk+(2*dy);
			}
			else
			{
				pk = pk+(2*(dy-dx));
				if(y<ys)
					y = y+1;
				else
					y = y-1;
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
			x= x1;y = y1;ys = y2;xs = x2;
		}
		else
		{
			x = x2;y = y2;ys = y1;xs = x1;
		}
		while(y<ys)
		{
			putpixel(x,y,WHITE);
			if(pk<0)
			{
				//ck = ck-dy*x1;
				pk = pk+(2*dx);
				x = x;
			}
			else
			{
				//ck = ck-dy*x1-3*dx*dy;
				pk = pk+(2*(dx-dy));
				if(x<xs)
					x = x+1;
				else
					x = x-1;
			}
			y = y+1;
		}
	}
	//case when slop is >1 and -ve
	else if(m<-1)
	{

		ck = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		//pk = (2*dy)-dx;
		if(y1<y2)
		{
			x = x1;y = y1;ys = y2;xs = x2;
		}
		else
		{
			x = x2;y = y2;ys = y1;xs = x1;
		}
		while(y<ys)
		{
			putpixel(x,y,WHITE);
			if(ck<0)
			{
				ck = ck-(dy*x1);
				//pk = pk+(2*dx);
				if(x>xs)
					x = x-1;
				else
					x = x+1;
			}
			else
			{
				ck = ck-(dy*x1)-(3*dx*dy);
				//pk = pk+2*(dx-dy);
				x = x;
			}
			y = y+1;
		}
	}

}