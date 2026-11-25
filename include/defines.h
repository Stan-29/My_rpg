/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** defines header
*/

#ifndef DEFINES_H_
    #define DEFINES_H_

    #define OK 0
    #define ERROR 84

    #define TILE_W 192
    #define TILE_H 96

    #define FULL_SCREEN_WIDTH 1920
    #define FULL_SCREEN_HEIGHT 1080
    #define WINDOWED_WIDTH 1280
    #define WINDOWED_HEIGHT 720

    #define RATIO_HOVER_POS 0.05
    #define RATIO_HOVER_SCALE 1.1
    #define RATIO_CLICK_POS -0.05
    #define RATIO_CLICK_SCALE 0.9

    #define FPS 60

    #define PLAYER_SPEED 300

    #define CAMERA_LOOKAHEAD 300
    #define CAMERA_SMOOTH 2

    #define INIT_RATIO 0.5f

    #define SAVE_COUNT 3
    #define MAX_SAVE_INFOS 4

    #define MAP_OFFSET_X (FULL_SCREEN_WIDTH / 2.0f)
    #define MAP_OFFSET_Y 100.0f

    #define FRAME_W 48
    #define FRAME_H 64
    #define PLAYER_SCALE 2
    #define PLAYER_SPAWN_COL 12
    #define PLAYER_SPAWN_ROW 12
    #define PLAYER_HITBOX_W 36
    #define PLAYER_HITBOX_H 12
    #define MAX_DELTA 0.05f

    #define HALF_TILE_W (TILE_W / 2.0f)
    #define HALF_TILE_H (TILE_H / 2.0f)
    #define TILE_TO_WORLD_X(c, r) (((c) - (r)) * HALF_TILE_W + MAP_OFFSET_X)
    #define TILE_TO_WORLD_Y(c, r) (((c) + (r)) * HALF_TILE_H + MAP_OFFSET_Y)

    #define MAP_FLOORS_PATH "./ressource/maps/map_floors.data"
    #define MAP_OBJECTS_PATH "./ressource/maps/map_objects.data"
    #define MAP_FLOORS_SIZE 50

#endif
