//drawing lines using dda
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void main()
{
   int gd = DETECT, gm;
   float y,y1,y2,x,x1,x2,m,n;
   printf("Enter for the  x1 coordinate:");
   scanf("%f",&x1);
   printf("Enter for the  y1 coordinate:");
   scanf("%f",&y1);
   printf("Enter for the  x2 coordinate:");
   scanf("%f",&x2);
   printf("Enter for the  y2 coordinate:");
   scanf("%f",&y2);
   clrscr();
   initgraph(&gd, &gm, "c:\\tc\\bgi");

   m=(y2-y1)/(x2-x1);

   x=x1;
   y=y1;

   if(m<1)
   {
	if(x<x2)
	{
		while(x<x2)
		{
			putpixel(x,y,YELLOW);
			y=y+m;
			x++;
		}
	}
       else
       {
		 while(x>x2)
		{
			putpixel(x,y,YELLOW);
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
			putpixel(x,y,YELLOW);
			x=x+n;
			y++;
		}
	}
	else
	{
		while(y>y2)
		{
			putpixel(x,y,YELLOW);
			x=x-n;
			y--;
		}
	}

   }
   getch();
   closegraph();
}