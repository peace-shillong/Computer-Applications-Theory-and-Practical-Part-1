#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void mless(int,int,int,int);
void mmore(int,int,int,int);
void mequal(int,int,int,int);
void main(int,int,int,int)
{
	int driver=DETECT,mode;
	int x1,x2,y1,y2,m,ch;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	printf("Enter first coordinate x1:");
	scanf("%d",&x1);
	printf("Enter first coordinate y1:");
	scanf("%d",&y1);
	printf("Enter second coordinate x2:");
	scanf("%d",&x2);
	printf("Enter second coordinate y2:");
	scanf("%d",&y2);
	m=(y2-y1)/(x2-x1);
	if (m>1)
	ch=1;
	if(m<1)

