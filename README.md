MEMO : map.level :
- 1 char type
- 1 int posY
- 1 int summon

Drag Management : 
 - Input parameters : 
    - posX constanstly
    - posY ""
    - Chased Element
    - custom drag choosen ?
 - Function's actions :
    - Paint a drag behind the gliding block
 - Output parameters : 
    - Nothing ?


Particules
Liste chainée
A chaque loop :
Si pas en saut :
- Ajout au sommet de la file
- On dessine tout en descend la file
- On drop la dernière sans la dessine
- Contion de drop : + de X particules
- Spawn à X hauteur (plus en bas, moins en haut)



### Ecran principal
- [ ] PLAY -> Écran de niveaux (Petit descriptif des niveaux)
- [ ] Skins (+ traînée / skins premium)
### Niveaux
- [x] L’arrière plan scroll, le cube reste fixe horizontalement, pas verticalement
- [x] Sol minimal à X hauteur, et il peut monter selon l’obstacle sur lequel on glisse
- [x] Apparence (bg bouge lentement, sol bouge rapidement)
- [x] Différent obstacle/trucs (blocks, piques, pad, rond magique, reverse)
- [x] Musique
- [ ] Particules (pour la parabole)
- [ ] Début / fin
- [ ] Barre de % du niveau
- [ ] Retourner personnage quand gravité inversée
### Paramètres
- [ ] Skins
- [ ] Volume