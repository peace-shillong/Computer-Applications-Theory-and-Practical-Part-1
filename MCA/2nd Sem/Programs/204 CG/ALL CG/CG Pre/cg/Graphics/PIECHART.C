
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<string.h>

struct Data
{
	char items[30];
	int data;
	int itemColor;
};
typedef struct Data Data;

struct Coordinate
{
	int x,y;
};
typedef struct Coordinate Coordinate;

struct Queue
{
	int x;
	int y;
	struct Queue* next;
};
typedef struct Queue Queue;

Queue* front=NULL;
Queue* rear=NULL;

void enQueue(int x,int y)
{
	Queue * p = (Queue *)malloc(sizeof(Queue));
	if(p == NULL)
	{
		printf("Queue is full");
		getch();
		return;
	}
	p->x = x;
	p->y = y;
	p->next = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->next = p;
	rear = p;
}
void deQueue(int *x,int *y)
{
	Queue * p;
	if(front == NULL)
	{
		printf("Queue is empty");
		getch();
		exit(0);
	}
	p = front;
	front = front->next;
	*x = p->x;
	*y = p->y;
	free(p);
}


void floodFill(int x,int y,int fillColor,int boundaryColor)
{
	int color;
	front=rear=NULL;
	color = getpixel(x,y);
	if(color != boundaryColor && color!=fillColor)
	{
		putpixel(x,y,fillColor);
		enQueue(x,y-1);
		enQueue(x,y+1);
		enQueue(x+1,y);
		enQueue(x-1,y);
		while(front != NULL)
		{
			deQueue(&x,&y);
			color = getpixel(x,y);
			if(color != fillColor && color != boundaryColor)
			{
				putpixel(x,y,fillColor);
				enQueue(x,y-1);
				enQueue(x,y+1);
				enQueue(x+1,y);
				enQueue(x-1,y);
			}
		}
	}
}

void convertToString(int n , char str[])
{
	int i = 0;
	for(i = 0 ; n > 0 ; i++)
	{
		str[i] ='0'+(n%10);
		n = n/10;
	}
	str[i]='\0';
	strrev(str);
}

int main()
{
	Data d[30];
	Coordinate pts[100];
	double total=0;
	char *title="\0";
	double newSlice,lastSlice;
	double x1,x2,y1,y2;
	double x,y,click,oldx,oldy;
	double xC,yC;
	double midX,midY;
	char *str;
	int i,j,k;
	int radius,n;
	int DRIVER = DETECT,mode;
	const double TwoPI = 6.2857143;
	x1=150;	x2=620;
	y1=20;	y2=350;
	 clrscr();
	//calculation of midpoint of circle
	xC = (x1+x2)/2;
	yC = (y1+y2)/2;
	radius = 150;
       //	printf("\n\n\t\tPROGRAM  TO DRAW A PIE-CHART::\n\n");

	printf("\n\n\tTitle of the PIE CHART::");
	scanf("%[^\n]s",title);
	for(i = 0  ; i < strlen(title);i++)
		title[i] = toupper(title[i]);
	printf("\n\n\tEnter the no. of items::");
	scanf("%d",&n);
	for(i = 0 ; i < n ; i++)
	{
		printf("\nEnter name for item no %d::",i+1);
		scanf("%s",&d[i].items);
		fflush(stdin);
		printf("\nEnter data for item no. %d::",i+1);
		scanf("%d",&d[i].data);
		fflush(stdin);
		d[i].itemColor = i+1;
	}
	initgraph(&DRIVER,&mode,"c:\\tc\\bgi");

	//drawing the rectangular boundaries
	setcolor(WHITE);
	rectangle(10,20,145,350);
	rectangle(x1,y1,x2,y2);

	setcolor(BROWN);
	settextstyle(GOTHIC_FONT, HORIZ_DIR,2);
	outtextxy(30, 22, "Legends");

	//drawing the legends
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
	for(j=60,k=70,i = 0 ; i < n ; i++)
	{
		rectangle(25,j,35,k);
		outtextxy(40,j+2,d[i].items);
		floodFill(30,j+5,d[i].itemColor,WHITE);
		j+=20;
		k+=20;
	}
	setcolor(BROWN);
	circle(xC,yC,radius+1);
	setcolor(WHITE);
	circle(xC,yC,radius);
	circle(xC,yC,radius-1);

	//drawing and filing the pieChart
	for(i = 0 ; i < n ; i++)
		total += d[i].data;
	i = 0;
	lastSlice=0;
	newSlice = TwoPI*d[i].data/total+lastSlice;
	pts[i].x = xC + radius*cos(newSlice);
	pts[i].y = yC + radius*sin(newSlice);
	line(xC ,yC,pts[i].x,pts[i].y);
	lastSlice = newSlice;

	for(i = 1 ; i < n ; i++)
	{
		newSlice = TwoPI*d[i].data/total+lastSlice;
		pts[i].x = xC + radius*cos(newSlice);
		pts[i].y = yC + radius*sin(newSlice);
		line(xC ,yC,pts[i].x,pts[i].y);
		midX = xC + (radius/2)*cos((newSlice+lastSlice)/2);
		midY = yC + (radius/2)*sin((newSlice+lastSlice)/2);
		floodFill(midX,midY,d[i].itemColor,WHITE);
		lastSlice = newSlice;
	}
	//filling the pie chart
	for(i = 0 ; i < n ; i++)
	{
		newSlice = TwoPI*d[i].data/total+lastSlice;
		line(xC ,yC,pts[i].x,pts[i].y);
		midX = xC + (radius/2)*cos((newSlice+lastSlice)/2);
		midY = yC + (radius/2)*sin((newSlice+lastSlice)/2);
		floodFill(midX,midY,d[i].itemColor,WHITE);
		lastSlice = newSlice;
	}

	//drawing the title at the bottom
	setcolor(BROWN);
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,3);
	outtextxy(200,400,title);
	getch();
	closegraph ();
	return 0;

}