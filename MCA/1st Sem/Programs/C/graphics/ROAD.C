#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
 
void main()
{
        int i,gd=DETECT,gm;
        detectgraph(&gd,&gm);
        initgraph(&gd,&gm,"*** BGI Path ***");
 
        // Set Background colour to GREEN
        setbkcolor(GREEN);
 
        // The program runs indefinitely until you press a key
        while(!kbhit())
        {
 
                // Draw the road
                setfillstyle(SOLID_FILL,8);
                bar(150,0,470,500);
 
                // Draw the WHITE divider lines
                setfillstyle(SOLID_FILL,15);
                bar(310,0+i,320,50+i);
                bar(310,70+i,320,120+i);
                bar(310,140+i,320,190+i);
                bar(310,210+i,320,260+i);
                bar(310,280+i,320,330+i);
                bar(310,350+i,320,400+i);
                bar(310,420+i,320,470+i);
 
                delay(200);
 
                i=i+10;
 
                if(i >= 50) {
                        i=0;
                }
 
        }
 
        closegraph();
        getch();
}