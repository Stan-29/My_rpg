/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene internal header
*/

#ifndef SCENE_INTERNAL_H_
    #define SCENE_INTERNAL_H_

    #include "types.h"

    #include "image/image.h"
    #include "linked_list/linked_list.h"
    #include "map/map.h"
    #include "music/music.h"
    #include "player/player.h"
    #include "sound/sound.h"
    #include "text/text.h"

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

    #define RATIO_HOVER_POS 0.05
    #define RATIO_HOVER_SCALE 1.1
    #define RATIO_CLICK_POS -0.05
    #define RATIO_CLICK_SCALE 0.9

extern const image_tab_t image_menu_tab[];
extern const image_tab_t image_save_tab[];
extern const image_tab_t image_settings_tab[];
extern const image_tab_t image_game_tab[];
extern const image_tab_t image_pause_tab[];

extern const text_tab_t text_menu_tab[];
extern const text_tab_t text_save_tab[];
extern const text_tab_t text_settings_tab[];
extern const text_tab_t text_game_tab[];
extern const text_tab_t text_pause_tab[];

extern const music_tab_t music_menu_tab[];
extern const music_tab_t music_save_tab[];
extern const music_tab_t music_settings_tab[];
extern const music_tab_t music_game_tab[];
extern const music_tab_t music_pause_tab[];

extern const sound_tab_t sound_menu_tab[];
extern const sound_tab_t sound_save_tab[];
extern const sound_tab_t sound_settings_tab[];
extern const sound_tab_t sound_game_tab[];
extern const sound_tab_t sound_pause_tab[];

typedef struct scene_list_s {
    linked_list_t *ll_images;
    linked_list_t *ll_texts;
    linked_list_t *ll_sounds;
    linked_list_t *ll_musics;
} scene_list_t;

struct scene_s {
    unsigned int id;
    sfView *view;
    image_t *held;
    sfVector2f offset;
    map_t *map;
    player_t *player;
    scene_list_t *lists;
};

#endif
