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
#include "linked_list/linked_list.h"
#include "scene/scene.h"
#include "scene/scene_internal.h" // IWYU pragma: keep
#include "text/text.h"
#include "sound/sound.h"

#include <SFML/Audio/Music.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>

static unsigned int scene_init_images(linked_list_t **ll_images,
    unsigned int id)
{
    image_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    for (unsigned int index = 0; images_scenes_tab[index].id_scene !=
        SCENE_NONE; index++) {
        if (images_scenes_tab[index].id_scene != id)
            continue;
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

static unsigned int scene_init_texts(linked_list_t **ll_texts,
    unsigned int id)
{
    text_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    for (unsigned int index = 0; texts_scenes_tab[index].id_scene !=
        SCENE_NONE; index++) {
        if (texts_scenes_tab[index].id_scene != id)
            continue;
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

static unsigned int scene_init_sounds(linked_list_t **ll_sounds,
    unsigned int id)
{
    sound_t *new_elem = NULL;
    linked_list_t *new_node = NULL;

    for (unsigned int index = 0; sounds_scenes_tab[index].id_scene
        != SCENE_NONE; index++) {
        if (sounds_scenes_tab[index].id_scene != id)
            continue;
        new_elem = sound_create(&sounds_scenes_tab[index]);
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

static unsigned int scene_init_music(scene_t *scene, unsigned int id)
{
    unsigned int index = 0;

    while (musics_scenes_tab[index].id_scene != SCENE_NONE) {
        if (musics_scenes_tab[index].id_scene == id)
            break;
        index++;
    }
    if (musics_scenes_tab[index].id_scene == SCENE_NONE)
        return OK;
    if (musics_scenes_tab[index].filepath == NULL)
        return OK;
    scene->music = sfMusic_createFromFile(musics_scenes_tab[index].filepath);
    if (!scene->music)
        return ERROR;
    sfMusic_setLoop(scene->music, sfTrue);
    sfMusic_setVolume(scene->music, 50.0f);
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
    if (scene_init_sounds(&scene->ll_sounds, id) == ERROR)
        return scene_destroy(scene);
    if (scene_init_music(scene, id) == ERROR)
        return scene_destroy(scene);
    if (scene_init_images(&scene->ll_images, id) == ERROR ||
        scene_init_texts(&scene->ll_texts, id) == ERROR)
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
    if (scene->music)
        sfMusic_destroy(scene->music);
    while (scene->ll_sounds != NULL) {
        sound_destroy(linked_list_get_data(scene->ll_sounds));
        linked_list_delete_start(&scene->ll_sounds);
    }
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
