# Jeu-de-la-Vie

Ce projet implémente le célèbre "Jeu de la Vie" de John Conway, un automate cellulaire qui simule l'évolution d'une population de cellules selon des règles simples. Le jeu se déroule sur une grille à deux dimensions où chaque cellule peut être "vivante" ou "morte". À chaque itération, l'état de la grille est mis à jour en fonction des règles définies pour la naissance et la mort des cellules.

# Règles du Jeu

Le "Jeu de la Vie" suit les règles suivantes :

  - Naissance : Si une cellule est morte mais qu'elle a au moins birthLimit voisins vivants, elle devient vivante.
  - Mort : Si une cellule est vivante et possède moins de deathLimit voisins vivants, elle meurt.
  - Survie : Si une cellule vivante a au moins deathLimit voisins vivants, elle reste vivante.
  
Ces règles sont appliquées à chaque cellule de la grille simultanément pour générer la grille suivante.

# Fonctionnalités

  - Initialisation de la grille avec une probabilité donnée pour qu'une cellule soit vivante.
  - Affichage de la grille pour chaque itération.
  - Mise à jour de l'état de la grille selon les règles du jeu.
  - Personnalisation de la taille de la grille, du nombre d'itérations, et des limites de naissance et de mort.
    
# Utilisation

Le programme initialise une grille de taille rows x cols avec une probabilité chanceToStartAlive que chaque cellule soit vivante. Il applique ensuite les règles du jeu pendant un nombre donné d'itérations, affichant la grille à chaque étape.

Les paramètres peuvent être modifiés directement dans le code :

  - rows et cols : définissent la taille de la grille.
  - chanceToStartAlive : probabilité initiale qu'une cellule soit vivante.
  - birthLimit et deathLimit : définissent les seuils de naissance et de mort pour les cellules.
  - nbIteration : nombre d'itérations du jeu.
  
Comment l'exécuter
1 . Cloner le fichier depuis GitHub :

git clone https://github.com/TheNeas1/Jeu-de-la-Vie.git

2 . Compiler le fichier main.c avec gcc :

gcc main.c -o Jeu-de-la-Vie

3 . Lancer le jeu :

./Jeu-de-la-Vie
