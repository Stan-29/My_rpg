/*
** PERSONAL PROJECT, 2026
** My_rpg
** File description:
** scene code
*/
#include "scene.h"
#include <stdlib.h>
      
struct scene_s {
    unsigned int id;
    sfView *view;
    sfMusic *music;
};

scene_t *scene_create(unsigned int id)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (!scene)
        return NULL;
    scene->id = id;
    return scene;
}

void scene_draw(scene_t *scene)
{
    return;
}

void scene_destroy(scene_t *scene)
{
    free(scene);
}
