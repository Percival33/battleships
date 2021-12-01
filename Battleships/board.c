#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <assert.h>

#include "constants.h"
#include "player.h"
#include "board.h"

dim_t* dim_init(int ROWS, int COLS) {
	dim_t* dim = (dim_t*)malloc(sizeof(dim));

	assert(dim != NULL);

	dim->COLS = COLS;
	dim->ROWS = ROWS;

	return dim;
}

board_t** board_init(dim_t* dim) {
	const int ROWS = dim->ROWS;
	const int COLS = dim->COLS;

	board_t** board = (board_t**)malloc(ROWS * sizeof(board_t*));

	assert(board != NULL);

	for (int i = 0; i < ROWS; i++) {
		board[i] = (board_t*)malloc(COLS * sizeof(board_t));
		assert(board[i] != NULL);
	}


	for (int i = 0; i < COLS; i++) {
		board[ROWS / 2][i].type = B_BAN;
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j].type = B_EMPTY;
			board[i][j].playerId = B_EMPTY;
		}
	}

	return board;
}

void board_free(board_t** board, dim_t* dim) {
	for (int i = 0; i < dim->ROWS; i++)
		free(board[i]);
	free(board);
	return;
}

/*
int board_inside(dim_t* dim, field_t* field) {
	const int ROWS = dim->ROWS;
	const int COLS = dim->COLS;

	int inRows = (0 <= field->y && field->y < ROWS && field->y != ROWS/2);
	int inCols = (0 <= field->x && field->x < COLS);

	if (inRows && inCols) {
		return True;
	}
	return False;
}
*/
void board_print(board_t** board, dim_t* dim, int mode, player_t** player) {
	const int COLS = dim->COLS;
	const int ROW_LOW = 0;
	const int ROW_HIGH = dim->ROWS;

	for (int i = ROW_LOW; i < ROW_HIGH; i++) {
		for (int j = 0; j < COLS; j++) {
			if (board[i][j].type == B_EMPTY || board[i][j].type == B_BAN) {
				printf(" ");
			}
			else if (board[i][j].type == B_TAKEN) {
				printf("+");
			}
			else if (board[i][j].type == B_DESTROYED) {
				printf("x");
			}
			//printf("{%d,%d} = %d ", i, j, board[i][j].type);
		}
		printf("\n");
	}

	int AReamaining = get_remaining_parts(player[PLAYER_A]);
	int BReamaining = get_remaining_parts(player[PLAYER_B]);


	printf("PARTS REMAINING:: A : %d B : %d\n", AReamaining, BReamaining);

	return;

}