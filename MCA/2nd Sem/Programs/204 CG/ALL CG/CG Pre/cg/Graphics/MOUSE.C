#include<stdio.h>
#include<conio.h>
#include <dos.h>
union REGS in,out;
initmouse()
{
	in.x.ax=0;
	int86(51,&in,&out);
	return(out.x.ax);
}
hidemousept()
{
	in.x.ax=2;
	int86(51,&in,&out);
	return 0;
}
showmousept()
{
	in.x.ax=1;
	int86(51,&in,&out);
	return 0;
}
getmspos(int *button,int *x,int *y)
{

	in.x.ax=3;
	int86(51,&in,&out);
	*button=out.x.bx;
	*x=out.x.cx;
	*y=out.x.dx;
	return 0;
}
