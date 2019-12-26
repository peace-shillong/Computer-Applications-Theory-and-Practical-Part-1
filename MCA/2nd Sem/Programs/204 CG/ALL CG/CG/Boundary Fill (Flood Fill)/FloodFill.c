#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void main()
{
    int flag;
    char ch;
    /*  request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, "");
    /* read result of initialization */
    errorcode = graphresult();
    if (errorcode != grOk)  /* an error occurred */
    {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
    }
    do
    {
	clrscr();
	printf("Do you wish to continue?(Y/N) :");
	ch=getche();
    }while(ch=='Y'||ch=='y');
    closegraph();
	printf("\nThank you for using the programme.\nPress any key to terminate.");
	getch();
}
