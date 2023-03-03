							//Program 2

//Write a C++ program to draw the following pattern. Use DDA line and Bresenham’s circle drawing algorithm. Apply the concept of encapsulation.


#include<iostream>
#include<graphics.h>
#include<math.h>
class DDA
{
public:
void drawline(int x1,int y1,int x2,int y2);
};
void DDA::drawline(int x1,int y1,int x2,int y2)
{
int dx,dy,length,i;
float xi,yi,x,y;
dx=(x2-x1);
dy=(y2-y1);
if(abs(dx) >= abs(dy))
length = abs(dx);
else
length = abs(dy);
xi=(float) dx/length;
yi=(float) dy/length;
x=x1+0.5;
y=y1+0.5;
for(i=1;i<=length;i++)
{
putpixel(int(x),int(y),BLUE);
x=x+xi;
y=y+yi;
}
}
class Bresenham
{
public:
void draw_circle(int xc,int yc,int rad)
{
int x,y,s,length,i,r;

r=rad;
x=0;
y=r;
s=3-2*r;
while(x<=y)
{
if(s<=0)
{
s=s+4*x+6;
x++;
}
else
{
s=s+4*(x-y)+10;
x++;
y--;
}
putpixel(x+xc,y+yc,RED);
putpixel(-x+xc,y+yc,RED);
putpixel(x+xc,-y+yc,RED);
putpixel(-x+xc,-y+yc,RED);
putpixel(y+xc,x+yc,RED);
putpixel(-y+xc,x+yc,RED);
putpixel(y+xc,-x+yc,RED);
putpixel(-y+xc,-x+yc,RED);
}
}
};
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
Bresenham circle;
setbkcolor(WHITE);
circle.draw_circle(210,240,68);
circle.draw_circle(210,248,138);
DDA line1;
line1.drawline(87,310,333,310);
line1.drawline(87,310,210,110);
line1.drawline(210,110,333,310);
getch();
closegraph();
return 0;
}
