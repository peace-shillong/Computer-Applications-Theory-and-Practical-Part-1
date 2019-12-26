#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void drawcircle(int,int,int);
void main()
{
      int gd,gm,xc,yc,r;
      gd=DETECT;
      clrscr();
      printf("\n\t Enter the centre(xc and yc): ");
      scanf("%d %d",&xc,&yc);
      printf("\n\t Enter the radius: ");
      scanf("%d",&r);
      initgraph(&gd,&gm,"c:\\tc\\bgi");
      drawcircle(xc,yc,r);
      getch();
      closegraph();
}
void drawcircle(int xc,int yc,int r)
{
	int x,maxx,i,y,pk;
	x=0;
	y=r;
	pk=1-r;
	while(x<y)
	{

		if(pk<0)
		{
			pk=pk+2*x+3;
			x=x+1;
			y=y;

		}
		else
		{
			pk=pk+2*x-2*y+5;
			x=x+1;
			y=y-1;

		}
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+y,yc+x,WHITE);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc-y,yc-x,WHITE);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc-x,yc+y,WHITE);
	}
}


