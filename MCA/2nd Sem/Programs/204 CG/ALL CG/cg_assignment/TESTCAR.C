#include <graphics.h>
#include <dos.h>
#include <conio.h>
void drawline(int x1,int y1,int x2,int y2);

main()
{
   int i, j = 0, gd = DETECT, gm;

   initgraph(&gd,&gm,"C:\\TC\\BGI");

   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(25,240,"Press any key");

   getch();
   setviewport(0,0,639,440,1);

   for( i = 0 ; i <= 420 ; i = i + 10, j++ )
   {
      rectangle(50+i,275,150+i,400);
      rectangle(150+i,350,200+i,400);
      circle(75+i,410,10);
      circle(175+i,410,10);
      setcolor(j);
      delay(50);

      if( i == 420 )
	 break;

      clearviewport();
   }

   getch();
   closegraph();
   return 0;
}
void drawline(int x1,int y1,int x2,int y2)
{
	int x,y;
	if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,WHITE);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,WHITE);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,WHITE);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,WHITE);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,WHITE);

	}

}

