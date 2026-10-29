/*
** PERSONAL PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef SCENE_H_
    #define SCENE_H_

    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Audio/Music.h>
      
typedef struct scene_s scene_t;

scene_t *scene_create(unsigned int id);
void scene_draw(scene_t *scene); 
void scene_destroy(scene_t *scene); 

#endif