//Program to implement basic transformations
#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"stdlib.h"
#include "math.h"
void rotat(double,double,double,double,double,double,double,double,double);
void draw(double,double,double,double);
void drawline(double x1,double y1,double x2,double y2)
{
	if((x2<x1)||(x2==x1 && y2<y1))
		draw(x2,y2,x1,y1);
	else
		draw(x1,y1,x2,y2);
}
void draw(double x1,double y1,double x2,double y2){
	double p,m=0;
	double dx,dy,xend,yend;
	double i,j;

	if(x1==x2){
		for(j=y1;j<=y2;j++)
			putpixel(x1,j,9);
		return;
	}

	else if(y1==y2){
		for(i=x1;i<=x2;i++)
			putpixel(i,y1,9);
		return;
	}

	dx=(x2-x1);
	dy=(y2-y1);
	m=(dy/dx);
	p=2*dy-dx;
	if(m==1 || m==-1){
		for(i=x1,j=y1;i<=x2;i++){
			putpixel(i,j,9);
			if(dy<0)
				j--;
			else
				j++;
		}
	}
	else if(m<1 && m>-1){
		if(dy<0){
			j=y1;
			for(i=x1;i<=x2;i++){
				if(p<0){
					putpixel(i,j,9);
					p=p-2*dy;
				}
				else{
					putpixel(i,--j,9);
					p=p-2*dx+2*dy;
				}
			}
		}
		else{
			j=y1;
			for(i=x1;i<=x2;i++){
				if(p<0){
					putpixel(i,j,9);
					p=p+2*dy;
				}
				else{
					putpixel(i,++j,9);
					p=p-2*dx+2*dy;
				}
			}
		}
	}
	else
	{
		if(dy<0){
			i=x1;
			for(j=y1;j>=y2;j--){
				if(p<0){
					putpixel(i,j,9);
					p=p+2*dx;
				}
				else{
					putpixel(++i,j,9);
					p=p-2*dx+2*dy;
				}
			}
		}
		else{
			i=x1;
			for(j=y1;j<=y2;j++){
				if(p<0){
					putpixel(i,j,9);
					p=p+2*dx;
				}
				else{
					putpixel(++i,j,9);
					p=p+2*dx-2*dy;
				}
			}
		}
	}


}

void main(){
	int gd=DETECT,gm,i,n,k;
	double x1,x2,y1,y2,x3,y3,m,X,Y,tempx1,tempx2,tempx3,tempy1,tempy2,tempy3,x11,x21,x31,y11,y21,y31,rf,xr,yr;

	initgraph(&gd,&gm,"c:\tc\bgi");

	printf("Enter the first coordinate :");
	scanf("%lf%lf",&x1,&y1);
	printf("Enter the second coordinate :");
	scanf("%lf%lf",&x2,&y2);
	printf("Enter the third coordinate :");
	scanf("%lf%lf",&x3,&y3);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);

	printf("Enter the degree of rotation :");
	scanf("%lf",&rf);

	xr=(x1+x2+x3)/3;
	yr=(y1+y2+y3)/3;

	rf=(M_PI/180)*rf;

	cleardevice();

		x11=xr+(x1-xr)*cos(rf)-(y1-yr)*sin(rf);
		y11=yr+(x1-xr)*sin(rf)+(y1-yr)*cos(rf);

		x21=xr+(x2-xr)*cos(rf)-(y2-yr)*sin(rf);
		y21=yr+(x2-xr)*sin(rf)+(y2-yr)*cos(rf);

		x31=xr+(x3-xr)*cos(rf)-(y3-yr)*sin(rf);
		y31=yr+(x3-xr)*sin(rf)+(y3-yr)*cos(rf);

		cleardevice();
		line(x11,y11,x21,y21);
		line(x21,y21,x31,y31);
		line(x31,y31,x11,y11);
		delay(10);
		x1=x11,x2=x21,x3=x31;
		y1=y11,y2=y21,y3=y31;

	getch();
	closegraph();
}
// output:100,50,100,100,50,100,45