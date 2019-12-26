#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void lline(float x1,float y1,float x2,float y2);

void main()
{

    float x[10],y[10];
    int n,i;
    int d=DETECT,gm;
    printf("\nHow many coordinates? ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       printf("\nEnter the coordinates of x %d and y %d: ",i,i);
       scanf("%f %f",&x[i],&y[i]);
    }
    initgraph(&d,&gm,"c:\\tc\\bgi");
    for(i=1;i<n;i++)
    {
	line(x[i],y[i],x[i+1],y[i+1]);
       /*printf("x[%d]=%f",i,x[i]);
       printf("y[%d]=%f",i,y[i]);
	printf("x[%d]=%f",i,x[i+1]);
	printf("y[%d]=%f",i,y[i+1]);*/

    }
   /* lline(x[1],y[1],x[2],y[2]);
    lline(x[2],y[2],x[3],y[3]); */

    line(x[n],y[n],x[1],y[1]);
    getch();
    closegraph();
}
void lline(float x1,float y1,float x2,float y2)
{
	float m,x,y;
	x=x1;
	y=y1;
	m=(y2-y1)/(x2-x1);
       //	c=yr-(m*x1);

	if((m<1) || (m==1.0))
	{
		printf("m==0 or m<1");
		if(x1==x2)
		{
			if(y1==y2)
			{
				putpixel(x,y,1);
			}
			else if(y1<y2)
			{
				for(y=y1;y<y2;y++)
				{
				putpixel(x,y,1);
				}
			}
			else if(y1>y2)
			{
				for(y=y1;y>y2;y--)
				{
					putpixel(x,y,1);
				}
			}

		}
		else if(x1<x2)
		{
			if(y1==y2)
			{
				for(x=x1;x<=x2;x++)
				{
					putpixel(x,y,1);
				}
			}
		       else if(y1>y2)
			{
				for(x=x1;x<=x2;x++)
				{
					putpixel(x,y,1);
				     y=y+m;  //	y=y-m;
				}
			}
			else if(y1<y2)//*********000
			{
				for(x=x1;x<=x2;x++)
				{


			//printf("HWllo");//m==1
					putpixel(x,y,1);
					y=y+m;
				}
			}
		}
		else if(x1>x2)
		{
			if(y1==y2)
			{
				for(x=x1;x>=x2;x--)
				{
					putpixel(x,y,1);
				}
			}
			else if(y1>y2)
			{
				for(x=x1;x>=x2;x--)
				{
			       //	printf("x1>x2,y1>y2");
					putpixel(x,y,1);
					y=y-m;
				}
			}
			else if(y1<y2)
			{
				for(x=x1;x>=x2;x--)
				{
					putpixel(x,y,1);
				       y=y-m;//	y=y+m;
				}
			}

		}
	}
	if (m>1)
	{
		if(y1==y2)
		{
			if(x1==x2)
			{
				putpixel(x,y,1);
			}
			else if(x1>x2)
			{
				for(x=x1;x>=x2;x--)
				{
					putpixel(x,y,1);
				}
			}
			else if(x1<x2)
			{
				for(x=x1;x<=x2;x++)
				{
					putpixel(x,y,1);
				}
			}

		}
		else if(y1>y2)
		{
			if(x1==x2)
			{
				for(y=y1;y>y2;y++)
				{
					putpixel(x,y,1);
				}
			}
			else if(x1>x2)
			{
				for(y=y1;y>=y2;y--)
				{
					putpixel(x,y,1);
					x=x-(1/m);
				}
			}
			else if(x1<x2)
			{
				for(y=y1;y>=y2;y--)
				{
					putpixel(x,y,1);
					x=x+(1/m);
				}

			}

		}
		else if(y1<y2)
		{
			if(x1==x2)
			{
				for(y=y1;y>y2;y++)
				{
					putpixel(x,y,1);
				}
			}
			else if(x1>x2)
			{
				for(y=y1;y<=y2;y++)
				{
					putpixel(x,y,1);
					x=x-(1/m);
				}
			}
			else if(x1<x2)//********
			{
				for(y=y1;y<=y2;y++)
				{
					putpixel(x,y,1);
					x=x+(1/m);
				}

			}
		}
	}


}