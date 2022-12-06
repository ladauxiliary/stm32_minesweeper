#include "logic.h"

uint8_t mine_field[X_TILE_COUNT][Y_TILE_COUNT]; // if 0 - tile containing no mines, 1 - tile containing a mine
uint8_t how_many_mines_around[X_TILE_COUNT][Y_TILE_COUNT]; // X(0..8) mines placed around tile
uint8_t tile_memory[X_TILE_COUNT][Y_TILE_COUNT]; // Contains info about previously held pictogram 
uint8_t tile_check_flag; // This flag is used to tell the programm that we are going to open a tile
bool game_started;
bool game_over_flag;
uint8_t ingame_selector;
extern bool terminator;
extern uint8_t selected_difficulty;

void (*piktograms[PIKTOGRAMM_ARRAY_LENGTH])(uint8_t,uint8_t);


void inicialise_tile_memory(void)
{
    for (uint8_t x = 0; x < X_TILE_COUNT; x++)
    {
        for (uint8_t y = 0; y < Y_TILE_COUNT; y++)
        {
            tile_memory[x][y] = 3;
        }
    }
}

/// @brief Initialising array of pointers on functions, wich used for drawing graphical primitives
void inicialise_piktogramm_array(void)
{
    //piktograms[0]=draw_mine;
    piktograms[0]=draw_flag;
    piktograms[1]=draw_question_mark;
    piktograms[2]=draw_ok;
    piktograms[3]=draw_empty_tile;
}

void select_tile(uint8_t x_number, uint8_t y_number)
{
    load_map(Bit_map,Board);
    draw_selection(x_number,y_number);
}

void spawn_mines(uint8_t  mine_field[X_TILE_COUNT][Y_TILE_COUNT])
{
	uint8_t mine_count;
	switch (selected_difficulty)
	{
	case 0:
		mine_count  = 8;
		break;
	case 1:
		mine_count  = 12;
		break;
	case 2:
		mine_count  = 16;
		break;		
	default:
		break;
	}

	for (uint8_t i = 0; i < X_TILE_COUNT; i++)
	{
		for (uint8_t j = 0; j < Y_TILE_COUNT; j++)
		{
			mine_field[i][j]=0;
		}
	}		

	srand(TIM2 -> CNT);
	while (mine_count>0)
	{
		uint8_t x = (rand())%(X_TILE_COUNT);
		uint8_t y = (rand())%(Y_TILE_COUNT);
		
		if (mine_field[x][y]==0)
		{
			mine_field[x][y]=1;
			mine_count--;
		}
	}
	
}

void calculate_how_many_mines_around
(uint8_t  mine_field[X_TILE_COUNT][Y_TILE_COUNT],uint8_t  how_many_mines_around[X_TILE_COUNT][Y_TILE_COUNT])
{
    uint8_t current_mine_count;
    for (uint8_t i = 0; i < (X_TILE_COUNT); i++)
    {
        for (uint8_t j = 0; j < (Y_TILE_COUNT); j++)
        {
            current_mine_count = 0;
            if (mine_field[i][j]==0) // Tile does not need to know how many mines around it if there is a mine inside it
            {
                bool do_not_check_top = false;      // Bool flags are not necessary, but they are used to
                bool do_not_check_left = false;     // simplify code understanding
                bool do_not_check_bottom = false;   //
                bool do_not_check_right = false;    //
                
                if (i == 0)
                {
                    do_not_check_left = true;
                }

                if (i == (X_TILE_COUNT-1))
                {
                    do_not_check_right = true;
                }

                if (j==0)
                {
                    do_not_check_top = true;
                }

                if (j==(Y_TILE_COUNT-1))
                {
                    do_not_check_bottom = true;
                }
                
                if (do_not_check_left!=true)
                {
                    if (do_not_check_top != true ) 
                    {
                        current_mine_count += mine_field[i-1][j-1];
                    }

                    current_mine_count += mine_field[i-1][j];

                    if (do_not_check_bottom != true) 
                    {
                        current_mine_count += mine_field[i-1][j+1];
                    }
                }
                
                if (do_not_check_top!=true)
                {
                    current_mine_count += mine_field[i][j-1];
                }    
                if (do_not_check_bottom != true) 
                {
                    current_mine_count += mine_field[i][j+1];
                }

                if (do_not_check_right!=true)
                {
                    if (do_not_check_top != true ) 
                    {
                        current_mine_count += mine_field[i+1][j-1];
                    }

                    current_mine_count += mine_field[i+1][j];

                    if (do_not_check_bottom != true ) 
                    {
                        current_mine_count += mine_field[i+1][j+1];
                    }
                }            
            }
            else
            {
                current_mine_count = 9; // Marking tile as mined
            }
            how_many_mines_around[i][j] = current_mine_count; 
        }   
    }
}

void game_over(void)
{
    for (uint8_t x = 0; x < X_TILE_COUNT; x++)
    {
        for (uint8_t y = 0; y < Y_TILE_COUNT; y++)
        {
            draw_empty_tile(x,y);
            if (how_many_mines_around[x][y]==9)
            {
				if (tile_memory[x][y]!=0)
				{
					draw_mine(x,y);
				}
				else
				{
					draw_flag(x,y);
				}
            }
            else
            {
				if (tile_memory[x][y] != PIKTOGRAMM_ARRAY_LENGTH-1)
				{
					if (tile_memory[x][y] == 0)
					{
						draw_mistake(x,y);
					}
					else
					{
						draw_number(x,y,how_many_mines_around[x][y]);
					}
				}
            }
        }
    }
	game_over_flag = true;
    draw_changes();
}


void start_game(void)
{
    game_started = true;
	game_over_flag = false;
    posx=0;
	posy=0;
	inicialise_piktogramm_array();
	inicialise_tile_memory();
	spawn_mines(mine_field);
	calculate_how_many_mines_around(mine_field,how_many_mines_around);
	ingame_selector = 0;

	reset_map(Bit_map);
	draw_board();
	copy_map(Board,Bit_map);
	select_tile(0,0);
	draw_changes();

	transfer_control_to_buttons();
}

void ingame_click_mid(void)
{
	if (game_over_flag != true)
	{
		if (tile_memory[posx][posy]!=PIKTOGRAMM_ARRAY_LENGTH) // Preventing interactions with already opend tile
		{
			if (select_mode_enabled)
			{

				if (tile_check_flag == 1)
				{
					if (how_many_mines_around[posx][posy]==9)
					{
						game_over();
					}
					else 
					{
						draw_empty_tile(posx,posy);
						draw_default_tile_borders(posx,posy);
						draw_number(posx,posy,how_many_mines_around[posx][posy]);
						tile_memory[posx][posy] = PIKTOGRAMM_ARRAY_LENGTH; // Marking tile as opend (to prevent modifing manually)
						copy_map(Board,Bit_map);
						draw_selection(posx,posy);
						draw_changes();
						select_mode_enabled = !select_mode_enabled;
						return;
					}
				}
				draw_default_tile_borders(posx,posy);
				copy_map(Board,Bit_map);
				draw_selection(posx,posy);
				draw_changes();	
				
			} else
			{
				draw_empty_tile(posx,posy);
				ingame_selector=tile_memory[posx][posy];
				piktograms[ingame_selector](posx,posy);
				draw_selection(posx,posy);
				draw_changes();
			}
			select_mode_enabled = !select_mode_enabled;
		}
	}
	else
	{
		terminator = true;
	}	
}
void ingame_click_up(void)
{
    if (!select_mode_enabled)
	{
		if (posy>0)
		{
			posy--;
		}
		else 
		{
			posy = Y_TILE_COUNT - 1;
		}
		select_tile(posx,posy);
		draw_changes();
	}
}
void ingame_click_down(void)
{
    if (!select_mode_enabled)
	{
		if (posy<(Y_TILE_COUNT-1))
		{
			posy++;
		}
		else 
		{
			posy = 0;
		}
		select_tile(posx,posy);
		draw_changes();
	}	
}
void ingame_click_left(void)
{
    if (!select_mode_enabled)
	{
		if (posx>0)
		{
			posx--;
		}
		else 
		{
			posx = X_TILE_COUNT-1;
		}
		select_tile(posx,posy);
		draw_changes();
	}	
	else
	{
		if (ingame_selector>0)
		{
			ingame_selector--;
		}
		else
		{
			ingame_selector = (PIKTOGRAMM_ARRAY_LENGTH-1);
		}
		draw_empty_tile(posx,posy);
		tile_memory[posx][posy] = ingame_selector;
		piktograms[ingame_selector](posx,posy);
		draw_changes();
	}
}
void ingame_click_right(void)
{
    if (!select_mode_enabled)
	{
		if (posx<(X_TILE_COUNT-1))
		{
			posx++;
		}
		else 
		{
			posx = 0;
		}

		select_tile(posx,posy);
		draw_changes();
	}	
	else
	{
		if (ingame_selector<(PIKTOGRAMM_ARRAY_LENGTH-1))
		{
			ingame_selector++;
		}
		else
		{
			ingame_selector = 0;
		}
		draw_empty_tile(posx,posy);
		tile_memory[posx][posy] = ingame_selector;
		piktograms[ingame_selector](posx,posy);
		draw_changes();
	}
}