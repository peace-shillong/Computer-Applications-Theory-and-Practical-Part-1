//Line Drawing Algorithm - Bresenham
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
      int gd = DETECT, gm;
      int dx, dy, p, end;
      float x1, x2, y1, y2, x, y;

      printf("\n\nProgram to draw line using Breshenham's line algorithm");
      printf("\n-------------------------------------------------------");

      printf("\n\nEnter Value of starting point X1-axis: ");
      scanf("%f", &x1);
      printf("\n\nEnter Value of starting point Y1-axis: ");
      scanf("%f", &y1);
      printf("\n\nEnter Value of ending point X2-axis: ");
      scanf("%f", &x2);
      printf("\n\nEnter Value of ending point Y2-axis: ");
      scanf("%f", &y2);

      clrscr();
      initgraph(&gd, &gm, "c:\tc\bgi");

      dx = (x2 - x1);
      dy = (y2 - y1);
      p = 2 * dy - dx;

      x = x1;
      y = y1;

      for(x=x1;x<x2;x++)
      {
	    if(p < 0)
	    {
		  p = p + 2 * dy;
	    }
	    else
	    {
		  y = y + 1;
		  p = p + 2 * (dy - dx);
	    }
	    putpixel(x, y, 18);
      }
      getch();
      closegraph();
}
