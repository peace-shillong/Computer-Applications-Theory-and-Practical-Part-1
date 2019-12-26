//scalling program

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
void draw_line(float ,float ,float ,float );
void main()
{

    float x[10],y[10],newx[10],newy[10],Sx,Sy;
    int d=DETECT,gm,n,i,dir;
    float rotamtrix[2][2],angle,alignx,aligny;
    printf("\nEnter the no. of coordinates--->");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
	printf("\nEnter x%d and y%d--->",i,i);
       scanf("%f %f",&x[i],&y[i]);
    }
    printf("\nEnter the Scaling factor--->");
    printf("\nSX--->");
    scanf("%f",&Sx);
    printf("\nSY--->");
    scanf("%f",&Sy);
    alignx=Sx*50;
    aligny=Sy*100;
    initgraph(&d,&gm,"");
      outtextxy(20,400,"BEFORE SCALING");
    for(i=1;i<n;i++)
    {
	draw_line(x[i],y[i],x[i+1],y[i+1]);

    }
    draw_line(x[n],y[n],x[1],y[1]);
    getch();
    clrscr();
    setbkcolor(BLACK);


    setcolor(RED);
    for(i=1;i<=n;i++){
    x[i]*=Sx;
    y[i]*=Sy;

    }
      outtextxy(20,400,"AFTER SCALING");
    //setbkcolor(BLACK);
    for(i=1;i<n;i++)
    {
	draw_line(x[i]-alignx,y[i]-aligny,x[i+1]-alignx,y[i+1]-aligny);

    }
    draw_line(x[n]-alignx,y[n]-aligny,x[1]-alignx,y[1]-aligny);
    getch();
    closegraph();
}

void draw_line(float x1,float y1,float x2,float y2)
{
   float x,y;
   if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,RED);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,RED);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,RED);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,RED );
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