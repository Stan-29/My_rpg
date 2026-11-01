# My RPG

RPG en C avec la CSFML.

## Installation (macOS)

À faire une seule fois, à la racine du dépôt. La CSFML est compilée sur ta machine, ça peut prendre quelques minutes :

```bash
./install.sh
```

## Lancer le jeu

```bash
make compile
```

## Ajouter du contenu

Pas besoin de toucher au code du jeu : tout passe par les tableaux de `source/const/`.

- Images : `source/const/images_tab.c`, fichiers dans `ressource/images/`
- Textes : `source/const/texts_tab.c`, polices dans `ressource/fonts/`
- Musiques : `source/const/musics_tab.c`, fichiers dans `ressource/musics/`

Chaque ligne indique la scène où l'élément apparaît. La dernière ligne de chaque tableau (`SCENE_NONE`) doit rester à la fin.
