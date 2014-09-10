	#include<stdio.h>
	#include<conio.h>
	#include<graphics.h>
	void main()
	{
		int gd=DETECT,gm,i=0,bkcol;
		char bkname[35];
		void dda(int,int,int,int);
		void bresanhams_circle(int,int,int);
		void food(int,int,int);
		initgraph(&gd,&gm,"c:\\tc\\bgi");
		bkcol=14;
		setbkcolor(bkcol);
		dda(0,200,200,0);
		dda(200,0,400,200);
		dda(400,200,600,0);
		do
		{
		delay(200);
		circle(400,150,i);
		i++;
		}
		while(i<40);
	      delay(10);
	     food(100,100,4);

	   getch();
	}
  void dda(int x1,int y1,int x2,int y2)
  {
    int chx,chy,step,xinc,yinc,i,x,y;
    chx=x2-x1;
    chy=y2-y1;
    if(abs(chx)>abs(chy))

     step=abs(chx);
     else
     step=abs(chy);
     xinc=chx/step;
     yinc=chy/step;
     x=x1;
     y=y1;
     putpixel(x,y,4);
     for(i=0;i<step;i++)
     {
       x+=xinc;
       y+=yinc;
       putpixel(x,y,4);
     }
   }

	void bresenhams_circle(int xc,int yc,int r)
	{
	int x=0,y=r,p;

	void display(int,int,int,int);


	p=3-2*r;

	while(x<=y)
	{
		display(xc,yc,x,y);

		if(p<0)
		p+=4*x+6;
			else
		{
		   p+=4*(x-y)+10;
		   y--;
		}
			x++;
		}
	}

	void display(int xc,int yc,int x,int y)
	{
		putpixel(xc+x,yc+y,12);
		putpixel(xc+x,yc-y,12);
		putpixel(xc-x,yc+y,12);
		putpixel(xc-x,yc-y,12);
		putpixel(xc+y,yc+x,12);
		putpixel(xc+y,yc-x,12);
		putpixel(xc-y,yc+x,12);
		putpixel(xc-y,yc-x,12);
	}

	  void food(int x,int y,int fc)
	  {


	    putpixel(x,y,fc);
	    food(x+1,y,fc);
	    food(x-1,y,fc);
	    food(x,y+1,fc);
	    food(x,y-1,fc);

	 }





