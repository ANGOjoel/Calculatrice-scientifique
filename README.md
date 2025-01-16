Calculatrice en C
Ce dépôt contient un programme en langage C permettant d'évaluer des expressions mathématiques saisies par l'utilisateur. Le programme prend en charge les opérations arithmétiques de base, les fonctions trigonométriques, logarithmiques, les racines carrées et les calculs de puissance.

Fonctionnalités
Opérations arithmétiques de base : Addition (+), Soustraction (-), Multiplication (*) et Division (/).
Fonctions trigonométriques : sin(), cos() et tan() (les angles sont exprimés en degrés).
Fonction logarithmique : log() (logarithme naturel).
Racine carrée : sqrt().
Fonction puissance : pow(base, exposant).
Gestion des parenthèses : Prend en charge le regroupement et les expressions imbriquées.
Prise en main
Pré-requis
Un compilateur C, comme gcc.
Un terminal ou une console pour exécuter le programme.
Format d'entrée
Opérateurs arithmétiques : Utilisez +, -, *, / pour l'addition, la soustraction, la multiplication et la division.
Fonctions :
sin(valeur) - Fonction sinus.
cos(valeur) - Fonction cosinus.
tan(valeur) - Fonction tangente.
sqrt(valeur) - Racine carrée.
log(valeur) - Logarithme naturel.
pow(base, exposant) - Fonction puissance.
Parenthèses : Utilisez les parenthèses pour regrouper les expressions ou pour les arguments des fonctions.

Aperçu du code
Principaux composants
Validation de l'entrée (expressionvalide) :

Vérifie que l'expression contient des fonctions et des opérateurs valides.
Vérifie les parenthèses non fermées et les opérateurs mal positionnés.
Évaluation de l'expression (evaluerExpression) :

Analyse la chaîne d'entrée pour évaluer les expressions en respectant la priorité des opérateurs.
Prend en charge l'évaluation récursive pour les expressions imbriquées.
Gestion des fonctions (fonction) :

Évalue les fonctions mathématiques supportées en analysant leurs arguments.
Bibliothèques utilisées
<math.h> : Pour les opérations trigonométriques, logarithmiques et les puissances.
<ctype.h> : Pour la validation et la gestion des caractères.
<string.h> : Pour les opérations sur les chaînes de caractères.
<stdlib.h> : Pour l'allocation mémoire et la conversion de chaînes en nombres.
Limitations
Seules les fonctions et opérateurs listés ci-dessus sont supportés.
Les angles des fonctions trigonométriques doivent être fournis en degrés.
L'entrée doit respecter les formats et les règles de parenthèses.
