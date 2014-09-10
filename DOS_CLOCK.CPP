	      /**********************************************
	      ** coded by:	Rahul Malik  **
		  **   date  :      FEB,2004                   **
	      ***********************************************/



//included header files

#include<conio.h>    //for getch()
#include<dos.h>  //for delay()
#include<graphics.h>   //for initgraph() and other graphics function
#include<process.h>//for exit()
#include<string.h>
#include<stdlib.h>
#include<iostream.h>  //for dyanamic initialisation of variables
#include<math.h> //for sine() and cosine() functions
#include<time.h>  //for taking system time
#include<stdio.h>//for printf()


//  initialising graphics mode

void Initialize(void)
{
int gd =DETECT,gm;
initgraph(&gd,&gm,"d:\\tc\\bgi"); //INITIALISING GRAPHICS MODE,FOR DETAIL
			//HEADER FILE GRAPHICS.H
clearviewport();  //CLEARS THE SCREEN
}

void aryanlogo(int);  //DECLARING THE FUNCTION



//FUNCTION FOR MAIN FRAME OF THE CLOCK

void DrawMainFrame(void)
{
setbkcolor(BLACK);
int i=270;
int cx=300,cy=250;
int  j=0;
//ARRAY OF POINTERS USED FOR PRINTING THE NUMBERS ON THE CLOCK
char * num[12]={"12","1","2","3","4","5","6","7","8","9","10","11"};
settextstyle(2,0,10); //FOR HELP SEE GRAPHICS.H
setcolor(YELLOW);    //SETS THE CURRENT DRAWING COLOR
outtextxy(200,14,"DOS CLOCK"); //OUTPUTS THE STRING UNDER ""
					//TO GIVEN X&Y CO-ORDINATES
setcolor(GREEN);
  line(180,53,420,53);//DRAWS LINE FROM FROM ONE POINT TO ANOTHER ON SCREEN
			//TAKES THE CO-ORDINATES OF POINTS AS INPUT
  line(180,56,420,56);

  line(180,20,420,20);
  line(180,23,420,23);
  line(180,20,180,150);
  line(420,20,420,150);

settextstyle(2,0,9);
setcolor(BLUE);
//DRAWING THE OUTER CIRCLE
circle(cx,cy,170);  //DRAWS CIRCLE  OF SPECIFIED RADIUS
			// TAKING THE COORDINATE   OF CENTRE POINT AS INPUT
setfillstyle(1,4);
floodfill(cx,cy,BLUE); //GOES TO A GIVEN COORDINATE
		//ON SCREEN AND FILLS THE SCREEN TILL IF REACHES AN
		//INCLOSED AREA BOUNDED BY THE SPECIFIED COLOR
circle(cx,cy,140);
setfillstyle(1,5);
floodfill (cx+145,cy,BLUE);

setcolor(3);
     while(i<(360+270))   //PRINTING THE NUMBERS ON CLOCK FRAME
	{
	outtextxy(cx+125*cos(3.14*i/180)-10,cy+125*sin(3.14*i/180)-20,num[j]);
	i+=30;
	j++;
	}
setcolor(RED);

}



//DRAWS THE LOGO OF ARYAN ENTERPRISES
void aryanlogo(int sun)
{
int p=getmaxx(),q=getmaxy();

for(int i=0;i<sun;i+=2)
{

setcolor(WHITE);
sector(p-300,q/2-50,356,359,20+i,20+i);

sector(p-300,q/2-45,356,359,20+i,20+i);
sector(p-300,q/2-40,356,359,20+i,20+i);

sector(p-306,q/2-73,45,50,20+i,20+i);
sector(p-302,q/2-68,45,50,20+i,20+i);
sector(p-310,q/2-78,45,50,20+i,20+i);

sector(p-340,q/2-90,85,90,20+i,20+i);
sector(p-334,q/2-90,85,90,20+i,20+i);
sector(p-328,q/2-90,85,90,20+i,20+i);

sector(p-360,q/2-80,135,140,20+i,20+i);
sector(p-364,q/2-74,135,140,20+i,20+i);
sector(p-368,q/2-68,135,140,20+i,20+i);

sector(p-370,q/2-45,178,183,20+i,20+i);
sector(p-370,q/2-40,178,183,20+i,20+i);
sector(p-370,q/2-50,178,183,20+i,20+i);

sector(p-360,q/2-20,220,225,20+i,20+i);
sector(p-364,q/2-24,220,225,20+i,20+i);
sector(p-356,q/2-16,220,225,20+i,20+i);

sector(p-340,q/2-10,268,272,20+i,20+i);
sector(p-332,q/2-10,268,272,20+i,20+i);
sector(p-325,q/2-10,268,272,20+i,20+i);

sector(p-302,q/2-24,313,318,20+i,20+i);
sector(p-306,q/2-20,313,318,20+i,20+i);
sector(p-310,q/2-16,313,318,20+i,20+i);
 delay(110);
}
setcolor(WHITE);
settextstyle(4,0,4);
outtextxy(p/2,q/2+10,"Aryan");
}




//DRAWS THE MINUTE NEEDLE,TAKES THE CURRENT SYSTEM TIME IN MINUTES AS INPUT
//THE FUNCTION TAKES BOTH THE CURRENT AND PREVIOUS TIME IN MINUTES

DrawMin(int min,int min2)
{
int cx=300,cy=250;
int temp;
int temp2;
int mx,mx0,my,my0;
temp2=(min2)*6-90; //CONVERTING  PREVIOUS TIME TO DEGREES

mx=100*cos(temp2*3.14/180);
my=100*sin(temp2*3.14/180);
mx0=mx;
my0=my;

setcolor(4);
line(cx,cy,cx+mx0,cy+my0);   //DRAWING LINE AT PREVIOUS POSITION

temp=min*6-90; //CONVERTING CURRENT TIME TO DEGREES
setcolor(0);
settextstyle(2,0,10);
mx=100*cos(temp*3.14/180);
my=100*sin(temp*3.14/180);

line(cx,cy,cx+mx,cy+my);  //DRAWING LINE AT CURRENT POSITION

}




//DRAWS THE HOUR NEEDLE,TAKES THE CURRENT SYSTEM TIME IN HOUR AS INPUT
//THE FUNCTION TAKES BOTH THE THE CURRENT AND PREVIOUS TIME IN HOURS

DrawHour(int hour,int hour2)
{
int cx=300,cy=250;
int temp,temp2;
	if(hour>60)
		hour-=60;
temp=hour*6-90;//CONVERTING CURRENT HOURS  TIME TO DEGREES

	if(hour2>60)
		hour2-=60;
temp2=hour2*6-90;  //CONVERTING PREVIOUS HOURS TO DEGREES
setcolor(4);
settextstyle(2,0,10);

//DRAWING LINE AT PREVIOUS POSITION
line(cx,cy,cx+70*cos(temp2*3.14/180),cy+70*sin(temp2*3.14/180));

setcolor(14);
settextstyle(2,0,10);

//DRAWING LINE AT CURRENT POSITION
line(cx,cy,cx+70*cos(temp*3.14/180),cy+70*sin(temp*3.14/180));



}

//SCROLLS THE TEXT OUTPUT,TAKES THE STRING TO BE SCROLLED AS INPUT

 void DrawScrollText(char Text[])

{

	for(int i=0; i<strlen(Text); i++)
	{
		char Prn[2];
		if(Text[i]=='\0')
		{
		break;
		}
		else
		sound(400);
		Prn[0] = Text[i];
		Prn[1] = '\0';


		outtext(Prn);

		delay(50);
		nosound();
	}
}


//DRAWS THE FINAL OUTPUT SCREEN

void OUTPUT(void)
{
clearviewport();
setcolor(WHITE);
aryanlogo(15);  //DRAWING THE LOGO
settextstyle(2,0,6);
circle(255,310,12);
outtextxy(250,300,"c:");
outtextxy(270,300,"Aryan enterprises");
setcolor(GREEN);
settextstyle(2,0,6);
outtextxy(150,320,"developers:");
setcolor(YELLOW);
moveto(210,350);
DrawScrollText("1.ABHISHEK MISHRA (S.E.I.T ,28)");
moveto(210,400);
DrawScrollText("2.SAMARTH BHAGWAT (S.E.I.T,2)");
setcolor(LIGHTRED);
outtextxy(150,430,"Thank You for using DOS CLOCK");
getch();
}


//MAIN STARTS HERE
void main()
{
Initialize();  //initialising graphics mode
int cx=300,cy=250;  //declaring centre coordinates of the clock
int i=0;
struct  time t;   //declaring instance for time structure
gettime(&t); //gets system  time using time structure
int count=t.ti_sec;
// printf("The current time is: %2d:%02d:%02d.%02d\n",
//  t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);


//CALCULATING THE TOTAL NUMBER OF DIVISIONS
int curr_hr = (t.ti_hour * 5+t.ti_min/12);

int T_init=6*(t.ti_sec)-90;
i+=T_init;
int sx=0,sy=0;
int sx0,sy0;
DrawMainFrame();
int counter=60*t.ti_min+t.ti_sec;

while(!kbhit())  //checks for key press
{

sx0=sx;sy0=sy;
setcolor(4);		 //draws the main screen for clock
line(cx,cy,cx+sx0,cy+sy0);

//DRAWING THE SECOND NEEDLE

sx=100*cos(i*3.14/180);
sy=100*sin(i*3.14/180);
setcolor(LIGHTGREEN);
settextstyle(2,0,8);
outtextxy(cx-29,cy-80,"ORPAT");

outtextxy(cx-40,cy+50,"QUARTZ");

setcolor(WHITE);
line(cx,cy,cx+sx,cy+sy);

//sound(800);delay(100);
nosound( );

i+=6;
count++;
counter++;
	if(count%60==0)
		{
		t.ti_min+=1;
		DrawMin(t.ti_min,t.ti_min-1);
		}
	else
		DrawMin(t.ti_min,0);


	if(counter%720==0)
		{
		curr_hr+=1;
		DrawHour(curr_hr,curr_hr-1);
		}
	else
		{

		DrawHour(curr_hr,0);
		}

delay(900);
settextstyle(2,0,8);
setcolor(YELLOW);
outtextxy(150,430,"press any key to quit");

}

OUTPUT();       //CALLS TO DRAW THE FINAL OUTPUT SCREEN

getch();
}