/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "consts.h"
#include "defines.h"

#include "garbage_collector/garbage_collector.h"
#include "image/image.h"
#include "linked_list/linked_list.h"
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "text/text.h"
#include "sound/sound.h"
#include "music/music.h"

#include <SFML/Audio/Music.h>
#include <SFML/Graphics/RenderWindow.h>
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

scene_t *scene_create(unsigned int id)
{
    sfFloatRect rect = {0, 0, FULL_SCREEN_WIDTH, FULL_SCREEN_HEIGHT};
    scene_t *scene = garbage_collector_malloc(sizeof(scene_t));

    if (!scene)
        return NULL;
    scene->id = id;
    scene->view = sfView_createFromRect(rect);
    if (!scene->view)
        return scene_destroy(scene);
    if (scene_init_sounds(&scene->ll_sounds, scenes_tab[id].sounds) == ERROR)
        return scene_destroy(scene);
    if (scene_init_musics(&scene->ll_musics, scenes_tab[id].musics) == ERROR)
        return scene_destroy(scene);
    if (scene_init_images(&scene->ll_images, scenes_tab[id].images) == ERROR ||
        scene_init_texts(&scene->ll_texts, scenes_tab[id].texts) == ERROR)
        return scene_destroy(scene);
    return scene;
}

void scene_draw(scene_t *scene, sfRenderWindow *window)
{
    linked_list_t *temp = NULL;

    if (!scene)
        return;
    sfRenderWindow_setView(window, scene->view);
    temp = scene->ll_images;
    while (temp != NULL) {
        image_draw(linked_list_get_data(temp), window);
        temp = linked_list_get_next(temp);
    }
    temp = scene->ll_texts;
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
    linked_list_destroy(&scene->ll_musics, &music_destroy);
    linked_list_destroy(&scene->ll_sounds, &sound_destroy);
    linked_list_destroy(&scene->ll_images, &image_destroy);
    linked_list_destroy(&scene->ll_texts, &text_destroy);
    garbage_collector_free(scene);
    return NULL;
}
