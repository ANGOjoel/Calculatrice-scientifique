# Calculatrice  Scientifique

Ce dépôt contient un programme en langage C permettant d'évaluer des expressions mathématiques saisies par l'utilisateur.Le programme prend en charge plusieurs fonctionnalités : opérations arithmétiques, fonctions trigonométriques, logarithmiques, racines carrées et calculs de puissance.

## Fonctionnalités principales

### Opérations arithmétiques de base

Addition (+), Soustraction (-), Multiplication (*), Division (/).

### Fonctions mathématiques avancées

Trigonométrie : sin(), cos(), tan() (les angles sont en degrés).

Logarithme naturel : log().

Racine carrée : sqrt().

Puissance : pow(base, exposant).

### Fonctions disponibles :

Sinus : sin(valeur)

Cosinus : cos(valeur)

Tangente : tan(valeur)

Logarithme naturel : log(valeur)

Racine carrée : sqrt(valeur)

Puissance : pow(base, exposant)

### Opérateurs mathématiques :

Addition (+)

Soustraction (-)

Multiplication (*)

Division (/)


## Structure du Code

### Validation d'entrée (expressionvalide)

Vérifie que l'expression est syntaxiquement correcte :

Opérateurs correctement placés.

Parenthèses ouvertes et fermées.

### Évaluation de l'expression (evaluerExpression)

Analyse l'expression mathématique.

Traite les opérations imbriquées en respectant la priorité des opérateurs.

### Gestion des fonctions mathématiques (fonction)

Traite les fonctions spécifiques comme sin(), sqrt(), pow() et les évalue correctement.

## Limitations

### Restrictions actuelles :

Les angles pour les fonctions trigonométriques doivent être saisis en degrés.

Ne prend en charge que les fonctions listées ci-dessus.


