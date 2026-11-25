/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** player internal header
*/

#ifndef PLAYER_INTERNAL_H_
    #define PLAYER_INTERNAL_H_

    #include "enums.h"

    #include <stdbool.h>

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Rect.h>

typedef struct player_skin_s {
    sfTexture *textures[SKIN_COUNT];
    skin_id_t current_skin;
} player_skin_t;

typedef struct player_anim_s {
    sfSprite *sprite;
    sfIntRect rect;
    unsigned int frame;
    float timer;
} player_anim_t;

typedef struct player_move_s {
    sfVector2f pos;
    sfVector2f movement;
    dir_id_t facing;
    dir_id_t prev_facing;
} player_move_t;

typedef struct player_state_s {
    state_id_t state;
    state_id_t prev_state;
    bool run;
} player_state_t;

struct player_s {
    player_skin_t skin;
    player_anim_t anim;
    player_move_t move;
    player_state_t state;
};

#endif
