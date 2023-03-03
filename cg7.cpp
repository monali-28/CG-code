/*a) Write a C++ program to control a ball using
arrow keys. Apply the concept of polymorphism. OR (b) Write a C++ program to
implement bouncing ball using sine wave form. Apply the concept of
polymorphism. OR (c) Write C++ program to draw man walking in the rain with an
umbrella. Apply the concept of polymorphism. OR (c) Write a C++ program to
implement the game of 8 puzzle. Apply the concept of polymorphism. OR (d) Write
a C++ program to implement the game Tic Tac Toe. Apply the concept of
polymorphism.*/


#include<graphics.h>
#define HEIGHT getmaxy()
#define WIDTH getmaxx()
#define GROUND 450
#define MAXHEIGHT 420
using namespace std;
int main()
{
	int x,y=0,t=MAXHEIGHT,c=1;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	setcolor(RED);
	for(x=40;x<=getmaxx();x=x+2)
	{
		rectangle(0,MAXHEIGHT,getmaxx(),MAXHEIGHT+5);
		floodfill(5,MAXHEIGHT+3,WHITE);
		pieslice(x,y,0,360,20);
		delay(100);
		if(y>MAXHEIGHT-20)
		{
			c=0;
			t=t-40;
		}
		if(y<=(MAXHEIGHT-t))
		{
			c=1;
		}
		if(t>=40)
		y=y+(c? 15:-15);
		cleardevice();
		//if(kbhit())
		//break;
	}
	getch();
}
