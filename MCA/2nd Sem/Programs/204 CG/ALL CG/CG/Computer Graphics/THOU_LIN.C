#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	int mode, driver = DETECT;
	int x1, x2, y1, y2, x, y,i,j,m,count=0;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	for(i=1;i<400;i++)
		for(j=1;j<400;j++)
		{
			x1=j;
			y1=i;
			x2=j+100;
			y2=j+100;
			m=(y1-y2)/(x1-x2);
			x=x1;
			while(x<x2)
			{
				y=m*(x-x1)+y1;
				if(count<15)
					count++;
				else
					count=0;
				putpixel(x,y,count);
				x++;
			}
		}

getch();
closegraph();
}