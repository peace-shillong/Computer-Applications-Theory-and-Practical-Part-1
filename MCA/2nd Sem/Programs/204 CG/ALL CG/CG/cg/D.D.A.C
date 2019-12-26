#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	int x1,x2,y1,y2;
	int gd=DETECT,mode,m;

	printf("Enter two coordinates\n");
	printf("\n\nEnter first coordinates:");
	scanf("%d%d",&x1,&y1);
	printf("\n\nEnter second coordinates:");
	scanf("%d%d",&x2,&y2);

	initgraph(&gd,&mode,"c:\\tc\\bgi");
	m=abs(y2-y1)/(x2-x1);

	if(m==1)
		{
		while(x1!=x2)
			{
			putpixel(x1,y1,WHITE);
			x1++;
			y1++;
			}
		}
	else
		{
		if(m<1)
			{
			while(x1!=x2)
				{
				putpixel(x1,y1,WHITE);
				x1++;
				y1=y1+m;
				}
			}

		       else if(m>1)
			{
				while(x1!=x2)
				{
				putpixel(x1,y1,WHITE);
				y1++;
				x1=x1+(1/m);
				}
			}
		}
	getch();
}
