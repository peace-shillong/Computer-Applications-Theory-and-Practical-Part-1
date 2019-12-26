#include<conio.h>
#include<graphics.h>
void main()
{
	int driver,mode,m,x1,y1,x2,y2,x,y,i;
	clrscr();
	driver = DETECT;
	printf("\nEnter the starting point:");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter the ending point:");
	scanf("%d%d",&x2,&y2);
	initgraph(&driver,&mode,"Z:\\tc\tc\bgi");
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