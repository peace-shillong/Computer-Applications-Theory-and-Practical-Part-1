		/* Drawing a straight line with DDA algorithm*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void dda1(float,float);
void dda2(float,float);
void dda3(float,float);
int x1,y1,xr,yr,dx,dy, r,i,dx,dy,xinc,yinc,k,x;
void main()
{
	int driver,mode;
	driver=DETECT;
	initgraph(&driver,&mode,"h:\\software\\tc\\bgi");
	clrscr();
	printf("Enter the First co-ordinates:");
	scanf("%d %d",&x1,&y1);

	printf("Enter The Last co-ordinates:");
	scanf("%d %d",&xr,&yr);



	dx=xr-x1;
	dy=yr-y1;

	if(dy<dx)
	   dda1(x1,y1);
	else if(dy>dx)
	    dda2(x1,y1);
	else
	    dda3(x1,y1);
	getch();
}

 void dda1(float x1,float y1)
 {
	//int r,i,dx,dy,xinc,yinc;
	r=dx;
	xinc=dx/r;
	yinc=dy/r;
	putpixel(x1,y1,1);
	for(i=x1;i<xr;i++)
	{
		x1=x1+xinc;
		y1=y1+yinc;
		putpixel(x1,y1,1);
	}
 }

 void dda2(float x1,float y1)
 {
	//int i,k,r,dx,dy,yinc,xinc,xr,x;
	r=dy;
	k=1;
	putpixel(x1,y1,1);
	yinc=dy/r;
	xinc=r/dx;
	xinc=1/xinc;
	for(i=y1;i<yr;i++)
	{
		x1=x+(k*xinc);
		y1=y1+yinc;
		putpixel(x1,y1,1);
		k++;
	}
 }

 void dda3(float x1,float y1)
 {
       //int i;
	for(i=x1;i<xr;i++)
	{
		x1=x1+1;
		y1=y1+1;
		putpixel(x1,y1,1);
	}
 }

