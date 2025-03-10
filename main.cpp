#include <graphics.h>

void box()
{
    setcolor(MAGENTA);
    setlinestyle(0, 0, 3);
    rectangle(100,100,300,400);
    setcolor(WHITE);
    line(165,100,235,100);
    line(165,400,235,400);
    setlinestyle(1, 0, 1);
    setcolor(LIGHTBLUE);
    line(100,250,300,250);
    circle(200, 250, 10);
}

void circle1(int x, int y, int color)
{
    setcolor(color);
    circle(x, y, 10);
    circle(x, y, 15);
}

void circle2(int x, int y)
{
    setcolor(CYAN);
    setfillstyle(1, CYAN);
    circle(x, y, 10);
    floodfill(x, y, CYAN);
}

void flicker(int del)
{
    static int page = 1;
    setactivepage(page);
    setvisualpage(1 - page);
    page = 1 - page;
    cleardevice();
    delay(del);
}

void score(char str[])
{
    setlinestyle(0, 0, 1);
    settextstyle(0, 0, 2);
    setcolor(DARKGRAY);
    outtextxy(350, 240, "SCORE");
    settextstyle(0, -1, 2);
    outtextxy(320, 200, str);
}

void show(int color, char text[], int pos, int i)
{
    settextstyle(3, 0, 6);
    if (i % 2 == 0)
    {
        setcolor(color + 8);
    }
    else
    {
        setcolor(color);
    }
    outtextxy(pos, 220, text);
}


int main()
{
    int gd = DETECT, gm, i;
    initgraph(&gd, &gm, (char *)"");
    setbkcolor(WHITE);
    for (i = 0; i < 100; i++)
    {
        flicker(1);
        box();
        score("0    0");
        circle1(200, 142, RED);
        circle1(250, 377, GREEN);
        circle2(200, 190);
    }

    for (i = 0; i < 8; i++)    //red down, hits yellow
    {
        flicker(1);
        box();
        score("0    0");
        circle1(200, 142 + 4*i, RED);
        circle1(250, 377, GREEN);
        circle2(200, 190);
    }

    for (i = 0; i < 30; i++)    //yellow down, green saves
    {
        flicker(10);
        box();
        score("0    0");
        circle1(200, 166, RED);
        circle1(250 - 1.36*i, 377 - 1.86*i, GREEN);
        circle2(200, 190 + 4*i);
    }

    for (i = 0; i < 25; i++)    //yellow down, green saves, reflects yellow
    {
        flicker(10);
        box();
        score("0    0");
        circle1(200, 166, RED);
        circle1(210.56, 323.06, GREEN);
        circle2(200 - 4*i, 306 - 4*i);
    }

    for (i = 0; i < 20; i++)    //yellow towards red, red hits back
    {
        flicker(1);
        box();
        score("0    0");
        circle1(200 - 2*i, 166 - 0.58*i, RED);
        circle1(210.56 + i, 323.06, GREEN);
        circle2(104 + 2*i, 210 - 2*i);
    }

    for (i = 0; i < 9; i++)    //yellow hits edge
    {
        flicker(10);
        box();
        score("0    0");
        circle1(162, 155, RED);
        circle1(229.56, 323.06, GREEN);
        circle2(142 - 4*i, 172 + 4*i);
    }

    for (i = 0; i < 33; i++)    //yellow towards green, hits edge
    {
        float j;
        j = 0.3*i;
        flicker(10);
        box();
        score("0    0");
        circle1(162, 155, RED);
        circle1(229.56 - 4*j, 323.06, GREEN);
        circle2(106 + 6*i, 208 + 4*i);
    }

    for (i = 0; i < 18; i++)    //red scores
    {
        flicker(10);
        box();
        score("0    0");
        circle1(162, 155, RED);
        circle1(191.16, 323.06, GREEN);
        circle2(298 - 5*i, 336 + 4*i);
    }

    for (i = 0; i < 10; i++)    //red scores
    {
        flicker(250);
        box();
        score("1    0");
        show(RED, "RED SCORES", 30, i);
        circle1(162, 155, RED);
        circle1(191.16, 323.06, GREEN);
    }

    for (i = 0; i < 9; i++)    //green up
    {
        flicker(10);
        box();
        score("1    0");
        circle1(240, 150, RED);
        circle1(200, 377 - 4*i, GREEN);
        circle2(200, 326);
    }

    for (i = 0; i < 30; i++) //yellow up, red blocks
    {
        float j = 0.75*i;
        flicker(10);
        box();
        score("1    0");
        circle1(240 - j, 150 + j, RED);
        circle1(200, 347, GREEN);
        circle2(200, 326 - 5*i);
    }

    for (i = 0; i < 20; i++) //yellow goes down to edge
    {
        flicker(10);
        box();
        score("1    0");
        circle1(218.25, 171.75, RED);
        circle1(200, 347, GREEN);
        circle2(200 - 5*i, 181 + 5*i);
    }

    for (i = 0; i < 20; i++) //yellow towards green, blocks and deflects
    {
        flicker(10);
        box();
        score("1    0");
        circle1(218.25 - 1.5*i, 171.75 + 1.5*i, RED);
        circle1(200, 347 + 2.5*i, GREEN);
        circle2(105 + 5*i, 276 + 5*i);
    }

    for (i = 0; i < 55; i++) //yellow to score for green
    {
        flicker(10);
        box();
        score("1    0");
        circle1(189.75 - 0.5*i, 200.25 + 0.5*i, RED);
        circle1(200, 394.5 + 0.1*i, GREEN);
        circle2(200, 371 - 5*i);
    }

    for (i = 0; i < 10; i++)    //green scores
    {
        flicker(250);
        box();
        score("1    1");
        show(GREEN, "GREEN SCORES", 10, i);
        circle1(162.25, 227.75, RED);
        circle1(200, 400, GREEN);
    }

    for (i = 0; i < 30; i++)    //red left
    {
        flicker(1);
        box();
        score("1    1");
        circle1(230 - 2*i, 150, RED);
        circle1(200, 347, GREEN);
    }

    for (i = 0; i < 18; i++)     //red diagonal, hits yellow
    {
        flicker(1);
        box();
        score("1    1");
        circle1(170 + 2*i, 150 + 2*i, RED);
        circle1(200, 347, GREEN);
        circle2(220, 200);
    }

    for (i = 0; i < 20; i++)     //yellow edge, green up
    {
        flicker(1);
        box();
        score("1    1");
        circle1(200, 177, RED);
        circle1(200, 347 - 3*i, GREEN);
        circle2(220 + 4*i, 200 + 4*i);
    }

    for (i = 0; i < 21; i++)     //yellow down
    {
        flicker(10);
        box();
        score("1    1");
        circle1(200, 177, RED);
        circle1(200, 290 + 3*i, GREEN);
        circle2(296 - 5*i, 276 + 5*i);
    }

    for (i = 0; i < 8; i++)     //yellow diagonal, green down
    {
        flicker(10);
        box();
        score("1    1");
        circle1(200, 177, RED);
        circle1(200, 350, GREEN);
        circle2(198, 376 + 4*i);
    }

    for (i = 0; i < 10; i++)     //yellow diagonal, green down
    {
        flicker(250);
        box();
        score("2    1");
        show(RED, "RED SCORES", 30, i);
        circle1(200, 177, RED);
        circle1(200, 350, GREEN);
    }

    for (i = 0; i < 11; i++)    //green up
    {
        flicker(10);
        box();
        score("2    1");
        circle1(200, 177, RED);
        circle1(200, 350 - 3*i, GREEN);
        circle2(200, 300);
    }

    for (i = 0; i < 22; i++)    //yellow up, red down
    {
        flicker(10);
        box();
        score("2    1");
        circle1(200, 177 + i, RED);
        circle1(200, 320, GREEN);
        circle2(200, 300 - 4*i);
    }

    for (i = 0; i < 23; i++)    //yellow down, green side
    {
        flicker(10);
        box();
        score("2    1");
        circle1(200, 198, RED);
        circle1(200 - i, 320, GREEN);
        circle2(200, 216 + 4*i);
    }

    for (i = 0; i < 25; i++)    //yellow edge
    {
        flicker(10);
        box();
        score("2    1");
        circle1(200, 198 + i, RED);
        circle1(178, 320, GREEN);
        circle2(200 + 4*i, 304 - 4*i);
    }

    for (i = 0; i < 28; i++)    //yellow to goal
    {
        flicker(10);
        box();
        score("2    1");
        circle1(200, 222 - 3*i, RED);
        circle1(178, 320, GREEN);
        circle2(296 - 4*i, 208 - 4*i);
    }

    for (i = 0; i < 10; i++)    //green scores
    {
        flicker(250);
        box();
        score("2    2");
        show(GREEN, "GREEN SCORES", 10, i);
        circle1(200, 141, RED);
        circle1(178, 320, GREEN);
    }

    for (i = 0; i < 20; i++)    //red green in position
    {
        flicker(1);
        box();
        score("2    2");
        circle1(222 - i, 177 - i, RED);
        circle1(210 - 0.5*i, 340 + i, GREEN);
    }

    for (i = 0; i < 23; i++)    //red, green to yellow
    {
        flicker(1);
        box();
        score("2    2");
        circle1(200, 164 + 3*i, RED);
        circle1(190, 334 - 3*i, GREEN);
        circle2(200, 250);
    }

    for (i = 0; i < 25; i++)    //yellow hits edge
    {
        flicker(1);
        box();
        score("2    2");
        circle1(200, 227, RED);
        circle1(190, 269, GREEN);
        circle2(200 + 4*i, 250 + 4*i);
    }

    for (i = 0; i < 20; i++)    //red scores
    {
        flicker(1);
        box();
        score("2    2");
        circle1(200, 227, RED);
        circle1(190, 269, GREEN);
        circle2(290 - 3.7*i, 346 + 3*i);
    }

    for (i = 0; i < 50; i++)    //red wins
    {
        flicker(250);
        box();
        score("3    2");
        show(RED, "RED WINS", 65, i);
        circle1(200, 227, RED);
        circle1(190, 269, GREEN);
    }

    getch();
    closegraph();
    return 0;
}
