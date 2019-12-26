#include<conio.h>
#include<graphics.h>
void main(void)
{
	int driver,mode,m,x1,y1,x2,y2,x,y,i,dx,dy;
	clrscr();
	driver = DETECT;
	printf("\nENTER THE STARTING POINT:");
	scanf("%d%d",&x1,&y1);
	printf("\nENTER THE ENDING POINT:");
	scanf("%d%d",&x2,&y2);
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
	dx = x2-x1;dy = y2-y1;
	m = (y2-y1)/(x2-x1);
	for(i = x1;i<=x2;i=i+m)
	{
		x = i;
		y = m*(x-x1)+y1;
		putpixel(x,y,WHITE);
	}
	getch();
	closegraph();
}
