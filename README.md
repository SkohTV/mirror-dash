# Mirror Dash


## Cahier des charges

### Ecran principal - [Robin](https://github.com/mkkuu)
- [ ] Bouton play
- [ ] Écran de niveaux (Petit descriptif des niveaux + choix)
- [ ] Skins (+ traînée / skins premium)
- [ ] Changement du volume
- [ ] Faux gameplay en background
- [ ] Sélection via les touches directionnelles

### Niveaux - [Noé](https://github.com/SkohTV)
- [x] L’arrière plan scroll, le cube reste fixe horizontalement, pas verticalement
- [x] Sol minimal à X hauteur, et il peut monter selon l’obstacle sur lequel on glisse
- [x] Apparence (bg bouge lentement, sol bouge rapidement)
- [x] Différent obstacle/trucs (blocks, piques, pad, rond magique, reverse)
- [x] Musique
- [x] Particules (pour la parabole)
- [ ] Début / fin
- [ ] Barre de % du niveau
- [x] Retourner personnage quand gravité inversée
- [ ] Fichiers de niveau compilé et encodé


<br>


## Structure du projet

```
├── README.md           # Documentation du code (vous êtes ici)
├── make.sh             # Script qui build automatiquement le projet
├── CMakeLists.txt      # Paramètres de build du projet
├── main.c              # Point d'entrée du code du projet
├── .editorconfig       # Configuration unifiée pour les éditeurs
├── .gitignore          # Fichiers à ignorer pour git
├── build/              # Temporaire, pour cache les fichiers de build
├── primitives/         # Fonction primaires et data structures
├── interfaces/         # Encapsulation des parties du jeu
├── tests/              # Tests que des parties du code sont tjr fonctionnelles
└── assets/             # Assets pour le projet
    ├── blocks/         # Blocs et obstacles chargés en jeu
    ├── gui/            # Images pour le menu principal
    ├── maps/           # Répertoires de levels
    └── skins/          # Skins pour le joueur en game
```


<br>


## Installation

### Build
Pour build ce projet, vous aurez besoin de :

- WSL ou Linux
- gcc (GNU C Compiler)
- cmake (Makefile Generator)

Ainsi que des librairies :
- <SDL2/SDL.h> (`sudo apt-get install libsdl2-dev`)
- <SDL2/SDL_image.h> (`sudo apt-get install libsdl2-image-dev`)
- <SDL2/SDL_mixer.h> (`sudo apt-get install libsdl2-mixer-dev`)
- <SDL2/SDL_ttf.h> (`sudo apt-get install libsdl2-ttf-dev`)

Puis lancer le fichier `make.sh`, il s'occupe de tout


### Jouer
Vous pouvez soit télécharger une release **[ici](https://github.com/SkohTV/Mirror-dash/releases)**, ou le build vous même.