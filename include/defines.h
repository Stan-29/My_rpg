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
    #define MAP_ROWS 25
    #define MAP_COLS 25

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

#endif
