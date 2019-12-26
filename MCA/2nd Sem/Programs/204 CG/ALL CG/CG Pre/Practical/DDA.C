#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define ROUND(a) ((int)a+0.5)
void DDA(int,int,int,int);
void main()
{
	int x1,x2,y1,y2;
	int driver=DETECT,mode;
	clrscr();

	initgraph(&driver,&mode,"C:\\TC\\BGI");

	printf("\nEnter X1 : ");
	scanf("%d",&x1);
	printf("\nEnter Y1 : ");
	scanf("%d",&y1);
	printf("\nEnter X2 : ");
	scanf("%d",&x2);
	printf("\nEnter Y2 : ");
	scanf("%d",&y2);
	getch();
	closegraph();
}
void DDA(int x0,int y0,int x1,int y1)
{
	int x,m;
	double y,dx,dy;

	dy=y1-y0;
	dx=x1-x0;
	m=dy/dx;
	y=y0;

	if(dy>dx)
	{
		for(x=x0;x<=x1;x++)
		{
			putpixel(x,ROUND(y),GREEN);
			y+=m;
		}
	}
	else
	{
		for(x=x0;x<=x1;x++)
		{
			putpixel(y,ROUND(x),WHITE);
			y=(x+(1/m));
		}
	}
}