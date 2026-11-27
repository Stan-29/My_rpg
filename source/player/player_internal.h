/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** player internal header
*/

#ifndef PLAYER_INTERNAL_H_
    #define PLAYER_INTERNAL_H_

    #include "player/player.h"

    #include <stdbool.h>

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Rect.h>

    #define PLAYER_SPEED 300

    #define FRAME_W 48
    #define FRAME_H 64
    #define PLAYER_SCALE 2
    #define PLAYER_HITBOX_W 36
    #define PLAYER_HITBOX_H 12
    #define MAX_DELTA 0.05f

typedef enum state_id_e {
    STATE_IDLE = 0,
    STATE_WALKING,
    STATE_RUNNING,
    STATE_ATTACKING,
    STATE_COUNT
} state_id_t;

typedef enum dir_id_e {
    DIR_DOWN = 0,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP,
    DIR_COUNT
} dir_id_t;

typedef struct skin_tab_s {
    const char *filepath;
} skin_tab_t;

extern const skin_tab_t skin_tab[];

typedef struct state_tab_s {
    unsigned int first_row;
    unsigned int frame_count;
    float delay;
    float speed;
} state_tab_t;

extern const state_tab_t state_tab[];

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
