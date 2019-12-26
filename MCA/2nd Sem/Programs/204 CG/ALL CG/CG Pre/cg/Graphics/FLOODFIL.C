#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void fill_right(int x,int y)
{
	if(getpixel(x,y)==0)
	{
		putpixel(x,y,RED);
		fill_right(++x,y);
		x=x-1;
		fill_right(x,y-1);
		fill_right(x,y+1);
	}
}
void fill_left(int x,int y)
{
      if(getpixel(x,y)==0)
	{
		putpixel(x,y,RED);
		fill_left(--x,y);
		x=x+1;
		fill_left(x,y-1);
		fill_left(x,y+1);
	}
}
void main()
{
	int x,y,a[10][10];
	int gd,gm,n,i;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"c:\\tc\\bgi") ;
	printf("\n\n\tEnter the number of edges of polygon:");
	scanf("%d",&n);
	printf("Enter the coordinate of polygon:\n\n\n");
	for(i=0;i<n;i++)
	{
		printf("\tx%d y%d:",i,i) ;
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	a[n][0]=a[0][0];
	a[n][1]=a[0][1];
	printf("\n\n\tEnter the seed point:");
	scanf("%d%d",&x,&y);
	cleardevice();
	setcolor(WHITE);
	for(i=0;i<n;i++)
	{
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}
	fill_right(x,y);
	fill_left(x-1,y);
	getch();
}
