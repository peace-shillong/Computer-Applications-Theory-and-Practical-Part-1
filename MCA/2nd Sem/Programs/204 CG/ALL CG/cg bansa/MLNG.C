			#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void setline(int,int,int,int);
void main()
{
	int driver=DETECT,mode;
	int x1,x2,y1,y2;
	printf("Enter x1:");
	scanf("%d",&x1);
	printf("Enter y1:");
	scanf("%d",&y1);
	printf("Enter x2:");
	scanf("%d",&x2);
	printf("Enter y2:");
	scanf("%d",&y2);
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	clrscr();
	line(x1,y1,x2,y2);
	putpixel(200,200,RED);
	for(x1=x1;x1<=x2;x1++)
	for(y1=y1;y1<=x2;y1++)
	{
		putpixel(x1,y1,BLUE);
		y1++;x1++;
	}
	closegraph();
	getch();
}