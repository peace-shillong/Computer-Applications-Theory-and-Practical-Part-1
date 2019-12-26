#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#define MAX 30
void dline(int x1,int y1,int x2,int y2)
{
	 float dx,dy,xi,yi,x,y,i,t;
	 dx=x2-x1;
	 dy=y2-y1;

	 if(abs(dx)>abs(dy))
		 t=abs(dx);
	 else
		 t=abs(dy);
	 xi=dx/t;
	 yi=dy/t;
	 x=x1;
	 y=y1;
	 for(i=1;i<t;i++)
	 {
		  x=x+xi;
		  y=y+yi;
		  putpixel(x,y,WHITE);
	 }
}

void main()
{
	int x[MAX],y[MAX],n,i;
	int gd=DETECT,gm;
	printf("\nEnter the number of points: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		 printf("\nEnter the points(x%d and y%d): ",i,i);
		 scanf("%d %d",&x[i],&y[i]);
	}
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	for(i=1;i<n;i++)
		dline(x[i],y[i],x[i+1],y[i+1]);
	dline(x[n],y[n],x[1],y[1]);
	getch();
	closegraph();
}
