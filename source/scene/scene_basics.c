/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "scene.h"
#include "consts.h"
#include "defines.h"
#include "garbage_collector/garbage_collector.h"
#include "linked_list/linked_list.h"
#include "image/image.h"
#include "text/text.h"
#include <SFML/Graphics/View.h>
#include <SFML/Audio/Music.h>

struct scene_s {
    unsigned int id;
    sfView *view;
    sfMusic *music;
    linked_list_t *ll_images;
    linked_list_t *ll_texts;
};

static unsigned int scene_init_images(linked_list_t **ll_images)
{
    image_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    for (unsigned int index = 0; images_scenes_tab[index].id_scene != 0;
        index++) {
        new_elem = image_create(&images_scenes_tab[index], index);
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

static unsigned int scene_init_texts(linked_list_t **ll_texts)
{
    text_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    for (unsigned int index = 0; texts_scenes_tab[index].id_scene != 0;
        index++) {
        new_elem = text_create(&texts_scenes_tab[index], index);
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

scene_t *scene_create(unsigned int id)
{
    sfFloatRect rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    scene_t *scene = garbage_collector_malloc(sizeof(scene_t));

    if (!scene)
        return NULL;
    scene->id = id;
    scene->view = sfView_createFromRect(rect);
    if (!scene->view)
        return scene_destroy(scene);
    scene->music = sfMusic_createFromFile("ressource/musics/music.wav");
    if (!scene->music)
        return scene_destroy(scene);
    sfMusic_setLoop(scene->music, sfTrue);
    sfMusic_setVolume(scene->music, 50.0f);
    if (scene_init_images(&scene->ll_images) == ERROR ||
        scene_init_texts(&scene->ll_texts) == ERROR)
        return scene_destroy(scene);
    sfMusic_play(scene->music);
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
    if (scene->music)
        sfMusic_destroy(scene->music);
    while (scene->ll_images != NULL) {
        image_destroy(linked_list_get_data(scene->ll_images));
        linked_list_delete_start(&scene->ll_images);
    }
    while (scene->ll_texts != NULL) {
        text_destroy(linked_list_get_data(scene->ll_texts));
        linked_list_delete_start(&scene->ll_texts);
    }
    garbage_collector_free(scene);
    return NULL;
}
