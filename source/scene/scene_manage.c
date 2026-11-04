/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "defines.h"

#include "linked_list/linked_list.h"
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "types.h"
#include "sound/sound.h"
#include "music/music.h"
#include "image/image.h"

#include <SFML/Audio/Music.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Mouse.h>

void scene_start(scene_t *scene)
{
    if (!scene)
        return;
    music_play(linked_list_get_data(scene->ll_musics));
}

void scene_stop(scene_t *scene)
{
    if (!scene)
        return;
    music_stop(linked_list_get_data(scene->ll_musics));
}

void scene_change_sound_volume(scene_t *scene, float ratio)
{
    linked_list_t *temp = NULL;
    sound_t *data = NULL;

    if (!scene)
        return;
    temp = scene->ll_sounds;
    while (temp != NULL) {
        data = linked_list_get_data(temp);
        sound_change_volume(data, ratio);
        temp = linked_list_get_next(temp);
    }
}

void scene_change_music_volume(scene_t *scene, float ratio)
{
    linked_list_t *temp = NULL;
    music_t *data = NULL;

    if (!scene)
        return;
    temp = scene->ll_musics;
    while (temp != NULL) {
        data = linked_list_get_data(temp);
        music_change_volume(data, ratio);
        temp = linked_list_get_next(temp);
    }
}
