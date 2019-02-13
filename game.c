#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_game( GameParams * params )
{
	strcpy( params->version, "2.0.0" );
	params->turn = PLAYER_O;
	params->last_won = PLAYER_ANY;
	params->score_player_o = 0;
	params->score_player_x = 0;
	params->cnt = 0;
}

void init_board( Board * board )
{
	for ( int cnt = 0; cnt < MATRIX_SIZE; ++cnt )
	{
		board->field[cnt] = PLAYER_ANY;
	}
	board->ring_position = 5;
	
	board->board = malloc( MATRIX_X * MATRIX_Y );
}

void clear_board( Board * board )
{
	for ( int cnt = 0; cnt < MATRIX_SIZE; ++cnt )
	{
		board->field[cnt] = PLATER_ANY;
	}
	board->ring_position = 5;
	for ( int cnt = 0; cnt < MATRIX_X * MATRIX_Y; ++cnt )
	{
		board->board + cnt = ' ';
	}
}

void deinit_board( Board * board )
{
	free( board->board );
}

void print_header( GameParams * params )
{
	system( "clear" );
	printf("Tic Tac Toe ( version: %s )\n\r",  params->version);
	printf("\n\r");
	printf("Player %s : %u\n\r", params->name_player_o, params->score_player_o);
	printf("Player %s : %u\n\r", params->name_player_x, params->score_player_x);
	printf("\n\r");
	if ( params->turn == PLAYER_X ) 
	{
		printf("\tTURN: PLAYER X - %s\n\r", params->name_player_x);
	}
	else
	{
		 printf("\tTURN: PLAYER O - %s\n\r", params->name_player_o);
	}
	printf("\n\r");
	printf("\n\r");
	//printf("%u\n\r", params->cnt);
}

void print_board( Board * board, GameParams * param )
{
	insert_board_lines( board );
	insert_board_player( board );
	insert_board_ring( board );
	for ( int y = 0; y < MATRIX_Y; ++y )
	{
		printf("  ");
		for ( int x = 0; x < MATRIX_X; ++x )
		{
			if ( y == 5 || y == 11 )
			{
				if ( x == 8 || x == 17 )
				{
					printf("%c", * ( board->board + y * MATRIX_X + x ) );
				}
				else
				{
					printf("%c", * ( board->board + y * MATRIX_X + x ) );
				}				
			}
			else
			{
				if ( x == 8 || x == 17 )
				{
					printf("%c", * ( board->board + y * MATRIX_X + x ) );
				}
				else
				{
					printf("%c", * ( board->board + y * MATRIX_X + x ) );
				}
			}
		}
		printf("\n\r");
	}
}

void insert_board_character( Board * board, const char c, unsigned int y, unsigned int x )
{
	*( board->board + y * MATRIX_X + x ) = c;
}

void insert_X( Board * board, unsigned int position )
{
	
}

void insert_O( Board * board, unsigned int position )
{
	
}

void insert_board_player( Board * board )
{
	if ( board->field[0] == PLAYER_X )
	{
		insert_board_character( board, '\\', 1, 3 );
		insert_board_character( board, '/', 1, 5 );
		insert_board_character( board, 'X', 2, 4 );
		insert_board_character( board, '/', 3, 3 );
		insert_board_character( board, '\\', 3, 5 );
	}
	else if ( board->field[0] == PLAYER_O )
	{
		insert_board_character( board, '-', 1, 4 );
		insert_board_character( board, '|', 2, 2 );
		insert_board_character( board, '|', 2, 6 );
		insert_board_character( board, '-', 3, 4 );
	}
}

void insert_board_ring( Board * board )
{
	switch ( board->ring_position )
	{
		case 1:
			insert_board_character( board, '*', 0, 0 );
			break;
		case 2:
			*(board->board + 10) = '*';
			break;
		case 3:
			*(board->board + 20) = '*';
			break;
		case 4:
			*(board->board + 174) = '*';
			break;
		case 5:
			*(board->board + 184) = '*';
			break;
		case 6:
			*(board->board + 194) = '*';
			break;
		case 7:
			*(board->board + 348) = '*';
			break;
		case 8:
			*(board->board + 358) = '*';
			break;
		case 9:
			*(board->board + 368) = '*';
			break;
	}
}

void insert_board_lines( Board * board )
{
	for ( int y = 0; y < MATRIX_Y; ++y )
	{
		for ( int x = 0; x < MATRIX_X; ++x )
		{
			if ( y == MATRIX_LINE_Y_1 || y == MATRIX_LINE_Y_2 )
			{
				if ( x == MATRIX_LINE_X_1 || x == MATRIX_LINE_X_2 )
				{
					* ( board->board + y * MATRIX_X + x ) = '+';
				}
				else
				{
					* ( board->board + y * MATRIX_X + x ) = '-';
				}				
			}
			else
			{
				if ( x == MATRIX_LINE_X_1 || x == MATRIX_LINE_X_2 )
				{
					* ( board->board + y * MATRIX_X + x ) = '|';
				}
				else
				{
					* ( board->board + y * MATRIX_X + x ) = ' ';
				}
			}
		}
	}
}

void clear_board_matrix( Board * board )
{
	for ( int cnt = 0; cnt < MATRIX_X * MATRIX_Y; ++cnt )
	{
		*( board->board + cnt ) = ' ';
	}
} 

void move( Board * board, unsigned int _move )
{
	if ( _move == MOVE_RIGHT )
	{
		if ( board->ring_position < 9 )
			board->ring_position = board->ring_position + 1;
	}
	if ( _move == MOVE_LEFT )
	{
		if ( board->ring_position > 1 )
			board->ring_position = board->ring_position - 1;
	}
	if ( _move == MOVE_DOWN )
	{
		if ( board->ring_position < 7 )
			board->ring_position = board->ring_position + 3;
	}
	if ( _move == MOVE_UP )
	{
		if ( board->ring_position > 3 )
			board->ring_position = board->ring_position - 3;
	}
}

unsigned int write( GameParams * param, Board * board)
{
	if ( board->ring_position == 1 && board->field[0] == PLAYER_ANY )
	{
		board->field[0] = param->turn;
		return 1;
	}
	if ( board->ring_position == 2 && board->field[1] == PLAYER_ANY )
	{
		board->field[1] = param->turn;
		return 1;
	}
	if ( board->ring_position == 3 && board->field[2] == PLAYER_ANY )
	{
		board->field[2] = param->turn;
		return 1;
	}
	if ( board->ring_position == 4 && board->field[3] == PLAYER_ANY )
	{
		board->field[3] = param->turn;
		return 1;
	}
	if ( board->ring_position == 5 && board->field[4] == PLAYER_ANY )
	{
		board->field[4] = param->turn;
		return 1;
	}
	if ( board->ring_position == 6 && board->field[5] == PLAYER_ANY )
	{
		board->field[5] = param->turn;
		return 1;
	}
	if ( board->ring_position == 7 && board->field[6] == PLAYER_ANY )
	{
		board->field[6] = param->turn;
		return 1;
	}
	if ( board->ring_position == 8 && board->field[7] == PLAYER_ANY )
	{
		board->field[7] = param->turn;
		return 1;
	}
	if ( board->ring_position == 9 && board->field[8] == PLAYER_ANY )
	{
		board->field[8] = param->turn;
		return 1;
	}
	return 0;
}

unsigned int check_winer (GameParams * param, Board * b )
{
	if (    ( b->field[0] == PLAYER_O ) && ( b->field[1] == PLAYER_O ) && ( b->field[2] == PLAYER_O )
		||	( b->field[3] == PLAYER_O ) && ( b->field[4] == PLAYER_O ) && ( b->field[5] == PLAYER_O )
		||	( b->field[6] == PLAYER_O ) && ( b->field[7] == PLAYER_O ) && ( b->field[8] == PLAYER_O )
		||	( b->field[0] == PLAYER_O ) && ( b->field[3] == PLAYER_O ) && ( b->field[6] == PLAYER_O )
		||	( b->field[1] == PLAYER_O ) && ( b->field[4] == PLAYER_O ) && ( b->field[7] == PLAYER_O )
		||	( b->field[2] == PLAYER_O ) && ( b->field[5] == PLAYER_O ) && ( b->field[8] == PLAYER_O )
		||	( b->field[0] == PLAYER_O ) && ( b->field[4] == PLAYER_O ) && ( b->field[8] == PLAYER_O )
		||	( b->field[6] == PLAYER_O ) && ( b->field[4] == PLAYER_O ) && ( b->field[2] == PLAYER_O ) )
	{
		param->last_won = PLAYER_O;
		param->score_player_o++;
		return 1;
	}
	
	if (    ( b->field[0] == PLAYER_X ) && ( b->field[1] == PLAYER_X ) && ( b->field[2] == PLAYER_X )
		||	( b->field[3] == PLAYER_X ) && ( b->field[4] == PLAYER_X ) && ( b->field[5] == PLAYER_X )
		||	( b->field[6] == PLAYER_X ) && ( b->field[7] == PLAYER_X ) && ( b->field[8] == PLAYER_X )
		||	( b->field[0] == PLAYER_X ) && ( b->field[3] == PLAYER_X ) && ( b->field[6] == PLAYER_X )
		||	( b->field[1] == PLAYER_X ) && ( b->field[4] == PLAYER_X ) && ( b->field[7] == PLAYER_X )
		||	( b->field[2] == PLAYER_X ) && ( b->field[5] == PLAYER_X ) && ( b->field[8] == PLAYER_X )
		||	( b->field[0] == PLAYER_X ) && ( b->field[4] == PLAYER_X ) && ( b->field[8] == PLAYER_X )
		||	( b->field[6] == PLAYER_X ) && ( b->field[4] == PLAYER_X ) && ( b->field[2] == PLAYER_X ) )
	{
		param->last_won = PLAYER_X;
		param->score_player_x++;
		return 1;
	}
	
	if ( b->field[0] != PLAYER_ANY && b->field[1] != PLAYER_ANY && b->field[2] != PLAYER_ANY
		&& b->field[3] != PLAYER_ANY && b->field[4] != PLAYER_ANY && b->field[5] != PLAYER_ANY
		&& b->field[6] != PLAYER_ANY && b->field[7] != PLAYER_ANY && b->field[8] != PLAYER_ANY )
	{
		param->last_won = PLAYER_ANY;
		return 2;
	}
	return 0;
}

unsigned char get_signal( int * _key )
{
	int temp;
	temp = getchar();
	if ( temp == KEY_QUIT )
	{
		*_key = KEY_QUIT;
		return 1;
	}
	if ( temp == KEY_ENTER )
	{
		*_key = KEY_ENTER;
		return 1;
	}
	if ( temp == KEY_SPACE )
	{
		*_key = KEY_SPACE;
		return 1;
	}
	if ( temp == 27 )
	{
		getchar();
		switch( getchar() )
		{
			case KEY_ARROW_UP:
				*_key = KEY_ARROW_UP;
				break;
			case KEY_ARROW_DOWN:
				*_key = KEY_ARROW_DOWN;
				break;
			case KEY_ARROW_LEFT:
				*_key = KEY_ARROW_LEFT;
				break;
			case KEY_ARROW_RIGHT:
				*_key = KEY_ARROW_RIGHT;
				break;								
		}
		return 1;
	}
	return 0;
}

void ask_names( GameParams * param )
{
	char line[20];
	system("clear");
	printf("\n");
	printf("     Player 1 : ");
	if ( scanf("%s", line) == 0 )
	{
		strcpy(param->name_player_o, "O");
	}
	else
	{
		strcpy(param->name_player_o, line);
	}
	system("clear");
	printf("\n");
	printf("     Player 2 : ");
	if ( scanf("%s", line) == 0 )
	{
		strcpy(param->name_player_x, "X");
	}
	else
	{
		strcpy(param->name_player_x, line);
	}
	getchar();
}

void show_winer ( GameParams * param)
{
	system("clear");
	printf("\n\r");
	if ( param->last_won == PLAYER_O )
	{
		printf("     *** Last winer: %s ***\n\r", param->name_player_o);
	}
	else if ( param->last_won == PLAYER_X )
	{
		printf("     *** Last winer: %s ***\n\r", param->name_player_x);
	}
	else
	{
		printf("     *** Draw ***\n\r");
	}
	printf("\n\r");
	printf("     Scores:\n\r");
	printf("\n\r");
	printf("     %s : %u\n\r", param->name_player_o, param->score_player_o);
	printf("     %s : %u\n\r", param->name_player_x, param->score_player_x);
	getchar();
}

void change_turn ( GameParams * param )
{
	if ( param->turn == PLAYER_O )
	{
		param->turn = PLAYER_X;
	}
	else
	{
		param->turn = PLAYER_O;
	}
}
















