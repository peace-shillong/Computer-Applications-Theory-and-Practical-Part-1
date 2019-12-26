#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void setline(int,int,int,int);

void main()
{
	int driver=DETECT,mode,m,n=0,i;
	int x, x1, x2;
	int y, y1, y2;


	initgraph(&driver,&mode,"c:\\tc\\bgi");
//	printf("\n\tEnter N : ");
//	scanf("%d",&n);
	while(n<=727)
//	for(i=0;i<n;i++)

	{
		x=getmaxx();
		y=getmaxy();
		x1=rand()%x;
		x2=rand()%x;
		y1=rand()%y;
		y2=rand()%y;
		setline(x1, y1, x2, y2);
		n++;
	}

	getch();
	closegraph();
}
void setline(int x1,int y1,int x2,int y2)
{
	int x,y;

	x=x1;
	y=y2;

	while(x<=x2 && y<=y2)
	{
		putpixel(x,y,14);
		y=(y2-y1)/(x2-x1)*(x1-x)+y2;
	    //	y=(y2-y1)/(x2-x1)*(x-x1)+y2;
		x++;
	}

}