# Mirror Dash

## Intro
Un remix de Geometry Dash, où l'on contrôle deux cubes au lieu d'un, en mirroir sur l'axe horizontal.<br>
Il sera facile de créer et ajouter des nouvelles maps/skins.<br>
Les paramètres seronts réglables.<br>
<br>

## Analyse du projet
Ecran principal
- Parametres (tailles de screen + truc son)
- PLAY -> Ecran de niveaux (Petit descriptif des niveaux)
- Skins (+ trainée / skins premium payants)

Niveaux
- Centré horizontalement
- Pas centré verticalement
- Différence entre sol et obstacle
- Apparence (bg bouge lentement, sol bouge rapidement, 180° de saut)
- Différent obstacle/trucs (blocks, piques, pad, rond magique, scies circulaires, reverse, fin, levier rouge/bleu, canon (angle custom)) (potentiellement portails)
- Musique
- Particules
- Début / fin
- Barre de % du niveau
- Deux persos, un bouton pour chaque

Paramètres
- Taille de la fenêtre
- Skins
- Volume
- Touches
- Code source

Système de niveaux
- Fichier raw
- Assets (Background - Obstacles / blocks - Personnage - Particules)
- Fichier mp3
- Fichier txt (pour les infos)
<br>

## Synthèse
- Thèmes
- Tâches / sous tâches
- Interfaces
<br>

## Réalisation
- Diagramme de Gantt
- Décrire algos complexes (schémas)
<br>


---


DATE DE RENDU : 25/05

7 semaine


<!--Create cool diagram
```mermaid
erDiagram
	CUSTOMER }|..|{ DELIVERY-ADDRESS : has
	CUSTOMER ||--o{ ORDER : places
	CUSTOMER ||--o{ INVOICE : "liable for"
	DELIVERY-ADDRESS ||--o{ ORDER : receives
	INVOICE ||--|{ ORDER : covers
	ORDER ||--|{ ORDER-ITEM : includes
	PRODUCT-CATEGORY ||--|{ PRODUCT : contains
	PRODUCT ||--o{ ORDER-ITEM : "ordered in"
```-->