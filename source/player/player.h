/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** player module
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "enums.h"
    #include "saves.h"

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>

typedef struct player_s player_t;

player_t *player_create(const player_save_t *data);
void *player_destroy(player_t *player);
void player_draw(player_t *player, sfRenderWindow *window);

void player_update(player_t *player, float dt);
void player_update_dir(player_t *player, sfVector2f *dir);
void player_set_run(player_t *player, bool run);
void player_reset_inputs(player_t *player);
void player_set_skin(player_t *player, skin_id_t skin);

sfVector2f *player_get_pos(player_t *player);
sfVector2f *player_get_movement(player_t *player);

#endif
