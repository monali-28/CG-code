// Scanline polygon filling algorithm
#include<iostream>
#include<graphics.h>
#include<math.h>
//#include<conio.h>
//#include<dos.h>
using namespace std;

class scan
{
    public:
    int x[20],y[20],k;
    float slope[20],x_int[20];
    void polygon(int n);
};

void scan::polygon(int n)
{
    int i,p;
    float dx,dy;
    int temp;
    x[n]=x[0];
    y[n]=y[0];
    for(i=0;i<n;i++)
    {
	line(x[i],y[i],x[i+1],y[i+1]);
    }
    // cal. ymin and ymax
    int ymin = y[0];
    int ymax = y[0];
    for (i=0;i<n;i++)
    {
	if (ymin > y[i])
	   ymin = y[i];
	if (ymax < y[i])
	   ymax = y[i];
    }
    // cal. slope
    for(i=0;i<n;i++)
    {
	dy=y[i+1]-y[i];
	dx=x[i+1]-x[i];
	if(dy==0)
	slope[i]=1;
	else if(dx==0)
	slope[i]=0;
	else
	slope[i]=dx/dy;
    }

    for(p=ymin;p<ymax;p++)
    {
	// for eack scanline p, find no. of intersections k
	k=0;
	for(i=0;i<n;i++)
	{
	    if(((y[i]<=p)&&(y[i+1]>p))||((y[i]>p)&&(y[i+1]<=p)))
	      {
		  x_int[k]=x[i]+slope[i]*(p-y[i]);
		  k++;
	      }
	  }

	  // sort x intersections obtained
	  for(int j=0;j<k-1;j++)
	  {
	      for(i=0;i<k-1;i++)
	      {
		  if(x_int[i]>x_int[i+1])
		  {
		      temp=x_int[i];
		      x_int[i]=x_int[i+1];
		      x_int[i+1]=temp;
		  }
	      }
	  }

	  // draw scanline between pairs of intersections
	  for(i=0;i<k;i=i+2)
	  {
	      setcolor(YELLOW);
	      line(x_int[i],p,x_int[i+1],p);
	      delay(10);
	  }
      }
  }

  int main()
  {
      int n,i;
      scan p;
      cout<<"Enter no. of edges : \t";
      cin>>n;
      cout<<"\n\nEnter Coordinates : \t";
      for(i=0;i<n;i++)
      {
	  cin>>p.x[i]>>p.y[i];
      }
      int gd,gm;
      gd=DETECT;
      initgraph(&gd,&gm,NULL);
      p.polygon(n);

      getch();
      closegraph();
      return 0;
}
