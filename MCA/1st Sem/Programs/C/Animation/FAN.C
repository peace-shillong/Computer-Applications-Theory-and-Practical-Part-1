#include<conio.h>
#include<stdio.h>
#include<graphics.h>
void rotate();
void main()
{
int gd= DETECT, gm,i,m,j;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
while(kbhit()==0)
{
	rotate();
}
if(i==100)
	rotate();

else
	printf("Hello");
closegraph();
getch();
}

void rotate(){
	int i;
	while(!kbhit()){
	i=getch();
	if(i==100){
	do{
	for(i=80;i>=0;i-=20)
	{
		setcolor(BLUE);
		circle(320,240,65);
		circle(320,240,67);
		setfillstyle(SOLID_FILL,BLUE);
		bar(310,307,330,360);
		bar(290,360,350,375);
		setcolor(RED);
		setfillstyle(SOLID_FILL,RED);
		pieslice(320,240,i,i+40,60);
		pieslice(320,240,i+120,i+160,60);
		pieslice(320,240,i+240,i+280,60);
		setcolor(BLUE);
		circle(320,240,10);
		setfillstyle(SOLID_FILL,BLUE);
		floodfill(320,240,BLUE);
		delay(100);

		setcolor(0);
		setfillstyle(SOLID_FILL,0);
		pieslice(320,240,i,i+40,60);
		pieslice(320,240,i+120,i+160,60);
		pieslice(320,240,i+240,i+280,60);

	}
	}while(!kbhit());
	}
	else
	{
	}
	}
}