#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int x1 , x2 , y1 , y2, m , x ,y ,gd,dr;
	clrscr();
	dr=DETECT;
	initgraph(&dr,&gd,"c:\\Tc\\bgi");
	printf("\nEnter for x1:");
	scanf("%d",&x1);
	printf("\nEnter for y1:");
	scanf("%d",&y1);
	printf("\nEnter for x2:");
	scanf("%d",&x2);
	printf("\nEnter for y2:");
	scanf("%d",&y2);
	m = (y2-y1)/(x2-x1);
	if(m<1){
		for(x=x1;x<=x2;x++)
			{
				for(y=y1;y<=y2;y++)
				{
				    y1=y1+m;
				putpixel(x,y1,YELLOW);
				}
			}
     }

	getch();
	closegraph();
}
