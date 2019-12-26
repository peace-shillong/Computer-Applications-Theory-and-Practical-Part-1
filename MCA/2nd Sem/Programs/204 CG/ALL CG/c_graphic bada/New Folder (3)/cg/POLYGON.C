#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void draw_poly(int,int,int,int);
void main()
{

	int x[10],y[10],n,i;
	int gd=DETECT,gm;
	printf("\n\n\t Enter the number of points: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		 printf("\n\n\t Enter the points(x%d and y%d): ",i,i);
		 scanf("%d %d",&x[i],&y[i]);
	}
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	for(i=1;i<n;i++)
		draw_poly(x[i],y[i],x[i+1],y[i+1]);
	draw_poly(x[n],y[n],x[1],y[1]);
	getch();
	closegraph();
}

void draw_poly(int x1,int y1,int x2,int y2)
{
	 float dx,dy,xi,yi,x,y,i,temp;
	 dx=x2-x1;
	 dy=y2-y1;

	 if(abs(dx)>abs(dy))
		 temp=abs(dx);
	 else
		 temp=abs(dy);

	 xi=dx/temp;
	 yi=dy/temp;
	 x=x1;
	 y=y1;
	 for(i=1;i<temp;i++)
	 {
		  x=x+xi;
		  y=y+yi;
		  putpixel(x,y,BLUE);
	 }
}
