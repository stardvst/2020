#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row, col;
char *board = NULL;
int *hashes = NULL;
int index = 0;
char *boards[500];

int powInt(int x, int y)
{
	int i;
	for (i = 0; i < y; i++)
		x *= 10;
	return x;
}

int parseInt(char *chars)
{
	int sum = 0;
	int x;
	int len = strlen(chars);
	for (x = 0; x < len; x++)
	{
		int n = chars[len - (x + 1)] - '0';
		sum = sum + powInt(n, x);
	}
	return sum;
}

void initialize_board()
{
	/* create the board */
	board = (char *)malloc(row * col * sizeof(char));
	int i, j;

	/* initialize all cells to spaces */
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			int idx = i * col + j;
			board[idx] = ' ';
		}
	}
}

int read_file(const char *fileName)
{
	FILE *f;
	int	j;
	char s[100];
	int r, c;

	f = fopen(fileName, "r");
	int cellCount = 0;

	/* read a line */
	if (fgets(s, 100, f))
	{
		/* first line is alive cell count */
		sscanf(s, "%d", &cellCount);

		/* read alive cell coordinates */
		for (j = 0; j < cellCount; j++)
		{
			fgets(s, 100, f);
			sscanf(s, "%d %d", &r, &c);

			/* make sure cell is within board boundaries */
			if (!(c > 0 && c <= col && r > 0 && r <= row))
			{
				fprintf(stderr, "Cell is outside the board\n");
				return -1;
			}

			/* mark alive cell in the board */
			*(board + r * col + c) = '0';
		}
	}

	fclose(f);
	return 0;
}

void print(char *brd)
{
	int	i, j;

	/* print first row */
	printf("*");
	for (i = 0; i < col; ++i)
		printf("-");
	printf("*\n");

	/* print the board */
	for (i = 0; i < row; i++)
	{
		printf("|");

		for (j = 0; j < col; j++)
		{
			/* calculate hash */
			char ch = *(brd + i * col + j);
			printf("%c", ch);
		}
		printf("|\n");
	}

	/* print last row */
	printf("*");
	for (i = 0; i < col; ++i)
		printf("-");
	printf("*\n");
}

int calculate_hash(char *brd)
{
	int hash = 0, i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (*(brd + i * col + j) != ' ')
				hash += ((i * col) * 50 + j);
		}
	}

	return hash;
}

int is_alive(char ch)
{
	/* if char is 0-9 or X, it is alive */
	return (ch >= '0' && ch <= '9') || ch == 'X' ? 1 : 0;
}

int next()
{
	int	i, j, a;
	char age;
	char *p;
	char *newboard = (char *)malloc(row * col * sizeof(char));

	/* get alive neighbor count for each cell */
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			int aliveNeighbours = 0;

			/* next column */
			if (j + 1 < col) aliveNeighbours += is_alive(*(board + i * col + (j + 1)));

			if (i + 1 < row)
			{
				/* next row */
				aliveNeighbours += is_alive(*(board + (i + 1) * col + j));

				/* next row and next column */
				if (j + 1 < col) aliveNeighbours += is_alive(*(board + (i + 1) * col + (j + 1)));
			}

			if (j - 1 >= 0)
			{
				/* previous column */
				aliveNeighbours += is_alive(*(board + i * col + (j - 1)));

				/* previous column and next row */
				if (i + 1 < row) aliveNeighbours += is_alive(*(board + (i + 1) * col + (j - 1)));
			}

			if (i - 1 >= 0)
			{
				/* previous row */
				aliveNeighbours += is_alive(*(board + (i - 1) * col + j));

				/* previous row and previous column */
				if (j - 1 >= 0) aliveNeighbours += is_alive(*(board + (i - 1) * col + (j - 1)));

				/* previous row and next column */
				if (j + 1 < col) aliveNeighbours += is_alive(*(board + (i - 1) * col + (j + 1)));
			}

			/* current cell dies from loneliness */
			if (is_alive(*(board + i * col + j)) && (aliveNeighbours < 2))
				*(newboard + i * col + j) = ' ';

			/* current cell dies from overcrowding */
			else if (is_alive(*(board + i * col + j)) && (aliveNeighbours > 3))
				*(newboard + i * col + j) = ' ';

			/* current dead cell will become alive */
			else if ((*(board + i * col + j) == ' ') && (aliveNeighbours == 3))
				*(newboard + i * col + j) = '0';

			/* otherwise it stays the same */
			else
			{
				/* get current age */
				age = (*(board + i * col + j));

				/* if current age is 9, incrementing should give us X */
				if (age == '9')
					age = 'X';

				/* otherwise if it is a number */
				else if (age != 'X' && age != ' ')
				{
					/* increment the number */
					p = &age;
					a = atoi(p) + 1;
					age = a + '0';
				}

				/* and set the new age */
				*(newboard + i * col + j) = age;
			}
		}
	}

	index += 1;
	boards[index] = newboard;

	/* copy the new board to current board */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			board[i * col + j] = newboard[i * col + j];

	/* check if board hash already exists */
	int found = 1;
	int hash = calculate_hash(newboard);
	int m;
	for (m = 0; m < index; m++)
	{
		found = 1;
		if (hashes[m] == hash)
		{
			char *current = NULL;
			current = boards[m];
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
				{
					if (is_alive(*(current + i * col + j)) != is_alive(*(newboard + i * col + j)))
					{
						found = 0;
						break;
					}
				}
			}

			if (found)
				return 0;
		}
	}

	if (found)
		return 0;

	/* save hash */
	hashes[index] = hash;

	return 1;
}

int main(const int argc, char *argv[])
{
	int generations, i;

	if (argc != 5)
	{
		fprintf(stderr, "Usage: <program> <file> <width> <height> <rounds>");
		return -1;
	}

	/* create board hashes */
	hashes = (int *)malloc(row * col * sizeof(int));

	/* get generation count */
	sscanf(argv[4], "%d", &generations);

	/* get board width and height */
	sscanf(argv[3], "%d", &row);
	sscanf(argv[2], "%d", &col);

	/* initialize the board */
	initialize_board();

	/* read the file for alive cells */
	if (read_file(argv[1]) != 0)
		return -1;

	/* print the initial board */
	char *cpyboard = NULL;
	cpyboard = (char *)malloc(row * col * sizeof(char));
	memcpy(cpyboard, board, row * col * sizeof(char));
	boards[index] = cpyboard;
	hashes[index] = calculate_hash(board);
	print(board);

	/* process next generations */
	for (i = 0; i < generations; ++i)
	{
		/* print 2 blank lines after each generation */
		printf("\n\n");

		/* get next generation */
		if (next() == 0)
		{
			print(board);
			printf("\nPeriod detected (%d): exiting\n", index);
			return 0;
		}

		/* print new generation */
		print(board);
	}

	/* print Finished */
	printf("\nFinished\n");

	free(board);
	free(hashes);
	return 0;
}
