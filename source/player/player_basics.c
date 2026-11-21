/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** player_basics
*/
#include "consts.h"
#include "defines.h"

#include "enums.h"
#include "garbage_collector/garbage_collector.h"
#include "player/player.h"
#include "player/player_internal.h" // IWYU pragma: keep

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

 

static void player_fill_saved_infos(player_t *player, const player_save_t *data)
{
    player->move.pos = data->pos;
    player->skin.current_skin = data->skin;
}

static unsigned int player_fill_skin(player_skin_t *skin)
{
    for (unsigned int skin_id = 0; skin_id < SKIN_COUNT; skin_id++) {
        if (skin_tab[skin_id].filepath == NULL)
            continue;
        skin->textures[skin_id] = sfTexture_createFromFile
            (skin_tab[skin_id].filepath, NULL);
        if (!skin->textures[skin_id]) {
            return ERROR;
        }
    }
    return OK;
}

static unsigned int player_fill_anim(player_anim_t *anim, sfTexture *texture,
    sfVector2f *pos)
{
    anim->sprite = sfSprite_create();
    if (!anim->sprite)
        return ERROR;
    sfSprite_setTexture(anim->sprite, texture, sfFalse);
    anim->rect = (sfIntRect){0, 0, FRAME_W, FRAME_H};
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){FRAME_W / 2.0f, FRAME_H});
    sfSprite_setScale(anim->sprite, (sfVector2f){PLAYER_SCALE, PLAYER_SCALE});
    sfSprite_setPosition(anim->sprite, *pos);
    return OK;
}

player_t *player_create(const player_save_t *data)
{
    player_t *player = garbage_collector_malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player_fill_saved_infos(player, data);
    if (player_fill_skin(&player->skin) == ERROR)
        return player_destroy(player);
    if (player_fill_anim(&player->anim,
            player->skin.textures[player->skin.current_skin],
            &player->move.pos) == ERROR)
        return player_destroy(player);
    return player;
}

void *player_destroy(player_t *player)
{
    if (!player)
        return NULL;
    if (player->anim.sprite)
        sfSprite_destroy(player->anim.sprite);
    for (unsigned int skin_id = 0; skin_id < SKIN_COUNT; skin_id++)
        if (player->skin.textures[skin_id])
            sfTexture_destroy(player->skin.textures[skin_id]);
    garbage_collector_free(player);
    return NULL;
}

void player_draw(player_t *player, sfRenderWindow *window)
{
    if (!player || !window)
        return;
    sfRenderWindow_drawSprite(window, player->anim.sprite, NULL);
}
