#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void drawpoly(float,float,float,float,int);
void main()
{
	int n,i,j,k,gd,gm,dy,dx;
	int x,y,temp,col;
	int a[20][20],xi[20];
	float slope[20];
	int driver=DETECT,mode;
	clrscr();
	printf("\n\nEnter how many edges:");
	scanf("%d",&n);
	printf("\n\nEnter the coordinate :\n\n\n");
	for(i=0;i<n;i++)
	{
		printf("X[%d] Y[%d]:",i,i);
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	a[n][0]=a[0][0];
	a[n][1]=a[0][1];
	printf("\n\nWhich color:");
	printf("\n\n 1. Blue");
	printf("\n\n 2. Green");
	printf("\n\n 3. Cyan");
	printf("\n\n 4. Red");
	printf("\n\n 5. Magenta");
	printf("\n\n 6. Brown");
	printf("\n\n 7. Light Grey");
	printf("\n\n 8. Dark Grey");
	printf("\n\n 9. Light Blue");
	printf("\n\n 10. Light Green");

	printf("\n");
	scanf("%d",&col);

       //	clrscr();
	initgraph(&driver,&mode,"c:\\tc\\bgi");
       //	detectgraph(&gd,&gm,"c:\\tc\\bgi");
       //	//draw polygon
	for(i=0;i<n;i++)
	{
		drawpoly(a[i][0],a[i][1],a[i+1][0],a[i+1][1],col);
	}
	for(i=0;i<n;i++)
	{
		dy=a[i+1][1]-a[i][1];
		dx=a[i+1][0]-a[i][0];
		if(dy==0)slope[i]=1.0;
		if(dx==0)slope[i]=0.0;
		if((dy!=0)&&(dx!=0))
		{
			slope[i]=(float)dx/dy;
		}
	}
	for(y=0;y<480;y++)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			if(((a[i][1]<=y) &&(a[i+1][1]>y))||((a[i][1]>y)&&(a[i+1][1]<=y)))
			{
				xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
				k++;
			}
		}
		for(j=0;j<k-1;j++)
			for(i=0;i<k-1;i++)
			{
				if(xi[i]>xi[i+1])
				{
					temp=xi[i];
					xi[i]=xi[i+1];
					xi[i+1]=temp;

				}
			}

			for(i=0;i<k;i+=2)
			{
				drawpoly(xi[i],y,xi[i+1]+1,y,col);

			}
			}
			getch();
			closegraph();
}

void drawpoly(float x1,float y1,float x2,float y2,int col)
{
	int x,y;
	if(x1<x2)
	{
		for(x=x1;x<x2;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,col);
		}
	}
	else if(x1>x2)
	{
		for(x=x2;x<x1;x++)
		{
			y=y1+(((x-x1)*(y1-y2))/(x1-x2));
			putpixel(x,y,col);
		}
	}
	else
	{
		x=x1;
		if(y1<y2)
		{
			for(y=y2;y<y1;y--)
			{
				putpixel(x,y,col);
			}
		}
		else
		{
			for(y=y1;y<y2;y++)
			{
				putpixel(x,y,col);
			}
		}

	}
	if(x1==x2 && y1==y2)
	{
	      x=x1;
	      y=y1;
	      putpixel(x,y,col);

	}
}