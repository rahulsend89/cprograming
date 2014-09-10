#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	float xc,yc,rx,ry;int gd=DETECT,gm;
	void mid_ellipse(float,float,float,float);
	printf("Enter the major and minor radius :");
	scanf("%f%f",&rx,&ry);
	printf("\nEnter the center coordinates :");
	scanf("%f%f",&xc,&yc);
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	mid_ellipse(xc,yc,rx,ry);
	getch();
}

void mid_ellipse(float xc,float yc,float rx,float ry)
{
	int x,y;
	float p,slope;
	void display(float,float,float,float);
	p=rx*ry-rx*rx*rx-0.25*rx*rx;
	x=0;
	y=ry;
	slope=-(ry*ry*x)/(rx*rx*y);
	while(abs(slope)<1)
	{
		display(xc,yc,x,y);
		if(p<0) p+=ry*ry*(2*x+3);
		else
		{
			p+=ry*ry*(2*x+3)+rx*rx*(2-2*y);
			y--;
		}
		x++;
		slope=-(ry*ry*x)/(rx*rx*y);
	}
	p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*((y-1)*(y-1)-ry*ry);
	while(y>=0)
	{
		display(xc,yc,x,y);
		if(p<0)
		{
			p+=ry*ry*(2*x+2)+rx*rx*(3-2*y);
			x++;
		}
		else
			p+=rx*rx*(3-2*y);
		y--;
	}

}
void display(float xc,float yc,float x, float y)
{
	putpixel(xc+x,yc+y,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc-x,yc-y,15);
}