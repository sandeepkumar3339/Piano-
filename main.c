#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct keys
{
    int num;
    char pos[4];
    float frequency;
}k;



void read_data()
{
    system("cls");
    FILE *ek;
    ek=fopen("record.dat","a");
    fprintf(ek,"%d %s %f\n",k.num,k.pos,k.frequency);
    fclose(ek);
    getch();
}

void splitter(char data[100])
{
        system("cls");
        int i,j=0;
        char c[10];
		for(i=0;i<=strlen(data);i++)
        {
           if(data[i]=='.'||data[i]=='\0')
        {
            c[j]='\0';

            FILE *ek;
            ek=fopen("record.dat","r");
            while(fscanf(ek,"%d %s %f\n",&k.num,k.pos,&k.frequency)!=EOF)
            {
                if(strcmpi(k.pos,c)==0)
                {

                    Beep(k.frequency,10);
                    Sleep(500);

                }
            }
            fclose(ek);
            j=0;
        }
        else
        {
            c[j]=data[i];
            j++;
        }
       }
}

int main()
{
    char data[100];
    printf("Enter the notes");
    fgets(data,sizeof(data),stdin);
    splitter(data);
}
