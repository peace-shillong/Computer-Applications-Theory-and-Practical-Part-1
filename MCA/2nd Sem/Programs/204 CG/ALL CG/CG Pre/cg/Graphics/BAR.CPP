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
void barcart(diag *x,int size,char *name);
void main()
{       //int gd=DETECT,mode;
	int n,maxx,i,j,h[100],Ix,choice;
	char nam[20],* str,c;
	float per[100],Iy;
	diag b[100];
	clrscr();
       // cout<<"Enter The Title"
	cout<<"\n\nNUMBER OF DATA TO BE ENTERED:";
	cin>>n;
	for(i=0;i<n;i++)
	{	cout<<"\n\nEnter the name for data: ";
		cin>>b[i].name;
		cout<<"\n\n\t\tEnter the data"<<i+1<<" : ";
		cin>>b[i].data;
	}
	barcart(b,n,nam);
getch();
}

void barcart(diag *x,int size,char *name)
{       int gd=DETECT,mode;
	int i,Ix,j,h[100],maxx;
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

	initgraph(&gd,&mode,"c:\\tc\\bgi");
	/*Drawing the x-axis and y-axis*/
	SDDA_LINE(100,20,100,420,WHITE);
	SDDA_LINE(100,420,500,420,WHITE);

	//Drawing and labelling the y-axis
	for(i=0,j=maxx+Iy;i<420;i+=20,j-=Iy)
	{	SDDA_LINE(95 ,i-2,105 ,i-2,WHITE);
		gcvt(j,10,str);
		outtextxy(60,i-5,str);
		}
       //	outtextxy(305,449,name);
	//Drawing the Bar diagram

	for(i=0,j=Ix;i<size;j+=(2*Ix),i++)
	{      // delay(500);
		SDDA_LINE(100+j,420,(100+j),420-h[i],WHITE);
		SDDA_LINE(100+(j+Ix),420,100+j+Ix,420-h[i],WHITE);
		SDDA_LINE(100+j,420-h[i],100+(Ix+j),420-h[i],WHITE);
		setfillstyle(SOLID_FILL,i+1);
		floodfill(101+j,415,WHITE);
		outtextxy(95+j,410-h[i],x[i].name);
	}

getch();
}

