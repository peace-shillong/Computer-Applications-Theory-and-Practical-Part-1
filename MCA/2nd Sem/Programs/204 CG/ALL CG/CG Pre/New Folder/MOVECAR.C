#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#define MAX 30
void translate(int *,int *);
void drawcircle(int xc,int yc,int r,int colr)
{
	int x,maxx,i,y,pk;
	x=0;
	y=r;
	pk=1-r;
	while(x<y)
	{
		if(pk<0)
		{
			pk=pk+2*x+3;
			x=x+1;
			y=y;
		}
		else
		{
			pk=pk+2*x-2*y+5;
			x=x+1;
			y=y-1;

		}
		putpixel(xc+x,yc+y,colr);
		putpixel(xc+y,yc+x,colr);
		putpixel(xc+y,yc-x,colr);
		putpixel(xc+x,yc-y,colr);
		putpixel(xc-x,yc-y,colr);
		putpixel(xc-y,yc-x,colr);
		putpixel(xc-y,yc+x,colr);
		putpixel(xc-x,yc+y,colr);
		putpixel(xc-r,yc,colr);
		putpixel(xc+r,yc,colr);

	}
}
void drawline(int x1,int y1,int x2,int y2,int col)
{
	int d1,d2,x,y,dx,dy,pk,i,x3,y3;
	float m=0;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;
	y=y1;
	if(dx!=0)
	{
		m=(float)dy/(float)dx;
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
					putpixel(x,y,col);
					y = y+1;
				}
			}
			else
			{
				x=x2;
				y=y2;
				for(i=y2;i<=y1;i++)
				{
					putpixel(x,y,col);
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
					putpixel(x,y,col);
					x= x+1;
				}
			}
			else
			{
				x=x2;
				y=y2;
				for(i=x2;i<=x1;i++)
				{
					putpixel(x,y,col);
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
			x=x1;
			y=y1;
			x3=x2;
			y3=y2;
		}
		else
		{
			x=x2;
			y=y2;
			x3=x1;
			y3=y1;
		}
		while(x<x3)
		{
			putpixel(x,y,col);
			if(pk<0)
			{
				pk=pk+(2*dy);
				if(y>y3)
					y=y-1;
				else
					y=y+1;
			}
			else
			{
				pk = pk+(2*(dy-dx));
			}
			x=x+1;
		}
	}
	//case when m is +ve and less than 1
	else if(0<m && m<=1)
	{
		pk=(2*dy)-dx;
		if(x1<x2)
		{
			x=x1;
			y=y1;
			x3=x2;
			y3=y2;
		}
		else
		{
			x=x2;
			y=y2;
			x3=x1;
			y3=y1;
		}
		while(x<x3)
		{
			putpixel(x,y,col);
			if(pk<0)
			{
				pk=pk+(2*dy);
			}
			else
			{
				pk=pk+(2*(dy-dx));
				if(y<y3)
					y=y+1;
				else
					y=y-1;
			}
			x=x+1;
		}
	}
	//case when slop is >1 and +ve
	else if(m>1)
	{
		pk = (2*dy)-dx;
		if(y1<y2)
		{
			x=x1;
			y=y1;
			y3=y2;
			x3=x2;
		}
		else
		{
			x=x2;
			y=y2;
			y3=y1;
			x3=x1;
		}
		while(y<y3)
		{
			putpixel(x,y,col);
			if(pk<0)
			{
				pk=pk+(2*dx);
				x=x;
			}
			else
			{
				pk = pk+(2*(dx-dy));
				if(x<x3)
					x=x+1;
				else
					x=x-1;
			}
			y=y+1;
		}
	}
	//case when slop is >1 and -ve
	else if(m<-1)
	{

		pk = -(dy*x1)-(2*dx*y1)-(2*dy*x1)-(2*dy)-(3*dx*dy);
		if(y1<y2)
		{
			x=x1;
			y=y1;
			y3=y2;
			x3=x2;
		}
		else
		{
			x=x2;
			y=y2;
			y3=y1;
			x3=x1;
		}
		while(y<y3)
		{
			putpixel(x,y,col);
			if(pk<0)
			{
				pk=pk-(dy*x1);
				if(x>x3)
					x=x-1;
				else
					x=x+1;
			}
			else
			{
				pk=pk-(dy*x1)-(3*dx*dy);
				x=x;
			}
			y=y+1;
		}
	}

}
void boundaryfill(int x, int y, int fcolor, int bcolor)
{
	int a,b,c;
	int x1, y1;
	x1=x;
	y1=y;
	a=getpixel(x,y);
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x++;
			c=getpixel(x,y);
		}
		y++;
		x=x1;
		b=getpixel(x,y);
		c=getpixel(x,y);
	}
	x=x1;
	y=y1;
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x--;
			c=getpixel(x,y);
		}
	y++;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}

	x=x1;
	y=y1;
	b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x--;
			c=getpixel(x,y);
		}
	y--;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}
		x=x1;
		y=y1;
		b=c=a;
	while(b!=bcolor)
	{
		while(c!=bcolor)
		{
			putpixel(x,y,fcolor);
			x++;
			c=getpixel(x,y);
		}
	y--;
	x=x1;
	b=getpixel(x,y);
	c=getpixel(x,y);
	}
}
void translate(int x[],int y[])
{
	int tx = 2,ty = 0,i;
	for(i = 0;i<400;i++)
	{
		if(kbhit())
		{
			break;
		}
		boundaryfill(x[8],y[8],BLACK,WHITE);
		boundaryfill(x[9],y[9],BLACK,WHITE);
		boundaryfill(x[10],y[10],BLACK,WHITE);
		drawline(x[0],y[0],x[1],y[1],BLACK);
		drawline(x[0],y[0],x[2],y[2],BLACK);
		drawline(x[3],y[3],x[4],y[4],BLACK);
		drawline(x[5],y[5],x[1],y[1],BLACK);
		drawline(x[4],y[4],x[6],y[6],BLACK);
		drawline(x[6],y[6],x[5],y[5],BLACK);
		drawline(x[2],y[2],x[7],y[7],BLACK);
		drawline(x[7],y[7],x[3],y[3],BLACK);
		drawcircle(x[8],y[8],15,BLACK);
		drawcircle(x[9],y[9],15,BLACK);

		x[0] = x[0]+tx;
		y[0] = y[0]+ty;
		x[1] = x[1]+tx;
		y[1] = y[1]+ty;
		x[2] = x[2]+tx;
		y[2] = y[2]+ty;
		x[3] = x[3]+tx;
		y[3] = y[3]+ty;
		x[4] = x[4]+tx;
		y[4] = y[4]+ty;
		x[5] = x[5]+tx;
		y[5] = y[5]+ty;
		x[6] = x[6]+tx;
		y[6] = y[6]+ty;
		x[7] = x[7]+tx;
		y[7] = y[7]+ty;
		x[8] = x[8]+tx;
		y[8] = y[8]+ty;
		x[9] = x[9]+tx;
		y[9] = y[9]+ty;
		x[10] = x[10]+tx;
		y[10] = y[10]+ty;

		drawline(x[0],y[0],x[1],y[1],WHITE);
		drawline(x[0],y[0],x[2],y[2],WHITE);
		drawline(x[3],y[3],x[4],y[4],WHITE);
		drawline(x[5],y[5],x[1],y[1],WHITE);
		drawline(x[4],y[4],x[6],y[6],WHITE);
		drawline(x[6],y[6],x[5],y[5],WHITE);
		drawline(x[2],y[2],x[7],y[7],WHITE);
		drawline(x[7],y[7],x[3],y[3],WHITE);
		drawcircle(x[8],y[8],15,WHITE);
		drawcircle(x[9],y[9],15,WHITE);
		boundaryfill(x[10],y[10],6,WHITE);
		boundaryfill(x[8],y[8],8,WHITE);
		boundaryfill(x[9],y[9],8,WHITE);
		delay(10);
		//write equation for x//write equation for y
		//redraw the lines with white boundaryfill with new x,y
		//do for all points here only
	}
}
void main()
{
	int gd,gm,x[11],y[11];
	int maxx,maxy;
	clrscr();
	gd=DETECT;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	maxx=getmaxx();
	//maxy=getmaxy();
	drawline(1,400,maxx,400,WHITE);//line
	drawline(70,280,170,280,WHITE); //70 280 170 280
	drawline(70,280,70,330,WHITE); //70 330
	drawline(170,280,170,330,WHITE);//170 330
	drawline(70,330,40,330,WHITE); //40 330
	drawline(170,330,200,330,WHITE);//200 330
	drawline(40,330,40,370,WHITE); //40 370
	drawline(200,330,200,370,WHITE);//200 370
	drawline(40,370,200,370,WHITE);
	boundaryfill(71,281,6,WHITE);
	drawcircle(70,385,15,WHITE); //70 385
	boundaryfill(71,386,8,WHITE);
	//drawcircle(70,385,10);
	drawcircle(170,385,15,WHITE); //170 385
	boundaryfill(171,386,8,WHITE);
	//boundaryfill(100,90,
       //	drawcircle(170,385,10);
	x[0]=70;y[0]=280;
	x[1]=170;y[1]=280;
	x[2]=70;y[2]=330;
	x[3]=170;y[3]=330;
	x[4]=40;y[4]=330;
	x[5]=200;y[5]=330;
	x[6]=40;y[6]=370;
	x[7]=200;y[7]=370;
	x[8]=70;y[8]=385;
	x[9]=170;y[9]=385;
	x[10]=71;y[10]=281;
	translate(x,y);
	getch();
	closegraph();
}