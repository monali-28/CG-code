#include<iostream>
//#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
//#include<dos.h>
//#include<conio>
using namespace std;

#define SIN 0.86602540 //sin(60 degrees)
void koch(int x1, int y1, int x2, int y2, int m)
{ 	int xx, yy, x[5], y[5], lx, ly, offx=50, offy=300;
	lx=(x2-x1)/3;
	ly=(y2-y1)/3;
	x[0]=x1;
	y[0]=y1;
	x[4]=x2;
	y[4]=y2;
	x[1]=x[0]+lx;
	y[1]=y[0]+ly;
	x[3]=x[0]+2*lx;
	y[3]=y[0]+2*ly;
	xx= x[3]-x[1];
	yy= y[3]-y[1];
	x[2]=xx*(0.5)+yy*(SIN);
	y[2]=-xx*(SIN)+yy*(0.5);
	x[2]=x[2]+x[1];
	y[2]=y[2]+y[1];
	if(m>0)
	{
	delay(10);
	koch(x[0], y[0], x[1], y[1], m-1); //Recursive call to Draw part1
	koch(x[1], y[1], x[2], y[2], m-1); //Recursive call to Draw part2
	koch(x[2], y[2], x[3], y[3], m-1); //Recursive call to Draw part3
	koch(x[3], y[3], x[4], y[4], m-1); //Recursive call to Draw part4
	delay(10);
	}
	else
	{
	line(offx+x[0], offy+y[0], offx+x[1], offy+y[1]);
	delay(100);
	line(offx+x[1], offy+y[1], offx+x[2], offy+y[2]);
	delay(100);
	line(offx+x[2], offy+y[2], offx+x[3], offy+y[3]);
	delay(100);
	line(offx+x[3], offy+y[3], offx+x[4], offy+y[4]);
	delay(100);
	}
}//Koch curve Function End

int main()
{
	int n;
	int gd = DETECT,gm;
	cout<<"\nEnter the level of curve generation:";
	cin>>n;
	initgraph(&gd, &gm,NULL);
	cleardevice();
	int x1=0, x2=550, y1=0, y2=0;
	koch(x1,y1,x2,y2,n);
	delay(1000);
	closegraph();
   //	getch();
	return 0;
}

