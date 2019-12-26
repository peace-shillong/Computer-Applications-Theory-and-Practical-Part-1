#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void draw_line(float ,float ,float ,float );
void main()
{

    int x[10],y[10],n,i;
    int d=DETECT,gm;
    printf("\nNumber of coordinates:");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
	printf("\nEnter the coordinates of x%d:",i);
	scanf("%d",&x[i]);
	printf("\nEnter the coordinates of y%d:",i);
	scanf("%d",&y[i]);
    }
    initgraph(&d,&gm,"c:\\tc\\bgi");
    for(i=1;i<n;i++)
    {
	draw_line(x[i],y[i],x[i+1],y[i+1]);

    }
    draw_line(x[n],y[n],x[1],y[1]);
    getch();
    closegraph();
}

void draw_line(float x1,float y1,float x2,float y2)
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