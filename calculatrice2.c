#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


double addition(double a,double b)
{
    return a+b;
}
double soustraction(double a,double  b)
{
    return a-b;
}
double  multiplication(double a,double b)
{
    return a*b;
}
double division(double a,double b)
{
    if(b!=  0)
    {
        return a/b;
    }
    else 
    {
        return 1;
    }
}
double sinus(double a)
{
    return sin(a);
}
double cosinus(double b)
{
    return cos(b);
}
double tangente(double c)
{
    return tan(c);
}
double arcsinus(double d)
{
    return asin(d);
}
double arccosinus(double e)
{
    return acos(e);
}
double arctangente(double f)
{
    return atan(f);
}
int main()
{
    double result=0;
    char calcul[100];
    FILE *fichier=fopen("fichier.txt","r");
    if(fichier==NULL)
    {
        printf("Erreur d'ouverture du fichier");
        return 1;
    }
    fgets(calcul,sizeof(calcul),fichier);
    
    for(int i=0;i<strlen(calcul);i++)
    {
        if (calcul[i]='+')
        {
           result=result+ addition(calcul[i-1],calcul[i+1]);
        }
    }
    printf("%.2lf",result);
    fclose(fichier);
}