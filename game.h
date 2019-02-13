#ifndef GAME_H
#define GAME_H

#define MATRIX_X 29
#define MATRIX_Y 17
#define MATRIX_LINE_X_1 9
#define MATRIX_LINE_X_2 19
#define MATRIX_LINE_Y_1 5
#define MATRIX_LINE_Y_2 11
#define MATRIX_SIZE 9
#define MATRIX_FIELD_1 0
#define MATRIX_FIELD_2 10
#define MATRIX_FIELD_3 20
#define MATRIX_FIELD_4 174
#define MATRIX_FIELD_5 184
#define MATRIX_FIELD_6 194
#define MATRIX_FIELD_7 348
#define MATRIX_FIELD_8 358
#define MATRIX_FIELD_9 368

#define COLOR_NC \E[0M
#define COLOR_BLUE \e[0;34m
#define COLOR_RED \e[0;31m
#define COLOR_YELLOW \e[1;33m

#define KEY_ARROW_UP 'A'
#define KEY_ARROW_DOWN 'B'
#define KEY_ARROW_RIGHT 'C'
#define KEY_ARROW_LEFT 'D'
#define KEY_ENTER 13
#define KEY_QUIT 'q'
#define KEY_SPACE 32
#define MOVE_UP 0
#define MOVE_DOWN 1
#define MOVE_LEFT 2
#define MOVE_RIGHT 3

#define PLAYER_O 0
#define PLAYER_X 1
#define PLAYER_ANY 2

typedef struct 
{
	unsigned short turn;
	unsigned short last_won;
	unsigned short score_player_o;
	unsigned short score_player_x;
	char name_player_o [20];
	char name_player_x [20];
	char version[10];
	unsigned short ring;
	unsigned int cnt;
} GameParams;

typedef struct
{
	unsigned short ring_position;
	char * board;
	int field[MATRIX_SIZE];
} Board;

void init_game( GameParams * );
void init_board( Board * );
void clear_board( Board * );
void deinit_board( Board * );
void print_header(GameParams * );
void print_board ( Board *, GameParams *);
unsigned char get_signal(int * );
void move( Board *, unsigned int _move );
unsigned int write( GameParams *, Board * );
unsigned int check_winer (GameParams *, Board * );
void ask_names( GameParams * );
void show_winer ( GameParams * );
void change_turn ( GameParams * );
void insert_board_player( Board * );
void insert_board_lines( Board * );
void insert_board_ring( Board * );
void clear_board_matrix( Board * );

#endif // GAME_H
