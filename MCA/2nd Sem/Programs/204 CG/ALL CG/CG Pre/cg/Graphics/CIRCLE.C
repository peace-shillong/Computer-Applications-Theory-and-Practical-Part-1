			  /*DRAWING A CIRCLE*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
	int driver=DETECT,mode;
	int rad,x,y,i,j,x1,y1,r;
	initgraph(&driver,&mode,"");
	printf("Enter The Radius:");
	scanf("%d",&r);
	printf("Enter The Co-ordinates:");
	scanf("%d %d",&x1,&y1);
	clrscr();
	initgraph(&driver,&mode,"");
	for(x=x1-r;x<=x1+r;x++)
	{
		y=y1+(sqrt(r*r-pow((x1-x),2)));
		putpixel(x,y,1);
		y=y1-sqrt(r*r-pow((x1-x),2));
		putpixel(x,y,1);
	}

	for(y=y1-r;y<=y1+r;y++)
	{
		x=x1+sqrt(r*r-pow((y1-y),2));
		putpixel(x,y,3);
		x=x1-sqrt(r*r-pow((y1-y),2));
		putpixel(x,y,1);
	}
getch();
}