#include<graphics.h>
#include<conio.h>
#include<stdio.h>

void main()
{
	int gd=DETECT,gm,n,i=10;
	int x=0,y=0;
	initgraph(&gd,&gm,"C:\\TC\\bgi");
	//n=5;
	//setlinestyle(DOTTED_LINE,1,1);
	//setcolor(RED);
	printf("how many circles do you want?(Maximum 10)\n");
	scanf("%d",&n);
	if(n<=10){
		n*=10;
		while(i<=n){
			circle(150,100,i+10);
			i+=10;
	}}

	getch();
}