#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void main()
{
    int i,driver=DETECT,mode,rad,x,y;
    float new_y,new_x;
    clrscr();
    printf("\n\nENTER THE RADIUS OF THE CIRCLE: ");
    scanf("%d",&rad);
    printf("\n\nENTER THE CENTRE COORDINATES OF CIRCLE : ");
    scanf("%d%d",&x,&y);
    initgraph(&driver,&mode,"c:\\tc\\bgi");

for(i=-rad;i<=rad;i++)
    {
	new_y=(sqrt(rad*rad-i*i));
	putpixel(x+i,y+new_y,WHITE);
	putpixel(x+i,y-new_y,WHITE);

    }
    for(i=-rad;i<=rad;i++)
    {
	new_x=(sqrt(rad*rad-i*i));
	putpixel(x+new_x,y+i,WHITE);
	putpixel(x-new_x,y+i,WHITE);

    }
    getch();
}