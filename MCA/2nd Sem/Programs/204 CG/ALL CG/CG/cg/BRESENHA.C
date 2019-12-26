	/*DRAWING A LINE USING BRESHEMHAM'S ALGORITHM*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
	int driver=DETECT,mode;
	int dx,xa,xb,dy,ya,r,x1,y1,yb,p,x,y,xend,m,i;
	initgraph(&driver,&mode,"");

	printf("Enter The 1st Co-ordinates:");
	scanf("%d %d",&xa,&ya);

	printf("Enter The 1st Co-ordinates:");
	scanf("%d %d",&xb,&yb);

	dx=abs(xa-xb);
	dy=abs(ya-yb);
	p=(2*dy)-dx;

	if(xa>xb)
	{
		x=xb;
	       if(ya>yb)
		y=yb;
	       else
		y=ya;
		xend=xa;
	}
	else
	{
		x=xa;
	       if(ya>yb)
		y=ya;
	       else
		y=yb;
		xend=xb;
	}
	putpixel(x,y,1);

	while(x<xend)
	{
		x=x+1;
		if(m==1)
			y=y+1;
		if(dx==0)
			y=y+1;
		if(dy==0)
			x=x+1;
		if(p<0)
			p=p+(2*dy);
		else
		{
			y=y+1;
			p=p+2*(dy-dx);
		}
		putpixel(x,y,1);
	}
	getch();
}

