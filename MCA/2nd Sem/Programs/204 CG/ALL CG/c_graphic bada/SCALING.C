//Scaling
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void lline(float x1,float y1,float x2,float y2,int c);
void main()
{

    int x[10],y[10],n,i,sx,sy,xf,yf;
    int d=DETECT,gm;
    printf("\nEnter the number of sides : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
	printf("\n\nPoint %d:",i);
       printf("\nEnter the coordinates of x %d and y %d: ",i,i);
       scanf("%d %d",&x[i],&y[i]);
    }
    printf("\n Enter the Scaling factor Sx : ");
    scanf("%d",&sx);
     printf("\n Enter the Scaling factor Sy : ");
    scanf("%d",&sy);

    printf("\n Enter the pivot point(xf,yf) : ");
    scanf("%d %d",&xf,&yf);

    initgraph(&d,&gm,"c:\\tc\\bgi");
    for(i=1;i<n;i++)
    {
	lline(x[i],y[i],x[i+1],y[i+1],4);

    }
    lline(x[n],y[n],x[1],y[1],4);
    getch();
   // clrscr();
    printf("\n After Scaling");

    for(i=1;i<n;i++)
    {
	lline(x[i],y[i],x[i+1],y[i+1],0); //redrawing old line in black color

    }
    lline(x[n],y[n],x[1],y[1],0);

    //transaltion part
    for(i=1;i<=n;i++)
    {
	x[i]=xf+(x[i]-xf)*sx;
	y[i]=yf+(y[i]-yf)*sy;
    }
    for(i=1;i<n;i++)
    {
	lline(x[i],y[i],x[i+1],y[i+1],3);

    }
     lline(x[n],y[n],x[1],y[1],3);
     getch();

    closegraph();
}

void lline(float x1,float y1,float x2,float y2,int c)
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