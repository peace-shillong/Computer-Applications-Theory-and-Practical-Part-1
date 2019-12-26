#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<Z:\draw.h>
//#include<d:\mydocs\sem2\cg\draw.h>
void rotateline(int &x,int &y,int xf,int yf,float theta,int color)
{
	line_dda(x,y,xf,yf,BLACK);
	theta=6.28*(theta/360);
	float x1=ROUND((float)(xf+(x-xf)*cos(theta)-(y-yf)*sin(theta)));
	float y1=ROUND((float)(yf+(x-xf)*sin(theta)+(y-yf)*cos(theta)));
	x=ROUND(x1);y=ROUND(y1);
	line_dda(x,y,xf,yf,color);
}
void translate(int *b,int x,int y)
{
	for(int i=0;i<=3;i+=2)
	{
		b[i]=b[i]+x;
		b[i+1]=b[i+1]+y;
	}
}
void main()
{
	int wall[]={100,300,350,300,350,450,100,450};
	int gd=DETECT,mode;
	initgraph(&gd,&mode,"c:\\tc\\bgi");
	/*HOUSE*/
	polygn(4,wall,WHITE);
	fldfil(wall[0]+20,wall[1]+20,BLUE);
	wall[0]=350;wall[1]=300;wall[2]=400;wall[3]=270;wall[4]=400;wall[5]=420;wall[6]=350;wall[7]=450;
	polygn(4,wall,WHITE);
	fldfil(wall[0]+10,wall[1]+20,BLUE);
	wall[0]=80;wall[1]=330;wall[2]=340;wall[3]=330;wall[4]=370;wall[5]=230;wall[6]=150;wall[7]=230;
	polygn(4,wall,WHITE);
	fldfil(wall[0]+50,wall[1]-20,WHITE);
	fldfil(wall[0]+50,wall[1]-40,WHITE);
	line_dda(370,230,412,285,WHITE);
	fldfil(370,250,RED);
	line_dda(412,285,400,285,WHITE);

	/*BIRD*/
	int x=getmaxx()-20;
	int wnglft[]={360,150,350,145},wngrt[]={360,150,370,145};
	setcolor(YELLOW);
	circle((wngrt[0]+wnglft[0])/2,wngrt[1]+1,2);
	circle((wngrt[0]+wnglft[0])/2,wngrt[1]+1,1);
	line_dda(wnglft[0],wnglft[1],wnglft[2],wnglft[3],WHITE); //wings
	line_dda(wngrt[2],wngrt[3],wngrt[0],wngrt[1],WHITE);
	int s=1,i;
	while(!kbhit())
	{
		for(i=0;i<2;i++){
		rotateline(wnglft[2],wnglft[3],wnglft[0],wnglft[1],s*-20,YELLOW);
		rotateline(wngrt[2],wngrt[3],wngrt[0],wngrt[1],s*20,YELLOW);
		setcolor(WHITE);
		circle((wngrt[0]+wnglft[0])/2,wngrt[1]+1,2);
		circle((wngrt[0]+wnglft[0])/2,wngrt[1]+1,1);
		delay(150);
		}
		s*=-1;

		setcolor(BLACK);
		circle((wngrt[0]+wnglft[0])/2,wngrt[1]+1,2);
		circle((wngrt[0]+wnglft[0])/2,wngrt[1]+1,1);
		line_dda(wnglft[0],wnglft[1],wnglft[2],wnglft[3],BLACK);
		line_dda(wngrt[2],wngrt[3],wngrt[0],wngrt[1],BLACK);

		if(wnglft[0]<=30)
		{
			wnglft[0]=x;wnglft[2]=x-10;
			wngrt[0]=x;wngrt[2]=x+10;
			wnglft[1]=200;wnglft[3]=195;
			wngrt[1]=200;wngrt[3]=195;
		}
		else
		{
			translate(wnglft,-4,-1);
			translate(wngrt,-4,-1);
		}
	}
	getch();
}
