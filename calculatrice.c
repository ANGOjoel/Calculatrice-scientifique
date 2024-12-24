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
int main ()
{
    char calcul[1000];
    double result;
    double nbre1,nbre2;
    FILE* fichier=fopen("fichier.txt","r");
     fgets(calcul,sizeof(calcul),fichier);
     printf("%s",calcul);
     for (int i=0;i<strlen(calcul);i++)
     {
        if (calcul[i]=='*')
        {
            int n=sscanf(calcul,"%lf %c %lf",&nbre1,&calcul[i],&nbre2);
            if (n==3)
            {
                result=multiplication(nbre1,nbre2);
            }
        }
        else if (calcul[i]=='+')
        {
            int n=sscanf(calcul,"%lf %c %lf",&nbre1,&calcul[i],&nbre2);
            if (n==3)
            {
                result=addition(nbre1,nbre2);
            }
        }
        else if (calcul[i]=='-')
        {
            int n=sscanf(calcul,"%lf %c %lf",&nbre1,&calcul[i],&nbre2);
            if (n==3)
            {
                result=soustraction(nbre1,nbre2);
            }
        }
        else if (calcul[i]=='/')
        {
            int n=sscanf(calcul,"%lf %c %lf",&nbre1,&calcul[i],&nbre2);
            if (n==3)
            {
                result=division(nbre1,nbre2);
            }
        }
       
        
     }
     printf("Le resultat est:%.2lf",result);
     

    
       
    
    fclose(fichier);

    return 0;
}

