//program to draw a filled polygon using scanline filling algorithm

#include<graphics.h>
#include<conio.h>
#include<stdio.h>
struct Coordinate
{
	int x,y;
};
typedef struct Coordinate Coordinate;

void drawLine(int x1, int y1, int x2, int y2);
int sign(int x);
void drawPolygon(Coordinate pts[],int n);
int isVertex(int x, int y,Coordinate pts[],int n);
void fillPolygon(Coordinate pts[],int n);

void main()
{
	int driver=DETECT,mode;
	int i,n;
	Coordinate pts[100];
	printf("\nEnter the number of co-ordinates:");
	scanf("%d",&n);
	for(i=0;i< n;i++)
	{
		printf("\nEnter the %d-coordinate:",i+1);
		scanf("%d",&pts[i].x);
		printf("\nEnter the %d-coordinate:",i+1);
		scanf("%d",&pts[i].y);
	}
	pts[i]=pts[0];
	initgraph(&driver,&mode,"");
	drawPolygon(pts,n);
	fillPolygon(pts,n);
	getch();
	closegraph();
}

void drawLine(int x1,int y1,int x2,int y2)
{
	int x,y,dx,dy,s1,s2,swap=0,pk;
	int temp,i;
	x=x1;
	y=y1;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		swap=1;
	}
	pk=2*dy-dx;
	for(i=0;i<dx;i++)
	{
		putpixel(x,y,WHITE);
		while(pk>=0)
		{
			pk=pk-2*dx;
			if(swap)
			x=x+s1;
			else
			y=y+s2;
		}
		pk=pk+2*dy;
		if(swap)
		y=y+s2;
		else
		x=x+s1;
	}
}

int sign(int x)
{
	if(x>0)
	return 1;
	else if(x<0)
	return(-1);
	else
	return 1;
}

void drawPolygon(Coordinate pts[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	drawLine(pts[i].x,pts[i].y,pts[i+1].x,pts[i+1].y);
	}
}

int isVertex(int x,int y,Coordinate pts[],int n)
{
	int i,found=0;
	for(i=0;i<n;i++)
	if(pts[i].x==x && pts[i].y==y)
	{
		found=1;
		break;
	}
	return found;
}

void fillPolygon(Coordinate pts[],int n)
{
	int i,j,k,minX,minY,maxX,maxY;
	int intersect=0;
	minX=maxX=pts[0].x;
	minY=maxY=pts[0].y;
	for(i=1;i<n;i++)
	if(pts[i].x<minX)
	minX=pts[i].x;
	for(i=1;i<n;i++)
	if(pts[i].y<minY)
	minY=pts[i].y;
	for(i=1;i<n;i++)
	if(pts[i].x>maxX)
	maxX=pts[i].x;
	for(i=1;i<n;i++)
	if(pts[i].y>maxY)
	maxY=pts[i].y;
	intersect=0;
	for(i=minY;i<maxY;i++,intersect=0)
		for(j=minX;j<maxX;j++)
		{
		     if(isVertex(j,i,pts,n))
		     {
			for(k=j+1;k<=maxX;k++)
			{
				if(getpixel(k,i)==WHITE && !isVertex(k,i,pts,n))
				{
					intersect=1;
					break;
				}
			}
			if(!intersect)
				continue;
			else
				j++;
		     }
		     if(intersect)
			     if(getpixel(j,i)==WHITE)
			     {
					if(getpixel(j+1,i)==WHITE)
						while(getpixel(j,i)==WHITE)
							j++;
					intersect = 0;
					continue;
			     }
			     else
			     {
				putpixel(j,i,BLUE);
				delay(10);
			     }
		     else
			     if(getpixel(j,i)==WHITE && !isVertex(j,i,pts,n))
			     {
					if(getpixel(j+1,i)==WHITE)
						while(getpixel(j,i)==WHITE)
							j++;
					intersect = 1;
					continue;
			     }
		}
}

