#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
	int driver=DETECT,mode;
	int rad,x,y,i,j,x1,y1,r,p;
	printf("Enter The Radius:");
	scanf("%d",&r);
	printf("Enter The Centre Co-ordinates:");
	scanf("%d %d",&x1,&y1);
	initgraph(&driver,&mode,"");
	p=1-r;
	x=0;
	y=r;
	while(x<y)
	{
		putpixel(x1+x,y1+y,1);
		putpixel(x1+x,y1-y,1);
		putpixel(x1-x,y1+y,1);
		putpixel(x1-x,y1-y,1);
		putpixel(x1+y,y1+x,1);
		putpixel(x1+y,y1-x,1);
		putpixel(x1-y,y1+x,1);
		putpixel(x1+x,y1-y,1);
		putpixel(x1-y,y1-x,1);



		if(p<=0)
		     {
			p=p+(2*x)+3;
			x=x+1;
		     }
		else
		     {
			p=p+(2*x)-(2*y)+5;
			x=x+1;
			y=y-1;
		     }
	}
	getch();
}






