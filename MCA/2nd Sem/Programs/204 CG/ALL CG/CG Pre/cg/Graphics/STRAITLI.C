		     /*Drawing a straight line*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	int driver,mode;
       //	int xa=100,xb=800,yb=600,ya=100,x;
       int xa,xb,ya,yb,x,i,y;
	driver=DETECT;
	initgraph(&driver,&mode,"h:\\software\\tc\\bgi");
	clrscr();
	printf("Enter the First x co-ordinate:");
	scanf("%d",&xa);

	printf("Enter The First y co-ordinate:");
	scanf("%d",&ya);

	printf("Enter The Last x co-ordinate:");
	scanf("%d",&xb);

	printf("Enter The Last y co-ordinate:");
	scanf("%d",&yb);

	for(i=xa;i<=xb;i++)
	{

		y=(((i-xa)*(ya-yb))/(xa-xb))+ya;
		putpixel(i,y,3);
	}
	getch();
}

