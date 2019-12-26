#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
	 int driver=DETECT,mode,x1,y1,x2,y2;
	 float dx,dy,xi,yi,x,y,i,t;
	 clrscr();
	 printf("\nEnter the starting points: ");
	 scanf("%d %d",&x1,&y1);
	 printf("\nEnter the ending points: ");
	 scanf("%d %d",&x2,&y2);
	 initgraph(&driver,&mode,"c:\\tc\\bgi");
	 dx=x2-x1;
	 dy=y2-y1;
	 if(abs(dx)>abs(dy))
		 t=abs(dx);
	 else
		 t=abs(dy);

	 xi=dx/t;
	 yi=dy/t;
	 x=x1;
	 y=y1;
	 for(i=1;i<t;i++)
	 {
		  x=x+xi;
		  y=y+yi;
		  putpixel(x,y,RED);
	 }

	 getch();
	 closegraph();
}