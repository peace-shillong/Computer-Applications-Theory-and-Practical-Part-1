#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<math.h>
void triangle(int x1,int y1,int x2,int y2,int x3,int y3);
void rotate(int x1,int y1,int x2,int y2,int x3,int y3);
void scale(int x1,int y1,int x2,int y2,int x3,int y3 );
void translate(int x1,int y1,int x2,int y2,int x3,int y3 );
void main()
{
	int ch;
	int gd=DETECT,gm;
	int x1,y1,x2,y2,x3,y3;
	clrscr();
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	printf("Enter the first position of triangle");
	scanf("%d%d",&x1,&y1);
	printf("Enter the second position of triangle");
	scanf("%d%d",&x2,&y2);
	printf("Enter the third position of triangle");
	scanf("%d%d",&x3,&y3);
	triangle(x1,y1,x2,y2,x3,y3);
	getch();
      //	cleardevice();

	 setcolor(1);
       do
       {
	printf("-------------MENU---------------------");
	printf("\n1)Translate\n2)Scale\n3)rotate\n4)exit");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	cleardevice();
	switch(ch)
	{
		case 1:translate(x1,y1,x2,y2,x3,y3);
			break;
		case 2: scale(x1,y1,x2,y2,x3,y3 );
			break;
		case 3: rotate(x1,y1,x2,y2,x3,y3 );
			break;
		case 4: exit(0);
			break;
		default:printf("Entered wrong choice");
			break;
	}
	}while(ch!=4);
      //	getch();
	closegraph();
	getch();
}
void triangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
}
void rotate(int x1,int y1,int x2,int y2,int x3,int y3)
{
	int x,y,a1,b1,a2,b2,a3,b3,p=x2,q=y2;
	float angle;
	printf("Enter the angle of rotation");
	scanf("%f",&angle);
	cleardevice();
	angle=(angle*3.14)/180 ;
	a1=p+(x1-p)*cos(angle)-(y1-q)*sin(angle);
	b1=q+(x1-p)*sin(angle)+(y1-q)*cos(angle);
	a2=p+(x2-p)*cos(angle)-(y2-q)*sin(angle);
	b2=q+(x2-p)*sin(angle)+(y2-q)*cos(angle);
	a3=p+(x3-p)*cos(angle)-(y3-q)*sin(angle);
	b3=q+(x3-p)*sin(angle)+(y3-q)*cos(angle);
	printf("Rotate");
	triangle(a1,b1,a2,b2,a3,b3);
	getch();
}
void scale(int x1,int y1,int x2,int y2,int x3,int y3 )
{
	int x,y,a1,a2,a3,b1,b2,b3;
	int mx,my;
	printf("Enter the scaling coordinates");
	scanf("%d%d",&x,&y);
	mx=(x1+x2+x3)/3;
	my=(y1+y2+y3)/3;
	cleardevice();
	a1=mx+(x1-mx)*x;
	b1=my+(y1-my)*y;
	a2=mx+(x2-mx)*x;
	b2=my+(y2-my)*y;
	a3=mx+(x3-mx)*x;
	b3=my+(y3-my)*y;
	triangle(a1,b1,a2,b2,a3,b3);
	getch();
}
void translate(int x1,int y1,int x2,int y2,int x3,int y3 )
{
	int x,y,a1,a2,a3,b1,b2,b3;
	printf("Enter transection coordinate");
	scanf("%d%d",&x,&y);
	cleardevice();
	a1=x1+x;
	b1=y1+y;
	a2=x2+x;
	b2=y2+y;
	a3=x3+x;
	b3=y3+y;
	triangle(a1,b1,a2,b2,a3,b3);
	getch();
}