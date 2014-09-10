#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<math.h>

struct point
{
	float x,y;
};

struct window
{
	int xmin,ymin,xmax,ymax;
};

void main()
{
	int gd=DETECT,gm;
	void Liang_Barsky(struct point,struct point,struct window);
	struct point p1,p2;
	struct window w;
	printf("Enter window coordinates : ");
	printf("\nEnter left boundary: ");
	scanf("%d",&w.xmin);
	printf("\nEnter right boundary: ");
	scanf("%d",&w.xmax);
	printf("\nEnter bottom boundary: ");
	scanf("%d",&w.ymin);
	printf("\nEnter top boundary: ");
	scanf("%d",&w.ymax);
	printf("Enter line coordinates : ");
	printf("\n Enter x of A =>");
	scanf("%f",&p1.x);
	printf("\n Enter y of A =>");
	scanf("%f",&p1.y);
	printf("\n Enter x of B =>");
	scanf("%f",&p2.x);
	printf("\n Enter y of B =>");
	scanf("%f",&p2.y);
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	setcolor(14);
	rectangle(w.xmin,w.ymin,w.xmax,w.ymax);
	setcolor(5);
	line(p1.x,p1.y,p2.x,p2.y);
	getch();

	Liang_Barsky(p1,p2,w);
	getch();
}

void Liang_Barsky(struct point p1,struct point p2,struct window w)
{
	int i,j,p[4],q[4];
	float r[4],u1,u2,temp[4];
	struct point i1,i2;

	p[0]=-(p2.x-p1.x);
	p[1]=p2.x-p1.x;
	p[2]=-(p2.y-p1.y);
	p[3]=p2.y-p1.y ;
	getch();
	cleardevice();
	for(i=0;i<4;i++)
		printf("\np[%d]=%d",i,p[i]);
	getch();

	q[0]=p1.x-w.xmin;
	q[1]=w.xmax-p1.x;
	q[2]=p1.y-w.ymin;
	q[3]=w.ymax-p1.y;

	for(i=0;i<4;i++)
		printf("\nq[%d]=%d",i,q[i]);
	getch();

	if(p[0]==0 && p[1]==0 & p[2]==0 &&p[3]==0)
		if(q[0]<0 && q[1]<0 && q[2]<0 && q[3]<0)
		{
			closegraph();
			printf("Line is outside the window.");
			getch();
			exit(1);
		}

	for(i=0;i<4;i++)
		r[i]=(float)q[i]/p[i];

	for(i=0;i<4;i++)
		printf("\nr[%d]=%f",i,r[i]);
	getch();

	for(i=0,j=0;i<4;i++)
		if(p[i]<0)
		{
			temp[j]=r[i];
			j++;
		}
	temp[j]=0;

	for(i=0;i<=j;i++)
		printf("temp[%d]=%f",i,temp[i]);

	if(temp[0]>temp[1])
		u1=temp[0];
	else
		u1=temp[1];

	for(i=2;i<j;i++)
		if(u1<temp[i])
			u1=temp[i];

	printf("\nu1=%f",u1);

	for(i=0,j=0;i<4;i++)
		if(p[i]>0)
		{
			temp[j]=r[i];
			j++;
		}
	temp[j]=1;
	for(i=0;i<=j;i++)
		printf("temp[%d]=%f",i,temp[i]);

	if(temp[0]<temp[1])
		u2=temp[0];
	else
		u2=temp[1];

	for(i=2;i<j;i++)
		if(u2>temp[i])
			u2=temp[i];

	printf("\nu2=%f",u2);

	if(u1>u2)
	{
		closegraph();
		printf("Line is outside the window.");
		getch();
		exit(1);
	}

	i1.x=p1.x+u1*(p2.x-p1.x);
	i1.y=p1.y+u1*(p2.y-p1.y);
	i2.x=p1.x+u2*(p2.x-p1.x);
	i2.y=p1.y+u2*(p2.y-p1.y);

	printf("\nI\'(x\',y\')=%2f,%2f",i1.x,i1.y);
	printf("\nI\'\'(x\',y\'\')=%2f,%2f",i2.x,i2.y);

	setcolor(2) ;
	getch();
	cleardevice();
	rectangle(w.xmin,w.ymin,w.xmax,w.ymax);
	line(i1.x,i1.y,i2.x,i2.y);
}
