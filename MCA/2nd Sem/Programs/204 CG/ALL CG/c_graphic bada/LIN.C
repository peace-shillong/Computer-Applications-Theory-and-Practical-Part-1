#include<graphics.h>
#include<conio.h>
void main(){
	float x1,x2,y1,y2, gd , dr , x,y ;

	clrscr();
	dr=DETECT;
	initgraph(&dr,&gd,"c:\\Tc\\bgi");
	printf("\nEnter the value of x -coordinate of start point:");
	scanf("%d",&x1);
	printf("\nEnter the value of y -coordinate of start point");
	scanf("%d",&y1);
	printf("\nEnter the value of x -coordinate of end point:");
	scanf("%d",&x2);
	printf("\nEnter the value of y -coordinate of end point:");
	scanf("%d",&y2);
	for(x=x1;x<=x2;x++)
	{
		float r1, r2, r3;
		r1 = x-x1 ;
		r2 = x1-x2;
		r3 = y1-y2 ;
		y=((r1)/(r2))*(r3)+y1;
		putpixel(x,y,YELLOW);
	}
	getch();
	closegraph();
}