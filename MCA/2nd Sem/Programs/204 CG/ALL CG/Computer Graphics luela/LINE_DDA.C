#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void main()
{
	int gdriver= DETECT, gmode= DETECT, s, dx,dy,i,x1,y1,x2,y2;
	float xi,yi,x,y;
	clrscr();
	printf("\nEnter the starting points:");
	scanf("%d %d",&x1,&y1);
	printf("\nEnter the ending points:");
	scanf("%d %d", &x2,&y2);
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		s=abs(dx);
	else
		s=abs(dy);
	xi=dx/(float)s;
	yi=dy/(float)s;
	x=x1;
	y=y1;
	putpixel(x1,y1,RED);
	for(i=0;i<s;i++)
	{
		x+=xi;
		y+=yi;
		putpixel(x,y,RED);
	}
	getch();
	closegraph();
}