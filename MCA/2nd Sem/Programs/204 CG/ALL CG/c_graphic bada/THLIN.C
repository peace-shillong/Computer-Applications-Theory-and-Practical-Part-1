#include<graphics.h>
#include<conio.h>
void main(){
	int x1,x2,y1,y2, gd , dr , x,y ;
	clrscr();
	dr=DETECT;
	initgraph(&dr,&gd,"c:\\Tc\\bgi");
		x=getmaxx();
		y=getmaxy();
		x1=rand()%x;
		x2=rand()%x;
		y1=rand()%y;
		y2=rand()%y;
	for(x=x1;x<=x2;x++){
		y=((x-x1)/(x1-x2))*(y1-y2)+y1;
		putpixel(x,y,YELLOW);
	}
	getch();
	closegraph();
}