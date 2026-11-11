/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** scene header
*/

#ifndef MUSIC_INTERNAL_H_
    #define MUSIC_INTERNAL_H_

    #include <SFML/Audio/Music.h>

struct music_s {
    unsigned int id;
    float base_volume;
    sfMusic *music;
};

#endif
