#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void poly(float,float,float,float);
void main()
{

    int x[10],y[10],n,i,tx,ty;
    int gd=DETECT,gm;
    clrscr();

    printf(" Enter the number of coordinates: ");
    scanf("%d",&n);

     printf("\n Translation");
     for(i=0;i<3;i++)
     {
	printf("\n\nEnter the coordinates of x%d and y%d of the triangle: ",i,i);
	scanf("%d %d",&x[i],&y[i]);
     }
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	for(i=0;i<2;i++)
	{
		poly(x[i],y[i],x[i+1],y[i+1]);

	}
	poly(x[2],y[2],x[0],y[0]);

	printf("\n\n Enter the translation factor(tx,ty):");
	scanf("%d %d",&tx, &ty);
	clrscr();
	x[0]=x[0]+tx;
	y[0]=y[0]+ty;
	x[1]=x[1]+tx;
	y[1]=y[1]+ty;
	x[2]=x[2]+tx;
	x[2]=x[2]+ty;
	for(i=0;i<2;i++)
	{
		//x[i]=x[i]+tx;
		//y[i]=y[i]+ty;
		poly(x[i],y[i],x[i+1],y[i+1]);
	}
	 poly(x[2],y[2],x[0],y[0]);

    getch();
    closegraph();
}
void poly(float x1,float y1,float x2,float y2)
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