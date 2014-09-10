#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
int a[10][10];
void main()
{
	int gd=DETECT,gm=DETECT,x,y,n,i,choice;
	void boundary_fill(int,int,int[10][10],int);
	void flood_fill(int,int,int[10][10],int);
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	printf("enter no of edges of polygon");
	scanf("%d",&n);
	printf("enter coordinates of polygon \n");
	for(i=0;i<n;i++)
	{
		printf("\nX%d , Y%d",i,i);
		scanf("%d%d",&a[i][0],&a[i][1]);
		printf("\n");
	}

	printf("\nEnter seed point : ");
	scanf("%d%d",&x,&y);

	a[n][0]=a[0][0];
	a[n][1]=a[0][1];
	do
	{
		printf("1.Boundary fill\n");
		printf("2.Flood fill\n");
		printf("3.Exit\n");
		printf("Enter your choice : ");

		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				cleardevice();
				boundary_fill(x,y,a,n);
				break;
			case 2:
				cleardevice();
				flood_fill(x,y,a,n);
				break;
			case 3:
				exit(1);
				break;
		   }
	}
	while(choice<=3);
}

void boundary_fill(int x,int y,int a[10][10],int n)
{
	int i;
	void fill_right(int,int);
	void fill_left(int,int);
	setcolor(WHITE);
	for(i=0;i<n;i++)
	{
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}

	fill_right(x,y);
	fill_left(x-1,y);
}

void fill_right(int x,int y)
{

	while((getpixel(x,y)!=WHITE)&&(getpixel(x,y)!=BLUE))
	{
		putpixel(x,y,BLUE);
		fill_right(++x,y);
		x=x-1;
		fill_right(x,y-1);
		fill_right(x,y+1);
	}
}

void fill_left(int x,int y)
{
	while((getpixel(x,y)!=WHITE)&&(getpixel(x,y)!=BLUE))
	{
		putpixel(x,y,BLUE);
		fill_left(--x,y);
		x=x+1;
		fill_left(x,y-1);
		fill_right(x,y+1);
	}
}

void flood_fill(int x,int y,int a[10][10],int n)
{
	void fill_right1(int,int);
	void fill_left1(int,int);
	int ch[10],i;
	for(i=0;i<n;i++)
	{
		printf("Enter color for line %d",i+1);
		scanf("%d",&ch[i]);
	}
	for(i=0;i<n;i++)
	{
		setcolor(ch[i]);
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}

	fill_right1(x,y);
	fill_left1(x-1,y);
}
void fill_right1(int x,int y)
{

	while(getpixel(x,y)==0)
	{
		putpixel(x,y,RED);
		fill_right1(++x,y);
		x=x-1;
		fill_right1(x,y-1);
		fill_right1(x,y+1);
	}
}

void fill_left1(int x,int y)
{
	while(getpixel(x,y)==0)
	{
		putpixel(x,y,RED);
		fill_left1(--x,y);
		x=x+1;
		fill_left1(x,y-1);
		fill_left1(x,y+1);
	}
}
