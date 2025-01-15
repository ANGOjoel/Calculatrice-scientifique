#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int compteur=0,c=0;
    char calcul[100];
    int i=0,j=0,k=0;
    printf("Entrer votre calcul:");
    scanf("%s",&calcul);
    double tab[strlen(calcul)];
    double tab_nbre[strlen(calcul)];
    for(i=0;i<strlen(calcul);i++)
    {
        if (calcul[i]=='1')
        {
            compteur++;
            tab[k]=1;

        }
        else if (calcul[i]=='2')
        {
            compteur++;
            tab[k]=2;

        }
         else if (calcul[i]=='2')
        {
            compteur++;
            tab[k]=2;

        }
         else if (calcul[i]=='3')
        {
            compteur++;
            tab[k]=3;

        }
         else if (calcul[i]=='4')
        {
            compteur++;
            tab[k]=4;

        }
         else if (calcul[i]=='5')
        {
            compteur++;
            tab[k]=5;

        }
         else if (calcul[i]=='6')
        {
            compteur++;
            tab[k]=6;

        }
         else if (calcul[i]=='7')
        {
            compteur++;
            tab[k]=7;

        }
         else if (calcul[i]=='8')
        {
            compteur++;
            tab[k]=8;

        }
         else if (calcul[i]=='9')
        {
            compteur++;
            tab[k]=9;

        }
         else if (calcul[i]=='0')
        {
            compteur++;
            tab[k]=0;

        }
        else
        {
            double number=0;
            for ( j = 0; j < compteur; j++)
            {
                double exposant=compteur-1-j;
                double p=pow(10,exposant);
                number=number + tab[j]*p;
            }
            compteur=0;
            tab_nbre[c]=number;
            c++;
            k=-1;
        }
        k++;
    }
    for ( i = 0; i < c; i++)
    {
        printf("n[%d]=%lf\n",i,tab_nbre[i]);
    }
    
    return 0;
}