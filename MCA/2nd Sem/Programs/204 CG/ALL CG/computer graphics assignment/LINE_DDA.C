#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void main()
{

   int gdriver = DETECT, gmode;

   float y,y1,y2,x,x1,x2,m,n;
   printf("\nProgram to draw line using DDA algorithm");

   printf("\n\n\nEnter the  value of starting point X1-axis: ");
   scanf("%f",&x1);
   printf("\n\nEnter the value of starting point y1-axis: ");
   scanf("%f",&y1);
   printf("\n\nEnter the value of ending point x2-axis: ");
   scanf("%f",&x2);
   printf("\n\nEnter the value of ending point y2-axis: ");
   scanf("%f",&y2);

   clrscr();
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   m=(y2-y1)/(x2-x1);

   x = x1;
   y = y1;

   if(m<1)
   {
	if(x<x2)
	{
		while(x<x2)
		{
			putpixel(x,y,18);
			y=y+m;
			x++;
		}
	}
       else
       {
		 while(x>x2)
		{
			putpixel(x,y,18);
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
			putpixel(x,y,18);
			x=x+n;
			y++;
		}
	}
	else
	{
		while(y>y2)
		{
			putpixel(x,y,18);
			x=x-n;
			y--;
		}
	}

   }

   getch();
   closegraph();
}