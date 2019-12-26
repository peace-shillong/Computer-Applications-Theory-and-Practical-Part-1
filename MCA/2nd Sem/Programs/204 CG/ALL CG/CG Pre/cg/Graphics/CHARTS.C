#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<z:\draw.h>
struct data
{
	char nam[20];
	int a;
};
void main()
{
	struct data d[20];
	int gd=DETECT,mode,c,n,i,poly[8]={2,4,637,4,637,478,2,478};

	printf("\n\tEnter the no. of items");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{       printf("\n\nEnter the name %d - ",i+1);
		scanf("%s",&d[i].nam);
		printf("\nEnter the value of %d - ",i+1);
		scanf("%d",&d[i].a);
	}
	printf("Enter your choice\n\t");
	printf("1: Bar graph\n\t2: Line chart\n\t3: Pie chart\n\t4: Exit");
	c=(getch()-'0');
	initgraph(&gd,&mode,"c:\\tc\\bgi");
	polygn(4,poly,WHITE);
	switch(c)
	{


		case 1:
			Bar_chart(d,n);
			getch();
			break;
		case 2:
			Line_chart(d,n);
			getch();
			break;
		case 3:
			Pie_chart(d,n);
			getch();
			break;
		case 4:
			exit(0);
	}
}
Bar_chart(struct data *d,int n)
{
	int m,i,x,temp,s,j,poly[8];
	float perc,num;
	char *str;
	char nam[20][10];
	for(i=0,temp=0;i<n;i++)
	{
		if(d[i].a>temp)
			temp=d[i].a;
	}
	line_dda(100,20,100,400,WHITE);   //Y-Axis
	for(i=0,num=temp;i<400;i+=20,num=num-perc)
	{
		line_dda(98,20+i,102,20+i,WHITE);
	}
	line_dda(100,400,500,400,WHITE);  //X-Axis
	m=400/(2*n);
	for(i=0,x=150;i<n;i++)
	{
		delay(500);
		perc=d[i].a/(float)temp;
		s=380-(380*perc);
		poly[0]=x;
		poly[1]=20+s;
		poly[2]=x+m;
		poly[3]=20+s;
		poly[4]=x+m;
		poly[5]=400;
		poly[6]=x;
		poly[7]=400;
		polygn(4,poly,WHITE);
		setfillstyle(SOLID_FILL,i+1);
		floodfill(x+2,22+s,WHITE);
		outtextxy(x-4,10+s,d[i].nam);
		gcvt(d[i].a,10,str);
		x+=2*m;
	}
	getch();
	return;
}
Line_chart(struct data *d,int n)
{
	int m,i,x,temp,s,j,poly[8],x1,x2,y1,y2;
	float perc,num;
	char *str;
	char nam[20][10];
	for(i=0,temp=0;i<n;i++)
	{
		if(d[i].a>temp)
			temp=d[i].a;
	}
	line_dda(100,20,100,400,WHITE);   //Y-Axis
	for(i=0,num=temp;i<400;i+=20,num=num-perc)
	{
		line_dda(98,20+i,102,20+i,WHITE);
	}

	line_dda(100,400,500,400,WHITE);  //X-Axis

	m=400/(2*n);                        //Range of x-axis=400
	perc=d[0].a/(float)temp;
	s=380-(380*perc);                   //Range of y-axis=380
	x=x1=150;
	y1=20+s;
	x+=2*m;
	setcolor(YELLOW);
	outtextxy(x1-4,10+s,d[0].nam);
	outtextxy(x1-1,y1-2,"*");
	for(i=1;i<n;i++)
	{
		delay(800);
		perc=d[i].a/(float)temp;
		s=380-(380*perc);
		x2=x;
		y2=20+s;
		outtextxy(x2-1,y2-2,"*");
		line_dda(x1,y1,x2,y2,RED);
		outtextxy(x-4,10+s,d[i].nam);
		x+=2*m;
		x1=x2;
		y1=y2;

	}
	return;
}
Pie_chart(struct data *d,int n)
{
	int i,j,total=0,r=150,perc,x,x1,y,y1,x2,y2,poly[8]={20,20,40,20,40,40,20,40};
	float theta,theta1=0;
	char str[10];
	x=getmaxx()/2;y=getmaxy()/2;
	circl(x,y,r);
	circl(x,y,r+3);
	for(i=0;i<n;i++)
		total=total+d[i].a;
	x2=getmaxx()/2+5;		y2=getmaxy()/2+3;
	for(i=0,j=1;i<n;i++,j++)
	{
		theta=6.28*(d[i].a/(float)total)+theta1;
		perc=(d[i].a/(float)total)*100;
		x1=r*cos(theta)+x;
		y1=r*sin(theta)+y;
		theta1=theta;
		line_dda(x,y,x1-1,y1,WHITE);
		if(i!=0)
		{
			x2=(x+(abs(x2+x1)/2))/2;
			y2=(y+(abs(y2+y1)/2))/2;
		}
		gcvt(perc,10,str);
		str[2]='%';
		str[3]='\0';
		setfillstyle(SOLID_FILL,j);
		floodfill(x2,y2,WHITE);
		polygn(4,poly,WHITE);
		floodfill(poly[0]+2,poly[1]+2,WHITE);
		setcolor(WHITE);
		outtextxy(poly[2]+2,poly[3]+2,d[i].nam);
		setcolor(BLACK);
		outtextxy(x2+1,y2,str);
		poly[1]+=20;
		poly[3]+=20;
		poly[5]+=20;
		poly[7]+=20;
		x2=x1;y2=y1;
	}
	return;
}