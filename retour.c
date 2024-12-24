#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
void printfnumber(char calcul[100])
{
    int a=0,b=0;
    char tab[100];
    int number[100];
    for(int i=0;i<strlen(calcul);i++)
    {
         if (calcul[i] == ' ' || calcul[i] == '\n') 
        {
            continue;
        }
        if (calcul[i]!='+' && calcul[i]!='-' && calcul[i]!='*' && calcul[i]!='/')
        {
        
         
         tab[a]=calcul[i];
         a++;

           
        }
        else
        {
            tab[a]='\0';
            if(a>0)
            {
               number[b]=atoi(tab);
               b++;
               
            }
            a=0;

        }
        
    }
    if(a>0)
    {
        number[b]=atoi(tab);
        b++;
    }
    for(int i=0;i<b;i++)
    {
        printf("%d ",number[i]);
    }
}
int main()
{
    char calcul[100];
    FILE* fichier=fopen("fichier.txt","r");
    if(fichier==NULL)
    {
        printf("Erreur d'ouverture du fichier");
        return 1;
    }
    fgets(calcul,sizeof(calcul),fichier);
    printfnumber(calcul);
    fclose(fichier);

    return 0;
}