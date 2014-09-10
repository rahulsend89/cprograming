// Program for Process creation
#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp1,*fp2,*fp3;
	char ch;
	clrscr();
	fp1=fopen("abc.txt","r");
	fp2=fopen("xyz.txt","w");
	printf("\n\n\tContents of source are: ");
	while(!feof(fp1))
	{
		ch=fgetc(fp1);
		fputc(ch,fp2);
		fputc(ch,stdout);
	}
	fclose(fp1);
	fclose(fp2);
	fp3=fopen("xyz.txt","r");
	printf("\n\n\tFile copying operation successful ");
	printf("\n\n\tContents of destination are: ");
	while(!feof(fp3))
	fputc(fgetc(fp3),stdout);
	getch();
}

/*                  ***** OUTPUT *****



	Contents of source are: UNIX IS THE SECOND BEST O.S.
ÿ
	File copying operation successful

	Contents of destination are: UNIX IS THE SECOND BEST O.S.
ÿÿ
								    */





                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
