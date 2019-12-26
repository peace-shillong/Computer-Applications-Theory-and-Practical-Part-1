
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void main()
{

   int gdriver = DETECT, gmode, errorcode;

   float y,y1,y2,x,x1,x2,m,n;
   printf("\n\tDrawing line using DDA algorithm");

   printf("\n\n\nEnter the  x1 coordinate:");
   scanf("%f",&x1);
   printf("Enter the  y1 coordinate:");
   scanf("%f",&y1);
   printf("Enter the  x2 coordinate:");
   scanf("%f",&x2);
   printf("Enter the  y2 coordinate:");
   scanf("%f",&y2);

   clrscr();
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   m=(y2-y1)/(x2-x1);

   x=x1;
   y=y1;

   if(m<1)
   {
	if(x<x2)
	{
		while(x<x2)
		{
			putpixel(x,y,BLUE);
			y=y+m;
			x++;
		}
	}
       else
       {
		 while(x>x2)
		{
			putpixel(x,y,WHITE);
			y=y-m;
			x--;
		}
	}

   }
   else if(m>=1)
   {
	n=1/m;
	if(y<y2)
	{
		while(y<y2)
		{
			putpixel(x,y,WHITE);
			x=x+n;
			y++;
		}
	}
	else
	{
		while(y>y2)
		{
			putpixel(x,y,WHITE);
			x=x-n;
			y--;
		}
	}

   }

   getch();
   closegraph();
}