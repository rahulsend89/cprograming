#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct point
{
 float x,y;
 };
 void main()
 {
  struct point p[24];
  int gd=DETECT,gm,i,n,t;
  void bspline(struct point *p, int ,int );
  clrscr();
  printf("ENTER THE NO OF POINTS\N");
  scanf("%d",&n);
   printf("ENTER THE (X,Y) CORDIMATES=>\n");
   for(i=0;i<n;i++)
   scanf("%f%f",&(p[i].x),&(p[i].y));
   printf("ENTER THE DEGREE OF POLYNOMIAL");
   scanf("%d",&t);
   initgraph(&gd,&gm,"c:\\tc\\bgi");
  setcolor(4);
  for(i=0;i<n-1;i++)
  line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
  bspline(p,n-1,t+1);
  getch();
  }
  void bspline(struct point *p,int n,int t)
  {
   int k,j,i;
   double xu,yu,u=0.001,uu[30];
   double nkt(int k ,int t,double u,double *uu);
   for(j=0;j<=n+t;j++)
   if(j<t);
     uu[j]=0;
  if(j<=n)
     uu[j]=j-t+1;
  else
     uu[j]=n-t+2;


   while(u<=n-t+2)
   {
    xu=yu=0;
    for(k=0;k<=n;k++)
    {
      xu+=p[k].x*nkt(k,t,u,uu);
      yu+=p[k].y*nkt(k,t,u,uu);
     }
     putpixel(xu,yu,15);
     u+=0.001;
    }
  }

  double nkt(int k,int t,double u,double *uu)
  {
     double n1,d1,n2,d2,f1,f2;
     if(t==1)
     if((uu[k]<=u)&&(u<uu[k+1]))
     return 1;
     else
     {
       n1=u-uu[k];
       d1=uu[k+t-1]-uu[k];
       if(d1==0)
       f1=0;
       else
       f1=n1/d1;
       n2=uu[k+t]-u;
       d2=uu[k+t]-uu[k+1];
       if(d2==0)
       f2=0;
       else
       f2=n2/d2;
     }
       return( f1* nkt(k,t-1,u,uu)+f2*nkt(k+1,t-1,u,uu));
     }


