#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define gx getmaxx()
#define gy getmaxy()
void main()
{
	int x1,y1,x2,y2,gd=DETECT,gm;
	void dda(int,int,int,int);
	printf("Enter the coordinates of both end points  ");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	line(gx/2,0,gx/2,gy);
	line(0,gy/2,gx,gy/2);
	dda(x1,y1,x2,y2);
	getch();
}

void dda(int x1,int y1,int x2,int y2)
{
	int chx,chy,steps,i;
	float xinc,yinc,x,y;
	chx=x2-x1;
	chy=y2-y1;
	if(abs(chx)>abs(chy))
		steps=abs(chx);
	   else
		steps=abs(chy);

	xinc=(float)(chx/steps);
	yinc=(float)(chy/steps);
	x=x1;y=y1;
	putpixel(x+gx/2,-y+gy/2,5);
	for(i=1;i<=steps;i++)
	{
		x+=xinc;
		y+=yinc;
		putpixel(x+gx/2,-y+gy/2,5);
	}
}
