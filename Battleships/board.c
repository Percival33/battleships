#include <stdlib.h>
#include <assert.h>

#include "constants.h"
#include "board.h"
#include "player.h"

board_t** board_init(dim_t* dim) {
	const int ROWS = dim->ROWS;
	const int COLS = dim->COLS;

	board_t** board = (board_t**)malloc(ROWS * sizeof(board_t*));
	
	assert(board != NULL);

	for (int i = 0; i < ROWS; i++) {
		board[i] = (board_t*)malloc(COLS * sizeof(board_t));
		assert(board[i] != NULL);
	}


	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j].type = B_EMPTY;
		}
	}

	return board;
}

void board_print(board_t** board, dim_t* dim) {
	const int ROWS = dim->ROWS;
	const int COLS = dim->COLS;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("{%d,%d} = %d ", i, j, board[i][j].type);
		}
		printf("\n");
	}
}

void board_free(board_t** board, dim_t* dim) {
	const int ROWS = dim->ROWS;

	for (int i = 0; i < ROWS; i++) {
		free(board[i]);
	}
	free(board);
	return;
}

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