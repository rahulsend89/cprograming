#include<stdio.h>
#include<graphics.h>
#include<conio.h>
struct point
{
   float x,y;
};
void main()
{
	struct point p[24];
	int gd=DETECT,gm,i,n;
	//char s[10];
	void bezier(struct point *p,int n);
	printf("ENTER THE NO OF CONTROL POINTS\N");
	scanf("%d",&n);
	printf("ENTER (X,Y) POINTS\n");
	for(i=0;i<n;i++)
	scanf("%f%f",&(p[i].x),&(p[i].y));
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setcolor(4);
	for(i=0;i<n-1;i++)
	//sprintf(s,"(%d%d)",(int) p[i].x, (int)p[i].y);
	//outtextxy(p[i].x,p[i].y,s);
		line(p[i].x,p[i].y,p[i+1].x,p[i+1].y); getch();
	bezier(p,n-1);
	getch();
	getch();
}
void bezier(struct point *p,int n)
{
	int k;
	float f,sum,xu,yu,b;
	float fact(int);
	double u=0.001;
	while(u<=1)
	{
		xu=0;
		yu=0;
		for(k=0;k<=n;k++)
		{
			f=fact(n)/(fact(k)*fact(n-k));
			b=exp(k*log(u))*exp((n-k)*log(1-u));
			xu+=p[k].x*f*b;
			yu+=p[k].y*f*b;
		}
		putpixel(xu,yu,15); getch();
		u+=0.001;
	}
	getch();
}
float fact(int x)
{
	int i;
	float f=1;
	for(i=1;i<=x;i++)
	f=f*i;
	return(f);
}
