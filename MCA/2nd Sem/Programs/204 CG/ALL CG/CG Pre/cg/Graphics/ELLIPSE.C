#include<graphics.h>
#include<stdio.h>
#include<conio.h>
void plot(float,float,float,float);

void main()
{
	int p,px,py,x,y,Rx2,Ry2,Rx,Ry,twoRy2,twoRx2;
	int xcenter,ycenter;
	int driver,mode;
	driver=DETECT;
	initgraph(&driver,&mode,"h:\\software\\tc\\bgi");
	clrscr();
	Ry2=Ry*Ry;
	Rx2=Rx*Rx;
	twoRy2=2*Ry2;
	twoRx2=2*Rx2;
	printf("Enter The Two Radius");
	scanf("%d %d",&xcenter,&ycenter);
	printf("Enter The Two Co-ordinates:");
	scanf("%d %d",&Rx,&Ry);
	x=0;
	y=Ry;
	plot(xcenter,ycenter,x,y);
	p=(Ry2-Rx2*Ry+(0.25*Rx2));
	px=0;
	py=twoRx2*y;
	while(px<py)
	{
		x=x+1;
		px=px+twoRy2;
		if(p>0)
		{
			y=y-1;
			py=py-twoRx2;
		}
		if(p<0)
		   p=p+Ry2+px;
		else
		   p=p+Ry2+px-py;
		plot(xcenter,ycenter,x,y);
	}//end of while
		p=(Ry2*(x+0.5)*(x+0.5)+Rx2*(y-1)*(y-1)-Rx2*Ry2);
		while(y>0)
		{
			y=y-1;
			py=py=twoRx2;
			if(p<=0)
			{
				x=x+1;
				px=px+twoRy2;
			}
			if(p>0)
			{
				p=p+Rx2-py;
			}
			else
			{
				p=p+Rx2-py+px;
			}
			plot(xcenter,ycenter,x,y);
		}//end of while
	getch();

}

void plot(float xcenter,float ycenter,float x,float y)
{
       //	int xcenter,ycenter,x,y;
	putpixel(xcenter+x,ycenter+y,1);
	putpixel(xcenter-x,ycenter+y,1);
	putpixel(xcenter+x,ycenter-y,1);
	putpixel(xcenter-x,ycenter-y,1);
}