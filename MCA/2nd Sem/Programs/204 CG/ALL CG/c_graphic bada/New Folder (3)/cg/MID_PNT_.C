#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void main()
{
	int r,xc=0,yc=0;
	int x1,y1,p;
	int driver=DETECT,mode;
	clrscr();

	printf("\n Enter the center for x and y: ");
	scanf("%d %d",&xc,&yc);

	printf("\nEnter radius :");
	scanf("%d",&r);

	initgraph(&driver,&mode,"C:\\tc\\bgi");
	x1=0;
	y1=r;
	p=1-r;

	while(y1>x1)
	{
		if(p<0)
		{
			x1++;
			y1=y1;
			p=p+2*x1+3;
		}
		else
		{
		    x1++;
		    y1=y1-1;
		    p=p+2*x1-2*y1+5;
		}


	       putpixel(xc+x1,yc+y1,WHITE);
	       putpixel(xc+y1,yc+x1,WHITE);
	       putpixel(xc+y1,yc-x1,WHITE);
	       putpixel(xc+x1,yc-y1,WHITE);
	       putpixel(xc-x1,yc-y1,WHITE);
	       putpixel(xc-y1,yc-x1,WHITE);
	       putpixel(xc-y1,yc+x1,WHITE);
	       putpixel(xc-x1,yc+y1,WHITE);
       }
       getch();
       closegraph();
}
