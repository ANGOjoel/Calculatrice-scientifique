#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 100

int verifiexpression(char calcul[1000]) 
{
    int parenthese = 0;  // Compteur pour vérifier les parenthèses
    int verifieoperateur = 1;  // Permet de vérifier qu'un opérateur ne se trouve pas en dernier

    for (int i = 0; i < strlen(calcul); i++)
     {
        // Si c'est un caractère valide (chiffre, opérateur, ou fonction trigonométrique)
        if (isdigit(calcul[i]) || calcul[i] == '.' || 
            calcul[i] == '(' || calcul[i] == ')' ||
            calcul[i] == '+' || calcul[i] == '-' || 
            calcul[i] == '*' || calcul[i] == '/') 
            {
            
            // Vérification qu'un opérateur ne suit pas directement un autre opérateur
            if ((calcul[i] == '+' || calcul[i] == '-' || calcul[i] == '*' || calcul[i] == '/') && verifieoperateur) 
            {
                return 0; // Syntaxe invalide (deux opérateurs successifs)
            }

            // Vérification des parenthèses
            if (calcul[i] == '(') 
            {
                parenthese++;
            } else if (calcul[i] == ')') 
            {
                parenthese--;
                if (parenthese < 0) 
                {
                    return 0; // si il y a une parenthèse qui est fermée sans être ouverte
                }
            }

            // Si un chiffre est suivi d'un opérateur, c'est ok
            if (isdigit(calcul[i]))
            {
                verifieoperateur = 0;
            } else if (calcul[i] == '(') 
            {
                verifieoperateur = 1;
            } else {
                verifieoperateur = 0;
            }
        } else if (!isalpha(calcul[i])) 
        {
            // Si le caractère est ni un chiffre ni un opérateur ni une parenthèse, c'est une erreur
            return 0; // Caractère invalide
        }
    }

    // Vérification que les parenthèses sont équilibrées
    if (parenthese != 0) 
    {
        return 0; // Parenthèses non équilibrées
    }

    // Vérification que l'expression ne se termine pas par un opérateur
    if (verifieoperateur) 
    {
        return 0; // Erreur si l'expression se termine par un opérateur
    }

    return 1;  // Expression valide
}

void printfnumber(char calcul[MAX]) 
{
    int a = 0, b = 0, k = 0;
    char tab[MAX];
    double number[MAX];
    char operateur[MAX];
    double c, d, result;

    if (!verifiexpression(calcul)) 
    {
        printf("Erreur de syntaxe : Expression invalide.\n");
        return;
    }

    // Parcourir chaque caractère dans l'expression
    for (int i = 0; i < strlen(calcul); i++) 
    {
        if (calcul[i] == ' ' || calcul[i] == '\n') 
        {
            continue;  // Ignorer les espaces et les nouvelles lignes
        }

        // Vérification si le caractère actuel fait partie d'un nombre
        if (isdigit(calcul[i]) || calcul[i] == '.') 
        {
            tab[a] = calcul[i];
            a++;
        }
        // Vérification si nous rencontrons une fonction trigonométrique ou mathématique
        else if (strncmp(&calcul[i], "sin", 3) == 0 || strncmp(&calcul[i], "cos", 3) == 0 || 
                 strncmp(&calcul[i], "tan", 3) == 0 || strncmp(&calcul[i], "log", 3) == 0 || 
                 strncmp(&calcul[i], "sqrt", 4) == 0) 
        {
            // Identifier la fonction trigonométrique ou mathématique
            char func[5]; // Nous avons besoin d'un tableau de 5 caractères pour stocker le nom de la fonction (max 4 caractères)

            // Extraire la fonction (3 ou 4 caractères selon le cas)
            if (strncmp(&calcul[i], "sin", 3) == 0) {
                strncpy(func, &calcul[i], 3);
                func[3] = '\0';
                i += 3;  // Passer après "sin"
            }
            else if (strncmp(&calcul[i], "cos", 3) == 0) {
                strncpy(func, &calcul[i], 3);
                func[3] = '\0';
                i += 3;  // Passer après "cos"
            }
            else if (strncmp(&calcul[i], "tan", 3) == 0) {
                strncpy(func, &calcul[i], 3);
                func[3] = '\0';
                i += 3;  // Passer après "tan"
            }
            else if (strncmp(&calcul[i], "log", 3) == 0) {
                strncpy(func, &calcul[i], 3);
                func[3] = '\0';
                i += 3;  // Passer après "log"
            }
            else if (strncmp(&calcul[i], "sqrt", 4) == 0) {
                strncpy(func, &calcul[i], 4);
                func[4] = '\0';
                i += 4;  // Passer après "sqrt"
            }

            // Vérification si la parenthèse ouvrante est présente
            if (calcul[i] == '(') 
            {
                i++;  // Ignorer la parenthèse ouvrante
                int start = i;
                while (calcul[i] != ')' && i < strlen(calcul)) 
                {
                    i++;
                }

                char nombreentreparenthese[MAX];
                strncpy(nombreentreparenthese, &calcul[start], i - start);
                nombreentreparenthese[i - start] = '\0';
                number[b] = atof(nombreentreparenthese); // Convertir l'argument en nombre

                // Calcul de la fonction trigonométrique ou mathématique
                if (strcmp(func, "sin") == 0) 
                {
                    number[b] = sin(number[b]);  // Calcul de sin
                } 
                else if (strcmp(func, "cos") == 0) 
                {
                    number[b] = cos(number[b]);  // Calcul de cos
                }
                else if (strcmp(func, "tan") == 0) 
                {
                    number[b] = tan(number[b]);  // Calcul de tan
                }
                else if (strcmp(func, "log") == 0) 
                {
                    if (number[b] <= 0) 
                    {
                        printf("Erreur : Logarithme d'un nombre <= 0\n");
                        return;
                    }
                    number[b] = log(number[b]);  // Calcul du logarithme naturel
                }
                else if (strcmp(func, "sqrt") == 0) 
                {
                    if (number[b] < 0) 
                    {
                        printf("Erreur : Racine carrée d'un nombre négatif\n");
                        return;
                    }
                    number[b] = sqrt(number[b]);  // Calcul de la racine carrée
                }
                b++; // Incrémenter l'indice des nombres
            }
        }
        else // Si c'est un opérateur
        {
            tab[a] = '\0';  // Terminer le nombre actuel
            if (a > 0) 
            {
                number[b] = atof(tab);  // Convertir le tableau en nombre
                b++;
            }
            operateur[k] = calcul[i];  // Ajouter l'opérateur au tableau
            k++;
            a = 0;  // Réinitialiser l'indice pour le prochain nombre
        }
    }

    // Si le dernier caractère dans 'tab' est un nombre, on l'ajoute à la liste
    if (a > 0)
    {
        tab[a] = '\0';
        number[b] = atof(tab);
        b++;
    }

    // Affichage des nombres extraits
    printf("Les nombres extraits : ");
    for (int i = 0; i < b; i++) 
    {
        printf("%.2lf ", number[i]);
    }
    printf("\n");

    // Calcul des opérations avec priorité multiplication et division
    for (int i = 0; i < k; i++) 
    {
        if (operateur[i] == '*' || operateur[i] == '/') 
        {
            c = number[i];
            d = number[i + 1];

            if (operateur[i] == '*') 
            {
                result = c * d;
            } 
            else if (operateur[i] == '/') 
            {
                if (d == 0) 
                {
                    printf("Erreur de division par zéro\n");
                    return;
                } 
                else 
                {
                    result = c / d;
                }
            }

            number[i] = result;
            for (int j = i + 1; j < b - 1; j++) 
            {
                number[j] = number[j + 1];  // Déplacer les nombres pour supprimer les éléments déjà utilisés
            }
            for (int j = i; j < k - 1; j++) 
            {
                operateur[j] = operateur[j + 1];  // Déplacer les opérateurs pour supprimer les éléments déjà utilisés
            }
            b--;
            k--;
            i--;
        }
    }

    // Calcul des opérations d'addition et de soustraction
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

    // Affichage du résultat final
    printf("Le résultat de l'expression est : %.2f\n", result);
}

int main() 
{
    char calcul[MAX];
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
