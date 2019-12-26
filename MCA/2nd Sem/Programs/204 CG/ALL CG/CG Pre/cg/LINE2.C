#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int driver=DETECT,mode;
	int x1,y1,x2,y2,m,x,y,i,j;

	initgraph(&driver,&mode,"c:\\tc\\bgi");
	for(i=1;i<1000;i++)
	{
	 for(j=1;j<1000;j++)
	 {
		x1=j;
		y1=i;
		x2=j+100;
		y2=j+100;
		x=x1;
		while(x<x2)
		{
			y=(((y2-y1)/(x2-x1))*(x-x1))+y1;
			putpixel(x,y,GREEN);
			x++;
		}
	 }
	}
getch();
closegraph();
}






































