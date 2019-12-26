//drawing scenery using all learned functions

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>
union REGS in,out;
void getmspos(int *,int *,int *);
initmouse()
{
	in.x.ax=0;
	int86(51,&in,&out);
	return(out.x.ax);
}
void show()
{
	in.x.ax=1;
	int86(51,&in,&out);
	return;
}
void bezier(int x1[3],int y1[3])  //for drawing curves
{
	float t;
	int xt,yt,i;
	for(t=0.0;t<1.0;t=t+0.0005)   //smother curve
	{
		xt=pow(1-t,2)*x1[0]+2*t*pow(1-t,1)*x1[1]+pow(t,2)*x1[2];
		yt=pow(1-t,2)*y1[0]+2*t*pow(1-t,1)*y1[1]+pow(t,2)*y1[2];
		putpixel(xt,yt,WHITE);
	}
       // for(i=0;i<3;i++)
	 //  putpixel(x1[i],y1[i],BLACK);

}

void bezier1(int x[4],int y[4])
{
	float t;
	int xt,yt,i;
	for(t=0.0;t<1.0;t=t+0.0000005)   //smother curve
	{
		xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
		yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
		putpixel(xt,yt,WHITE);
	}
    /*	for(i=0;i<4;i++)
	   putpixel(x[i],y[i],WHITE);
	getch(); */
}
void DDA(int x1,int y1,int xr,int yr)   //for drawing lines
{
	float dx,dy,xinc,yinc,x,y,i,m;

	dx=xr-x1;
	dy=yr-y1;

	if(abs(dx)>abs(dy))
		m=abs(dx);
	else
		m=abs(dy);
	xinc=dx/m;
	yinc=dy/m;
	x=x1;
	y=y1;
	getpixel(x,y);
	for(i=1;i<m;i++)
	{
		x=x+xinc;
		y=y+yinc;
		putpixel (x,y,WHITE);
	}
}
void polar(int xc,int yc,int rad)
{
	int i,x,y;
	for(i=0;i<=360;i++)    //uses polar coordinate algorithm
	{
	   x=xc+(rad*cos(i));
	   y=yc+(rad*sin(i));
	   putpixel(x,y,YELLOW);
	}
}
void main()
{	int gd=DETECT,gm;
	int x1[3]={95,40,80},y1[3]={480,230,125};
	int x2[3]={0,20,77},y2[3]={135,165,130};
	int x3[3]={183,145,65},y3[3]={134,185,180};
	int x4[3]={350,300,180},y4[3]={0,100,135};
	int lx={63},ly={280},lx1={640},ly1={280};
	int ux={152},uy={162},ux1={640},uy1={160};
	int vx={268},vy={91},vx1={325},vy1={165};
	int x5[3]={324,420,520},y5[3]={164,30,162};
	int x6[3]={520,580,640},y6[3]={160,45,160};
	int xc=360,yc=80,rad=30;
	int i,button,x,y;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

    /*	printf("\nEnter the control points: ");
	for(i=0;i<3;i++)
	{
		printf("\nControl point(%d):",i+1);
		scanf("%d %d",&x1[i],&y1[i]);
	}  */
	initmouse();
	show();
	bezier(x1,y1);
	bezier(x2,y2);
	bezier(x3,y3);
	bezier(x4,y4);
	setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL,LIGHTGREEN);
	floodfill(20,20,WHITE);
	setcolor(BROWN);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(20,200,WHITE);


	setcolor(WHITE);
	line(lx,ly,lx1,ly1);

	line(ux,uy,ux1,uy1);
	line(vx,vy,vx1,vy1);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(300,400,WHITE);
	setcolor(BROWN);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(230,140,WHITE);
	bezier(x5,y5);
	bezier(x6,y6);
	setcolor(WHITE);
	circle(xc,yc,rad);

	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(380,72,WHITE);

	setcolor(BROWN);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(427,133,WHITE);
	setcolor(BROWN);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(580,134,WHITE);
		setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(410,52,WHITE);
		setcolor(GREEN);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(290,214,WHITE);

	setcolor(WHITE);
	rectangle(528,216,584,266);
	setcolor(BROWN);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(530,220,WHITE);
	setcolor(WHITE);
	line(528,216,556,188);
	line(556,188,584,216);
		setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,DARKGRAY);
	floodfill(556,190,WHITE);
	setcolor(WHITE);
	rectangle(540,233,565,260);
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,DARKGRAY);
	floodfill(545,250,WHITE);



       while(!kbhit())
	{
		getmspos(&button,&x,&y);
		gotoxy(65,3);
		printf("x=%d y=%d",x,y);
	}

	closegraph();
}
void getmspos(int *button,int *x, int *y)
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*button=out.x.bx;
	*x=out.x.cx;
	*y=out.x.dx;
	return;
}