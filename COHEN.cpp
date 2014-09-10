#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
 float xmin,xmax,ymin,ymax,x1,x2,y1,y2;
 int gd=DETECT,gm;
 //char s[15];
 void clip(float,float,float,float,float,float,float,float);
 clrscr();
 printf("Enter the window co-ordinates =");
 scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);
 printf("Enter the co-ordinates= ");
 scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 setcolor(15);
 rectangle(xmin,ymin,xmax,ymax);
 //sprintf(s,"(%d,%d)",(int)xmin, (int)ymin);
 //outtextxy(xmin-40,ymin-40,s);
 //sprintf(s,"(%d,%d)",(int)xmax, (int)ymax);
 //outtextxy(xmax+40,ymax+40,s);
 line(x1,y1,x2,y2);
 outtextxy(100,400,"BEFORE CILPPING");
 //sprintf(s,"(%d,%d)",(int)x1,(int)y1);
 //outtextxy(x1,y1,s);
 // sprintf(s,"(%d,%d)",(int)x2,(int)y2);
 //outtextxy(x2,y2,s);
 getch();
 setcolor(0);
 line(x1,y1,x2,y2);
  outtextxy(100,400," AFTER CLIPPING");
 clip(xmin,ymin,xmax,ymax,x1,y1,x2,y2);

 closegraph();
}
void clip(float xmin,float ymin,float xmax,float ymax,float x1,float y1,float x2,float y2)
{
	static int c[4],c1[4],c2[4],flag1,flag2,i;
	float x,y;
	void code(float,float,float,float,float,float,int *);
	code(x1,y1,xmin,ymin,xmax,ymax,c1);
	code(x2,y2,xmin,ymin,xmax,ymax,c2);
	flag1=c1[0]||c1[1]||c1[2]||c1[3];
	flag2=c2[0]||c2[1]||c2[2]||c2[3];
	while(flag1||flag2)
	{
		if(c1[0]&&c2[0]||c1[1]&&c2[1]||c1[2]&&c2[2]||c1[3]&&c2[3])
		{
			closegraph();
			printf("Line is outside the window \n ");
			goto abc;
		}
		if(flag1==0)
		for(i=0;i<4;i++)
			c[i]=c2[i];
		else
		for(i=0;i<4;i++)
			c[i]=c1[i];
		if(c[0]==1)
		{
			y=y1+(y2-y1)*(xmin-x1)/(x2-x1);
			x=xmin;
		}
		else
		if(c[1]==1)
		{
			 y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
			x=xmax;
		}
		else
		if(c[2]==1)
		{
			x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
			y=ymax;
		}
		else
		if(c[3]==1)
		{
			x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
			y=ymin;
		}
		if(flag1==0)
		{
			x2=x;
			y2=y;
			code(x2,y2,xmin,ymin,xmax,ymax,c2);
			flag2=c2[0]||c2[1]||c2[2]||c2[3];
		}
		else
		{
			x1=x;
			y1=y;
			code(x1,y1,xmin,ymin,xmax,ymax,c1);
			flag1=c1[0]||c1[1]||c1[2]||c1[3];
		}
	}
	setcolor(15);
	line(x1,y1,x2,y2);
	abc:getch();

}
void code(float x,float y,float xmin,float ymin,float xmax,float ymax,int *c)
{
if(x<xmin)
{
    c[0]=1;
    c[1]=0;
}
else
  if(x>xmax)
  {
     c[0]=0;
     c[1]=1;
  }
  else
    c[0]=c[1]=0;
if(y>ymax)
{
    c[2]=1;
    c[3]=0;
}
else
  if(y<ymin)
  {
    c[2]=0;
    c[3]=1;
  }
  else
     c[2]=c[3]=0;
}