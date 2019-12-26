#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#define ROUND(a) ((int)(a+0.5))
#define RAD 0.01745329

void translate(int p[],int dx,int dy)
{
	int i,x1,y1;
	for(i=0;i<8;i=i+2)
	{
	       p[i]=p[i]+dx;
	       p[i+1]=p[i+1]+dy;
	       //p[i]=x1;
	       //p[i+1]=y1;
	}
}
void trans(int *x,int *y,int dx,int dy)
{
	*x=*x+dx;
	*y=*y+dy;
}
void rotate(int *x,int *y,int xf,int yf,int theta)
{
	float x1,y1;
	theta=6.28*(theta/360);
	x1=(xf+(*x-xf)*cos(theta)-(*y-xf)*sin(theta));
	y1=(yf+(*x-xf)*sin(theta)+(*y-xf)*cos(theta));
	*x=ROUND(x1);
	*y=ROUND(y1);
}


//void erase(int p[])
void line_dda(int x1,int y1,int x2,int y2,int c)        //DDA Line Algorithm
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


void circl(int x1,int y1,int r)
{
	int x,y;
	for(x=x1-r;x<=x1+r;x++)
	{
		y=y1+sqrt(r*r-pow((x1-x),2));
		putpixel(x,y,WHITE);
		y=y1-sqrt(r*r-pow((x1-x),2));
		putpixel(x,y,WHITE);
	}
	for(y=y1-r;y<=y1+r;y++)
	{
		x=x1+sqrt(r*r-pow((y1-y),2));
		putpixel(x,y,WHITE);
		x=x1-sqrt(r*r-pow((y1-y),2));
		putpixel(x,y,WHITE);
	}
}
void crcl_Oct(int x1,int y1,int r,int c)
{
	int x=0,y=r,p;
	putpixel(x1+x,y1+y,c);
	p=pow((x+1),2)+pow((y-1/2),2)-pow(r,2);
	for(;x!=y;x++)
	{
		if(p>0)
		{
			y=y-1;
			p=p+(2*x)-(2*y)+5;
		}
		else
			p=p+(2*x)+3;
		putpixel(x1+x,y1+y,c);
		putpixel(x1-x,y1+y,c);
		putpixel(x1-y,y1+x,c);
		putpixel(x1-y,y1-x,c);
		putpixel(x1-x,y1-y,c);
		putpixel(x1+x,y1-y,c);
		putpixel(x1+y,y1-x,c);
		putpixel(x1+y,y1+x,c);

	}

}

void erase(int a[])
{
	line_dda(a[0],a[1],a[2],a[3],getbkcolor());
	line_dda(a[2],a[3],a[4],a[5],getbkcolor());
	line_dda(a[4],a[5],a[6],a[7],getbkcolor());
	line_dda(a[6],a[7],a[0],a[1],getbkcolor());
}
void move(int a[])
{
	line_dda(a[0],a[1],a[2],a[3],WHITE);
	line_dda(a[2],a[3],a[4],a[5],WHITE);
	line_dda(a[4],a[5],a[6],a[7],WHITE);
	line_dda(a[6],a[7],a[0],a[1],WHITE);
}
void wheel(int x,int y,int r)
{
	setcolor(WHITE);
	circle(x,y,r);
}
void wle(int x,int y,int r)
{
	setcolor(BLACK);
	circle(x,y,r);
}
void fill(int x, int y, int fcolor, int bcolor)
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
/*void rotate(int *x,int *y,int theta)
{
	int x1=*x,y1=*y;
	x1=x1*cos(theta)-y1*sin(theta);
	y1=x1*sin(theta)+y1*cos(theta);
	*x=x1;
	*y=y1;
} */
void main()
{
	int a[8]={20,20,80,20,80,70,20,70},h[8]={80,45,100,45,100,70,80,70},w[8]={22,22,78,22,78,42,22,42};
       //	float c1[8],c2[8],c3[8];
	//int d,rq,rc;
	int gd=DETECT,mode,x=30,y=80,r=10,x1=40,x2=20,y1=80,y2=80,angle=90;
	initgraph(&gd,&mode,"c:\\tc\\bgi");
	angle=6.34*(angle/360);
	while(!kbhit())
	{

		move(a);
		move(h);
		move(w);
		wheel(x,y,r);
		wheel(x+50,y,r);
		line_dda(x,y,x1,y1,WHITE);
		line_dda(x,y,x2,y2,WHITE);
		//movew(c1);
		//fill(a[0]+1,a[1]+22,RED,WHITE);
		delay(50);
		erase(a);
		erase(h);
		erase(w);
		//fill(a[0]+1,a[1]+22,,WHITE);
		line_dda(x,y,x1,y1,BLACK);
		line_dda(x,y,x2,y2,BLACK);
		wle(x,y,r);
		wle(x+50,y,r);
		translate(a,4,0);
		translate(h,4,0);
		translate(w,4,0);
		trans(&x,&y,4,0);
		rotate(&x1,&y1,x,y,20);
		rotate(&x2,&y2,x,y,20);
	}
	getch();
}