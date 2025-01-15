#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define M_PI 3.14159265358979323846
void expressionvalide(char *entre)
{
    int i = 0;
    char *functions[] = {"sin", "cos", "tan", "sqrt", "log"};
    int num_functions = 5; // Nombre de fonctions mathématiques

    while (entre[i] != '\0')
    {
        // Vérifier si c'est une lettre
        if (isalpha(entre[i]))
        {
            // Chercher si le mot à partir de la position actuelle est une fonction valide
            int valid_function = 0;
            for (int j = 0; j < num_functions; j++)
            {
                int l = strlen(functions[j]);
                // Si la fonction est trouvée à cette position, passer à la fin de cette fonction
                if (strncmp(&entre[i], functions[j], l) == 0)
                {
                    i += l - 1;  // Avancer à la fin du mot de la fonction
                    valid_function = 1;
                    break;
                }
            }

            // Si ce n'est pas une fonction valide, l'expression est invalide
            if (!valid_function)
            {
                printf("Expression invalide\n");
                exit(0);
            }
        }
        i++;
    }
}

// Déclaration de la fonction evaluerExpression
double evaluerExpression(char *calcul, int *index);

// Fonction pour gérer les fonctions trigonométriques comme sin, cos, tan
double fonction(char *expression, int *index, char *nomfonction) 
{
    int i = *index;
    char tabfunction[100];
    int s = 0;
    
    while (expression[i] != '(' && expression[i] != '\0') 
    {
        i++;
    }
    
    if (expression[i] == '(') 
    {
        i++;  // Passer le '('
        while (expression[i] != ')' && expression[i] != '\0') 
        {
            tabfunction[s] = expression[i];
            s++;
            i++;
        }
        
        tabfunction[s] = '\0'; // Terminer la chaîne
        double nombrefonction = atof(tabfunction);
        *index = i; // Mettre à jour l'index après le calcul
        
        if (strcmp(nomfonction, "sin") == 0) 
        {
            return sin(nombrefonction * M_PI / 180);
        } 
        else if (strcmp(nomfonction, "cos") == 0) 
        {
            return cos(nombrefonction * M_PI / 180);
        } 
        else if (strcmp(nomfonction, "tan") == 0) 
        {
            return tan(nombrefonction * M_PI / 180);
        } 
        else if (strcmp(nomfonction, "sqrt") == 0) 
        {
            return sqrt(nombrefonction); // Fonction racine carrée
        } 
        else if (strcmp(nomfonction, "log") == 0) 
        {
            return log(nombrefonction); // Fonction logarithme
        }
    }
    
    return 0;
}

// Fonction récursive pour évaluer les expressions entre parenthèses
double evaluerParenthese(char *calcul, int *index) 
{
    (*index)++;  // Passer le '('
    double resultat = evaluerExpression(calcul, index);  // Évaluer l'expression à l'intérieur
    (*index)++;  // Passer le ')'
    return resultat;
}

// Fonction pour analyser et évaluer l'expression
double evaluerExpression(char *calcul, int *index) 
{
    int a = 0, b = 0, k = 0, i = *index;
    char tab[100];
    double number[100];
    char operateur[100];
    double c, d, result;

    while (calcul[i] != '\0') 
    {
        // Chercher les fonctions trigonométriques et mathématiques
        if (strstr(calcul + i, "sin") == calcul + i) 
        {
            double sin_result = fonction(calcul, &i, "sin");
            number[b++] = sin_result;
        } 
        else if (strstr(calcul + i, "cos") == calcul + i) 
        {
            double cos_result = fonction(calcul, &i, "cos");
            number[b++] = cos_result;
        } 
        else if (strstr(calcul + i, "tan") == calcul + i) 
        {
            double tan_result = fonction(calcul, &i, "tan");
            number[b++] = tan_result;
        } 
        else if (strstr(calcul + i, "sqrt") == calcul + i) 
        {
            double sqrt_result = fonction(calcul, &i, "sqrt");
            number[b++] = sqrt_result;
        } 
        else if (strstr(calcul + i, "log") == calcul + i) 
        {
            double log_result = fonction(calcul, &i, "log");
            number[b++] = log_result;
        } 
        else if (isdigit(calcul[i]) || calcul[i] == '.') 
        {
            tab[a] = calcul[i];
            a++;
        } 
        else if (calcul[i] == '(') 
        {
            // Si on trouve une parenthèse, on appelle evaluerParenthese
            number[b++] = evaluerParenthese(calcul, &i);  // Appel récursif pour évaluer l'expression entre parenthèses
        } 
        else if (calcul[i] == '+' || calcul[i] == '-' || calcul[i] == '*' || calcul[i] == '/') 
        {
            if (a > 0) 
            {
                tab[a] = '\0';
                number[b++] = atof(tab);
                a = 0;
            }
            operateur[k++] = calcul[i];
        }
        i++;
    }

    // Finalisation des nombres restants
    if (a > 0) 
    {
        tab[a] = '\0';
        number[b++] = atof(tab);
    }

    // Calcul des opérations avec priorité aux * et /, en traitant d'abord les multiplications et divisions
    for (int i = 0; i < k; i++) 
 {
    if (operateur[i] == '*' || operateur[i] == '/') 
    {
        c = number[i];
        d = number[i + 1];
        double result;

        if (operateur[i] == '*') 
        {
            result = c * d;
        } 
        else if (operateur[i] == '/') 
        {
            result = c / d;
        } 
        else 
        {
            result = 0;
        }

        number[i] = result;

        // Décalage des éléments dans les tableaux pour supprimer l'élément traité
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
        i--; // Réévaluer la position actuelle après le décalage
    }
}

// Calcul final pour les opérateurs + et - (addition et soustraction)
result = number[0];
for (int i = 0; i < k; i++) 
{
    if (operateur[i] == '+') 
    {
        result += number[i + 1];
    } 
    else if (operateur[i] == '-') 
    {
        result -= number[i + 1];
    }
}
    return result;
}

// Fonction principale pour lire l'expression depuis un fichier et calculer le résultat
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
    expressionvalide(calcul);

    int index = 0;
    double resultat = evaluerExpression(calcul, &index);
    printf("Le resultat de l'expression est : %.2f\n", resultat);

    fclose(fichier);
    return 0;
}
