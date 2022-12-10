#ifndef constant_set_H
    #define constant_set_H

    #include <stdbool.h>
    #include <stm32f10x.h>

    #define VIRTUAL 1
    #define REAL 0
    #define QUEUE_LENGTH 1024
    #define DISPLAY_HEIGHT 64
    #define DISPLAY_WIDTH 128
    #define DISPLAY_PAGE_COUNT 8

    #define TILE_SIDE 11
    #define BOARD_START_X 3
    #define BOARD_START_Y 4
    #define X_TILE_COUNT 11
    #define Y_TILE_COUNT 5
    #define PIKTOGRAMM_ARRAY_LENGTH 4
    #define DIFFICULTIES_ARRAY_LENGTH 3

    #define CL_BLACK 0
    #define CL_WHITE 1
    #define FILL_BLACK 0
    #define FILL_WHITE 1
    #define NO_FILL 3

    extern void (*piktograms[PIKTOGRAMM_ARRAY_LENGTH])(uint8_t,uint8_t);

    extern uint8_t tile_check_flag;
    extern uint8_t Bit_map[128][8];
    extern uint8_t Board[128][8];

    extern bool terminator;
    extern bool win_flag;
    extern bool ending_dialog;
    extern bool game_started;
    extern bool restart_flag;
    extern bool select_mode_enabled; 
    extern bool now_drawing;

    extern uint8_t selected_difficulty;

    extern int posx;
    extern int posy;

    extern uint8_t Game_UI[128][8];
    extern const uint8_t menu_bit_map[128*8];
    extern const uint8_t loading_bit_map[128*8];
    extern const uint8_t game_end_win[128*8];
    extern const uint8_t game_end_loose[128*8];   

#endif
