#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void polly(float x1,float y1,float x2,float y2,int c);

void main()
{

    int x[10],y[10],n,i,tx,ty,angle,xr,yr;
    int d=DETECT,gm;
    printf("\nHow many coordinates? ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
       printf("\nEnter the coordinates of x %d and y %d: ",i,i);
       scanf("%d %d",&x[i],&y[i]);
    }

    xr=x[1];
    yr=y[1];

    initgraph(&d,&gm,"c:\\tc\\bgi");
    for(i=1;i<n;i++)
    {
	polly(x[i],y[i],x[i+1],y[i+1],4);

    }
    polly(x[n],y[n],x[1],y[1],4);
      getch();

    printf("\n\n Enter the rotation angle : ");
    scanf("%d",&angle);

    printf("\n After Rotation");

    for(i=1;i<=n;i++)
    {
	x[i]=xr+(x[i]-xr)*cos(angle)-(y[i]-yr)*sin(angle);

	y[i]=yr+(x[i]-xr)*sin(angle)+(y[i]-yr)*cos(angle);

    }

    //drawing lines after changing value of x and y
    for(i=1;i<n;i++)
    {
	polly(x[i],y[i],x[i+1],y[i+1],3);
    }
    polly(x[n],y[n],x[1],y[1],3);
    getch();

}
void polly(float x1,float y1,float x2,float y2,int c)
{
	int x,y;
	if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,c);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,c);
		}
	}
	else if(x1==x2)
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,c);
			}
		}
		else
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,c);
			}
		}

	}

}
