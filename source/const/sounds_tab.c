/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** images_tab
*/
#include "consts.h"
#include "enums.h"

#include <stddef.h>

const sounds_tab_t sounds_scenes_tab[] = {
    {SCENE_MENU, SOUND_CLICK, "ressource/sounds/click.wav", 50},
    {SCENE_GAME, SOUND_CLICK, "ressource/sounds/click.wav", 50},
    {SCENE_NONE, SOUND_NONE, NULL, 0}
};
