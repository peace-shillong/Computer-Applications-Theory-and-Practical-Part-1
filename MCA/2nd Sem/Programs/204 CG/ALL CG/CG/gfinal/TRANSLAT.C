//translation program

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
void draw_line(float ,float ,float ,float );
void main()
{

    float x[10],y[10],newx[10],newy[10],tx,ty;
    int d=DETECT,gm,n,i,dir;
    float rotamtrix[2][2],angle;
    printf("\nEnter the number of coordinates--->");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
	printf("\nEnter the coordinates of x%d and y%d--->",i,i);
       scanf("%f %f",&x[i],&y[i]);
    }
    printf("\nEnter the Translation factor--->");
    printf("\nTx--->");
    scanf("%f",&tx);
    printf("\nTy--->");
    scanf("%f",&ty);
    initgraph(&d,&gm,"");
    outtextxy(20,20,"Before Translation");
    for(i=1;i<n;i++)
    {
	draw_line(x[i],y[i],x[i+1],y[i+1]);

    }
    draw_line(x[n],y[n],x[1],y[1]);
    getch();
    clrscr();
    setbkcolor(BLACK);



    for(i=1;i<=n;i++){
    x[i]+=tx;
    y[i]+=ty;

    }
    outtextxy(20,200,"After Translation");
    //setbkcolor(BLACK);
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