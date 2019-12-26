//Program for drawing the solar system.

#include<conio.h>
#include<dos.h>
//#include<Z:\draw.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#include<process.h>
#define ROUND(a) ((int)(a+0.5))
line_eq(int x1,int y1,int x2,int y2,int c)
{
	int x,y;
	if((abs(x1-x2)/abs(y2-y1))>=1)
		for(x=x1;x<=x2;x++)
		{
			y=(((x-x1)*(y1-y2))/(x1-x2))+y1;
			putpixel(x,y,c);
		}
	else
		for(x=x1;x>=x2;x--)
		{
			y=(((x-x1)*(y1-y2))/(x1-x2))+y1;
			putpixel(x,y,c);
		}
	return 0;
}
line_dda(int x1,int y1,int x2,int y2,int c)        //DDA Line Algorithm
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
return 0;
}
polygn(int s,int *poly,int c)
{
	int i,k,x1,x=poly[0],y1,y=poly[1],x2,y2;
	x2=x;
	y2=y;
	for(i=1,k=2;i<s;i++)
	{
		x1=poly[k++];
		y1=poly[k++];
		line_dda(x,y,x1,y1,c);
		x=x1;
		y=y1;
	}
	line_dda(x,y,x2,y2,c);
	return 0;
}

circl(int x1,int y1,int r)
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
return 0;
}
crcl_Oct(int x1,int y1,int r)
{
	int x=0,y=r,p;
	putpixel(x1+x,y1+y,1);
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
		putpixel(x1+x,y1+y,2);
		putpixel(x1-x,y1+y,3);
		putpixel(x1-y,y1+x,4);
		putpixel(x1-y,y1-x,5);
		putpixel(x1-x,y1-y,6);
		putpixel(x1+x,y1-y,7);
		putpixel(x1+y,y1-x,8);
		putpixel(x1+y,y1+x,9);

	}
	return 0;
}

void bres(int x1, int y1, int x2, int y2,int c)
{
	int dx, dy, x=x1,y=y1,s1,s2,swap=0,p,temp,i;
	s1=(x2-x1);
	s2=(y2-y1);
	dx=abs(s1);
	dy=abs(s2);
	swap=0;
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		swap=1;
	}
	p=(2*dy)-dx;
	for(i=0;i<dx;i++)
	{
		putpixel(x,y,c);
		while(p>=0)
		{
			p=p-2*dx;
			if(swap)
				x+=s1;
			else
				y+=s2;

			p=p+2*dy;
			if(swap)
				y+=s2;
			else
				x+=s1;
		}
	}
}
void fill_rt(int x,int y,int oc,int nc)
{
	if(getpixel(x,y)==oc)//||getpixel(x,y)==nc)
	{
		putpixel(x,y,nc);
		fill_rt(x+1,y,oc,nc);
		fill_rt(x,y-1,oc,nc);
		fill_rt(x,y+1,oc,nc);
	}
}
void fill_lft(int x,int y,int oc,int nc)
{
	if(getpixel(x,y)==oc)//||getpixel(x,y)==nc)
	{
		putpixel(x,y,nc);
		fill_lft(x-1,y,oc,nc);
		fill_lft(x,y-1,oc,nc);
		fill_lft(x,y+1,oc,nc);
	}
}
void fldfil(int x,int y,int nc)
{
	int oc=getpixel(x,y);
	fill_rt(x,y,oc,nc);
	fill_lft(x-1,y,oc,nc);
}

void rotate(int *xp,int *yp,int xf,int yf,float *theta)
{
	float x1,y1,thta[8];
	for(int i=0;i<8;i++)
	{
		thta[i]=6.28*(theta[i]/360);
		x1=ROUND((float)(xf+(xp[i]-xf)*cos(thta[i])-(yp[i]-yf)*sin(thta[i])));
		y1=ROUND((float)(yf+(xp[i]-xf)*sin(thta[i])+(yp[i]-yf)*cos(thta[i])));
		xp[i]=ROUND(x1);yp[i]=ROUND(y1);
	}
}
void main()
{
	int gd =DETECT,mode;
	initgraph(&gd,&mode,"c:\\tc\\bgi");
	int x=getmaxx()/2,y=getmaxy()/2;
	circle(x,y,20);

	int xp[]={x-30,x-50,x-70,x-100,x-130,x-160,x-180,x-200};
	int yp[]={y,y,y,y,y,y,y,y};
	int orbit[]={x-30,x-50,x-70,x-100,x-130,x-160,x-180,x-200};
	int size[]={3,5,8,10,8,5,5,4};
	float theta[]={8,4,3,4,3,4,3.5,1};
	//for(int i=0;i<8;i++)
	  //	circle(x,y,x-xp[i]);
	for(int i=0;i<8;i++)
	{
		circle(xp[i],yp[i],size[i]);
		setcolor(i);
	}
	while(!kbhit())
	{
		setcolor(BLACK);
		for(i=0;i<8;i++)
		{
			circle(x,y,x-orbit[i]);

		}
		for(i=0;i<8;i++)
		{      // fldfil(xp[i],yp[i],BLACK);
			circle(xp[i],yp[i],size[i]);
		}
		setcolor(WHITE);
		rotate(xp,yp,x,y,theta);
		for(i=0;i<8;i++)
		{
			circle(xp[i],yp[i],size[i]);
			setcolor(i+1);
		       //	fldfil(xp[i],yp[i],RED);
		}
		for(i=0;i<8;i++)
			circle(x,y,x-orbit[i]);
		delay(100);
	}
	getch();
}