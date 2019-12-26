#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void drawline(int x1,int y1,int x2,int y2)
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
		  putpixel(x,y,RED);
	 }
}
void main()
{

	int x[10],y[10],n,i;
	int gd=DETECT,mode;
	printf("\n\nEnter the number of points: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		 printf("\n\nEnter the points(x%d and y%d): ",i,i);
		 scanf("%d %d",&x[i],&y[i]);
	}
	initgraph(&gd,&mode,"c:\\tc\\bgi");
	for(i=1;i<n;i++)
		drawline(x[i],y[i],x[i+1],y[i+1]);
	drawline(x[n],y[n],x[1],y[1]);
	getch();
	closegraph();
}


