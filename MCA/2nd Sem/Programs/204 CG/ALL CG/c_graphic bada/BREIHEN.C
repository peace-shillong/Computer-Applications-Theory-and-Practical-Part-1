
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
      int gd = DETECT, gm;
      int dx, dy, p, end;
      float x1, x2, y1, y2, x, y ;
      printf("Enter Value for first coordinate x1: ");
      scanf("%f", &x1);
      printf("Enter Value for first coordinate y1: ");
      scanf("%f", &y1);
      printf("Enter Value for second coordinate x2: ");
      scanf("%f", &x2);
      printf("Enter Value for second coordinate y2: ");
      scanf("%f", &y2);
      clrscr();
      initgraph(&gd,&gm,"c:\tc\bgi");
      dx = x2 - x1;
      dy = y2 - y1;
      p = 2 * dy - dx;
      x= x1;
      y= y1;

      for(x=x1;x<x2;x++)
      {
		if(p>0)
		{
			y++ ;
			p= p + 2 * (dy-dx);
		}
		else
		{

			p= p + 2 * dy ;
		}
		putpixel(x, y, YELLOW);
      }

	getch();
	closegraph();
}
