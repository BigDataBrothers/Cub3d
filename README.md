# Cub3D

[![École 42](https://img.shields.io/badge/%C3%89cole-42-blue)](https://42.fr)
![Langage](https://img.shields.io/badge/Language-C-green)
![MiniLibX](https://img.shields.io/badge/Library-MiniLibX-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey)
![Graphics](https://img.shields.io/badge/Graphics-X11-informational)
![Build](https://img.shields.io/badge/Build-Makefile-blue)
![License](https://img.shields.io/badge/License-42%20School-lightblue)

Un moteur de raycasting 3D inspiré de Wolfenstein 3D, utilisant la bibliothèque MiniLibX.

## Fonctionnalités

### Rendu 3D :
- Affichage de murs texturés
- Rendu en temps réel basé sur le raycasting
- Textures différentes selon l'orientation des murs (Nord, Sud, Est, Ouest)

### Moteur de jeu :
- Collisions avec les murs
- Déplacement fluide du joueur
- Rotation de la caméra
- Gestion de la carte au format .cub

### Parseur de fichier de carte :
- Validation de la carte
- Configuration des textures
- Définition des couleurs du sol et du plafond
- Position et orientation initiale du joueur

## Installation

- Clonez le dépôt et compilez le projet:
```bash
# Clonez le dépôt
git clone https://github.com/BigDataBrothers/Cub3d
cd Cub3d

# Compilez le projet
make

# Testez avec une carte d'exemple
./cub3D maps/map.cub
```

## Dépendances

Le projet utilise les bibliothèques suivantes :
- MiniLibX (incluse comme sous-module)
- X11 pour le système de fenêtrage
- Math pour les calculs trigonométriques

Sur Debian/Ubuntu, installez les dépendances nécessaires :
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

## Contrôles

- `W` : Avancer
- `S` : Reculer
- `A` : Déplacement latéral vers la gauche
- `D` : Déplacement latéral vers la droite
- `Flèches gauche/droite` : Tourner la vue.
- `ESC` : Quitter le jeu.

## Format du fichier de carte

- NO, SO, WE, EA : Chemins vers les textures des murs
- F : Couleur RGB du sol
- C : Couleur RGB du plafond
- La carte utilise 1 pour les murs, 0 pour les espaces vides, et N, S, E ou W pour indiquer la position et l'orientation initiale du joueur

### Exemple de fichier `.cub` :
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

## Structure des fichiers

- `src/` : Contient le code source.
- `include/` : Fichiers d'en-tête.
- `assets/` : Ressources du jeu comme les textures.
- `maps/` : Contient les fichiers de carte au format `.cub`.
- `Makefile` : Instructions de construction.

## Tests

- Pour tester avec une carte personnalisée, placez-la dans le dossier `maps/` et exécutez :
```bash
./cub3D maps/votre_carte.cub
```

## Auteur
- **Mehdi Yassine** - [GitHub](https://github.com/BigDataBrothers)
- **Jessim Skiba**

## Licence

> ℹ️ Ce projet est réalisé dans le cadre du cursus de l'école 42. Il est soumis à ses politiques académiques et ne peut être utilisé à des fins commerciales ou éducatives sans autorisation.
