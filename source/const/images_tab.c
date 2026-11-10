/*
** EPITECH PROJECT, 2026
** My_rpg
** File description:
** images_tab
*/
#include "consts.h"
#include "images_func.h"

#include <stddef.h>

const images_tab_t images_menu_tab[] = {
    {"./ressource/images/Background Menu.PNG", {0, 0, 0, 0},
        {0, 0}, {1.15, 1.15}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/button.png", {0, 0, 0, 0},
        {750, 400}, {0.4, 0.4}, {0, 0, 0, 0}, &image_func_go_to_save},
    {"./ressource/images/button.png", {0, 0, 0, 0},
        {750, 550}, {0.4, 0.4}, {0, 0, 0, 0}, &image_func_go_to_settings},
    {"./ressource/images/button.png", {0, 0, 0, 0},
        {750, 700}, {0.4, 0.4}, {0, 0, 0, 0}, &image_func_exit_game},
    {NULL, {0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0, 0}, NULL}
};

const images_tab_t images_save_tab[] = {
    {"./ressource/images/filter.png", {0, 0, 0, 0},
        {0, 0}, {1920, 1080}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/wood_panel.png", {0, 0, 0, 0},
        {150, -650}, {1.4, 1.4}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/save_slot.png", {0, 0, 0, 0},
        {450, 350}, {1.8, 3}, {0, 0, 0, 0}, &image_func_start_save1},
    {"./ressource/images/save_slot.png", {0, 0, 0, 0},
        {800, 350}, {1.8, 3}, {0, 0, 0, 0}, &image_func_start_save2},
    {"./ressource/images/save_slot.png", {0, 0, 0, 0},
        {1150, 350}, {1.8, 3}, {0, 0, 0, 0}, &image_func_start_save3},
    {"./ressource/images/exit_settings_button.png", {0, 0, 0, 0},
        {820, 850}, {1, 1}, {0, 0, 0, 0}, &image_func_exit_sub_scene},
    {NULL, {0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0, 0}, NULL}
};

const images_tab_t images_settings_tab[] = {
    {"./ressource/images/filter.png", {0, 0, 0, 0},
        {0, 0}, {1920, 1080}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/wood_panel.png", {0, 0, 0, 0},
        {150, -650}, {1.4, 1.4}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/exit_settings_button.png", {0, 0, 0, 0},
        {820, 850}, {1, 1}, {0, 0, 0, 0}, &image_func_exit_sub_scene},
    {"./ressource/images/settings_elem.jpg", {458, 344, 240, 110},
        {680, 400}, {1, 1}, {0, 0, 0, 0}, &image_func_windowed},
    {"./ressource/images/settings_elem.jpg", {458, 344, 240, 110},
        {980, 400}, {1, 1}, {0, 0, 0, 0}, &image_func_full_screen},
    {"./ressource/images/settings_elem.jpg", {40, 355, 360, 100},
        {620, 600}, {1.8, 0.3}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/settings_elem.jpg", {590, 35, 102, 100}, {913, 585},
        {0.6, 0.6}, {620, 0, (360 * 1.8) - (102 * 0.6), 0},
        &image_func_music_volume},
    {"./ressource/images/settings_elem.jpg", {40, 355, 360, 100},
        {620, 720}, {1.8, 0.3}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/settings_elem.jpg", {590, 35, 102, 100}, {913, 705},
        {0.6, 0.6}, {620, 0, (360 * 1.8) - (102 * 0.6), 0},
        &image_func_sound_volume},
    {NULL, {0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0, 0}, NULL}
};

const images_tab_t images_game_tab[] = {
    {"./ressource/images/game.png", {0, 0, 0, 0},
        {0, 0}, {1, 1}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/button.png", {0, 0, 0, 0},
        {1550, 900}, {0.3, 0.3}, {0, 0, 0, 0}, &image_func_go_to_pause},
    {NULL, {0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0, 0}, NULL}
};

const images_tab_t images_pause_tab[] = {
    {"./ressource/images/filter.png", {0, 0, 0, 0},
        {0, 0}, {1920, 1080}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/wood_panel.png", {0, 0, 0, 0},
        {150, -650}, {1.4, 1.4}, {0, 0, 0, 0}, NULL},
    {"./ressource/images/exit_settings_button.png", {0, 0, 0, 0},
        {820, 850}, {1, 1}, {0, 0, 0, 0}, &image_func_exit_sub_scene},
    {"./ressource/images/settings_elem.jpg", {458, 344, 240, 110},
        {680, 400}, {1, 1}, {0, 0, 0, 0}, &image_func_back_to_menu},
    {"./ressource/images/settings_elem.jpg", {458, 344, 240, 110},
        {980, 400}, {1, 1}, {0, 0, 0, 0}, &image_func_go_to_settings},
    {NULL, {0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0, 0}, NULL}
};
