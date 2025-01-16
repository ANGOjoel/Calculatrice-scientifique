#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>



void expressionvalide(char *entre)
{
    int i = 0;
    char *functions[] = {"sin", "cos", "tan", "sqrt", "log", "pow"};
    int num_functions = 6; // Nombre de fonctions mathématiques

    // Vérification de la validité de l'expression
    while (entre[i] != '\0')
    {
        // Vérifier si c'est une lettre
        if (isalpha(entre[i]))
        {
            int fonctionvalide = 0;
            for (int j = 0; j < num_functions; j++)
            {
                int l = strlen(functions[j]);
                // Si la fonction est trouvée à cette position, passer à la fin du mot de la fonction
                if (strncmp(&entre[i], functions[j], l) == 0)
                {
                    i += l - 1;  // Avancer à la fin du mot de la fonction
                    fonctionvalide = 1;
                    break;
                }
            }

            // Si ce n'est pas une fonction valide, l'expression est invalide
            if (!fonctionvalide)
            {
                printf("Expression invalide\n");
                exit(1);
            }
        }
        i++;
    }

    // Vérification si l'expression se termine par un opérateur
    if (entre[strlen(entre)-1] == '+' || entre[strlen(entre)-1] == '-' || entre[strlen(entre)-1] == '*' || entre[strlen(entre)-1] == '/')
    {
        printf("Expression invalide\n");
        exit(1);
    }

    // Vérification pour les parenthèses ouvertes et non fermées
    int parentheses_count = 0;
    for (int i = 0; i < strlen(entre); i++) 
    {
        if (entre[i] == '(') 
        {
            parentheses_count++;
        }
        else if (entre[i] == ')') 
        {
            parentheses_count--;
        }
    }

    // Si le nombre de parenthèses ouvertes et fermées n'est pas égal, l'expression est invalide
    if (parentheses_count != 0)
    {
        printf("Expression invalide - Parentheses mal fermees\n");
        exit(1);
    }
}
int main()
{
    return 0;
}
