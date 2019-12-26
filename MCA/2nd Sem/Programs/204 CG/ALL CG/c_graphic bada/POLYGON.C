#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void draw_poly(int x1,int y1,int x2,int y2,int c)
{
	float dx,dy,x,xi,y,yi,i,step;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
		step=abs(dy);
	xi=dx/step;
	yi=dy/step;
	x=x1;
	y=y1;
	for(i=1;i<step;i++)
	{
		x=x+xi;
		y=y+yi;
		putpixel(x,y,c);

	}
}
void main()
{
	int x[10],y[10],n,i , c;
	int driver=DETECT,mode;
	//int x1,y1,x2,y2,n;
	//initgraph(&driver,&mode,"c:\\tc\\bgi");
	printf("Enter the no of points: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the points for x[%d] and y[%d]",i,i);
		scanf("%d %d",&x[i],&y[i]);
	}
	printf("Enter the colour: ");
	scanf("%d",&c);
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	for(i=1;i<n;i++)
	{
		draw_poly(x[i],y[i],x[i+1],y[i+1],c);
		draw_poly(x[n],y[n],x[1],y[1],c);
		}

		getch();
		closegraph();
}