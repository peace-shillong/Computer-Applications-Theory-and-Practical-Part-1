/* PROGRAM FOR DRAWING  HOUSE USING DDA ALGORITHM */

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void draw(int x1,int y1,int x2,int y2);
void main()
{
    int driver=DETECT,mode;

    //printf("\n\nENTER THE STARTING POINT COORDINATES :\n");
    //scanf("%d%d",&x1,&y1);
    //printf("\n\nENTER THE ENDING POINT COORDINATES :\n");
    //scanf("%d%d",&x2,&y2);
    initgraph(&driver,&mode,"c:\\tc\\bgi");
    //printf("\n\n\n\n\n\n		     DIGITAL DIFFERENTIAL ANALYSER EXAMPLE\n");
//    clrscr();
    draw(180,190,180,290);
    draw(180,190,220,160);
    draw(220,160,260,190);
    draw(259,190,260,290);
    draw(180,290,260,290);
    draw(180,190,260,190);

    draw(220,160,350,160);
    draw(259,190,380,190);
    draw(350,159,380,190);
    draw(200,290,380,290);
    draw(380,188,380,290);

    //doors
    draw(235,230,235,290);
    draw(205,230,205,290);
    draw(205,230,235,230);

    //windows
    draw(280,205,280,225);
    draw(279,205,300,205);
    draw(300,205,300,225);
    draw(280,225,300,225);
    draw(280,215,300,215);
    draw(290,205,290,225);

    draw(320,205,320,225);
    draw(319,205,340,205);
    draw(340,205,340,225);
    draw(320,225,340,225);
    draw(320,215,340,215);
    draw(330,205,330,225);

    //chimney
    draw(280,140,280,160);
    draw(279,140,290,140);
    draw(290,140,290,160);
    draw(275,140,285,130);
    draw(285,130,295,140);
    draw(275,140,295,140);
    draw(284,130,286,130);

    getch();
}
void draw(int x1,int y1,int x2,int y2){
	int dy,dx,k;
	float yi,xi,x,y,cor;
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
