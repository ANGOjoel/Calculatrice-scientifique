#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[100];
    int compteur=0,n;
    printf("Entrer vos nombres:");
    for(int i=0;i<100;i++)
    {
       scanf("%d", &tab[i]);
      
       
    }
   
    for(int i=0;i<100;i++)
    {
    if(tab[i]==1 || tab[i]==0)
    {
       compteur++;
    }
    }
    n=compteur;
    
    
    
    
    
    
    return 0;
}