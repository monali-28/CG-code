#include<iostream>
#include<graphics.h>
//#include<conio.h>
//#include<dos.h>
using namespace std;

void drawWindow(int xmin, int xmax,int ymin, int ymax)
{
line(xmin,ymax,xmin,ymin);//left edge
line(xmax,ymin,xmax,ymax);//right edge
line(xmin,ymin,xmax,ymin);//bottom edge
line(xmin,ymax,xmax,ymax);//top edge
}

class POINT
{
public:
int x,y;
int code[4];

void setcode(int xmin,int xmax,int ymin, int ymax)
{
//left
if(x < xmin)
code[3] = 1;
else
code[3] = 0;

//right
if(x > xmax)
code[2] = 1;
else
code[2] = 0;

//below
if(y > ymax)
code[1] = 1;
else
code[1] = 0;

//top
if(y < ymin)
code[0] = 1;
else
code[0] = 0;
}

void printcode();

};

void POINT::printcode()
{
for(int i=0; i < 4; i++)
cout<<code[i];
}

//return 0 if line is completely visible
//return 1 if line completely invisible

//return 2,otherwise
int check(POINT p1, POINT p2)
{
int flag = 0;

for(int i=0; i < 4; i++)
{
if(p1.code[i] != 0 || p2.code[i] != 0)
flag = 1;
}

//line completely visible
if(flag == 0)
return 0;
//line completely invisible
flag = 0;
for(int i=0; i < 4; i++)
{
if(p1.code[i] == 1 && p2.code[i] == 1)
flag =1;
}
if(flag == 1) //nonzero
return 1;
return 2;
}

POINT clipping(POINT p1, POINT p2,int xmin,int xmax, int ymin,int ymax)
{
float m;
//find intersection point with window boundaries
POINT pi;

if(p1.code[3] == 1)
pi.x = xmin;
if(p1.code[2] == 1)
pi.x = xmax;
if(p1.code[3] == 1 || p1.code[2] == 1)
{
//find slope of line
m = (float)(p2.y - p1.y)/(p2.x - p1.x);
pi.y = p1.y + m * (pi.x - p1.x);
pi.setcode(xmin,xmax,ymin,ymax);
if(pi.y <= ymax && pi.y >= ymin)
return pi;
}

if(p1.code[0] == 1) // line crosses top boundary
pi.y = ymin;
if(p1.code[1] ==1) //line crosses bottom boundary
pi.y = ymax;
if(p1.code[0] == 1 || p1.code[1] ==1)
{
//find slope of line
m = (float)(p2.y - p1.y)/(p2.x - p1.x);
pi.x = p1.x +(pi.y - p1.y) / m;
pi.setcode(xmin,xmax,ymin,ymax);
if(pi.x <= xmax && pi.x >= xmin)
return pi;
}
else
return p1;
}

int main()
{
POINT p1,p2;
cout<<"\nEnter x and y coordinates of start point of line ::";
cin>>p1.x>>p1.y;
cout<<"\nEnter x and y coordinates of end point of line ::";
cin>>p2.x>>p2.y;

int gd = DETECT, gm;
int xmin = 100, xmax = 300 ,ymin = 100, ymax = 300;

p1.setcode(xmin,xmax,ymin,ymax); //set code of p1
cout<<" p1 code = ";
p1.printcode();
p2.setcode(xmin,xmax,ymin,ymax); //set code of p2
cout<<" p2 code = ";
p2.printcode();

int value = check(p1,p2);
cout<<"flag = "<<value;
initgraph(&gd , &gm ,NULL);
setcolor(YELLOW);
//setbkcolor(YELLOW);
//textcolor(RED);
switch(value)
{
case 0: //line completely visible
outtextxy(50,50,"BEFORE CLIPPING");
drawWindow(xmin,xmax,ymin,ymax);
delay(3000);
line(p1.x,p1.y,p2.x,p2.y);
delay(3000);

cleardevice();
outtextxy(50,50,"AFTER CLIPPING");
drawWindow(xmin,xmax,ymin,ymax);
delay(3000);
line(p1.x,p1.y,p2.x,p2.y);
delay(3000);
break;

case 1: //line completely invisible
//textcolor(RED);
outtextxy(50,50,"BEFORE CLIPPING");
drawWindow(xmin,xmax,ymin,ymax);
delay(3000);
line(p1.x,p1.y,p2.x,p2.y);
delay(3000);

cleardevice();
//textcolor(RED);
outtextxy(50,50,"AFTER CLIPPING");
drawWindow(xmin,xmax,ymin,ymax);
delay(3000);
break;
case 2: //clip line
//textcolor(RED);
outtextxy(50,50,"BEFORE CLIPPING");
drawWindow(xmin,xmax,ymin,ymax);
delay(3000);
line(p1.x,p1.y,p2.x,p2.y);
delay(3000);

cleardevice();
//textcolor(RED);
outtextxy(50,50,"AFTER CLIPPING");
POINT p3=clipping(p1,p2,xmin,xmax,ymin,ymax);

// cout<<"p3 = "<<p3.x<<" "<<p3.y;
POINT p4=clipping(p2,p1,xmin,xmax,ymin,ymax);
// cout<<"p4 = "<<p4.x<<" "<<p4.y;
drawWindow(xmin,xmax,ymin,ymax);
delay(3000);
circle(p3.x,p3.y,5);
circle(p4.x,p4.y,5);
line(p3.x,p3.y,p4.x,p4.y);
delay(3000);
break;

// default :
// break; //cout<<"....";
}
getch();
closegraph();
return 0;
}
