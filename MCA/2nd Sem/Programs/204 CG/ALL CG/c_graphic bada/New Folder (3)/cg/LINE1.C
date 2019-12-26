#include<stdio.h>
#include<graphics.h>
#include<math.h>

void main()
{
	int driver=DETECT,mode;
	int x,y,x1,x2,y1,y2;
	float m;
	int m1;
	clrscr();

	printf("\nEnter the initial points:");
	scanf("%d %d",&x1,&y1);
	printf("\nEnter the terminal points:");
	scanf("%d %d",&x2,&y2);

	initgraph(&driver,&mode,"c:\\tc\\bgi");

	m=(y2-y1)/(x2-x1);
	m1=ceil(m);

	for(x=x1;x<=x2;x=x+m1)
	{
		y=m1*(x-x1)+y1;
		putpixel(x,y,RED);
	}

	getch();
	closegraph();
}