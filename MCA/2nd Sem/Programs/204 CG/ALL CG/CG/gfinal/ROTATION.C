//rotaion program
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
void draw_line(float ,float ,float ,float );
void main()
{

    float x[10],y[10],newx[10],newy[10],pvx,pvy;
    int d=DETECT,gm,n,i,dir;
    float rotamtrix[2][2],angle;
    printf("\nEnter the number of coordinates--->");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
       printf("\nEnter the coordinates of x%d and y%d: ",i,i);
       scanf("%f %f",&x[i],&y[i]);
    }
    printf("\nEnter the rotation angle--->");
    scanf("%f",&angle);

    printf("\nEnter the pivot point--->");
    scanf("%f %f",&pvx,&pvy);
    printf("\n\nEnter The direction:\tClockwise(0) or anticlockwise(1))--->");
    scanf("%d",&dir);

    initgraph(&d,&gm,"");
    outtextxy(20,20,"Before Rotation");
    for(i=1;i<n;i++)
    {
	draw_line(x[i],y[i],x[i+1],y[i+1]);

    }
    draw_line(x[n],y[n],x[1],y[1]);
    getch();

    setbkcolor(BLACK);
    if(dir==1){
	for(i=1;i<=n;i++){
		newx[i]=pvx+(x[i]-pvx)*cos(angle)-((pvy-y[i])*sin(angle));
		newy[i]=pvy+(x[i]-pvx)*sin(angle)+((pvy-y[i])*cos(angle));

		}
    }
    else{
	for(i=1;i<=n;i++){
		newx[i]=pvx+(x[i]-pvx)*cos(-angle)-(pvy-y[i])*sin(-angle);
		newy[i]=pvy+(x[i]-pvx)*sin(-angle)+(pvy-y[i])*cos(-angle);
	}
    }
    //setbkcolor(BLACK);
    clrscr();
    setcolor(RED);
    outtextxy(20,400,"After Rotation");
    for(i=1;i<n;i++)
    {
	draw_line(newx[i]+50,newy[i]+100,newx[i+1]+50,newy[i+1]+100);

    }
    draw_line(newx[n]+50,newy[n]+100,newx[1]+50,newy[1]+100);
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