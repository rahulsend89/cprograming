#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define gx getmaxx()
#define gy getmaxy()
#include<stdlib.h>
#define pi 3.14
struct point
{
	int x,y;
};
void main()
{
	int gd=DETECT,gm,i,n,ch;
	float tx,ty,sx,sy,theta;
	point p[15];
	void translate(struct point *,float,float,int);
	void scaling(struct point *,float,float,int);
	void rotate(struct point *,float,int);
	void draw(struct point*,int);
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	printf("Enter number of vertices :" );
	scanf("%d",&n);
	printf("Enter no of coordinates:");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
	}

	p[n]=p[0];

	printf("\n1.translate");
	printf("\n2.scaling");
	printf("\n3.rotate");
	printf("\n4.Exit");
	printf("\nenter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			cleardevice();
			draw(p,n);
			printf("\nEnter translation factors:");
			scanf("%f%f",&tx,&ty);
			translate(p,tx,ty,n);
			draw(p,n);
			break;
		case 2:
			cleardevice();
			draw(p,n);
			printf("Enter scaling factor :");
			scanf("%f%f",&sx,&sy);
			scaling(p,sx,sy,n);
			draw(p,n);
			break;
		case 3:
			cleardevice();
			draw(p,n);
			printf("Enter rotation angle");
			scanf("%f",&theta);
			rotate(p,theta,n);
			draw(p,n);
			getch();
			break;
		case 4:
			exit(1);
	}

}

void draw(struct point *p,int n)
{
	int i;
	line(gx/2,0,gx/2,gy);
	line(0,gy/2,gx,gy/2);

	for(i=0;i<n;i++)
	{
		line(p[i].x+gx/2,-p[i].y+gy/2,p[i+1].x+gx/2,-p[i+1].y+gy/2);

	}
	getch();
}

void translate(struct point *p,float tx,float ty,int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		p[i].x=p[i].x+tx;
		p[i].y=p[i].y+ty;
	}
	getch();
}

void scaling(struct point *p,float sx,float sy,int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		p[i].x=p[i].x*sx;
		p[i].y=p[i].y*sy;
	}
	getch();
}
void rotate(struct point *p,float theta,int n)
{
	int i;
	float t,t1,t2;
	t=theta*pi/180;
	for(i=0;i<=n;i++)
	{
		t1=p[i].x*cos(t)-p[i].y*sin(t);
		t2=p[i].x*sin(t)+p[i].y*cos(t);
		p[i].x=t1;
		p[i].y=t2;
	}
}

