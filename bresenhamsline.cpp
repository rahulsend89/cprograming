#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define gx getmaxx()
#define gy getmaxy()
void main()
{
	int x1,y1,x2,y2,gd=DETECT,gm;
	void bresenham_line(int,int,int,int);
	printf("Enter the coordinates of both the end points  :");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	line(gx/2,0,gx/2,gy);
	line(0,gy/2,gx,gy/2);
	bresenham_line(x1,y1,x2,y2);
	getch();
}

void bresenham_line(int x1,int y1,int x2, int y2)
{
	int x, y,p,dx,dy,xinc,yinc;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;y=y1;
	putpixel(x+gx/2,-y+gy/2,15);
	if (x1<x2)
		xinc=1;
	     else
		xinc=-1;
	if (y1<y2)
		yinc=1;
	     else
		yinc=-1;

	if(dx>=dy)
	{
		p=2*dy-dx;
		while(x!=x2)
		{
			x+=xinc;
			if(p<0) p+=2*dy;
			else
			{
				p+=2*(dy-dx);
				y+=yinc;
			}
			putpixel(x+gx/2,-y+gy/2,15);
		}
	}
	else
	{
		p=2*dx-dy;
		while(y!=y2)
		{
			y+=yinc;
			if(p<0) p+=2*dx;
			else
			{
				p+=2*(dx-dy);
				x+=xinc;
			}
			putpixel(x+gx/2,-y+gy/2,15);
		}
	}

}
