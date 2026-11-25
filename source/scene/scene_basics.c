/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene_basics
*/
#include "consts.h"
#include "defines.h"
#include "enums.h"

#include "garbage_collector/garbage_collector.h"
#include "image/image.h"
#include "map/map.h"
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "text/text.h"
#include "sound/sound.h"
#include "music/music.h"
#include "types.h"

#include <SFML/Audio/Music.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>

static unsigned int scene_init_images(linked_list_t **ll_images,
    const image_tab_t *image_tab)
{
    image_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    if (!image_tab)
        return OK;
    for (unsigned int index = 0; image_tab[index].filepath != NULL; index++) {
        new_elem = image_create(&image_tab[index], index);
        if (!new_elem)
            return ERROR;
        new_node = linked_list_create_node(new_elem, index);
        if (!new_node) {
            image_destroy(new_elem);
            return ERROR;
        }
        linked_list_add_end(ll_images, new_node);
    }
    return OK;
}

static unsigned int scene_init_texts(linked_list_t **ll_texts,
    const text_tab_t *text_tab)
{
    text_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    if (!text_tab)
        return OK;
    for (unsigned int index = 0; text_tab[index].filepath != NULL; index++) {
        new_elem = text_create(&text_tab[index], index);
        if (!new_elem)
            return ERROR;
        new_node = linked_list_create_node(new_elem, index);
        if (!new_node) {
            text_destroy(new_elem);
            return ERROR;
        }
        linked_list_add_end(ll_texts, new_node);
    }
    return OK;
}

static unsigned int scene_init_sounds(linked_list_t **ll_sounds,
    const sound_tab_t *sound_tab)
{
    sound_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    if (!sound_tab)
        return OK;
    for (unsigned int index = 0; sound_tab[index].filepath != NULL; index++) {
        new_elem = sound_create(&sound_tab[index]);
        if (!new_elem)
            return ERROR;
        new_node = linked_list_create_node(new_elem, index);
        if (!new_node) {
            sound_destroy(new_elem);
            return ERROR;
        }
        linked_list_add_end(ll_sounds, new_node);
    }
    return OK;
}

static unsigned int scene_init_musics(linked_list_t **ll_musics,
    const music_tab_t *music_tab)
{
    music_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    if (!music_tab)
        return OK;
    for (unsigned int index = 0; music_tab[index].filepath != NULL; index++) {
        new_elem = music_create(music_tab);
        if (!new_elem)
            return ERROR;
        new_node = linked_list_create_node(new_elem, index);
        if (!new_node) {
            music_destroy(new_elem);
            return ERROR;
        }
        linked_list_add_end(ll_musics, new_node);
    }
    return OK;
}

static unsigned int scene_init_lists(scene_t *scene, unsigned int id)
{
    scene->lists = garbage_collector_malloc(sizeof(scene_list_t));
    if (!scene->lists)
        return ERROR;
    if (scene_init_sounds(&scene->lists->ll_sounds,
            scene_tab[id].sounds) == ERROR)
        return ERROR;
    if (scene_init_musics(&scene->lists->ll_musics,
            scene_tab[id].musics) == ERROR)
        return ERROR;
    if (scene_init_images(&scene->lists->ll_images,
            scene_tab[id].images) == ERROR)
        return ERROR;
    if (scene_init_texts(&scene->lists->ll_texts,
            scene_tab[id].texts) == ERROR)
        return ERROR;
    return OK;
}

static unsigned int handle_game(scene_t *scene, unsigned int id)
{
    sfVector2f pos = {0};

    if (id == SCENE_GAME) {
        scene->map = map_create();
        scene->player = player_create(&default_save.player);
        if (!scene->map || !scene->player)
            return ERROR;
        pos = player_get_pos(scene->player);
        map_set_center(scene->map, &pos);
    } else {
        scene->map = NULL;
        scene->player = NULL;
    }
    return OK;
}

scene_t *scene_create(unsigned int id)
{
    sfFloatRect rect = {0, 0, FULL_SCREEN_WIDTH, FULL_SCREEN_HEIGHT};
    scene_t *scene = garbage_collector_malloc(sizeof(scene_t));

    if (!scene)
        return NULL;
    scene->id = id;
    scene->held = NULL;
    scene->offset = (sfVector2f){0, 0};
    scene->view = sfView_createFromRect(rect);
    if (!scene->view)
        return scene_destroy(scene);
    if (scene_init_lists(scene, id) == ERROR)
        return scene_destroy(scene);
    if (handle_game(scene, id) == ERROR)
        return scene_destroy(scene);
    return scene;
}

static void draw_game(scene_t *scene, sfRenderWindow *window)
{
    float feet_y = 0;

    feet_y = player_get_pos(scene->player).y;
    map_draw_floor(scene->map, window);
    map_draw_objects(scene->map, window, feet_y, false);
    player_draw(scene->player, window);
    map_draw_objects(scene->map, window, feet_y, true);
}

void scene_draw(scene_t *scene, sfRenderWindow *window)
{
    linked_list_t *temp = NULL;

    if (!scene)
        return;
    draw_game(scene, window);
    sfRenderWindow_setView(window, scene->view);
    temp = scene->lists->ll_images;
    while (temp != NULL) {
        image_draw(linked_list_get_data(temp), window);
        temp = linked_list_get_next(temp);
    }
    temp = scene->lists->ll_texts;
    while (temp != NULL) {
        text_draw(linked_list_get_data(temp), window);
        temp = linked_list_get_next(temp);
    }
    return;
}

void *scene_destroy(scene_t *scene)
{
    if (!scene)
        return NULL;
    if (scene->view)
        sfView_destroy(scene->view);
    if (scene->lists) {
        linked_list_destroy(&scene->lists->ll_musics, &music_destroy);
        linked_list_destroy(&scene->lists->ll_sounds, &sound_destroy);
        linked_list_destroy(&scene->lists->ll_images, &image_destroy);
        linked_list_destroy(&scene->lists->ll_texts, &text_destroy);
        garbage_collector_free(scene->lists);
    }
    map_destroy(scene->map);
    player_destroy(scene->player);
    garbage_collector_free(scene);
    return NULL;
}
