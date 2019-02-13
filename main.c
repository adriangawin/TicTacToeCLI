#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "game.h"
#include <sys/ioctl.h>

sig_atomic_t run = 1;

unsigned int cnt = 0;

void my_handler ( int param )
{
	run = 0;
}

int main()
{
	system( "/bin/stty raw" );
	void (*prev_handler)(int);
	prev_handler = signal (SIGINT, my_handler);
	
	GameParams params;
	init_game( &params );
	
	Board board;
	init_board( &board );
	
	ask_names( &params );
	
	print_header( &params );
	print_board_matrix( &board, &params );
	
	while ( run )
	{
		int key;
		if ( get_signal( &key ) )
		{
			switch ( key )
			{
				case KEY_QUIT:
					run = 0;
					break;
				case KEY_ARROW_LEFT:
					move( &board, MOVE_LEFT );
					break;
				case KEY_ARROW_RIGHT:
					move( &board, MOVE_RIGHT );
					break;
				case KEY_ARROW_UP:
					move( &board, MOVE_UP );
					break;
				case KEY_ARROW_DOWN:
					move( &board, MOVE_DOWN );
					break;
				case KEY_SPACE:
				case KEY_ENTER:
					params.cnt++;
					if ( write( &params, &board ) )
					{
						if ( check_winer( &params, &board ) )
						{
							show_winer( &params );
							init_board( &board );
						}
						change_turn( &params );
					}
					break;
			}
		}

		print_header( &params );
		print_board_matrix( &board, &params );
	}
	system("clear");
	deinit_board( &board );
	system( "/bin/stty cooked" );
	system("figlet Thanks!");
	return 0;
}
