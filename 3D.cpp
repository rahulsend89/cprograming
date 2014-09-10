#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int maxx,maxy,midx,midy;
void axis()
{
	getch();
	cleardevice();
	line(midx,0,midx,midy);line(0,midy,maxx,midy);
}
void main()
{
	int gd=DETECT,gm,x,y,z,o,x1,y1,x2,y2,c,v;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setfillstyle(0,getmaxcolor());
	maxx=getmaxx();maxy=getmaxy();
	midx=maxx/2;midy=maxy/2;
	axis();
	outtextxy(midx,midy,"midx,midy");
	bar3d(midx+50,midy-100,midx+60,midy-90,10,1);
	putpixel(midx+50,midy-100,5);
	putpixel(midx+60,midy-90,5);
	//translation
	outtextxy(50,50,"enter translation factors :");
	scanf("%d%d",&x,&y);
	axis();
	outtextxy(0,0,"after translation");
	bar3d(midx+x+50,midy-(y+100),midx+x+60,midy-(y+90),5,1);
	//scaling
	axis();
	bar3d(midx+50,midy-100,midx+60,midy-90,5,1);
	outtextxy(50,50,"enter scaling factors :");
	scanf("%d%d%d",&x,&y,&z);
	axis();
	outtextxy(0,0,"after scaling");
	bar3d(midx+(x*50),midy-(y*100),midx+(x*60),midy-(y*90),5*z,1);
	//rotation
	axis();
	bar3d(midx+50,midy-100,midx+60,midy-90,5,1);
	outtextxy(50,50,"enter Rotation angle :");
	scanf("%d",&o);
	 x1=50*cos(0*3.14/180)-100*sin(0*3.14/180);
	 y1=50*sin(0*3.14/180)-100*cos(0*3.14/180);
	 x2=60*cos(0*3.14/180)-90*sin(0*3.14/180);
	 y2=60*sin(0*3.14/180)-90*cos(0*3.14/180);
	axis();
	outtextxy(0,0,"after rotation @z axis");
	bar3d(midx+x1,midy-y1,midx+x2,midy-y2,5,1);
	axis();
	outtextxy(0,0,"after rotation @x axis");
	bar3d(midx+50,midy-x1,midx+60,midy-x2,5,1);
	axis();
	outtextxy(0,0,"after rotation @y axis");
	bar3d(midx+x1,midy-100,midx+x2,midy-90,5,1);
	getch();
	closegraph();
}