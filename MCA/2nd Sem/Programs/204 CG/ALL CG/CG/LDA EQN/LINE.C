
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm;
int X1,Y1,X2,Y2,x,y;
clrscr();
initgraph(&gd,&gm,"C:\\TC\\BGI");
printf("\n Enter the starting point");
printf("\n Enter the x coordinate\n");
scanf("%d",&X1);
printf("\n Enter the y coordinate\n");
scanf("%d",&Y1);
printf("\n Enter the ending point");
printf("\n Enter the x coordinate\n");
scanf("%d",&X2);
printf("\n Enter the y coordinate\n");
scanf("%d",&Y2);
clrscr();

	if(X1<X2)
	{
	for(x=X1;x<X2;x++)
    {
    //y=Y1;
    y=Y1+((Y1-Y2)/(X1-X2))*(x-X1);
    putpixel(x,y,RED);
    }
	}
	else if(X1>X2)
	{
		for(x=X2;x<=X1;x--)
	      {
	y=Y1+((Y1-Y2)/(X1-X2))*(x-X1);
	putpixel(x,y,RED);
	      }
	}
	else
	{
		printf("\nx1 X2 are equal");
		if(Y2<Y1)
		{
		   {
		   for(X1=X2;Y2<Y1;Y1--)
		   {
		       y=Y1+((Y1-Y2)/(X1-X2))*(x-X1);
		       putpixel(x,y,RED);
		   }
		}
		else if(Y1>Y2)
		{
			printf("\ny2 greater");
		}
		else
		{
			printf("\ny1=y2 greater");
		}
	}
getch();
closegraph();
}




