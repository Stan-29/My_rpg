/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
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
    const images_tab_t *images_tab)
{
    image_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    if (!images_tab)
        return OK;
    for (unsigned int index = 0; images_tab[index].filepath != NULL; index++) {
        new_elem = image_create(&images_tab[index], index);
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
    const texts_tab_t *texts_tab)
{
    text_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    if (!texts_tab)
        return OK;
    for (unsigned int index = 0; texts_tab[index].filepath != NULL; index++) {
        new_elem = text_create(&texts_tab[index], index);
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
    const sounds_tab_t *sounds_tab)
{
    sound_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    if (!sounds_tab)
        return OK;
    for (unsigned int index = 0; sounds_tab[index].filepath != NULL; index++) {
        new_elem = sound_create(&sounds_tab[index]);
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
    const musics_tab_t *musics_tab)
{
    music_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    if (!musics_tab)
        return OK;
    for (unsigned int index = 0; musics_tab[index].filepath != NULL; index++) {
        new_elem = music_create(musics_tab);
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
            scenes_tab[id].sounds) == ERROR)
        return ERROR;
    if (scene_init_musics(&scene->lists->ll_musics,
            scenes_tab[id].musics) == ERROR)
        return ERROR;
    if (scene_init_images(&scene->lists->ll_images,
            scenes_tab[id].images) == ERROR)
        return ERROR;
    if (scene_init_texts(&scene->lists->ll_texts,
            scenes_tab[id].texts) == ERROR)
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

void scene_draw(scene_t *scene, sfRenderWindow *window)
{
    linked_list_t *temp = NULL;

    if (!scene)
        return;
    map_draw(scene->map, window);
    player_draw(scene->player, window);
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
