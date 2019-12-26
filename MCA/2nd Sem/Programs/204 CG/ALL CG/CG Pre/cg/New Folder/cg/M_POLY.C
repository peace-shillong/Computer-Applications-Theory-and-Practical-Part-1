#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
union REGS in,out;
void main()
{
	int n,i,j,k,gd,gm,dy,dx,button;
	int x,y,temp;
	int a[20][20],xi[20];
	float slope[20];
	int driver=DETECT,mode;

	clrscr();

	printf("\n\n\tEnter the no. of sides of polygon : ");
	scanf("%d",&n);

	printf("\n\n\tEnter the coordinate of polygon :\n\n");
	for(i=0;i<n;i++)
	{
		printf("\tx%d y%d : ",i,i);
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	a[n][0]=a[0][0];
	a[n][1]=a[0][1];


	initgraph(&driver,&mode,"c:\\tc\\bgi");
	if(initmouse()==0)
	{
		closegraph();
		restorecrtmode();
		outtext("Mouse driver not loaded");
		exit(1);
	}
	//showmousept();

	//draw polygon
	for(i=0;i<n;i++)
	{
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}
	showmousept();
	for(i=0;i<n;i++)
	{
		dy=a[i+1][1]-a[i][1];
		dx=a[i+1][0]-a[i][0];
		if(dy==0)slope[i]=1.0;
		if(dx==0)slope[i]=0.0;
		if((dy!=0)&&(dx!=0))
		{
			slope[i]=(float)dx/dy;
		}
	}
	for(y=0;y<480;y++)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			if(((a[i][1]<=y) &&(a[i+1][1]>y))||((a[i][1]>y)&&(a[i+1][1]<=y)))
			{
				xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
				k++;
			}
		}

		for(j=0;j<k-1;j++)
			for(i=0;i<k-1;i++)
			{
				if(xi[i]>xi[i+1])
				{
					temp=xi[i];
					xi[i]=xi[i+1];
					xi[i+1]=temp;

				}
			}

		       setcolor(GREEN);
			while(!kbhit())
			{
				getmspos(&button,&x,&y);
				if(button==1)
			{
					for(i=0;i<k;i+=2)
					{

						line(xi[i],y,xi[i+1]+1,y);
						putpixel(x,y,14);
						//printf("\n\n\tGreen");
					       //	getch();
					}
			}
			}
	}
}

initmouse() /*initialize the mouse */
{
	in.x.ax=0;
	int86(0x33,&in,&out);
	return(out.x.ax);
}

showmousept() /*display the mouse pointer */
{
	in.x.ax=1;
	int86(0x33,&in,&out);
	return;
}


getmspos(int *button,int *x,int *y) /* get mouse status */
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*button=out.x.bx;
	*x=out.x.cx;
	*y=out.x.dx;
	return;
}