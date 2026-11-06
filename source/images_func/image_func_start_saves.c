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
#include "types.h"

#include "scene_manager/scene_manager.h"
#include "linked_list/linked_list.h"
#include "engine/engine.h"
#include "text/text.h"
#include "scene/scene.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static char *get_new_str(char *buffer, unsigned int index,
    char separator)
{
    char *new_str = garbage_collector_malloc(sizeof(char) * 128);
    unsigned int separator_count = 0;
    unsigned int index_buffer = 0;

    while (buffer[index_buffer] != '\0') {
        if (buffer[index_buffer] == separator)
            separator_count++;
        if (separator_count == index)
            break;
        index_buffer += 1;
    }
    if (buffer[index_buffer] == separator)
        index_buffer += 1;
    for (unsigned int index_new = 0; buffer[index_buffer] != '\0' &&
        buffer[index_buffer] != separator; index_new++) {
        new_str[index_new] = buffer[index_buffer];
        new_str[index_new + 1] = '\0';
        index_buffer += 1;
    }
    return new_str;
}

static void set_new_str(linked_list_t *temp, char *buffer)
{
    text_t *data = NULL;
    char *new_str = NULL;

    for (unsigned int index = 0; index < MAX_SAVE_INFOS; index++) {
        new_str = get_new_str(buffer, index, '\n');
        data = linked_list_get_data(temp);
        text_change_str(data, new_str);
        garbage_collector_free(new_str);
        temp = linked_list_get_next(temp);
    }
}

static void update_save_infos(scene_t *scene, char *buffer,
    unsigned int index_save)
{
    linked_list_t *temp = scene_get_texts(scene);
    text_t *data = NULL;
    unsigned int actual_index = 0;

    while (temp != NULL) {
        if (actual_index == index_save)
            break;
        data = linked_list_get_data(temp);
        if (text_contains(data, "Save"))
            actual_index += 1;
        temp = linked_list_get_next(temp);
    }
    if (temp != NULL)
        set_new_str(temp, buffer);
    return;
}

static unsigned int manage_save_infos(scene_t *scene, const char *save_path,
    unsigned int index_save)
{
    char *buffer = garbage_collector_malloc(sizeof(char) * 1028);
    int file_descriptor = open(save_path, O_RDONLY);
    int bytes_read = 0;

    if (file_descriptor == -1)
        return OK;
    bytes_read = read(file_descriptor, buffer, 500);
    buffer[bytes_read] = '\0';
    update_save_infos(scene, buffer, index_save);
    close(file_descriptor);
    garbage_collector_free(buffer);
    return OK;
}

unsigned int image_func_go_to_save(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_play_sound(scene, SOUND_CLICK);
    scene_manager_set_scene(scene_manager, SCENE_SAVE);
    scene = scene_manager_get_current(scene_manager);
    if (manage_save_infos(scene, saves_path_tab[0], 1) == ERROR ||
        manage_save_infos(scene, saves_path_tab[1], 2) == ERROR ||
        manage_save_infos(scene, saves_path_tab[2], 3) == ERROR)
        return ERROR;
    return OK;
}

unsigned int image_func_start_save1(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_play_sound(scene, SOUND_CLICK);
    scene_manager_exit_sub(scene_manager);
    scene_manager_set_scene(scene_manager, SCENE_GAME);
    return OK;
}

unsigned int image_func_start_save2(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_play_sound(scene, SOUND_CLICK);
    scene_manager_exit_sub(scene_manager);
    scene_manager_set_scene(scene_manager, SCENE_GAME);
    return OK;
}

unsigned int image_func_start_save3(scene_manager_t *scene_manager,
    scene_t *scene, engine_t *engine)
{
    (void)engine;
    scene_play_sound(scene, SOUND_CLICK);
    scene_manager_exit_sub(scene_manager);
    scene_manager_set_scene(scene_manager, SCENE_GAME);
    return OK;
}
