#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define M_PI 3.14159265358979323846
double evaluerExpression(char *calcul, int *index);

// Fonction pour valider l'expression
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
            return sin(nombrefonction * M_PI / 180);  // sin() utilise des radians
        } 
        else if (strcmp(nomfonction, "cos") == 0) 
        {
            return cos(nombrefonction * M_PI / 180);  // cos() utilise des radians
        } 
        else if (strcmp(nomfonction, "tan") == 0) 
        {
            return tan(nombrefonction * M_PI / 180);  // tan() utilise des radians
        } 
        else if (strcmp(nomfonction, "sqrt") == 0) 
        {
            return sqrt(nombrefonction); // Fonction racine carrée
        } 
        else if (strcmp(nomfonction, "log") == 0) 
        {
            return log(nombrefonction); // Fonction logarithme
        }
        else if (strcmp(nomfonction, "pow") == 0) 
        {
            double base, exposant;
            int j = 0;

            // Extraire la base (avant la virgule)
            while (tabfunction[j] != ',' && tabfunction[j] != '\0') 
            {
                j++;
            }
            tabfunction[j] = '\0';
            base = atof(tabfunction); // Convertir la base

            // Extraire l'exposant (après la virgule)
            exposant = atof(tabfunction + j + 1); // La partie après la virgule

            *index = i; // Mettre à jour l'index après le calcul

            return pow(base, exposant); // Calculer la puissance
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
            double sinresult = fonction(calcul, &i, "sin");
            number[b++] = sinresult;
        } 
        else if (strstr(calcul + i, "cos") == calcul + i) 
        {
            double cosresult = fonction(calcul, &i, "cos");
            number[b++] = cosresult;
        } 
        else if (strstr(calcul + i, "tan") == calcul + i) 
        {
            double tanresult = fonction(calcul, &i, "tan");
            number[b++] = tanresult;
        } 
        else if (strstr(calcul + i, "sqrt") == calcul + i) 
        {
            double sqrtresult = fonction(calcul, &i, "sqrt");
            number[b++] = sqrtresult;
        } 
        else if (strstr(calcul + i, "log") == calcul + i) 
        {
            double logresult = fonction(calcul, &i, "log");
            number[b++] = logresult;
        } 
        else if (strstr(calcul + i, "pow") == calcul + i) 
        {
            double powresult = fonction(calcul, &i, "pow");
            number[b++] = powresult;
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

// Fonction principale
int main() 
{
    char calcul[100];
    printf("Avant tout calcul vous devez tenir compte de certaines informaions\nPour pouvoir utiliser la fonction sinus vous devez entrer sin()\nPour pouvoir utiliser la fonction cossinus vous devez entrer cos()\nPour pouvoir utiliser la fonction tangente vous devez entrer tan()\nPour pouvoir utiliser la fonction logarithme neperien vous devez entrer log()\nPour pouvoir utiliser la fonction racine carree vous devez entrer sqrt()\nPour pouvoir utiliser la fonction puissance vous devez entrer pow(base,exposant)\nPour les fonctions trigonometriques,les angles sont deja consideres en degre,entrer juste la valeur de l'angle .\nNB:L'utlisation des parentheses est uniquement pour les fonctions trigonometriques et mathematiques\nEntrer votre expression : ");
    fgets(calcul, sizeof(calcul), stdin);
    printf("Expression lue depuis l'entree : %s\n", calcul);
   expressionvalide(calcul);

    int index = 0;
    double resultat = evaluerExpression(calcul, &index);
    printf("Le resultat de l'expression est : %.2f\n", resultat);
    
    return 0;
}
