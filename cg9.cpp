// Write a C++ program to implement Bresenham’s line drawing algorithm to draw a dotted line. Apply the concept of encapsulation.
// SE Monali Khairnar

#include<iostream>
#include<graphics.h>
#include<math.h>

class Bresenham
{int x1,x2,y1,y2,x,y;
public:
void getvalue()
{
x1=100;
y1=100;
x2=300;
y2=300;
}
void init()
{
x=x1;
y=y1;

}
int sign(int value)
{
if(value < 0)
return -1;
else if (value > 0)
return 1;
else
return 0;
}
void drawline();
};
void Bresenham::drawline()
{
int dx,dy,temp,interchange,G,i;
int s1,s2;

dx=abs(x2-x1);
dy=abs(y2-y1);
s1=sign(x2-x1);
s2=sign(y2-y1);

if(dy>dx)
{
temp=dx;
dx=dy;

dy=temp;
interchange=1;
}
else
interchange=0;
G=2*dy-dx;

int flag = 0;
for(i=1;i<=dx;i++)
{
if (flag==0)
{
putpixel(int(x),int(y),RED);
flag=1;
}
else
flag=0;

while(G>=0)
{
if(interchange==1)
x=x+s1;
else
y=y+s2;

G=G-2*dx;

}
if(interchange==1)
y=y+s2;
else
x=x+s1;

G=G+2*dy;
}
}

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
setbkcolor(WHITE);
Bresenham line1;
line1.getvalue();
line1.init();
line1.drawline();
getch();
closegraph();
return 0;
}
