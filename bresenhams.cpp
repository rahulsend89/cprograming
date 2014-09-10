		#include<stdio.h>
		#include<conio.h>
		#include<graphics.h>
		#include<math.h>

		void main()
	{
		int x1,y1,x2,y2,gd=DETECT,gm,gx,gy;
		void bresenhams_line(int,int,int,int);
		clrscr();
		printf("Enter the cordinates of both the points");
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		initgraph(&gd,&gm,"c:\\tc\\bgi");
		gx=getmaxx();
		gy=getmaxy();

		line(gx/2,0,gx/2,gy);
		line(0,gy/2,gx,gy/2);
		outtextxy(325,0,"y");
		outtextxy(325,470,"-y");
		outtextxy(gx/2,gy/2,"o");
		outtextxy(630,230,"x");
		outtextxy(0,230,"-x");
		bresenhams_line(x1,y1,x2,y2);
		getch();
	}
		void bresenhams_line(int x1,int y1,int x2,int y2)
	{
		int x,y,p,dx,dy,xinc,yinc,gx,gy;
		char *str1,*str2;
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		x=x1,
		y=y1;

	if(x1<x2)
		xinc=1;
	else
		xinc=-1;
	if(y1<y2)
		yinc=1;
	else
		yinc=-1;
	if(dx>=dy)
    {
		p=2*(dy-dx);
	while(x!=x2)
      {
			x+=xinc;
			if(p<0)
			p+=2*dy;
		else
		{
			p+=2*(dy-dx);
			y+=yinc;
		}
		putpixel(x,y,15);
      }
    }
    else
	{
		p=2*(dy-dx);
     while(y!=y2)
	{
			y+=yinc;
			if(p<0)
			p+=2*dx;
	else
		{
			p+=2*(dx-dy);
			x+=xinc;
		}
			putpixel(x,y,15);
	}
     }

}