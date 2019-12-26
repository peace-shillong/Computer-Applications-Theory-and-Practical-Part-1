#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void circle(int ,int ,int );

void main()
{
	int xc,yc,rad,driver=DETECT,mode;
	clrscr();
	initgraph(&driver,&mode,"C:\\TC\\BGI");
	printf("Enter Xc Coordinate    : ");
	scanf("%d",&xc);

	printf("Enter Yc Coordinate    : ");
	scanf("%d",&yc);

	printf("Enter Radius of Circle : ");
	scanf("%d",&rad);

	circle(xc,yc,rad);

	getch();
	closegraph();
}

void circle(int xx,int yy,int r)
{
	int x;
	for(x=1;x<xx;x++)
	{
		yy=sqrt((x*x)-(r*r));
		putpixel(xx,yy,4);
		yy=-sqrt((x*x)-(r*r));
		putpixel(xx,yy,14);
	}
}