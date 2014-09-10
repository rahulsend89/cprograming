#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define gx getmaxx()
#define gy getmaxy()
void main()
{
	int xc ,yc,r,gd=DETECT,gm;
	void midpoint_circle(int, int,int);
	printf("Enter the radius");
	scanf("%d",&r);
	printf("Enter the center coordinates :");
	scanf("%d%d",&xc,&yc);
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	midpoint_circle(xc,yc,r);
	getch();
}
void midpoint_circle(int xc,int yc, int r)
{
	int x=0,y=r,p;
	void display(int ,int,int,int);
	p=1-r;
	while(x<=y)
	{
		display(xc,yc,x,y);
		if(p<0) p+=2*x+3;
		else
		{
			p+=2*(x-y)+5;
			y--;
		}
		x++;
	}
}
void display(int xc,int yc,int x,int y)
{
	putpixel(xc+x,yc+y,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc-x,yc-y,15);
	putpixel(xc+y,yc+x,15);
	putpixel(xc+y,yc-x,15);
	putpixel(xc-y,yc+x,15);
	putpixel(xc-y,yc-x,15);

}