/* PROGRAM FOR DRAWING A HIVE USING DDA ALGORITHM */

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void draw_hive(int x,int y);
void main()
{
    int driver=DETECT,mode;
    int x=50,y=50;
    //printf("\n\nENTER THE STARTING POINT COORDINATES :\n");
    //scanf("%d%d",&x1,&y1);
    //printf("\n\nENTER THE ENDING POINT COORDINATES :\n");
    //scanf("%d%d",&x2,&y2);
    initgraph(&driver,&mode,"c:\\tc\\bgi");
    printf("a hive");
    draw_hive(x,y);
    getch();
}
void draw_hive(int a,int b){
	int dy,dx,k,Bx,By,Cx,Cy,Dx,Dy,Ex,Ey,Fx,Fy;
	float yi,xi,x,y,cor;
	int x1,x2,y1,y2,i;
	Bx=a+15;By=b-5;
	Cx=a;Cy=b+20;
	Dx=a+15;Dy=b+25;
	Ex=a+25;Ey=b;
	Fx=a+25;Fy=b+20;
	for(i=0;i<6;i++){
	switch(i){
		case 0:
			x1=a;y1=b;
			x2=Bx;y2=By;
			break;
		case 1:
			x1=a;y1=b-1;
			x2=Cx;y2=Cy;
			break;
		case 2:
			x1=Bx;y1=By;
			x2=Ex;y2=Ey;
			break;
		case 3:
			x1=Cx;y1=Cy;
			x2=Dx;y2=Dy;
			break;
		case 4:
			x1=Ex;y1=Ey-1;
			x2=Fx;y2=Fy;
			break;
		case 5:
			x1=Dx;y1=Dy;
			x2=Fx;y2=Fy;
			break;
		}
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
	       cor=abs(dx);
	else
		cor=abs(dy);

	xi=dx/cor;
	yi=dy/cor;
	x=x1;
	y=y1;
	getpixel(x,y);
	for(k=1;k<cor;k++)
	{
		x=x+xi;
		y=y+yi;
       //printf("\n%d %d",x,y);
		putpixel(x,y,WHITE);
	}
	}

}
