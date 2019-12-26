     #include<stdio.h>
    #include<conio.h>
    #include<graphics.h>
    #include<dos.h>

    void bg()
    {
    int xcord;
    cleardevice();
    setcolor(WHITE);

    xcord=getmaxx()/2;

    settextstyle(0, HORIZ_DIR,1);
    outtextxy(xcord,10,"Created By:Yasar Shaikh");
    outtextxy(xcord,20,"From: WIT,Solapur");
    outtextxy(xcord,30,"Roll No.SE IT 55");
    //First row of ballons
    setfillstyle(SOLID_FILL,RED);
    fillellipse(200,200,20,20);

    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(240,200,20,20);

    setfillstyle(SOLID_FILL,GREEN);
    fillellipse(280,200,20,20);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    fillellipse(320,200,20,20);

    setfillstyle(SOLID_FILL,CYAN);
    fillellipse(360,200,20,20);

    //second row of ballon

    setfillstyle(SOLID_FILL,MAGENTA);
    fillellipse(220,240,20,20);

    setfillstyle(SOLID_FILL,BLUE);
    fillellipse(260,240,20,20);

    setfillstyle(SOLID_FILL,LIGHTGREEN);
    fillellipse(300,240,20,20);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(340,240,20,20);

    //Third row of ballons

    setfillstyle(SOLID_FILL,BROWN);
    fillellipse(230,280,20,20);

    setfillstyle(SOLID_FILL,LIGHTRED);
    fillellipse(270,280,20,20);

    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    fillellipse(310,280,20,20);

    }

    void gun()
    {
    int a[8]={270,450,270,370,290,370,290,450};
    setfillstyle(SOLID_FILL,BROWN);
    fillpoly(4,a);
    }

    void main()
    {
    int gd=DETECT,gm,i;

    initgraph(&gd,&gm,"d:\cpp");

    bg();
    gun();
    setcolor(RED);

    outtextxy(100,100,"Press Any Key to Start...");
    getche();

    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
    for(i=0;i<210;i+=2)
    {
     bg();
     gun();
     settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
     setcolor(rand(i));
     outtextxy(280,370-i,".");
     outtextxy(280,370-i-2," ");
     delay(100);

    }

    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(280,200,20,20);

    setcolor(RED);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 10);
    outtextxy(100,200,"Bang...!!!");

    getche();
    getche();
    closegraph();
    }