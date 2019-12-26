#include<conio.h>
#include<graphics.h>
void drawlines(int,int,int,int);
void main(void)
{
	int driver,mode,i,j;
	int x1=10,y1=10,x2=30,y2=30;
	clrscr();
	driver = DETECT;
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
	for(i=1;i<=10000;i++)
	{
		drawlines(x1,y1,x2,y2);
		x1=x1+10;
		x2=x2+10;
		if(x2>getmaxx())
		{
			x1=10;x2=30;
			y1 = y1+20;y2 = y2+40;
		}
	}
	getch();
	closegraph();
}
void drawlines(int x1,int y1,int x2,int y2)
{
	int i,m,x,y;
	m = (y2-y1)/(x2-x1);
	if(m<1||m>-1){m=1;}
	for(i = x1;i<=x2;i=i+m)
	{
		x = i;
		y = m*(x-x1)+y1;
		putpixel(x,y,WHITE);
	}
}