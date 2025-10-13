# Introduction à la programmation
## Jeu du labyrinthe
Réalisé par Ethan Le Neindre.
Sous la supervision de Julien Rabin.
## Compte-rendu des étapes
### Étape 1
La réalisation du labyrinthe suit l'algorithme d'exploration exaustive, tel que décrit sur la page Wikipédia de [modélisation mathématique d'un labyrinthe](https://fr.wikipedia.org/wiki/Mod%C3%A9lisation_math%C3%A9matique_d%27un_labyrinthe#Exploration_exhaustive).
Le labyrinthe est une matrice (une tableau à double entrée) de Cell.

Cell est une structure de donnée définie comme un type, qui contient un cell_content, un entier qui sert de 'booléen' visited, et un nombre de points qui servira plus tard.

Le cell_content est une enum qui lie les différents types de cellules possibles dans le labyrinthe à leur représentation graphique. Ainsi, cela permet d'avoir un type Cell qui contient un contenu normalisé et affichable (ex : ``WALL`` pour un mur, qui s'affiche ``#`` dans la console).

J'ai également créer un tableau de vecteur, afin d'avoir le calcul rapide en fonction de la direction de la cellule voisine, défini dans l'ordre West/Est/North/South (ex : la cellule du haut est la ligne d'indice ``[2]`` avec pour vecteur ``{-2, 0}``).



### Étape 2
// TODO

### Étape 3
// TODO

### Étape 4
// TODO

