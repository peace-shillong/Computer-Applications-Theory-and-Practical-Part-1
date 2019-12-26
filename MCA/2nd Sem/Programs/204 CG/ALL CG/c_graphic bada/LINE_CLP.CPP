#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
typedef unsigned int outcode;
int calcode(float x,float y,float xwmin,float ywmin,float xwmax,float ywmax);
void lineclip(float,float,float,float,float,float,float,float);
void DDA(int,int,int,int);
enum {TOP=0x1,BOTTOM=0x2,RIGHT=0x4,LEFT=0x8};
void DDA(int xx1,int yy1,int xx2,int yy2)
{
	int dx,dy,steps,k;
	float x=xx1, y=yy1, xinc, yinc;
	dx=xx2-xx1;
	dy=yy2-yy1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xinc=dx/(float)steps;
	yinc=dy/(float)steps;
	putpixel(ceil(x),ceil(y),15);
	for(k=0;k<steps;k++)
	{
		x+=xinc;
		y+=yinc;
		putpixel(ceil(x),ceil(y),15);
	}
}

void lineclip(float x0,float y0,float x1,float y1,float xwmin,float ywmin,float xwmax,float ywmax)
{
	outcode code0,code1,codeout;
	int accept=0,done=0;
	code0=calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);
	code1=calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);
	do
	{
		if(!(code0|code1))
		{
			accept=1;
			done=1;
		}
		else if(code0 & code1)
			done=1;
		else
		{
			float xx,yy;
			codeout=code0?code0:code1;
			if(codeout &TOP)
			{
				xx=x0+(x1-x0)*(ywmax-y0)/(y1-y0);
				yy=ywmax;
			}
			else if(codeout &BOTTOM)
			{
				xx=x0+(x1-x0)*(ywmin-y0)/(y1-y0);
				yy=ywmin;
			}
			else if(codeout &RIGHT)
			{
				yy=y0+(y1-y0)*(xwmax-x0)/(x1-x0);
				xx=xwmax;
			}
			else if(codeout &LEFT)
			{
				yy=y0+(y1-y0)*(xwmin-x0)/(x1-x0);
				xx=xwmin;
			}
			if(codeout==code0)
			{
				x0=xx;
				y0=yy;
				code0=calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);
			}
			else
			{
				x1=xx;
				y1=yy;
				code1=calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);
			}
		}
	}while(done==0);
	if(accept)
	    DDA(ceil(x0),ceil(y0),ceil(x1),ceil(y1));
	rectangle(xwmin,ywmin,xwmax,ywmax);

}

int calcode(float x,float y,float xwmin,float ywmin,float xwmax,float ywmax)
{
	int code=0;
	if(y>ywmax)
	   code|=TOP;
	else if(y<ywmin)
	   code|=BOTTOM;
	else if(x>xwmax)
	   code|=RIGHT;
	else if(x<xwmin)
	   code|=LEFT;
	return code;
}
void main()
{        clrscr();
	float xwmin,ywmin,xwmax,ywmax;
	int gd=DETECT,gm,n,i;
	float xa1[10],ya1[10],xa2[10],ya2[10];
	cout<<"\n\tCohem-Sutherland Line Clipping Algorithm: ";
       //	cout<<"\n\t========================================: ";
	cout<<"\n\t*****************************************  ";
	cout<<"\n\n\tHow many lines do you want to display (MAX 10)? ";
	cin>>n;
	if(n>10)
	{
		cout<<"\n\n\tNo. of lines should be less than 10";
		exit(1);
	}
	cout<<"\n\tEnter the co-ordinates of window:\n";
	cout<<"\n\txwmin  ywmin: ";
	cin>>xwmin>>ywmin;
	cout<<"\n\txwmax  ywmin: ";
	cin>>xwmax>>ywmax;
	for(i=0;i<n;i++)
	{
		cout<<"\n\nLINE "<<i+1<<"::";
		cout<<"\n\nEnter the starting coordinates(x1,y1) for line: ",i;
		cin>>xa1[i]>>ya1[i];
		cout<<"Enter the starting coordinates(x2,y2) for line: ",i;
		cin>>xa2[i]>>ya2[i];
	}
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	for(i=0;i<n;i++)
	{
		DDA(ceil(xa1[i]),ceil(ya1[i]),ceil(xa2[i]),ceil(ya2[i]));
	}
	rectangle(xwmin,ywmin,xwmax,ywmax);
	getch();
	cleardevice();
	for(i=0;i<n;i++)
	{
		lineclip(xa1[i],ya1[i],xa2[i],ya2[i],xwmin,ywmin,xwmax,ywmax);
	}

	getch();
	closegraph();
}


