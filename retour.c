#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void printfnumber(char calcul[100]) 
{
    int a = 0, b = 0, k = 0;
    char tab[100];
    double number[100];
    char operateur[100];
    double c, d, result;


    for (int i = 0; i < strlen(calcul); i++)
    {
        if (calcul[i] == ' ' || calcul[i] == '\n') 
        {
            continue;
        }
        if (calcul[i] != '+' && calcul[i] != '-' && calcul[i] != '*' && calcul[i] != '/') 
        {
            tab[a] = calcul[i];
            a++;
        } else 
        {
            tab[a] = '\0';
            if (a > 0)
            
             {
                number[b] = atoi(tab);
                b++;
            }
            operateur[k] = calcul[i];
            k++;
            a = 0;
        }
    }

    if (a > 0)
    {
        tab[a] = '\0';
        number[b] = atoi(tab);
        b++;

    printf("Les nombres extraits : ");
    for (int i = 0; i < b; i++) 
    {
        printf("%.2lf ", number[i]);
    }
    printf("\n");

    for (int i = 0; i < k; i++) {
        if (operateur[i] == '*' || operateur[i] == '/') 
        {
            c = number[i];
            d = number[i + 1];

            if (operateur[i] == '*')
             {
                result = c * d;
            } else if (operateur[i] == '/')
            {
                result = c / d;
            }

            number[i] = result;
            for (int j = i + 1; j < b - 1; j++) 
            {
                number[j] = number[j + 1];
            }
            for (int j = i; j < k - 1; j++) 
            {
                operateur[j] = operateur[j + 1];
            }
            b--; 
            k--;  
            i--;  
        }
    }


    result = number[0];
    for (int i = 0; i < k; i++) 
    {
        if (operateur[i] == '+') 
        {
            result += number[i + 1];
        } else if (operateur[i] == '-') 
        {
            result -= number[i + 1];
        }
    }

    printf("Le resultat de l'expression est : %.2f\n", result);
}
}

int main() 
{
    char calcul[100];
    FILE *fichier = fopen("fichier.txt", "r");

    if (fichier == NULL) 
    {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    fgets(calcul, sizeof(calcul), fichier);
    printf("Expression lue depuis le fichier : %s\n", calcul);
    printfnumber(calcul);

    fclose(fichier);
    return 0;
}
