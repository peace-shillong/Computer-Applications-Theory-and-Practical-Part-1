#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<z:\line.h>
#include<dos.h>
#include<process.h>
#include<string.h>
//#define ROUND(a) (int(a+0.5))

typedef struct diag
{		char name[20];
		int data;

 };
void linecart(diag *x,int size,char *name);
void main()
{       //int gd=DETECT,mode;
	int n,maxx,i,j,h[100],Ix;
	char nam[20],* str,c;
	float per[100],Iy;
	diag b[100];
	clrscr();
	cout<<"\n\nNUMBER OF DATA TO BE ENTERED:";
	cin>>n;
	for(i=0;i<n;i++)
	{	cout<<"\n\nEnter the name for data: ";
		cin>>b[i].name;
		cout<<"\n\n\t\tEnter the data: ";
		cin>>b[i].data;
	}
	linecart(b,n,nam);
getch();
}



void linecart(diag * x,int size,char *name)
{	int gd=DETECT,mode;
	int i,Ix,j,h[100],maxx,x1,y1,x2,y2,temp;
	char nam[20],* str;
	float per[100],Iy;

	maxx=x[0].data;
	for(i=0;i<size;i++)
	{	if(maxx<x[i].data)
			maxx=x[i].data;
	}
	for(i=0;i<size;i++)
	{	per[i]=(x[i].data/(float)maxx)*100;
		h[i]=(per[i]*4);
	}

	Ix= ROUND(400/(2*size));
	Iy=(maxx/20);

	initgraph(&gd,&mode,"");


	/*Drawing the x-axis and y-axis*/
	SDDA_LINE(100,20,100,420,WHITE);
	SDDA_LINE(100,420,500,420,WHITE);

	//Drawing and labelling the y-axis
	for(i=0,j=maxx+Iy;i<420;i+=20,j-=Iy)
	{	SDDA_LINE(95 ,i-2,105 ,i-2,WHITE);
		gcvt(j,10,str);
		outtextxy(60,i-5,str);
	}

       x1=100;
       y1=420;

       for(i=0,j=Ix;i<size;j+=(2*Ix),i++)
	{       //delay(500);
		x2=100+j;
		y2=420-h[i];
		setcolor(RED);
		if(i==0)
			setcolor(BLACK);
		SDDA_LINE(x1,y1,x2,y2,WHITE);
		x1=x2;	y1=y2;
		setcolor(RED);
		D_circle(x1,y1,2,YELLOW);
		setfillstyle(SOLID_FILL,i+1);
		floodfill(x1,y1,YELLOW);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(95+j,400-h[i],x[i].name);
	}
	getch();
}




